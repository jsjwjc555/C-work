#include<stdio.h>
int main()
{
    int n,a,b;
    char s[2];
    scanf("%d",&n);
    while(n--){
        scanf("%s %d %d",s,&a,&b);
        if(s[0]=='+')printf("%d\n",a+b);
        else if(s[0]=='-')printf("%d\n",a-b);
        else if(s[0]=='*')printf("%d\n",a*b);
        else if(s[0]=='/' && a/b*b==a)printf("%d\n",a/b);
        else printf("%.2lf\n",(double)a/b);
    }
    return 0;
 } 
