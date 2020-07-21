#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
#include <stdio.h>//printf
using namespace std;
int n, size , w;
int na[9] = {};
void rall(int a)
{
	printf("%c",' ');
	for (int i = 0; i < a; i++)
		printf("%c", '-');
	printf("%c", ' ');
}
void rnone(int a)
{
	printf("%*s", a+2, " ");
}
void cleft(int a)
{
	printf("%*s%*s", 1, "|", a+1, " ");
}
void cright(int a)
{
	printf("%*s", a+2,"|");
}
void call(int a)
{
	printf("%*s%*s", 1, "|", a+1, "|");
}void array(int a,int b)
{   
	for (int i = 0; i < b;i++)
	{
		na[b - i - 1] = a % 10;
		a /= 10;
	}
}

int main()
{
	while (1)
	{
		scanf("%d%d", &size,&n);
		if (size == 0 && n == 0)
			break;
		else
		{
			 w = (int)ceil(log10(n));
			array(n, w);
			for (int m = 0; m < w; m++)//第一行
			{
				switch (na[m])
				{
				case 1:case 4:
					rnone(size); break;
				default:
					rall(size);
				}
				if (m!=w-1)
					printf("%c", ' ');
			}
			printf("\n");
			for (int i = 0; i < size; i++)//w行
			{
				for (int m = 0; m < w; m++)
				{
					switch (na[m])
					{
					case 1:case 2:case 3:case 7:
						cright(size); break;
					case 5:case 6:
						cleft(size); break;
					default:
						call(size);
					}
					if (m != w - 1)
						printf("%c", ' ');
				}
				printf("\n");
			}
		   for (int m = 0; m < w; m++)//第2+w行
		   {
			   switch (na[m])
			   {
			   case 1: case 7:case 0:
				   rnone(size); break;
			   default:
				   rall(size); break;
			   }
			   if (m != w - 1)
				   printf("%c", ' ');
		   }
		   printf("\n");
		   for (int i = 0; i < size; i++)//w行
		   {
			   for (int m = 0; m < w; m++)
			   {
				   switch (na[m])
				   {
				   case 2:
					   cleft(size); break;
				   case 6: case 8: case 0:
					   call(size); break;
				   default:
					   cright(size);
				   }
				   if (m != w - 1)
					   printf("%c", ' ');
			   }
			   printf("\n");
		   }
		   for (int m = 0; m < w; m++)//第2w+3行
		   {
			   switch (na[m])
			   {
			   case 1:case 4:case 7:
				   rnone(size); break;
			   default:
				   rall(size);
			   }
			   if (m != w - 1)
				   printf("%c", ' ');
		   }
		   printf("\n\n");
		}
	}
	return 0;
}
