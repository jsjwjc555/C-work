
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 
#define N 1005
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct Node
{
	int seq;
	double num;
}gold[N],medal[N],g_rate[N],m_rate[N];
 
bool cmp(Node a,Node b)
{
	return a.num>b.num;
}
int ranking[N][5];
int n,m;
double a[N],b[N],c[N];
int d[N];
void compute(Node x[],int k)//第k种排序方式 
{
	sort(x,x+m,cmp);//进行排序，大的在前 
	ranking[x[0].seq][k]=1;
	int cnt=2;
	for(int i=1;i<m;i++)
	{
		if(x[i].num==x[i-1].num)//如果和前面的大小相等，则排名和前面一样 
		{
			ranking[x[i].seq][k]=ranking[x[i-1].seq][k];
			
		}
		else//否则就是第cnt个数 
			ranking[x[i].seq][k]=cnt;
		cnt++;
	}
}
int main(int argc, char *argv[]) {
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&d[i]);
		}
		for(int i=0;i<m;i++)//选择出需要排序得那一部分 
		{
			gold[i].num=a[d[i]];
			gold[i].seq=d[i];
			medal[i].num=b[d[i]];
			medal[i].seq=d[i];
			g_rate[i].num=a[d[i]]/c[d[i]];
			g_rate[i].seq=d[i];
			m_rate[i].num=b[d[i]]/c[d[i]];
			m_rate[i].seq=d[i];
		}
		/*for(int i=0;i<m;i++)
		{
			printf("%lf,%lf,%lf,%lf\n",gold[i].num,medal[i].num,g_rate[i].num,m_rate[i].num);
		}*/
		memset(ranking,0,sizeof(ranking));
		compute(gold,1);//根据题目的意思，不同的排序方式 
		compute(medal,2);
		compute(g_rate,3);
		compute(m_rate,4);
		for(int i=0;i<m;i++)
		{
			int min=N,pos=1;
			for(int j=1;j<=4;j++)//找出四种排序方式中，排名最靠前的那种方式 
			{
				if(ranking[d[i]][j]<min)
				{
					min=ranking[d[i]][j];
					pos=j;
				}
			}
			printf("%d:%d\n",min,pos);
		}
		printf("\n");
	}
	return 0;
}

————————————————
版权声明：本文为CSDN博主「爱篮球爱IT」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/huanhuanxiaoxiao/article/details/63686009
