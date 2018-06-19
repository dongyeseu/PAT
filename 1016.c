/*
时间：2018/6/19 15点45分
作者：楼浩然
题目：
1016 部分A+B (15)（15 分）
正整数A的“D~A~（为1位整数）部分”定义为由A中所有D~A~组成的新整数P~A~。例如：给定A = 3862767，D~A~ = 6，则A的“6部分”P~A~是66，因为A中有2个6。
现给定A、D~A~、B、D~B~，请编写程序计算P~A~ + P~B~。
输入格式：
输入在一行中依次给出A、D~A~、B、D~B~，中间以空格分隔，其中0 < A, B < 10^10^。
输出格式：
在一行中输出P~A~ + P~B~的值。
输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
char shuru_1[MAX];
char shuru_2[MAX];

int part(char * p , int num)
{
    int i = 0;
    int total = 0;
    int res = num;
    while ( p[i] != '\0')
    {
        if ( (p[i] - '0') == num)
            total += 1;
        i++;
    }
    if (total == 0)
        return 0;
    else
    {
        for ( i=1 ; i<total ; i++)
        {
            res = res*10 + num;
        }
        return res;
    }
}

int main(void)
{
    int num_1,num_2;
    scanf("%s %d %s %d",shuru_1,&num_1,shuru_2,&num_2);
    int a[2]={0,0};
    a[0] = part(shuru_1,num_1);
    a[1] = part(shuru_2,num_2);
    printf("%d\n",a[0]+a[1]);
    return 0;
}
