/*
时间：2018/6/19 19点34分
作者：楼浩然
题目：
1046 划拳(15)（15 分）
划拳是古老中国酒文化的一个有趣的组成部分。酒桌上两人划拳的方法为：每人口中喊出一个数字，同时用手比划出一个数字。如果谁比划出的数字正好等于两人喊出的数字之和，谁就赢了，输家罚一杯酒。两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。

下面给出甲、乙两人的划拳记录，请你统计他们最后分别喝了多少杯酒。

输入格式：

输入第一行先给出一个正整数N（<=100），随后N行，每行给出一轮划拳的记录，格式为：

甲喊 甲划 乙喊 乙划

其中“喊”是喊出的数字，“划”是划出的数字，均为不超过100的正整数（两只手一起划）。

输出格式：

在一行中先后输出甲、乙两人喝酒的杯数，其间以一个空格分隔。

输入样例：

5
8 10 9 12
5 10 5 10
3 8 5 12
12 18 1 13
4 16 12 15
输出样例：

1 2
*/

#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d",&num);
    int shu_ru[num][4];
    int i;
    for(i=0 ; i<num ;i++)
        scanf("%d %d %d %d",&shu_ru[i][0],&shu_ru[i][1],&shu_ru[i][2],&shu_ru[i][3]);
    int jia_he = 0;
    int yi_he = 0;
    for (i=0 ; i<num ;i++)
    {
        int tem = shu_ru[i][0]+shu_ru[i][2];
        if(shu_ru[i][1]==tem && shu_ru[i][3] == tem)
            continue;
        else if (shu_ru[i][1]!=tem && shu_ru[i][3] != tem)
            continue;
        else if (shu_ru[i][1]==tem && shu_ru[i][3] != tem)
            yi_he++;
        else if (shu_ru[i][1]!=tem && shu_ru[i][3] == tem)
            jia_he++;
    }
    printf("%d %d\n",jia_he,yi_he);
    return 0;
}
