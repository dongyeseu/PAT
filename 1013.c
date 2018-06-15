/*
时间：2018/6/15 09点26分
作者：楼浩然
题目：
1013 数素数 (20)（20 分）
令P~i~表示第i个素数。现任给两个正整数M <= N <= 10^4^，请输出P~M~到P~N~的所有素数。
输入格式：
输入在一行中给出M和N，其间以空格分隔。
输出格式：
输出从P~M~到P~N~的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include <stdio.h>
#include <math.h>

void primer(int num_1,int num_2);
int IsPrime(int n);

int main(void)
{
    int i,j;
    scanf("%d %d",&i,&j);
    primer(i,j);
    return 0;
}

int IsPrime(int z)        //判断是否为素数
{
    int item = (int)sqrt(z)+1;
    int j;
    if (z<2)
        return 0;
    else if (z == 2 || z == 3)
        return 1;
    else if (z%6!=1 && z%6!=5)
        return 0;
    for (j = 5; j < item; j+=6)
    {
        if (z%j==0 || z%(j+2)==0)
            return 0;
    }
    return 1;
}

void primer(int num_1,int num_2)
{
    int prime[num_2 - num_1];
    int i = 0;
    int j = 2;
    int z;
    int total = 0;
    while (total < num_2)          //将满足条件素数键加入数组中
    {
        if (IsPrime(j))
        {
            total++;
            if(total>=num_1)
            {
                prime[i] = j;
                i++;
            }
        }
        if(j%2!=0)
            j+=2;
        else
            j++;
    }
    for(z=0 ; z<num_2-num_1+1 ; z++)         //按格式输出数组
    {

        if((z+1)%10!=0 && (z+1)!=num_2-num_1+1)
            printf("%d ",prime[z]);
        else if((z+1)%10==0 && (z+1) != num_2-num_1+1)
            printf("%d\n",prime[z]);
        else
            printf("%d",prime[z]);
    }
}
