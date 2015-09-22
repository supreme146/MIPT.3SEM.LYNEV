#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
	char[60] x;
	int y;
	int y1 = 0;
	int i; 
	scanf("%s", x);
	
	int j = 0; //identificator
	for (i = 0; i < 60; i++)
	{
		if ( x[i] 
	if ( (x == 45) || ( 47 < x && x < 58))
	{  
		if ( x == 45 ) 
		{
			y = 1;
		}
		else
		{
			y = -1;
		}
		while ( (x != 10) || ( 47 < x && x < 58))
			{
				x = x - 48;
				y1 = y1*10 + x;
			} 
		
	if ( x > 1 ) 
	{
		for ( i = 1; i < (x+1); i++)
		{
			printf("%d\n", i);
		}
	}
	else
	{
		for ( i = 1; (x-1) < i; i--)
		{
			printf("%d\n", i);
		}
	}
	return 0;
} 
