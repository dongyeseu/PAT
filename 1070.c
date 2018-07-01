/*
时间：2018/7/1
作者：楼浩然
题目：
1070 结绳（25 分）
给定一段一段的绳子，你需要把它们串成一条绳。每次串连的时候，是把两段绳子对折，再如下图所示套接在一起。这样得到的绳子又被当成是另一段绳子，可以再次对折去跟另一段绳子串连。每次串连后，原来两段绳子的长度就会减半。
给定 N 段绳子的长度，你需要找出它们能串成的绳子的最大长度。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出正整数 N (2≤N≤10
第 2 行给出 N 个正整数，即原始绳段的长度，数字间以空格分隔。所有整数都不超过10
输出格式：
在一行中输出能够串成的绳子的最大长度。结果向下取整，即取为不超过最大长度的最近整数。

输入样例：
8
10 15 12 3 4 13 1 15
输出样例：
14
*/

#include <stdio.h>
#include <math.h>

int cmp(const void * a,const void * b)
{
    return *(int *)a - *(int *)b;
}
/*
int cop(const void * a,const void * b)
{
    return *(int *)b - *(int *)a;
}*/

int main(void)
{
    int N;
    scanf("%d",&N);
    int num[N];
    int i;
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    double res_1 = 0;// res_2 = 0;
    qsort(num,N,sizeof(int),cmp);
    for(i=0 ; i<N ; i++)
    {
        if(i==0)
            res_1 = num[i]*1.;
        else
            res_1 = (res_1 + num[i])/2.;
    }
//    qsort(num,N,sizeof(int),cop);
 //   for(i=0 ; i<N ; i++)
 //       res_2 = (res_1 + num[i])/2;
    printf("%d\n",(int)res_1);
    return 0;
}

/*
总结：
1.第一段绳子是不需要/2的
2.排序算法：一开始思路是不是从小到大就是从大到小排序，肯定是其中一个没错；后来想想，如果最开始的绳子折叠越多，因此越小的绳子放在
越前面折叠是最划算的
3.使用qsort()函数进行排序
4.使用double类型来记录最后结果，然后用（int)强制类型转换
*/


/*
用数组的下标来记录绳子长度，用值来代表这个下标出现过几次
#include <stdio.h>

int main()
{
    int l[10001] = {0}, N, i;
    double length = 0;

    scanf("%d", &N);
    for(int j = 0; j < N; j++)
    {
        scanf("%d", &i);
        l[i]++;                 // record counts
    }


    for(i = 0; i < 10001; i++)  // find the shortest, special case
        if(l[i])
        {
            length = i;
            break;
        }

    for(; i < 10001; i++)       // make new ropes
        while(l[i]--)
            length = (length + i) / 2;

    printf("%d", (int)length);

    return 0;
}
*/
