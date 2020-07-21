#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
using namespace std;
void rall(int k, char a,int down)
{
    printf("%*c", k+1, a);
    for (int i = 0; i < down-1; i++)
    printf("%c", a);
    cout << endl;
}
void call(int k, char a,int down)
{
    for (int i = 0; i < k;i++)
     printf("%c", a);
    printf("%*s", down, " ");
    for (int i = 0; i < k; i++)
     printf("%c", a);

    cout << endl;
}
int main()
{
    int n, r[100],k,up,down;
    char a[100] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> r[i];
    for (int i = 0; i < n; i++)
    {
        if ((int)(r[i] - 3) % 2 == 0)
        {
            up = (r[i] - 3) / 2;
            down = (r[i] - 3) / 2;
        }
        else
        {
            up = (int)round((r[i] - 3) / 2);
            down = (r[i] - 3) / 2+1;
        }
        k = r[i]/6+1;
        if (i != 0)
            cout << endl;
        rall(k, a[i],down);
        for (int m = 0; m< up;m++)
                call(k, a[i],down);
        rall(k, a[i],down);
        for (int m = 0; m < down; m++)
                call(k,a[i],down);
        rall(k, a[i],down);
        
    }
    return 0;
}
