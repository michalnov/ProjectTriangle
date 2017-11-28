#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
	int i;
	char spz[9], j;
	
	srand(time(NULL));

	spz[0]='K';
	spz[1]='E';
	spz[2]='-';
	for(i=3;i<9;i++)
	{
		spz[i]='\0';
		if(i<6)
		{
			spz[i]=rand()%10+48;
		}
		else if(i<8)
		{
			spz[i]=rand()%26+65;
		}
	}
	printf(" %s \n", spz);
	return 0;
}
