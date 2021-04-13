import os
import numpy as np
from pynq import Overlay, PL, MMIO
from pynq import DefaultIP, DefaultHierarchy

class pynqOverlayDriverFilter2D(DefaultIP):
    def __init__(self, description):
        super().__init__(description=description)
        self.reset()
        
    bindto = ['xilinx.com:hls:filter2D_hls:1.0']

    def start(self):
        self.write(0x00, 0x01)

    def auto_restart(self):
        self.write(0x00, 0x81)

    def reset(self):
        self.rows_value = -1
        self.rows = 0
        self.columns_value = -1
        self.columns = 0
        self.channels_value = -1
        self.channels = 1 
        self.mode_value = -1
        self.mode = 0  
        self.r1_value = -1  
        self.r1 = 0
        self.r2_value = -1
        self.r2 = 0
        self.r3_value = -1
        self.r3 = 0
 
    @property
    def rows(self):
        return self.read(0x14)
    @rows.setter
    def rows(self, value):
        if not self.rows_value == value:
            self.write(0x14, value)
            self.rows_value = value

    @property
    def columns(self):
        return self.read(0x1c)
    @columns.setter
    def columns(self, value):
        if not self.columns_value == value:
            self.write(0x1c, value)
            self.columns_value = value

    @property
    def channels(self):
        return self.read(0x24)
    @channels.setter
    def channels(self, value):
        if not self.channels_value == value:
            self.write(0x24, value)
            self.channels_value = value
        
    @property
    def mode(self):
        return self.read(0x2c)
    @mode.setter
    def mode(self, value):
        if not self.mode_value == value:
            self.write(0x2c, value)
            self.mode_value = value    
    
    @property
    def r1(self):
        return self.read(0x34)
    @r1.setter
    def r1(self, value):
        if not self.r1_value == value:
            self.write(0x34, value)
            self.mode_value = value         
    
    @property
    def r2(self):
        return self.read(0x3c)
    @r2.setter
    def r2(self, value):
        if not self.r2_value == value:
            self.write(0x3c, value)
            self.mode_value = value

    @property
    def r3(self):
        return self.read(0x44)
    @r3.setter
    def r3(self, value):
        if not self.r3_value == value:
            self.write(0x44, value)
            self.mode_value = value
