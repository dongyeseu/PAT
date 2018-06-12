/*
时间：2018/6/12 08点46分
作者：楼浩然
题目：
1007 素数对猜想 (20)（20 分）
让我们定义 d~n~ 为：d~n~ = p~n+1~ - p~n~，其中 p~i~ 是第i个素数。显然有 d~1~=1 且对于n&gt1有 d~n~ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N (< 10^5^)，请计算不超过N的满足猜想的素数对的个数。
输入格式：每个测试输入包含1个测试用例，给出正整数N。
输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
输入样例：
20
输出样例：
4
*/

#include <stdio.h>
#include <math.h>

int prime_num(int * p,int n);
int prime_pair(int * p,int s);
int main(void)
{
    int num;
    int i;
    int pairs;
    scanf("%d",&num);
    int prime[num];
    i = prime_num(prime,num);
    pairs = prime_pair(prime,i);
    printf("%d",pairs);
    return 0;

}
int Is_prime(int z)     //判断是否为素数
{
    int j;
    int itm;
    if (z<2)
        return 0;
    else if (z == 2)
        return 1;
    else if (z > 2)
    {   itm = (int)sqrt(z)+2;
        for (j=2;j<itm;j++)
        {
            if ((z%j)==0)
                return 0;
        }
        return 1;
    }
}

int prime_num(int * p,int n)  //求出n以内的所有素数
{
    int i = 0;
    int j;
    for(j=0; j<=n; j++)
    {
        if(Is_prime(j))
         {
             p[i] = j;
             i+=1;
         }
    }
    i++;
    return i;
}

int prime_pair(int * p,int s) //返回素数对
{
    int j;
    int z = 0;
    for (j=1;j<=s;j++)
    {
        if((p[j]-p[j-1])==2)
        {
            z++;
        }

    }
    return z;
}
