#include<iostream>
#include<cmath>
#include<algorithm>//sort函数
using namespace std;
struct grade{
	int num;
	char time[1000];
	int id;//每组输入给个id 
}g[1500];
int cmp(grade a, grade b)
{
	if (a.num != b.num) return a.num>b.num;//题数不等先排序 
	else if (strcmp(a.time, b.time)<0)
	{
		return 1;
	}
	else if (strcmp(a.time, b.time) >= 0)//时间相等要返回0
	{
		return 0;
	}
}
int main()
{
	int n,i,p[1500];//定义一个数组根据id存放成绩 
	while (cin >> n&&n != -1)//注意仅n=0时循环结束，但此题n=0时循环继续 ，因此必须设定n!=-1时结束 
	{
		for (i = 0; i<n; i++)
		{
			cin >> g[i].num;
			cin >> g[i].time;
			g[i].id = i;
		}
		sort(g, g + n, cmp);
		for (i = 0; i<n; i++)
		{
			if (g[i].num == 5) p[g[i].id] = 100;
			else if (g[i].num == 0)	p[g[i].id] = 50;
			else
			{
				int s = i, e = 0;
				for (s = i; g[s].num == g[s + 1].num; s++)
					e++;
				for (s = 1; s <= (e + 1) / 2; s++)//同解题数的排名靠前半的获得分高一些
				{
					p[g[i].id] = g[i].num * 10 + 50 + 5;
					i++;
				}
				for (; s <= e + 1; s++)
				{
					p[g[i].id] = g[i].num * 10 + 50;
					i++;
				}
				i--;
			}
		}
		for (i = 0; i<n; i++)
			cout << p[i] << endl;
		printf("\n");
	}
	return 0;
}
