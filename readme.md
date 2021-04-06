<h1> Processamento immagini potenziato tramite overlay creato in Vivado 2018.3  </h1>

specifica coming soon


<h3> HARDWARE UTILIZZATO </h3>  
l'implementazione di questo progetto è stata fatta sulla scheda Pynq-z2 che si basa su piattaforme Xilinx .  

Dettagli della scheda http://www.pynq.io/  http://www.pynq.io/board.html


<h3> PIATTAFORME SOFTWARE </h3>  
Vivado 2018.3/Vivado HLS 2018.3/Jupyter Notebook


<h3>LIBRERIE UTILIZZATE IN PYTHON</h3> 
Numpy/CV2

<h3> RIGENERARE PROGETTO VIVADO(DMA) </h3>  


1.Per rigenerare il progetto MULT-CONST all'interno di DMA entra su vivado 2018.3  
2.Andare sulla" tcl console" in basso alla main page di vivado  
3.Digitare "cd" sul percorso dove si trova la cartella  
4.Appena ti trovi nella cartella, digitare "source project_2.tcl"  

<h3> RIGENERARE PROGETTO VIVADO(vdma) </h3>  


1.Per rigenerare il progetto hdmi.tcl all'interno di VDMA entra su vivado 2018.3  
2.Andare sulla" tcl console" in basso alla main page di vivado  
3.Digitare "cd" sul percorso dove si trova la cartella  
4.Appena ti trovi nella cartella, digitare "hdmi.tcl.tcl" 

<h3> JUPYTERNOTEBOOK</h3> 

Nelle cartelle bitstream si trovano i file da importare su jupyter per far funzionare multiply.ipynb e hdmi.ipynb
dove viene utilizzata la libreria cv2 per il filtering delle immagini
