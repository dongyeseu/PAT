/*
时间：2018/6/21 17点30分
作者：楼浩然
题目：
一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N~1~/M~1~ 和 N~2~/M~2~，要求你按从小到大的顺序列出它们之间分母为K的最简分数。

输入格式：

输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。题目保证给出的所有整数都不超过1000。

输出格式：

在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，按从小到大的顺序，其间以1个空格分隔。行首尾不得有多余空格。题目保证至少有1个输出。

输入样例：

7/18 13/20 12
输出样例：

5/12 7/12
*/
#include <stdio.h>

int IsCoprime(int m, int n)   //判断两个数互质的方法  辗转相除法
{
    int i;
    while(1)
    {
        i = m%n;
        if(i==0)
            break;
        else
        {
            m = n;
            n = i;
        }
    }
    if(n==1)
        return 1;
    else
        return 0;
}
int main(void)
{
    int M1,M2,N1,N2,K2;
    scanf("%d/%d %d/%d %d",&M1,&M2,&N1,&N2,&K2);
    double l1,l2;
    l1 = M1*1./M2;
    l2 = N1*1./N2;
    int len = M1/M2 > N1/N2 ? M1/M2+1 : N1/N2+1;
    int i;  //循环计数
    int j = 0;//输出计数
    for(i=1 ; i<len*K2 ; i++)
    {
        double res = i*1./K2;
        if((res>l1 && res<l2) || (res<l1 && res >l2))
        {
            if(IsCoprime(i,K2))
            {
                j++;
                if(j!=1)
                    printf(" %d/%d",i,K2);
                else
                    printf("%d/%d",i,K2);
            }
            else
                continue;
        }
    }
    return 0;
}
