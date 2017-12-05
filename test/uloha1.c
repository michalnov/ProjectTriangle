#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

 typedef struct{
 	int a = 0;
 	int b = 0;
 } cisla;

int main(int argc, char const *argv[]) {
  FILE *fr_data, *fw_output, *f_swap;
  fr_data = fopen("numbers" , "r");
  fw_output = fopen("result" , "w");
  int count = 0;
  vhile(1)
  {
  	
  }
  int a = 0, b = 0, o = 0, s = 0, help = 0;
  char c_swap[19];
  
  while(fscanf(fr_data, "%s", c_swap) != EOF){
  	if(atoi(c_swap) >= 0)
  		{
		  	if(help == 0)
		  	{
		  		a = atoi(c_swap);
		  		help++;
		  	}
		  	else
		  	{
		  		b = atoi(c_swap);
		  		o = 2*a+2*b;
		  		s = a*b;
		  		printf(" %d %d %d %d \n", a, b, o, s);
		  		fprintf(fw_output,"a = %d b = %d o = %d s = %d \n", a, b, o, s);
		  		help = 0;
		  	}
	  	}
	  else
	  {}
	  }
	return 0;
  }
