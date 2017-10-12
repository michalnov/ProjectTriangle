/*
	Author: Michal Novotny
	Date:	11.10.2017
*/


/*
Uloha1:
vstup: cisla a,b,c - strany trojuholnika
vystup: ano / nie
program zisti ci trojuholnik so stranami a,b,c sa da zostrojit
Vid trojuholnikova nerovnost - sucet lub. 2 stran v trojuholniku > tretia strana
Uloha2:
vstup: cisla a,b,c - strany trojuholnika
vystup: ano / nie
program zisti ci trojuholnik so stranami a,b,c je pravouhly
Vid pytagorova veta - nevieme ktora strana moze byt prepona,treba zistit
Uloha3:
vstup: den, mesiac
vystup: znamenie vo zverokruhu (slovom)
uzivate zada 2 cisla, den a mesiac. Program overi ci dany den a mesiac existuje
(kedze nezadavame rok, beriem do uvahy ze 29.2. existuje vzdy)
Ak su vstupy spravne zisti a vypise znamenie zverokruhu na dany den
Vid: kalendar
Odporucam precvicit prikazy switch a v nom prikaz if
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
	char task[7] = {0,0,0,0,0,0,0};

	if (argc == 1)
	{
		do
		{
			printf("Select task: \n");
			scanf("%s", &task[0]);
			if (strcmp(task, "repeat") == 0 || strcmp(task, "r") == 0)
			{
				mode = 0;
			}
			else if (strcmp(task, "exit") == 0 || strcmp(task, "0") == 0)
			{
				mode = 1;
				return 0;
			}
			else if (strcmp(task, "task1") == 0 || strcmp(task, "task 1") == 0 || strcmp(task, "1") == 0)
			{	
				task1();
			}
			else if (strcmp(task, "task2") == 0 || strcmp(task, "task 2") == 0 || strcmp(task, "2") == 0)
			{
				task2();
			}
			else if (strcmp(task, "task3") == 0 || strcmp(task, "task 3") == 0 || strcmp(task, "3") == 0)
			{
				task3();
			}
		} while (mode==0);
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1],"-1")==0)
		{	
			task1();
		}
		else if (strcmp(argv[1],"-2")==0)
		{
			task2();
		}
		else if (strcmp(argv[1],"-3") == 0)
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

int task1(){
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

int task2(){
	int a=0, b=0, c=0;
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
		if (a*a+b*b== c*c || a*a+c*c== b*b || c*c+b*b ==a*a)
		{
			printf("Right-angled triange CAN be constructed\n");
		}
	}
	else
	{
		printf("Right-angled triangle CANOT be constructed\n"); 
	}
}

int task3(){
	int dd = 0, mm = 0;
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
		return 1;
	}
	else
		printf("You can not construct the triangle with this input\n");
	return 0;
}

void HelpMenu(){
	system("clear");
	printf("This help message is show nebacuse you probably choose wrong mode\n \nMode selection:\n");
	printf("task1  or 1    - Mode for test if it is possible to create triangle\n");
	printf("task2  or 2    - Mode for test if it is possible to create right-angled triangle\n");
	printf("task3  or 3    - Mode for resolve zodiac sign from inserted date\n");
	printf("repeat or r    - repeat till exit command\n");
	printf("exit   or 0    - exit program if you are in repeat mode\n");
}


void HelpMenuTerminal(){
	system("clear");
	printf("This help message is show nebacuse you probably choose wrong mode\n \nArguments selection:\n");
	printf("-1         - Mode for test if it is possible to create triangle\n");
	//printf("Usage:     -1 a b c\n");
	//printf("             a, b, c, replace with numbers wich represent sides of triangle\n\n");

	printf("-2         - Mode for test if it is possible to create right-angled triangle\n");
	//printf("Usage:     -2 a b c\n");
	//printf("             a, b, c, replace with numbers wich represent sides of triangle\n\n");

	printf("-3         - Mode for find zodiac sing acording date\n");
	//printf("Usage:     -3 DD MM\n");
	//printf("              DD replace with number of day\n");
	//printf("              MM replace with number of month\n\n");
	printf("-h    - print this help message\n");
}

