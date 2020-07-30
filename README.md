# C-work（change
# 转入计算机专业暑假的c++作业
一点一点学习c++知识

# 1103 餐厅队列模拟
**关键字**：模拟，队列，处理HH:MM型字符方法，数组运用。

## 题目分析
在8：00至22：00会来客人，餐厅有2，4，6人桌，1-2人坐2人桌，3-4人坐4人桌以此类推。每波客人30分钟后就走，没有桌子时每波客人最多等待30分钟，Input数据如：
```
1(2人桌数) 1（4人桌数） 1（6人桌数）
10:40（客人来的时间） 1（客人数）
10:50 2
11:00 4
#（一天以＃分割）
1 1 1
10:40 1
10:50 2
11:00 2
#
```
要求写代码求每天就餐人数。
这是典型的队列问题，队列存储数据的特点是先到先走，符合实际，用到头文件<queue>的queue类和他的成员函数，解决问题比较方便。
### 处理HH:MM型字符办法
客人来的时间的格式是 11：00的字符型，=构造<sstream>的stringstream实现Str to int 函数
```c++
int strToInt(string s) 
{
    int t = 0;
    stringstream ss;
    ss << s;
    ss >> t;
    return t;
}
```
获取HH:MM的小时数乘以60再加上后面的分钟数完成时间的换算，这样后面判断客人是否离开桌子直接加30就行。
```c++
int now = 60 * strToInt(tim.substr(0, 2)) + strToInt(tim.substr(3, 2));
```
标准库的string有一个substr函数用来截取子字符串。
一般使用时传入两个参数，第一个是开始的坐标（第一个字符是0），第二个是截取的长度。

### 队列queue的成员函数
C++队列Queue类成员函数如下:

back()返回最后一个元素

empty()如果队列空则返回真

front()返回第一个元素

pop()删除第一个元素

push()在末尾加入一个元素

size()返回队列中元素的个数

**queue 的基本操作举例如下：**

* queue入队，如例：q.push(x); 将x 接到队列的末端。

* queue出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。

* 访问queue队首元素，如例：q.front()，即最早被压入队列的元素。

* 访问queue队尾元素，如例：q.back()，即最后被压入队列的元素。

* 判断queue队列空，如例：q.empty()，当队列空时，返回true。

* 访问队列中的元素个数，如例：q.size()
# 4011 北京工作路费问题
**关键字**：数组，比较，输入输出。
## 题目分析
比较简单的比较取最有，for循环加if else轻松搞定。
## 注意事项
oj题有运行时间限制，这题有很多的输入，此时c的scanf比c++的cin要快2-3倍，不然容易Time limit exceed。
## scanf的函数用法
格式字符           说明

%a           读入一个浮点值(仅C99有效) 

%A                 同上 

%c                 读入一个字符 

%d                 读入十进制整数 

%i                 读入十进制，八进制，十六进制整数 


%o                 读入八进制整数 

%x                 读入十六进制整数 

%X                 同上 

%c                 读入一个字符 

%s                 读入一个字符串 

%f                 读入一个浮点数 

%p                 读入一个指针 

%u                 读入一个无符号十进制整数 

%n                 至此已读入值的等价字符数 

%[]                扫描字符集合 

%%                 读%符号

### 实例
scanf()函数的控制串的使用
* 例1.
```c
#include "stdio.h" 
int main(void) 
{ 
int a,b,c; 
scanf("%d%d%d",&a,&b,&c); 
printf("%d,%d,%d/n",a,b,c);
return 0; 
}  
```
运行时按如下方式输入三个值：
3□4□5 ↙（输入a,b,c的值）
3，4，5 （printf输出的a，b，c的值）
   （1） &a、&b、&c中的&是地址运算符，分别获得这三个变量的内存地址。 
   
   （2） "%d%d%d"是按十进值格式输入三个数值。输入时，在两个数据之间可以用一个或多个空格、tab键、回车键分隔。
   
     >>> 以下是合法输入方式： 
     
      ① 3□□4□□□□5↙ 
      
      ② 3↙4□5↙ 
         
      ③ 3（tab键）4↙  5↙


