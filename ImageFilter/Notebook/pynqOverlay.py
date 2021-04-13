import os
import numpy as np
from pynq.lib.video import *
from pynq import Overlay, PL, MMIO
from pynq import DefaultIP, DefaultHierarchy
from pynq import allocate
from pynq.xlnk import ContiguousArray
from pynq.lib import DMA
from cffi import FFI


PYNQOVERLAY_ROOT_DIR = os.path.dirname(os.path.realpath('__file__'))

class pynqOverlay():
    MAX_WIDTH  = 1920
    MAX_HEIGHT = 1080       
    def __init__(self, load_overlay=True):
        self.bitstream_name = None
        self.bitstream_name = "accel.bit"
        self.bitstream_path = os.path.join(self.bitstream_name)
        self.ol = Overlay(self.bitstream_name) #self.bitstream_path)
        self.ol.download()
        self.ol.reset()
        #self.xlnk = Xlnk()
        self.partitions = 10 # il cma viene splittato per trasferimento in pipeline
        self.cmaPartitionLen = self.MAX_HEIGHT*self.MAX_WIDTH/self.partitions
        self.listOfcma = [allocate(shape=(int(self.MAX_HEIGHT/self.partitions),self.MAX_WIDTH), dtype=np.uint8) for i in range(self.partitions)]
        self.img_filters = self.ol.image_filters
        self.dmaOut = self.img_filters.axi_dma_0.sendchannel 
        self.dmaIn =  self.img_filters.axi_dma_0.recvchannel 
        self.dmaOut.stop()
        self.dmaIn.stop()
        self.dmaIn.start()
        self.dmaOut.start()
        self.filterSo=filters
        self.filter2DType = -1  # filter types: SobelX=0
        self.ffi = FFI()
        self.f2D = self.img_filters.filter2D_hls_0
        self.f2D.reset()
        
            #hdmi
        #self.hdmi_in = self.ol.video.hdmi_in
        #self.hdmi_out = self.ol.video.hdmi_out
        #self.ol.video.hdmi_in.configure(PIXEL_RGB)
        #self.ol.video.hdmi_out.configure(self.ol.video.hdmi_in.mode,PIXEL_RGB)
        #self.ol.video.hdmi_in.start()
        #self.ol.video.hdmi_out.start()
        #self.ol.video.hdmi_in.tie(self.ol.video.hdmi_out)
        
        #cma
        self.cmaBuffer_0 = allocate(shape=(self.MAX_HEIGHT,self.MAX_WIDTH), dtype=np.uint8)
        self.cmaBuffer0 =  self.cmaBuffer_0.view(self.ContiguousArrayPynqOverlay)
        self.cmaBuffer0.init(self.cmaBuffer_0)
        self.cmaBuffer_1 = allocate(shape=(self.MAX_HEIGHT,self.MAX_WIDTH), dtype=np.uint8)
        self.cmaBuffer1 =  self.cmaBuffer_1.view(self.ContiguousArrayPynqOverlay)
        self.cmaBuffer1.init(self.cmaBuffer_1)
        self.cmaBuffer_2 = allocate(shape=(self.MAX_HEIGHT*4,self.MAX_WIDTH), dtype=np.uint8) # *4 for CornerHarris return
        self.cmaBuffer2 =  self.cmaBuffer_2.view(self.ContiguousArrayPynqOverlay)
        self.cmaBuffer2.init(self.cmaBuffer_2)
    
    def __str__(self):
        return  str(self.__class__) + '\n'+ '\n'.join(('{} = {}'.format(item, self.__dict__[item]) for item in self.__dict__))

    
    def close(self):      
        self.cmaBuffer_0.close()
        self.cmaBuffer_1.close()
        self.cmaBuffer_2.close()
        for cma in self.listOfcma:
            cma.close()  
       

    def copyNto(self,dst,src,N):
        dstPtr = self.ffi.cast("uint8_t *", self.ffi.from_buffer(dst))
        srcPtr = self.ffi.cast("uint8_t *", self.ffi.from_buffer(src))
        self.ffi.memmove(dstPtr, srcPtr, N)

    def copyNtoOff(self,dst,src,N,dstOffset,srcOffset):   
        dstPtr = self.ffi.cast("uint8_t *", self.ffi.from_buffer(dst))
        srcPtr = self.ffi.cast("uint8_t *", self.ffi.from_buffer(src))
        dstPtr += dstOffset
        srcPtr += srcOffset
        self.ffi.memmove(dstPtr, srcPtr, N)
               
        
    def filter2D(self, src, dst):
        if dst is None :
            self.cmaBuffer1.nbytes = src.nbytes
        elif hasattr(src, 'physical_address') and hasattr(dst, 'physical_address') :
            self.dmaIn.transfer(dst)
            self.dmaOut.transfer(src)
            self.dmaIn.wait()
            return dst
        if hasattr(src, 'physical_address') :
            self.dmaIn.transfer(self.cmaBuffer1)
            self.dmaOut.transfer(src)
            self.dmaIn.wait()
        else:#a seconda della dimensione dello stream lo divide in n-byte
            if src.nbytes < 184800: #440x420
                self.partitions = 1
            elif src.nbytes < 180000: #600x300
                self.partitions = 2
            elif src.nbytes < 231200: #680x340
                self.partitions = 4
            else :
                self.partitions = 8
            self.cmaBuffer1.nbytes = src.nbytes
            self.dmaIn.transfer(self.cmaBuffer1)
            chunks_len = int(src.nbytes / (self.partitions))
            self.cmaBuffer0.nbytes = chunks_len
            self.cmaBuffer2.nbytes = chunks_len
            self.copyNto(src,self.cmaBuffer0,chunks_len)
            for i in range(1,self.partitions):
                if i % 2 == 1:
                    while not self.dmaOut.idle and not self.dmaOut._first_transfer:
                        pass 
                    self.dmaOut.transfer(self.cmaBuffer0)
                    self.copyNtoOff(src ,self.cmaBuffer2,chunks_len, i*chunks_len, 0)
                else:
                    while not self.dmaOut.idle and not self.dmaOut._first_transfer:
                        pass 
                    self.dmaOut.transfer(self.cmaBuffer2)
                    self.copyNtoOff(src ,self.cmaBuffer0,chunks_len,  i*chunks_len, 0)
            while not self.dmaOut.idle and not self.dmaOut._first_transfer:
                pass 
            self.dmaOut.transfer(self.cmaBuffer2)
            rest = src.nbytes % self.partitions 
            if rest != 0: #pulisce ogni residuo dei dati e liu manda al sistema
                self.copyNtoOff(src ,self.cmaBuffer0,chunks_len, self.partitions*chunks_len, 0)
                while not self.dmaOut.idle and not self.dmaOut._first_transfer:
                    pass 
                self.dmaOut.transfer(self.cmaBuffer0)
            self.dmaIn.wait()
        ret = np.ndarray(src.shape,src.dtype)
        self.copyNto(ret,self.cmaBuffer1,ret.nbytes)
        return ret
    

    def Sobel(self,src, ddepth, dx, dy, dst, ksize=3):
        if(ksize == 3):
            self.filter2DType = 0
            self.f2D.rows = src.shape[0]
            self.f2D.columns = src.shape[1]
            self.f2D.channels = 1
            self.f2D.r1 = 0x000100ff #[-1  0  1]
            self.f2D.r2 = 0x000200fe #[-2  0  2]
            self.f2D.r3 = 0x000100ff #[-1  0  1]           
            self.f2D.start()                                
            return self.filterSo.Sobel(src,-1,1,0,ksize=3,dst=dst)
                
            
    class ContiguousArrayPynqOverlay(ContiguousArray):
        def init(self,cmaArray):
            self._nbytes = cmaArray.nbytes
            if (cmaArray.nbytes < 0):
                self.physical_address = cmaArray.physical_address
                self.cacheable = cmaArray.cacheable
        # overwrite access to nbytes with own function
        @property
        def nbytes(self):
            return self._nbytes

        @nbytes.setter
        def nbytes(self, value):
            self._nbytes = value
            