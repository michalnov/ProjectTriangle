#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//void reverse(int arr[D]);

#define D 30

int main()
{
	srand(time(NULL));
	int arr[D], a=0, i=0, even=0, i2digit=0, i3digit=0, pa=0, pal[D], dev7=0, min=0, max=0;
	for(a = 0; a < D; a++){
		arr[a]=rand()%9990+10;
		printf("%d ", arr[a]);
		if(arr[a] % 7 == 0)
		{
			dev7++;			
		}
		if(a == 0)
		{
			min = arr[a];
			max = arr[a];
		}
		if(arr[a]%2 ==0)
		{
			even++;
		}
		if(arr[a] < 100)
		{
			i2digit++;
			if(arr[a]%10 == arr[a]/10)
			{
				pal[pa]=arr[a];
				pa++;
			}
		}
		else if(arr[a] < 1000)
		{
			i3digit++;
			if(arr[a]%10 == arr[a]/100)
			{
				pal[pa]=arr[a];
				pa++;
			}
		}
		else{
			if(arr[a]%10 == arr[a]/1000 && (arr[a]%10)/10 == (arr[a]%10)/100)
			{
				pal[pa]=arr[a];
				pa++;
			}
		}
		if(arr[a] < min || arr[a] > max)
		{
			if(arr[a] < min)
			{
				min = arr[a];
			}
			else
			{
				max = arr[a];
			}
		}
	}
	printf("\n %d numbers are even.\n", even);
	printf(" %d numbers are odd.\n", D - even);
	printf(" there is %d 2 digits, %d 3 digits and %d 4 digits numbers.\n", i2digit, i3digit, (D - (i2digit + i3digit)));
	printf(" %d is maximum.\n", max);
	printf(" %d is min.\n", min);
	printf("\nReverse of array:\n");
	for(a = D-1; a >= 0; a--)
	{
		printf("%d ", arr[a]);
	}
	printf("\nPalindromes are: \n");
	for(a = 0; a < pa; a++)
	{
		printf("%d , ", pal[a]);
	}
	printf("\n %d numbers can be devined by 7 without residuum\n", dev7);
	
}