例2.
```c
#include "stdio.h" 
int main(void) 
{ 
int a,b,c;
scanf("%d,%d,%d",&a,&b,&c); 
printf("%d,%d,%d/n",a,b,c);
return 0; 
}  
```
运行时按如下方式输入三个值：
3,4,5 ↙（输入a,b,c的值）
或者
3,□4,□5 ↙（输入a,b,c的值）
3,□□□4,□5 ↙（输入a,b,c的值） 

**都是合法的，但是","一定要跟在数字后面，如： 
3□，4,□5 ↙就非法了，程序出错。**

再如：
* 1、sacnf()中的变量必须使用地址。
       `int a, b; `
`scanf("%d%d",a,b); `//错误 
`scanf("%d%d",&a,&b);`
* 2、scanf()的格式控制串可以使用其它非空白字符，但在输入时必须输入这些字符。
例： 
`scanf("%d,%d",&a,&b); `
输入： 3，4 ↙（逗号与"%d,%d"中的逗号对应） 
`scanf("a=%d,b=%d",&a,&b); `
输入： a=3，b=4 ↙（"a=","b=",逗号与"%d,%d"中的"a=","b="及逗号对应）


* 3、在用"%c"输入时，空格和“转义字符”均作为有效字符。
例： 
`scanf("%c%c%c",&c1,&c2,&c3); `
输入：a□b□c↙ 
结果：a→c1，□→c2，b→c3 (其余被丢弃)

