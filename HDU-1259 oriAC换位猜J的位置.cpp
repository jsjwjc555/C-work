#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
using namespace std;

int main()
{
	int t, n, loc[2002] = {}, fin[1002] = {},j=2;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int l = 1; l < 2 * n + 1; l++)
			cin >> loc[l];
		for (int m = 1; m < n + 1; m++)
		{
			if (loc[2 * m - 1] == j)
				j = loc[2 * m];
			else if (loc[2 * m] == j)
				j = loc[2 * m - 1];
		}
		fin[i] = j;
		j = 2;
	}
	for (int p = 0; p < t; p++)
		cout << fin[p] << endl;
	return 0;
}
