/*
时间：2018/7/2
作者：楼浩然
题目：
1083 是否存在相等的差（20 分）
给定 N 张卡片，正面分别写上 1、2、……、N，然后全部翻面，洗牌，在背面分别写上 1、2、……、N。将每张牌的正反两面数字相减（大减小），得到 N 个非负差值，其中是否存在相等的差？

输入格式：
输入第一行给出一个正整数 N（2 ≤ N ≤ 10 000），随后一行给出 1 到 N 的一个洗牌后的排列，第 i 个数表示正面写了 i 的那张卡片背面的数字。

输出格式：
按照“差值 重复次数”的格式从大到小输出重复的差值及其重复的次数，每行输出一个结果。

输入样例：
8
3 5 8 6 2 1 4 7
输出样例：
5 2
3 3
2 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void)
{
    int N;//代表牌的数量
    scanf("%d",&N);
    int num[N];
    memset(num,0,sizeof(int)*N);
    int card[N];
    int i;
    for(i=0 ; i<N ; i++)
        scanf("%d",&card[i]);
    int mid;
    for(i=0 ; i<N ; i++)
    {
        mid = card[i] - (i+1);
//        if(mid!=0)
        num[abs(mid)]++;
    }
    for(i=N-1; i>=0 ; i--)
    {
        if(num[i]>=2)
            printf("%d %d\n",i,num[i]);
    }
    return 0;

}

/*
总结：
1.要把0作为差值也考虑进去
2.abs()函数的使用
3.由于用下标记录差值大小，因此从后往前输出就相当于差值从大到小输出
*/

/*
#include <stdio.h>

int main()
{
    int N, num, diff[10000] = {0};

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {   /* The front is i + 1, the back is num
        scanf("%d", &num);
        diff[(num > i + 1) ? (num - i - 1) : (i + 1 - num)]++;
    }

    for(int i = N - 1; i >= 0; i--)
        if(diff[i] >= 2)
            printf("%d %d\n", i, diff[i]);

    return 0;
}*/
