<h1> Processamento immagini potenziato tramite overlay creato in Vivado 2018.3  </h1>

specifica coming soon


<h3> HARDWARE UTILIZZATO </h3>  
l'implementazione di questo progetto è stata fatta sulla scheda Pynq-z2 che si basa su piattaforme Xilinx .  

Dettagli della scheda http://www.pynq.io/  http://www.pynq.io/board.html


<h3> PIATTAFORME SOFTWARE </h3>  
Vivado 2018.3/Vivado HLS 2018.3/Jupyter Notebook


<h3>LIBRERIE UTILIZZATE IN PYTHON</h3> 
Numpy/CV2

<h3> RIGENERARE PROGETTO VIVADO 2018.3 (DMA) </h3>  

1.Per rigenerare il progetto MULT-CONST all'interno di DMA entra su vivado 2018.3  
2.Andare sulla"console tcl" in basso alla main page di vivado  
3.Posizionarsi nella cartella dove è situato il file "project_2.tcl"
  tramite comandi dos (es: cd e:/folderprj)  
4.Sulla console tcl digitare: "source project_2.tcl".
5.Le cartelle "Calcola" e "Mult_Constant" contengono i progetti 
  Vivado HLS utilizzati per generare i bitstream usati negli esempi.
  Per aprire i progetti HLS fare doppio click con il mouse su i file ".app"


<h3> RIGENERARE PROGETTO VIVADO 2018.3 (vdma) </h3>  

1.Per rigenerare il progetto hdmi.tcl all'interno di VDMA entra su vivado 2018.3  
2.Andare sulla "console tcl" in basso alla main page di vivado  
3.Posizionarsi nella cartella dove è situato il file "hdmi.tcl"
  tramite comandi dos (es: cd e:/folderprj) 
4.Sulla console tcl digitare: "source hdmi.tcl" 


<h3> RIGENERARE PROGETTO VIVADO 2018.3 (ImageFilter) </h3>  

1.Per rigenerare il progetto project_7.tcl all'interno della cartella ImageFilter entrare su vivado 2018.3  
2.Andare sulla "console tcl" in basso alla main page di vivado  
3.Posizionarsi nella cartella dove è situato il file "project_7.tcl"
  tramite comandi dos (es: cd e:/folderprj)
4.Sulla console tcl digitare: "source project_7.tcl"
5.La cartella "filter2D" contiene il progetto Vivado HLS 
  utilizzato per generare i bitstream usati negli esempi.
  Per aprire i progetti HLS fare doppio click con il mouse su i file ".app"

<h3> JUPYTERNOTEBOOK</h3> 

Per gli esempi in python effettuare l'upload dei file contenuti nelle
cartelle bitstream e notebook.
