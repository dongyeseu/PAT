/*
时间：2018/6/24 14点23分
作者；楼浩然
题目：
1060 爱丁顿数(25)（25 分）
英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数”E，即满足有E天骑车超过E英里的最大整数E。据说爱丁顿自己的E等于87。

现给定某人N天的骑车距离，请你算出对应的爱丁顿数E（<=N）。

输入格式：

输入第一行给出一个正整数N（<=10^5^），即连续骑车的天数；第二行给出N个非负整数，代表每天的骑车距离。

输出格式：

在一行中给出N天的爱丁顿数。

输入样例：

10
6 7 6 9 3 10 8 2 7 8
输出样例：

6
*/

/*  正确答案
#include <stdio.h>
#include <stdlib.h>

int sort(const void * a, const void * b)
{
    return (*(int*)b-*(int*)a);
}

int main(void)
{
    int N;//总数目
    scanf("%d",&N);
    int i; //循环计数
    int num[N]; //存放数字
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    qsort(num,N,sizeof(int),sort);
    for(i=0;i<N && num[i]>i+1;i++);
    printf("%d",i);
    return 0;
}
*/


/*  24fen，有一个测试点过不去
#include <stdio.h>
#include <stdlib.h>

int sort(const void * a, const void * b)
{
    return (*(int*)a-*(int*)b);
}

int main(void)
{
    int N;//总数目
    scanf("%d",&N);
    int i; //循环计数
    int num[N]; //存放数字
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    qsort(num,N,sizeof(int),sort);
    int E;
    for(i=0 ; i<N ; i++)
    {
        E = N-i;
        if(num[i]>E)
            break;
    }
    printf("%d",E);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
//void bubble_sort(int * a, int n); //对数组从小到大排序
void InsertionSort(int * n ,int N);
//int cmp (const void * a, const void * b){   return ( *(int*)a - *(int*)b );}
int main(void)
{
    int N;//总数目
    scanf("%d",&N);
    int i; //循环计数
    int num[N]; //存放数字
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
 //   qsort(num,N,sizeof(int),cmp);
    InsertionSort(num,N);
    int E; //爱丁顿数
    for(E=0 ; E<N && num[E]>E+1 ; E++);        //原先的E的判断条件出现问题
    printf("%d",E);
    return 0;
}


//运行超时
void InsertionSort(int * n ,int N)
{
    int i,j; //循环计数
    for(i=1 ; i<N ; i++)
    {
        int tem = n[i];
        for(j=i ; j>0 && n[j-1]<tem ; j--)
            n[j] = n[j-1];
        n[j] = tem;
    }
}


/*
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
*/
