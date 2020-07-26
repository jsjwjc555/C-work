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
	string ss;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ss;
		int ascii;
		ss += 'A';//在末尾加上A作为循环结束符号
		for (int i = 0; ss[i] != 'A'; i++)
		{
			if (ss[i] == '#')
				printf(" ");
			else if (ss[i] == '-')
				continue;
			else if (ss[i] + 0 > 47 && ss[i + 1] + 0 > 47 && ss[i + 1] != 65)//防止最后一个数字为各位导致程序中断
			{
				printf("%c", (char)((ss[i] - 48) * 10 + ss[i + 1] - 48) + 64);
				i++;
			}
			else if (ss[i + 1] == 65)
				printf("%c", (char)(ss[i] + 16));
			else if (ss[i] + 0 > 47 && ss[i + 1] + 0 < 47)
				printf("%c", (char)(ss[i] + 16));
		}
			cout << endl;
	}
	return 0;


}
