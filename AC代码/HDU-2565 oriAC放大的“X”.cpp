#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
#include<string>
#include <stdio.h>//printf
using namespace std;
int main()
{
	int m,n=1;
	cin >> m;
	for (int i = 0; i < m;i++)
	{  
		cin >> n;
			for (int i = 1; i <= n; i++)
				if (i < (n - 1) / 2 + 1)
				{
				printf("%*s%*s", i, "X", n - 2 * i + 1, "X");
				printf("\n");
				}
				else if (i == (n - 1) / 2 + 1)
				{
					printf("%*s", (n - 1) / 2 + 1, "X");
					printf("\n");
				}
				else
				{
					printf("%*s%*s", n - i + 1, "X", 2 * (i - (n - 1) / 2 - 1), "X");
					printf("\n");
				}

			printf("\n");
	}
	return 0;
}
