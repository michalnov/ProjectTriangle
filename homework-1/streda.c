/*
	Author: Michal Novotny
	Date:	11.10.2017
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int IsTriangle(double a, double b, double c);
//int IsRectangular(double a, double b, double c);
int Zodiac(int a, int b);
int task1();
int task2();
int task3();
void HelpMenu(void);
void HelpMenuTerminal(void);

int main(int argc, char const *argv[])
{
	
	int mode = 1;
	char task[10] = {0,0,0,0,0,0,0,0,0,0};

	if (argc == 1)
	{
		do
		{
			HelpMenu();
			printf("Select task: \n");
			scanf("%s", &task[0]);
			if (strcmp(task, "repeat") == 0 )
			{
				mode = 0;
			}
			else if (strcmp(task, "exit") == 0 || strcmp(task, "0") == 0)
			{
				mode = 1;
				return 0;
			}
			else if (strcmp(task, "task1") == 0 || strcmp(task, "triangle") == 0 || strcmp(task, "t") == 0)
			{	
				task1();
			}
			else if (strcmp(task, "task2") == 0 || strcmp(task, "rectangular") == 0 || strcmp(task, "r") == 0)
			{
				task2();
			}
			else if (strcmp(task, "task3") == 0 || strcmp(task, "sign") == 0 || strcmp(task, "s") == 0)
			{
				task3();
			}
		} while (mode==0);
	}
	else if (argc == 2)    //Pri spusteni v Terminale s parametrom
	{
		if (strcmp(argv[1],"-1")==0 || strcmp(argv[1],"-t")==0)
		{	
			task1();
		}
		else if (strcmp(argv[1],"-2")==0 || strcmp(argv[1],"-r")==0)
		{
			task2();
		}
		else if (strcmp(argv[1],"-3") == 0 || strcmp(argv[1],"-s")==0)
		{
			task3();
		}		
	}
	else
	{
		HelpMenuTerminal();
	}
	return 0;
}									               	// END of main

int task1(){						//Vstup pre funkciu IsTriangle (Overenie ci moze byt trojuholnik zostrojeny)
	double a=0, b=0, c=0;
	printf("Please enter the sides of triangle\n");
	printf("side a = ");
	scanf("%lf", &a);
	printf("\nside b = ");
	scanf("%lf", &b);
	printf("\nside c = ");
	scanf("%lf", &c);
	printf("\n");
	IsTriangle(a, b, c);
}

int task2(){						//Overenie ci zo zadanych vstupov moze byt zostrojeny trojuholnik
	int a=0, b=0, c=0;				// ak ano tak overujem ci je mozne zostrojit pravouhly trojuholnik
	printf("Please enter the sides of triangle\n");
	printf("side a = ");
	scanf("%d", &a);
	printf("\nside b = ");
	scanf("%d", &b);
	printf("\nside c = ");
	scanf("%d", &c);
	printf("\n");
	if (IsTriangle(a, b, c) == 0)
	{
		if (a*a+b*b == c*c || a*a+c*c == b*b || c*c+b*b == a*a)
		{
			printf("Right-angled triange CAN be constructed\n");
		}
		else
		{
			printf("Right-angled triangle CANOT be constructed\n");
		}
	}
	else
	{
		printf("Right-angled triangle CANOT be constructed\n"); 
	}
}

int task3(){					//Vstup pre funkciu Zodiac ktora zistuje v znamenie v zverokruhu
	int dd = 0, mm = 0;			// pre zadany den a mesiac
	printf("Please enter the day:\n");
	scanf("%d", &dd);
	printf("please enter the month\n");
	scanf("%d", &mm);
	printf("\n");
	Zodiac(dd, mm);
}

int Zodiac(int dd, int mm){
	if (dd < 1 || dd > 31 || mm < 1 || mm > 12)
	{
		printf("Wrong input\n");
		return 0;
	}
	switch(mm){
		case 1:
			if (dd < 20)
			{
				printf(" Capricorn\n");
			}
			else{
				printf(" Aquarius\n");
			}
         	break;

         case 2:
         if (dd > 29)
         {
         	printf("Wrong input\n");
         	return 0; 
         }
			if (dd < 19)
			{
				printf(" Aquarius\n");
			}
			else{
				printf(" Pisces\n");
			}
         	break;

         case 3:
			if (dd < 21)
			{
				printf(" Pisces\n");
			}
			else{
				printf(" Aries\n");
			}
         	break;

         case 4:
         	if (dd > 30)
         	{
         	printf("Wrong input\n");
         	return 0; 
         	}
			if (dd < 20)
			{
				printf(" Aries\n");
			}
			else{
				printf(" Taurus\n");
			}
         	break;
         case 5:
			if (dd < 21)
			{
				printf(" Taurus\n");
			}
			else{
				printf(" Gemini\n");
			}
         	break;

         case 6:
			if (dd < 21)
			{
				printf(" Gemini\n");
			}
			else{
				printf(" Cancer\n");
			}
         	break;

         case 7:
         	if (dd > 30)
         	{
         	printf("Wrong input\n");
         	return 0; 
         	}
			if (dd < 23)
			{
				printf(" Cancer\n");
			}
			else{
				printf(" Leo\n");
			}
         	break;

         case 8:
			if (dd < 23)
			{
				printf(" Leo\n");
			}
			else{
				printf(" Virgo\n");
			}
         	break;

         case 9:
           	if (dd > 30)
         	{
         	printf("Wrong input\n");
         	return 0; 
         	}
			if (dd < 23)
			{
				printf(" Virgo\n");
			}
			else{
				printf(" Libra\n");
			}
         	break;

         case 10:
			if (dd < 23)
			{
				printf(" Libra\n");
			}
			else{
				printf(" Scorpio\n");
			}
         	break;

         case 11:
         	if (dd > 30)
         	{
         	printf("Wrong input\n");
         	return 0; 
         	}
			if (dd < 22)
			{
				printf(" Scorpio\n");
			}
			else{
				printf(" Sagittarius\n");
			}
         	break;

         case 12:
			if (dd < 22)
			{
				printf(" Sagittarius\n");
			}
			else{
				printf(" Capricorn\n");
			}
         	break;
	}

}

int IsTriangle(double a, double b, double c){		//test if it is possible to create triangle from entered coordinates
	if (a<=0 || b<=0 || c<=0)
	{
		printf("Wrong input\n");
		return 0;
	}
	if (a+b>c && a+c>b && b+c>a)
	{
		printf("It is possible to construct the triangle\n");
		return 0;
	}
	else
		printf("You can not construct the triangle with this input\n");
	return 1;
}

void HelpMenu(){
	system("clear");
	//printf("This help message is show nebacuse you probably choose wrong mode\n \nMode selection:\n");
	printf("Arguments selection:\n");
	printf("triangle 	 or t    - Mode for test if it is possible to create triangle\n");
	printf("rectangular 	 or r    - Mode for test if it is possible to create right-angled triangle\n");
	printf("signs 		 or s    - Mode for resolve zodiac sign from inserted date\n");
	printf("repeat 			     - repeat till exit command\n");
	printf("exit   		 or 0    - exit program if you are in repeat mode\n");
}


void HelpMenuTerminal(){		//vstup pre terminal s parametrom aj s hodnotami nieje dokončený
	system("clear");
	printf("This help message is show nebacuse you probably choose wrong mode\n");
	printf("\nArguments selection:\n");
	printf("-t   or -1      - Mode for test if it is possible to create triangle\n");
	//printf("Usage:     -1 a b c\n");
	//printf("             a, b, c, replace with numbers wich represent sides of triangle\n\n");

	printf("-r   or -2      - Mode for test if it is possible to create right-angled triangle\n");
	//printf("Usage:     -2 a b c\n");
	//printf("             a, b, c, replace with numbers wich represent sides of triangle\n\n");

	printf("-s   or -3      - Mode for find zodiac sing acording date\n");
	//printf("Usage:     -3 DD MM\n");
	//printf("              DD replace with number of day\n");
	//printf("              MM replace with number of month\n\n");
	printf("-h    - print this help message\n");
}

