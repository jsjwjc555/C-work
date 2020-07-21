#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
using namespace std;

int main()
{
	int casen, eventn, cost, salary, ftag, btag, fbtag, min = 0, none;
	cin >> casen;
	int arreve[100001] = {};
	for (int i = 0; i != casen; i++)
	{
		scanf_s("%d%d%d", &eventn, &cost, &salary);
		arreve[eventn + 1] = 0;
		if (eventn == 1)
		{
			cin >> none;
			min += cost * 2 + salary;
		}
		else
		{
			ftag = 2;
			btag = 1;
			fbtag = btag;
			for (int n = 1; n != eventn + 1; n++)
				scanf_s("%d", &arreve[n]);
			while (ftag != eventn + 2)
			{
				if (arreve[ftag] == 0)
				{
					ftag--;
					min += (arreve[ftag] - arreve[btag] + 1)*salary + 2 * cost;
					ftag += 2;
				}
				else if ((arreve[ftag] - arreve[fbtag] - 1)*salary <= (2 * cost))
				{
					ftag++;
					fbtag++;
				}
				else
				{
					ftag--;
					min += (arreve[ftag] - arreve[btag] + 1)*salary + 2 * cost;
					btag = ftag + 1;
					ftag = btag + 1;
					fbtag = btag;
				}
			}

		}
		cout << "Case #" << i + 1 << ": " << min << '\n';
		min = 0;
	}

	return 0;
}
