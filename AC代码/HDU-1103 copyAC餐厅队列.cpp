
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

	int A[maxn];//获取三种桌子的个数
	cin >> A[1] >> A[2] >> A[3];
	while (A[1] || A[2] || A[3]) 
	{
		int ans = 0;
		queue<int> q[maxn];//创建队列，这里q【0】不用，方便理解。
		string tim;
		cin >> tim;
		while (tim.compare("#")) //#作为一天的分割
		{
			int now = 60 * strToInt(tim.substr(0, 2)) + strToInt(tim.substr(3, 2));
			int num;
			cin >> num;
			int index = ceil(num / 2.0);//小数向上取整
			if (q[index].size()<A[index]) //有桌子没做过人直接安排入座
			{
				ans += num;
				q[index].push(now + 30);
			}
			else // 所有桌子都坐过人
			{
				int top = q[index].front();
				if (now >= top) //现在的时间比最先来的一桌人的时间晚大于30分钟，即这一桌人已经走了，可以安排入座
				{
					q[index].pop();
					q[index].push(now + 30);
					ans += num;
				}
				else if (now + 30 >= top)//如果来的人可以最多等30分钟，等到队首的人离开，可以入坐
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
