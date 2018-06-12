/*
时间：2018/6/12 22点48分
作者：楼浩然
题目：
1008 数组元素循环右移问题 (20)（20 分）
一个数组A中存有N（N&gt0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A~0~ A~1~……A~N-1~）变换为（A~N-M~ …… A~N-1~ A~0~ A~1~……A~N-M-1~）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。
输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
输入样例：
6 2
1 2 3 4 5 6
输出样例：
5 6 1 2 3 4
*/

#include <stdio.h>

void N_print(int num,int n);


int main(void)
{
    int num,n;
    scanf("%d %d",&num,&n);
    N_print(num,n);
    return 0;
}

void N_print(int num,int n)
{
    int right[num];
    n = n%num;
    int k;
    for(k = 0; k<num ; k++)
        scanf("%d",&right[k]);
    int *p = right;
    int i;
    if (num==1)
    {
        printf("%d",right[0]);
        return;
    }

    for (i=0 ; i<n ;i++)
        printf("%d ",p[num-n+i]);
    for (i=n ; i<num-1 ;i++)
        printf("%d ",p[i-n]);
    printf("%d",p[num-n-1]);
}
