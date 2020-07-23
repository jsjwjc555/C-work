#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct aa
{
	char c1[81], c2[81];
	int n;
}a[115];
bool camp(aa x, aa y)//c2水果，c1产地
{
	if (strcmp(x.c1, y.c1) != 0)
		return  strcmp(x.c1, y.c1)<0;
	return  strcmp(x.c2, y.c2)<0;
}
int main()
{
	int i, t, n, sum;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		   //getchar();
		for (i = 1; i <= n; i++)
			scanf("%s %s %d", a[i].c2, a[i].c1, &a[i].n);
		sort(a + 1, a + n + 1, camp);
		sum = a[1].n;
		for (i = 1; i <= n; i++)
		{
			if (strcmp(a[i].c1, a[i - 1].c1) != 0)
			{
				printf("%s\n", a[i].c1);
			}
			if (strcmp(a[i].c1, a[i + 1].c1) == 0 && strcmp(a[i].c2, a[i + 1].c2) == 0)
			{
				sum += a[i + 1].n;
			}
			else
			{
				printf("   |----%s(%d)\n", a[i].c2, sum);
				sum = a[i + 1].n;
			}
		}
		if (t)
			printf("\n");
	}
	return 0;
}
