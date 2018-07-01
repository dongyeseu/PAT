/*
时间：2018/6/19 16点27分
作者：楼浩然
题目：
1018 锤子剪刀布 (20)（20 分）
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
输入格式：
输入第1行给出正整数N（<=10^5^），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/

//测试点过不去，但是在调试中答案正确
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int who_win(char a, char b);  //如果甲赢，输出0 ； 如果乙赢，输出1；
int ci_shu(char a);//当赢的时候出的什么，如果是C，返回0；如果是J，返回1；如果是B，返回2；
char * shu_chu_zi_mu(int (*p)[3]); //比较每个字母出现的次数，输出最多的字母
void game(char * j, char * y, int num, int (*r)[3], int (*re)[3]); //甲乙两位选手石头剪刀布，并将结果保存
int main(void)
{
    int num;
    scanf("%d",&num);
    char jia[num],yi[num];
    char * b;
    int i;
    for( i=0 ; i<num ; i++)
        scanf(" %c %c",&jia[i],&yi[i]); //必须在最开始加空格，否则会出现空格读入的问题，导致最终读入的字符数量不足
    int res[2][3]={{0,0,0},{0,0,0}};
    int res_cishu[2][3]={{0,0,0},{0,0,0}};
    game( jia, yi, num , res, res_cishu);
    b = shu_chu_zi_mu(res_cishu);
    for( i=0 ; i<2 ; i++)
    {
        int j;
        for ( j=0 ; j<2 ; j++)
            printf("%d ",res[i][j]);
        printf("%d\n",res[i][2]);
    }
    printf("%c %c",b[0],b[1]);
    return 0;
}

int who_win(char a, char b)
{
    if (a == 'C' && b == 'J')
        return 0;
    else if (a == 'C' && b == 'B')
        return 1;
    else if (a == 'J' && b == 'C')
        return 1;
    else if( a == 'J' && b == 'B')
        return 0;
    else if (a == 'B' && b == 'C')
        return 0;
    else if (a == 'B' && b == 'J')
        return 1;
}

int ci_shu(char a)
{
    if(a == 'J')
        return 0;
    else if(a == 'C')
        return 1;
    else if(a == 'B')
        return 2;
}

char * shu_chu_zi_mu(int (*p)[3])
{
    char a[2];
    char * z;
    z = (char *)malloc(sizeof(char)*2);
    int i;
    for (i=0 ; i<2 ; i++)
    {
        if(p[i][2] >= p[i][1] && p[i][2] >= p[i][0])
            a[i] = 'B';
        else if(p[i][1] >= p[i][0] && p[i][1] > p[i][2])
            a[i] = 'C';
        else
            a[i] = 'J';
    }
    z = a;
    return z;
}

void game(char * j, char * y, int num ,int (*r)[3] ,int (*re)[3])
{
    int i;
    for (i=0 ; i<num ; i++)
    {
        if (y[i] == j[i])
        {
            r[0][1] += 1;
            r[1][1] += 1;
        }
        else
        {
            int tem = who_win(j[i],y[i]);
            r[tem][0] += 1;
            if (tem == 1)
            {
                int mid = ci_shu(y[i]);
                re[tem][mid]+=1;
            }
            else
            {
                int mid = ci_shu(j[i]);
                re[tem][mid]+=1;
            }
        }
    }
    r[0][2] = num - r[0][1] - r[0][0];
    r[1][2] = num - r[1][1] - r[1][0];
}

