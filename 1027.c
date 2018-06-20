/*
时间：2018/6/20 19点56分
作者：楼浩然
题目：
1027 打印沙漏(20)（20 分）
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例：

19 *
输出样例：

*****
 ***
  *
 ***
*****
2
*/

#include <stdio.h>

int length(int N, int * n);  //求出第一行的数目
void Paint(int M ,char ch);  //M代表第一行的符号数，该函数用于画漏斗

int main(void)
{
    int N,n; //N代表给的符号数；n代表剩下的符号数
    char ch; //漏斗使用的符号
    scanf("%d %c",&N,&ch);
    int max_length;  //漏斗中行中符号最多的数目
    max_length = length(N,&n);
    Paint(max_length,ch);
    printf("%d\n",n);
    return 0;
}

int length(int N, int * n)
{
    if(N==1)
    {
        *n = 0;
        return 1;
    }
    int max_length;
    int sum = -1; //漏斗中的符号数
    for(max_length = 1 ; sum < N ; max_length += 2)
    {
        sum+=max_length*2;
    }

    sum -= (max_length-2)*2;
    *n = N - sum;        //剩下的符号数
    max_length -=4;
    return max_length;
}

void Paint(int M,char ch)
{
    int i,j,z; //用于循环计数
    for (i=M ; i>=1 ; i-=2)
    {
        for(j=0;j<(M-i)/2;j++)putchar(' ');
        for(z=0;z<i;z++)putchar(ch);
        putchar('\n');
    }
    for (i=3 ; i<=M ; i+=2)
    {
        for(j=0;j<(M-i)/2;j++)putchar(' ');
        for(z=0;z<i;z++)putchar(ch);
        putchar('\n');
    }
}
