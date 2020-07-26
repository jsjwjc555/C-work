*Hint：
char *strchr(const char *string, int c);  
查找字符串string中首次出现的位置, NULL结束符也包含在查找中.  
返回一个指针, 指向字符c在字符串string中首次出现的位置, 如果没有找到, 则返回NULL.*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[1000000],b[1000000];
    int i,len1,len2;
    while(scanf("%s%s",a,b)!=EOF)
    {
        len1=strlen(a);
        len2=strlen(b);
        if(strchr(a,'.')!=NULL)
        {
            for(i=len1-1;a[i]=='0';i--)
                a[i]='\0';
            if(a[i]=='.')
               a[i]='\0';
        }
        if(strchr(b,'.')!=NULL)
        {
            for(i=len2-1;b[i]=='0';i--)
                b[i]='\0';
            if(b[i]=='.')
               b[i]='\0';
        }
        if(strcmp(a,b)==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
————————————————
版权声明：本文为CSDN博主「Dmenghu」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Dmenghu/article/details/82192629
