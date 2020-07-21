#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
using namespace std;
bool sushu(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
		if (a%i == 0) return 0;
	return 1;
	
}
int main()
{
	int n,tag,t;
	while (scanf("%d", &n) != EOF)
	{
		tag = n / 2;
		t = n / 2;
		for (int i = 0; i < n; i++)
		{
			if (sushu(tag) && sushu(n - tag))
			{
				cout << tag << ' ' << n - tag << endl;
				break;
			}tag--;
		}
	}
	return 0;
}
