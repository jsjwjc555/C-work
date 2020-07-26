#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
#include<string>
#include <stdio.h>//printf
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n)
	{
		for (int m = 1; m <= n; m++)
		{
			if (m == 1)
			{
				for (int i = 1; i <= n; i++)//第一行
					if (i == 10)
						printf("%s%d", " ",i);
					else
						printf("%*s%d", 2, " ", i);
				printf("\n");
			}
			else if (m == n)
			{
				for (int i = 3 * n - 2; i >= 2 * n - 1; i--)
					if (i < 10)
						printf("%*s%d", 2, " ", i);
					else
						printf("%s%d", " ", i);
				printf("\n");
			}
			else
			{
				if (4 * n - 4 - m + 2 < 10)
					printf("%*s%d", 2, " ", 4 * n - 4 - m + 2);
				else
					printf("%s%d", " ", 4 * n - 4 - m + 2);
				printf("%*s", 3 * (n - 2), " ");
				if (n+m-1<10)
					printf("%*s%d", 2, " ", n + m - 1);
				else
					printf("%s%d", " ", n + m - 1);
				printf("\n");
			}
		}
		cin >> n;
	}
	return 0;
}
