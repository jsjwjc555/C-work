#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n, t, bing[7000] = {}, loc,weizhi = 0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &t);
		for (int i = 1; i <= t; i++)
			bing[i] = i;
		int tag=1;
		weizhi = t;
		do
		{
			if (t <= 3)
			{
				weizhi = t; break;
			}
		  else if (tag % 2 == 1)
			{
				loc = 1;
				for (int i = 1; i <= weizhi; i++)
					if (i % 2 != 0)
					{
					bing[loc] = bing[i];
					loc++;
					}
				weizhi = loc - 1;
				tag++;
			}
			else 
			{
				loc = 1;
				for (int i = 1; i <= weizhi; i++)
					if (i % 3 != 0)
					{
					 bing[loc] = bing[i];
					 loc++;
					}
				weizhi = loc - 1;
				tag++;
			}
		} while (weizhi >3);
		{
			for (int i = 1; i <= weizhi; i++)
			{
				if (i == weizhi)
					cout << bing[i];
				else
					cout << bing[i] << ' ';
			}
		}
			cout << endl;
	}
	return 0;
}