~~详细用法走下面这个连接~~；
[C语言scanf函数用法详细解释！](https://blog.csdn.net/linux12121/article/details/51980556?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522159494597319724835822341%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=159494597319724835822341&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v3~pc_rank_v4-2-51980556.first_rank_ecpm_v3_pc_rank_v4&utm_term=scanf)
---
# 1084与1177与1263如出一辙 答题数和时间排序给分问题
**关键字**：结构体sort()排序。
# 分析
按答题数排序，然后相同答题数的还要根据答题时间再排序，最后分数输出还需要按原来输入的顺序，这就需要序号标记，一个人有多重属性，用结构体构造再合适不过，然后用sort的高级用法再进行排序，赋值分数后输出即可。
## sort（）的用法
头文件#include   **algorithm**

Sort函数有三个参数：

（1）第一个是要排序的数组的起始地址。

（2）第二个是结束的地址（实际上是数组末尾地址的下一位）（就是第一个参数加上要排序的长度）

（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。

Sort函数使用模板:

Sort(start,end,排序方法)
 
 其默认升序排序，若需要降序排序，则需要自己写一个cmp（）函数完成降序。
 ```c++
 
bool complare(int a,int b)
{
    return a>b;
}jiegoutipai
 ```
 ### 结构体排序
 
假设自己定义了一个结构体node
```c++

struct node
{
  int a;
  int b;
  double c;
}
```
有一个node类型的数组node arr[100]，想对它进行排序：先按a值升序排列，如果a值相同，再按b值降序排列，如果b还相同，就按c降序排列。就可以写这样一个比较函数：

以下是代码片段
```c
bool cmp(node x,node y)
{
   if(x.a!=y.a) return x.a<y.a;
   if(x.b!=y.b) return x.b>y.b;
   return x.c>y.c;
}
```
本体中的cmp函数即排序代码段：
```c
int cmp(grade a,grade b)
{
    if(a.num!=b.num) return a.num>b.num;//题数不等先排序 
    else if(strcmp(a.time,b.time)<0)//完成时间的升序排序
    {
        return 1;//不交换顺序
    }
        else if(strcmp(a.time,b.time)>=0)//时间相等要返回0
    {
        return 0;//交换顺序
    }
}
---
 sort(g,g+n,cmp);//g是数组首地址，n是要排序的个数，cmp是排序函数
```
algorithm头文件常用的函数地址：
[algorithm头文件下函数整合](https://blog.csdn.net/weixin_45884316/article/details/104198196)
# 1129 明码暗码转换
**关键字**：数组，ASCII码从char转为int，scanf与string的不匹配
## 问题分析
本体思路比较简单，input是暗码string型数据，转成char数组遍历后转成暗码int数组，用题中所给算法转成明码int数组，再通过映射转成明码string然后输出。过程清晰，但是出现了例子测试输出无误，思路无误但就是WA的问题，这就是HDU不好的地方，他不给你WA的测试数据让你很难发现特例漏洞。

### 方法即所学
* 由于scanf对c++的所有类都不支持包括string,所以string的输入还是用cin把。
* char型字符简单的+0后即转成他的ASCII码值。也可以用（int）强制转换。
## 四则运算
**关键字**:switch,printf的保留小数
# 题目分析
简单的switch完成加减乘除四则运算，需要注意的是除法需要保留小数点后两位，分两种情况，一种是结果是整数直接输出，另一种是小数的情况
## printf的保留n位小数
```c++

#include<stdio.h>
 
int main()
{
	
	printf("%f\n", 100.00);//默认保留6位小数
	printf("%.0f\n", 100.00);//保留0位小数，且结果自动四舍五入
	printf("\n");
 
	printf("%f\n", 100.30);
	printf("%.0f\n", 100.30);
	printf("\n");
 
	printf("%f\n", 100.50);
	printf("%.0f\n", 100.50);
	printf("\n");
 
	printf("%f\n", 100.53);
	printf("%.1f\n", 100.53);//保留一位小数
	printf("\n");
 
	printf("%f\n", 100.55);
	printf("%.1f\n", 100.55);
	printf("\n");
 
	printf("%f\n", 100.56);
	printf("%.1f\n", 100.56);
	printf("\n");
 
	printf("%f\n", 100.563);
	printf("%.2f\n", 100.563);
	printf("\n");
 
	printf("%f\n", 100.565);
	printf("%.2f\n", 100.565);
	printf("\n");
 
	printf("%f\n", 100.566);
	printf("%.2f\n", 100.566);
	printf("\n");
	return 0;
}
```
![结果](https://img-blog.csdn.net/20170715193016143?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvYWJjZHUx/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
 
 # HDU-1262 寻找素数对
**关键字**：判断素数，EOF的意义和用法
## 分析问题
让找一个偶数的两个素数之和，还要求两素数最接近。直观思路是先写一个判断是否是素数的bool型函数，然后将所给偶数除以二分头找，找到的第一个素数用偶数减去，看另一半是否也为素数，若是则为答案，若不是则继续找。

### 方法及知识
#### 素数的寻找
对于判断一个数n是否为素数，最朴素的方法是按素数的定义，试除以从2开始到m-1的整数，如果无一例外地不能整除，则该数一定是素数。
进阶版就是不用每一个都去找，判断m是否为素数，只要试除到m的平方根就可以了，不必一直到m-1。
```c
bool sushu(int a)
{
    for (int i = 2; i <= sqrt(a); i++)
        if (a%i == 0) return 0;
    return 1;
    
}
```
#### 数据输入问题
这道题与其他大多数题的不一样的地方是他输入数据没有结束标志，这让我无从下手，查阅csdn后得知c语言的`while(scanf("%d",&n) != EOF)`可以实现这样的效果.
>在C语言中，或更精确地说成C标准函数库中表示文件结束符（end of file）。在while循环中以EOF作为文件结束标志，这种以EOF作为文件结束标志的文件，必须是文本文件。在文本文件中，数据都是以字符的ASCII代码值的形式存放。我们知道，ASCII代码值的范围是0~127，不可能出现-1，因此可以用EOF作为文件结束标志。
档案存取或其它 I/O 功能可能传回等于象征符号值 (巨集) EOF 指示档案结束的情形发生。实际上 EOF 的值通常为 -1，但它依系统有所不同。巨集 EOF会在编译原始码前展开实际值给预处理器。
C语言中，EOF常被作为文件结束的标志。还有很多文件处理函数处错误后的返回值也是EOF，因此常被用来判断调用一个函数是否成功。

原文链接：https://blog.csdn.net/henu1710252658/article/details/83040281
* 但是同时得知了c++的`while(cin>>n,n)`有一样的效果，自己在vs2013上试了试的确如此，但HDU就给c++的output limited exceeded的错误，这还真是第一次见.
# C++里面的几种cin
>做oj题有各种格式的input，这时候就需要在程序里提供获取外部数据的接口，c一般是scanf，功能比较强大，可以自定义输入的格式，长度等，c++比较僵硬，cin，cin.getline（），getline等都是常用的函数，这里总结一下他们的用法和区别。

## Cin
```c++
#include <iostream>
using namespace std;
main ()
{
int a,b;
cin>>a>>b;
cout<<a+b<<endl;
}
```
* 用法1：输入一个数字或字符
输入：`jkljkljkl`
输出：`jkljkljkl`
* 用法2：接收一个字符串，遇“空格”、“TAB”、“回车”就结束
输入：`jkljkl jkljkl  `     //遇空格结束
输出：`jkljkl`
## cin.getline()
```c++
#include <iostream>
using namespace std;
main ()
{
char m[20];
cin.getline(m,5);
cout<<m<<endl;
}
```
用法:接收一个字符串，可以接收空格并输出
输入：`jkljkljkl`
输出：`jklj`
接收5个字符到m中，其中最后一个为'\0'，所以只看到4个字符输出；
如果把5改成20：
输入：`jkljkljkl`
输出：`jkljkljkl`
>延伸：
1、cin.getline()实际上有三个参数，cin.getline(接收字符串的变量,接收字符个数,结束字符)
2、当第三个参数省略时，系统默认为'\0'
3、如果将例子中cin.getline()改为cin.getline(m,5,'a');当输入jlkjkljkl时输出jklj，输入jkaljkljkl时，输出jk
## getline()
```c++
#include<iostream>
#include<string>
using namespace std;
main ()
{
string str;
getline(cin,str);
cout<<str<<endl;
}
```
用法：接收一个字符串，可以接收空格并输出，需包含“#include<string>”
输入：`jkljkljkl`
输出：`jkljkljkl`
输入：`jkl jfksldfj jklsjfl`
输出：`jkl jfksldfj jklsjfl`

## 注意的问题
>1、cin.getline()属于istream流，而getline()属于string流，是不一样的两个函数
2、当同时使用cin>>,getline()时，需要注意的是，在cin>>输入流完成之后，getline()之前，需要通过
方法一：str="\n"; getline(cin,str);
方法二：cin.clear(); cin.sync();
的方式作为输入流cin以清除缓存，如果不这样做的话，在控制台上就不会出现getline()的输入提示，而直接跳过，因为程序默认地将之前的变量作为输入流。

---
测试：
```c++
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	string s1;
	string s2;
	cin >> s1;
	cout << "s1 is :" << s1 << endl;
	cin.clear();cin.sync();//这两个作用一致，都是清空之前cin的缓存
	getline(cin, s2);
	cout << "s2 is :" << s2 << endl;
	//system("pause");
	return 0;
}
```
**更加详细的深层次的解读：[cin、cin.get()、getline()（讲解的很详细）黄刚的博客](https://blog.csdn.net/xuexiacm/article/details/8101859?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase)
# HDU-1509优先队列
经典优先队列
[优先对联](https://blog.csdn.net/qq_42614911/article/details/98743761?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param)
