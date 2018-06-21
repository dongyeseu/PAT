/*
时间：2018/6/21 19点36分
作者：楼浩然
题目：
1064 朋友数(20)（20 分）
如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。例如123和51就是朋友数，因为1+2+3 = 5+1 = 6，而6就是它们的朋友证号。给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。注意：我们默认一个整数自己是自己的朋友。
输入格式：
输入第一行给出正整数N。随后一行给出N个正整数，数字间以空格分隔。题目保证所有数字小于10^4^。
输出格式：
首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。
输入样例：
8
123 899 51 998 27 33 36 12
输出样例：
4
3 6 9 26
*/


#include <stdio.h>

int friend_s(int m);      //计算一个数字各个位置上的数字之和；
void bubble_sort(int * a, int n); //对输入的数组进行排序

int main(void)
{
    int N;// 输入的整数个数
    scanf("%d",&N);
    int num[N];  //输入的样本
    int res[N];  //存放计算所得的朋友号
    int i; //循环计数
    for(i=0 ; i<N ; i++)
    {
        scanf("%d",&num[i]);
        res[i] = friend_s(num[i]);
    }
    bubble_sort(res,N);  //对计算所得的朋友数进行排序
    int Sum=1; //不同朋友数的个数
    for(i=0 ; i<N-1 ; i++)
    {
        if(res[i]!=res[i+1])
            Sum+=1;
    }
    int j=0; //用于循环计数
    printf("%d\n",Sum);
    for(i=0 ; i<N-1 ; i++)
    {
        if(res[i]!=res[i+1])
        {
            j++;
            printf("%d%c",res[i],j!=Sum?' ':'\n');
        }
    }
    if(j!=Sum)
        printf("%d\n",res[N-1]);
    return 0;
}

int friend_s(int m)      //计算一个数字各个位置上的数字之和
{
    int res = 0;
    while(m)
    {
        res += (m%10);
        m = m/10 ;
    }
    return res;
}

void bubble_sort(int * a, int n)
{
    int i,j; //用于循环计数
    int change; //y用于判断第二个循环中是否存在元素互换过程
    int k; //用于元素互换
    for(i = n-1 , change = 1 ; i>=1 && change ; i--)
    {
        change = 0;
        for (j=0 ; j<n-1 ; j++)
        {
            if(a[j]>a[j+1])
            {
                k = a[j];
                a[j] = a[j+1];
                a[j+1] = k;
                change = 1;
            }
        }
    }
}
