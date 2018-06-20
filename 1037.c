/*
时间：2018/6/20 11点28分
作者：楼浩然
题目：
1037 在霍格沃茨找零钱（20）（20 分）
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：

输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 10^7^]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例1：

10.16.27 14.1.28
输出样例1：

3.2.1
输入样例2：

14.1.28 10.16.27
输出样例2：

-3.2.1
*/

#include <stdio.h>
#include <math.h>

//思路：先将钱全部转化为最小货币单位，输出时将钱转化为S.G.K格式
void ToKunt(int (*m)[3] , int * t); //将“Galleon.Sickle.Knut”的价钱转化为只用kunt表示
void ToGSK(int res, int * re);  //将价钱转化为“Galleon.Sickle.Knut”格式

int main(void)
{
    int money[2][3]; //以数组的形式存储应付价格和实付金钱，格式为“Galleon.Sickle.Knut”
    scanf("%d.%d.%d %d.%d.%d",&money[0][0],&money[0][1],&money[0][2],&money[1][0],&money[1][1],&money[1][2]);
    int total[2]; //以西可存储应付价格和实付价格
    ToKunt(money,total);
    int res = total[1]-total[0];
    int re[3];  //以“Galleon.Sickle.Knut”格式存储结果
    ToGSK(abs(res),re);
    if(res>=0)
        printf("%d.%d.%d\n",re[0],re[1],re[2]);
    else
        printf("-%d.%d.%d\n",re[0],re[1],re[2]);
    return 0;
}

void ToKunt(int (*m)[3] , int * t)
{
    int i;  //用于循环计数
    for(i=0 ; i<2 ; i++)
        t[i] = (m[i][0]*17+m[i][1])*29+m[i][2];    //不同货币单位的换算方式
}

void ToGSK(int res, int * re)
{
    re[0] = res/(29*17);
    res = res%(29*17);
    re[1] = res/29;
    re[2] = res%29;
}
