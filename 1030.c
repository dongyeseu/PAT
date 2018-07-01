/*
时间：2018/6/23 17点03分
作者：楼浩然
题目：
1030 完美数列(25)（25 分）
给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。

现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：

输入第一行给出两个正整数N和p，其中N（<= 10^5^）是输入的正整数的个数，p（<= 10^9^）是给定的参数。第二行给出N个正整数，每个数不超过10^9^。

输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：

10 8
2 3 20 4 5 1 6 7 8 9
输出样例：

8
*/

#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int * a,int n); //冒泡排序  //排序算法没有问题
//int comp(const void *a, const void *b) { return *(int*)a - *(int*)b; }

int main(void)
{
    int N,P; //M为数列中的元素个数，P为给定参赛
    scanf("%d %d",&N,&P);
    int num[N]; //存储给定的数列元素
    int i,j;//循环计数
    for(i=0 ; i<N ; i++) //元素赋值
        scanf("%d",&num[i]);
    bubble_sort(num,N); //对数列进行排序
//    qsort(num, N, sizeof(int), comp);
    int res=0;// 记录完美数列中最多有多少个元素
    /*  //这部分记录res的过程有问题
    for(i=0 ; i<N-1; i++)
    {
        for(j=N-1; j>i ; j--)
        {
            if(num[j]<=num[i]*P*1L)
            {
                if(j-i+1 > res)
                    res = j-i+1;
            }
            if(j-i<res)
                break;
        }
        if(N-i-1<res)
            break;
    }
    */
    int first,last;
    for(first = 0, last = 0; last < N; first++)  //两个计量，last用的很精髓
    {
        while(last < N && num[last] <= 1L * num[first] * P)
            last++;
        if(res < last - first)
            res = last - first;
    }
    printf("%d",res);
    return 0;
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

