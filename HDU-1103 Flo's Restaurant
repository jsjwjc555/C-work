
#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>

using namespace std;

const int maxn = 4;

int strToInt(string s) 
{
	int t = 0;
	stringstream ss;
	ss << s;
	ss >> t;
	return t;
}

int main() 
{

	int A[maxn];
	cin >> A[1] >> A[2] >> A[3];
	while (A[1] || A[2] || A[3]) 
	{
		int ans = 0;
		queue<int> q[maxn];
		string tim;
		cin >> tim;
		while (tim.compare("#")) 
		{
			int now = 60 * strToInt(tim.substr(0, 2)) + strToInt(tim.substr(3, 2));
			int num;
			cin >> num;
			int index = ceil(num / 2.0);
			if (q[index].size()<A[index]) 
			{
				ans += num;
				q[index].push(now + 30);
			}
			else 
			{
				int top = q[index].front();
				if (now >= top) 
				{
					q[index].pop();
					q[index].push(now + 30);
					ans += num;
				}
				else if (now + 30 >= top)
				{
					q[index].pop();
					q[index].push(top + 30);
					ans += num;
				}
			}
			cin >> tim;
		}
		cout << ans << endl;
		cin >> A[1] >> A[2] >> A[3];
	}
	return 0;
}
