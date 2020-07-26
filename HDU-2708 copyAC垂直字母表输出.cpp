#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
#include<cstring>
#include <stdio.h>//printf
using namespace std;
using namespace std;
char a[4][80];
int main()
{
	while (gets(a[0]))
	{
		int b[26] = { 0 };
		for (int i = 1; i<4; i++)
			gets(a[i]);
		int len;
		for (int i = 0; i<4; i++)
		{
			len = strlen(a[i]);
			for (int j = 0; j<len; j++)
				if (a[i][j] >= 65 && a[i][j] <= 91)
					b[a[i][j] - 'A']++;
		}
		int m = -1, j, maxn;
		for (int i = 0; i<26; i++)
			if (m<b[i])
				m = b[i];//获取出现频率最多的字母出现次数，即要打回车的次数
		for (int i = 0; i<m; i++)
		{
			maxn = -1;
			for (int i = 0; i<26; i++)
				if (maxn <= b[i])
				{
				maxn = b[i];
				j = i;//获取频率最多字母的数组下标
				}
			int f = 0;
			for (int k = 0; k <= j; k++)
			{
				if (f)
					printf(" ");
				if (b[k] == maxn)
				{
					printf("*");
					b[k]--;
				}
				else if (b[k]<maxn)
					printf(" ");
				f = 1;//核心算法
			}
			printf("\n");
		}
		for (int k = 0; k<25; k++)
			printf("%c ", 'A' + k);
		printf("Z\n");
	}
	return 0;
}
/*是这样的图形！！！！！
                            *'\n'
                            *'\n'
        *                   *'\n'
        *                   *     *   *'\n'
        *                   *     *   *'\n'
*       *     *             *     *   *'\n'
*       *     * *     * *   *     * * *'\n'
*       *   * * *     * *   * *   * * * *'\n'
*     * * * * * *     * * * * *   * * * *     * *'\n'
* * * * * * * * * * * * * * * * * * * * * * * * * *'\n'
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z'\n
*/
