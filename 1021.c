/*
时间：2018/6/19 14点37分
作者：楼浩然
1021 个位数统计 (15)（15 分）
给定一个k位整数N = d~k-1~*10^k-1^ + ... + d~1~*10^1^ + d~0~ (0<=d~i~<=9, i=0,...,k-1, d~k-1~>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。
输入格式：
每个输入包含1个测试用例，即一个不超过1000位的正整数N。
输出格式：
对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。
输入样例：
100311
输出样例：
0:2
1:3
3:1
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1001
char array[MAX];

int main(void)
{
    int i = 0;
    char c;
    int j;
    int res[10] = {0,0,0,0,0,0,0,0,0,0};
//    while (scanf("%c",&c) && c != '\n')  //和下面一种写法都能够通过测试点
    while (scanf("%c",&c)!= EOF)
    {
        array[i] = c;
        i++;
    }
    for ( j=0 ; j<i; j++)
    {
        int temp = array[j] - '0';    //很有用的一种将字符数字转换为数字的方法
        res[temp] += 1;
    }
    for ( j=0 ; j<10 ; j++)
    {
        if (res[j] != 0)
            printf("%d:%d\n",j,res[j]);
    }
    return 0;
}


/*   错误类型：当数字太大时，无法计算
void did(int * p, long int n);  //统计个位数
void print(int * p);

int main(void)
{
    long int num;
    int a[10]={0,0,0,0,0,0,0,0,0,0};
    int i;
    scanf("%ld",&num);
    did(a,num);
    print(a);
    return 0;
}

void did(int * p, long int n)
{
    int i;
    while(n!=0)
    {
        i = n%10;
        p[i] += 1;
        n = n/10;
    }
}

void print(int * p)
{
    int i;
    for( i=0 ; i<=9 ; i++)
    {
        if ( p[i] != 0)
            printf("%d:%d\n",i,p[i]);
    }
}
*/
