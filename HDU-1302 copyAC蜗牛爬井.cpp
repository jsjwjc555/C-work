#include<iostream>
int main()
{
	int i;
	double a, b, c, d, e, f;
	while (~scanf("%lf%lf%lf%lf", &a, &b, &c, &d))
	{
		if (!a)break;
		if (b - c >= a || b - c<0)i = 1;
		d = d / 100;
		e = b - c;
		f = b*d;
		for (i = 2;; i++)
		{
			b -= f;
			e += b;
			if (e >= a)break;
			e -= c;
			if (e<0)break;
		}
		if (e >= a)
			printf("success on day %d\n", i);
		else printf("failure on day %d\n", i);
	}
}
