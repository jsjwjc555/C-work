#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
#include<string>
#include <stdio.h>//printf
using namespace std;

int main()
{
	int k=1,l,ciphint[80],plainint[80];
	string ss;
	char ciphss[80], plainss[80];
	while (k)
	{
		scanf("%d", &k);
		cin >> ss;
		l = ss.length();
		for (int i = 0; i < l; i++)//将输入的暗码转换成char型数组暗码，方便遍历；
			ciphss[i] = ss[i];
		for (int m = 0; m < l; m++)//暗码转成暗码int数组
			switch (ciphss[m])
		{
			case '_': ciphint[m] = 0; break;
			case '.': ciphint[m] = 27; break;
			default:  ciphint[m] = ciphss[m] - 96;
		}
		for (int m = 0; m < l; m++)//暗码int变明码int数组
		{
			/*if (ciphint[m] == 27)
				plainint[k*m%l] = -1 + m;
			else
				plainint[k*m%l] = ((ciphint[m]+28)%28 + m) % 28;*/
			int pos = (k*m) % l;
			plainint[pos] = ((ciphint[m] + 28) % 28 + m) % 28;
		}
		for (int m = 0; m < l; m++)//明码int数组转明码char数组
			switch (plainint[m])
		{
			case 0: plainss[m] = '_'; break;
			case 27: plainss[m] = '.'; break;
			default: plainss[m] = (char)(plainint[m] + 96);
		}
		for (int m = 0; m < l; m++)
			cout << plainss[m];
		    cout << endl;
	}
		return 0;

}
