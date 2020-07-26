#include <iostream>
#include <queue> //queue类
#include <sstream>//stringsteam类
#include <cmath>
using namespace std;

int main() 
{
    int casen, eventn, cost, salary,i,j,none,k=1;
    long long int min = 0;
    cin >> casen;        
    while (casen--)
    {   
        min = 0;
        long long int arreve[100001] = {};
        scanf("%d%d%d", &eventn, &cost, &salary);
        if (eventn == 1)
        {
            cin >> none;
            min += cost * 2 + salary;
        }
        else
        {
            for (int m = 0; m < eventn; m++)
            {
                scanf( "%d",&arreve[m]);
            }
            for (i = 0, j = 1; j < eventn; i++, j++)
            {
                if ((arreve[j] - arreve[i] - 1) * salary < 2 * cost)    //选出两者中费用较少的
                {
                    min = min + (arreve[j] - arreve[i] - 1) * salary;
                }
                else
                {
                    min = min + 2 * cost ;
                }
            }
            min = min + eventn * salary + 2 * cost;   //加上固定的花费
            
        }
        cout << "Case #" << k++ << ": " << min << endl;
        
    }
    
    return 0;
}
