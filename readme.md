<h1> Processamento immagini potenziato tramite overlay creato in Vivado 2018.3  </h1>

specifica coming soon


<h3> HARDWARE UTILIZZATO </h3>  
l'implementazione di questo progetto è stata fatta sulla scheda Pynq-z2 che si basa su piattaforme Xilinx .  

Dettagli della scheda http://www.pynq.io/  http://www.pynq.io/board.html


<h3> PIATTAFORME SOFTWARE </h3>  
Vivado 2018.3/Vivado HLS 2018.3/Jupyter Notebook

<h3>STRUTTURA DEI FILE</h3> 

<h3>LIBRERIE UTILIZZATE IN PYTHON</h3> 
Numpy/CV2

<h3> RIGENERARE PROGETTO VIVADO(mult-const) </h3>  

mult-constant è un progetto base da cui partire per capire il funzionamento di Vivado e Vivado HLS.
in questo progetto vengono fusi due IP in un unico overlay e sono una piccola ALU e un sistema che utilizzando il DMA 
ci consente di caricare in memoria un vettore di numeri(o di tuple per il processamento immagini) e di riprenderlo modificato 
grazie al settaggio della costante che andra a influenzare i valori del vettore stesso  v[i]*const .

1.Per rigenerare il progetto MULT-CONST entra su vivado 2018.3  
2.Andare sulla" tcl console" in basso alla main page di vivado  
3.Digitare "cd" sul percorso dove si trova la cartella  
4.Appena ti trovi nella cartella, digitare "source project_2.tcl"  

<h3> RIGENERARE PROGETTO VIVADO(vdma) </h3>  


<h3> JUPYTERNOTEBOOK</h3> 

Nella cartella bitstream si trovano i file da importare su jupyter per far funzionare multiply.ipynb e ...
dove viene utilizzata la libreria cv2 per il filtering delle immagini
