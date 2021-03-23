void calcola(int a, int b,char o, int& c) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=a
#pragma HLS INTERFACE s_axilite port=b
#pragma HLS INTERFACE s_axilite port=o
#pragma HLS INTERFACE s_axilite port=c


  if (o == '+')
  {
	  c = a + b;
  }
  else if(o == '-')
  {
	  c = a - b;
  }
  else if (o == '*')
  {
	  c = a * b;
  }
  else if (o == '/')
  {
	  if (b > 0)
	  {
		  c = a / b;
	  }
	  else
	  {
		  c = 0;
	  }
  }
  else
  {
	  c = 0;
  }
}
