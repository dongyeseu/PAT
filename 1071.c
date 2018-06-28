/*
时间：2018/6/28 09点55分
作者：楼浩然
题目：
071 小赌怡情（15 分）
常言道“小赌怡情”。这是一个很简单的小游戏：首先由计算机给出第一个整数；然后玩家下注赌第二个整数将会比第一个数大还是小；玩家下注 t 个筹码后，计算机给出第二个数。若玩家猜对了，则系统奖励玩家 t 个筹码；否则扣除玩家 t 个筹码。

注意：玩家下注的筹码数不能超过自己帐户上拥有的筹码数。当玩家输光了全部筹码后，游戏就结束。

输入格式：
输入在第一行给出 2 个正整数 T 和 K（≤ 100），分别是系统在初始状态下赠送给玩家的筹码数、以及需要处理的游戏次数。随后 K 行，每行对应一次游戏，顺序给出 4 个数字：

n1 b t n2
其中 n1 和 n2 是计算机先后给出的两个[0, 9]内的整数，保证两个数字不相等。b 为 0 表示玩家赌小，为 1 表示玩家赌大。t 表示玩家下注的筹码数，保证在整型范围内。

输出格式：
对每一次游戏，根据下列情况对应输出（其中 t 是玩家下注量，x 是玩家当前持有的筹码量）：

玩家赢，输出 Win t! Total = x.；
玩家输，输出 Lose t. Total = x.；
玩家下注超过持有的筹码量，输出 Not enough tokens. Total = x.；
玩家输光后，输出 Game Over. 并结束程序。
输入样例 1：
100 4
8 0 100 2
3 1 50 1
5 1 200 6
7 0 200 8
输出样例 1：
Win 100!  Total = 200.
Lose 50.  Total = 150.
Not enough tokens.  Total = 150.
Not enough tokens.  Total = 150.
输入样例 2：
100 4
8 0 100 2
3 1 200 1
5 1 200 6
7 0 200 8
输出样例 2：
Win 100!  Total = 200.
Lose 200.  Total = 0.
Game Over.
*/
#include <stdio.h>
int IsWin(int n1,int n2)
{
    if(n2>n1)
        return 1;
    else
        return 0;
}

int main(void)
{
    int T,K ; //T为玩家总的筹码数，K为循环次数
    scanf("%d %d",&T,&K);
    int i;//循环计数
    int n1,b,t,n2; //n1,n2为比较大小的数，t为下的筹码，b为玩家对大小的判读
    int num[K][4];
    for(i=0 ; i<K && T>0 ; i++)
    {
        scanf("%d %d %d %d",&num[i][0],&num[i][1],&num[i][2],&num[i][3]);
   /* }
    for(i=0 ; i<K&&T>0 ; i++)
    {*/
        n1= num[i][0],b = num[i][1],t = num[i][2],n2 = num[i][3];
        if(T>=t)
        {
            if(b==IsWin(n1,n2))
            {
                T += t;
                printf("Win %d!  Total = %d.\n",t,T);
            }
            else
            {
                T -= t;
                printf("Lose %d.  Total = %d.\n",t,T);
            }
        }
        else
        {
            printf("Not enough tokens.  Total = %d.\n",T);
        }
        if(T==0)
        {
            printf("Game Over.\n");
        }

    }
    return 0;
}
