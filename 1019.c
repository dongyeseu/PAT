/*
时间：2018/6/23 08点56分
作者：楼浩然
题目：
1019 数字黑洞 (20)（20 分）
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089\ 9810 - 0189 = 9621\ 9621 - 1269 = 8352\ 8532 - 2358 = 6174\ 7641 - 1467 = 6174\ ... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：

6767
输出样例1：

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：

2222
输出样例2：

2222 - 2222 = 0000
*/

#include <stdio.h>

void bubble_sorting_1(int * n, int N); //数组递减排序
void bubble_sorting_2(int * n, int N);//数组递增排序
void ToChar(int * n,int N);
void ToInt(int *n,int *p);
int ToN_1(int N); //递减排序
int ToN_2(int N);//递增排序

int main(void)
{
    int N;//存储的数字，从0~10000
    scanf("%d",&N);

    do
    {
        int n1 = ToN_1(N);
        int n2 = ToN_2(N);
        N = n1 - n2;
        printf("%04d - %04d = %04d\n",n1,n2,N);
    }while(N!=6174 && N!=0);
    return 0;
}

void bubble_sorting_1(int * n, int N)//数组递减排序
{
    int i,j; //循环排序
    int flag=1; //判断条件
    int t;//用于元素互换；
    for (i=1 ; i<=N&&flag==1 ; i++)
    {
        flag = 0;
        for(j =0 ; j<N-1 ; j++)
        {
            if(n[j]<n[j+1])
            {
                t = n[j];
                n[j] = n[j+1];
                n[j+1] = t;
                flag = 1;
            }
        }
    }
}

void bubble_sorting_2(int * n, int N)//数组递增排序
{
    int i,j; //循环排序
    int flag=1; //判断条件
    int t;//用于元素互换；
    for (i=1 ; i<=N&&flag==1 ; i++)
    {
        flag = 0;
        for(j =0 ; j<N-1 ; j++)
        {
            if(n[j]>n[j+1])
            {
                t = n[j];
                n[j] = n[j+1];
                n[j+1] = t;
                flag = 1;
            }
        }
    }
}
void ToChar(int * n,int N)
{
    int i;
    for(i=0 ; i<4 ; i++)
    {
        if(N!=0)
        {
            n[i] = N%10;
            N = N/10;
        }
        else
            n[i] = 0;
    }
}

void ToInt(int *n,int *p)
{
    *p = n[0]*1000+n[1]*100+n[2]*10+n[3];
}
int ToN_1(int N)//递减排序
{
    int n[4]={0};
    ToChar(n,N);
    bubble_sorting_1(n,4);
    ToInt(n,&N);
    return N;
}
int ToN_2(int N)//递增排序
{
    int n[4]={0};
    ToChar(n,N);
    bubble_sorting_2(n,4);
    ToInt(n,&N);
    return N;
}


/*
反省：
1.注意while和do..while之间的联系和区别
2.scanf()中一定要记得加&
*/







