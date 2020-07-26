#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int month, date,num=0;
		scanf("%d%d", &month, &date);
		if (month == 10 && date == 21)
			printf("It's today!!");
		else if (month > 10)
			printf("What a pity, it has passed!");
		else if (month == 10 && date > 21)
			printf("What a pity, it has passed!");
		else if (month == 9)
		{
			num += 30 - date + 21;
			printf("%d", num);
		}
		else
		{
			num += 30 - date + 21 + (5 - (int)month / 2) + 30 * (10 - month - 1);
			if (month <= 2)
			num -= 2;//2月份只有28天，常识呜呜呜呜
			printf("%d", num);
		}
		cout << endl;
	}
}
