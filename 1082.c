/*
时间：2018/7/2
作者：楼浩然
题目：
1082 射击比赛（20 分）
本题目给出的射击比赛的规则非常简单，谁打的弹洞距离靶心最近，谁就是冠军；谁差得最远，谁就是菜鸟。本题给出一系列弹洞的平面坐标(x,y)，请你编写程序找出冠军和菜鸟。我们假设靶心在原点(0,0)。

输入格式：
输入在第一行中给出一个正整数 N（≤ 10 000）。随后 N 行，每行按下列格式给出：

ID x y
其中 ID 是运动员的编号（由 4 位数字组成）；x 和 y 是其打出的弹洞的平面坐标(x,y)，均为整数，且 0 ≤ |x|, |y| ≤ 100。题目保证每个运动员的编号不重复，且每人只打 1 枪。

输出格式：
输出冠军和菜鸟的编号，中间空 1 格。题目保证他们是唯一的。

输入样例：
3
0001 5 7
1020 -1 3
0233 0 -1
输出样例：
0233 0001
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    int ID[10000];
    int i,id;
    for(i=0 ; i<10000 ; i++)
        ID[i] = -1;
    int x,y; //代表坐标
    int N; //代表运动员人数
    scanf("%d",&N);
    int a = N;
    for(i=0 ; i<N ; i++)
    {
        scanf("%d %d %d",&id,&x,&y);
        int res = pow(x,2) + pow(y , 2);
        ID[id] = res;
    }
    int max_score = -1,min_score = 10001;
    int max_id,min_id;
    for(i=0 ; i<10000; i++)
    {
        if(ID[i]!=-1)
        {
            if(ID[i]>max_score)
            {
                max_score = ID[i];
                max_id = i;
            }
            else if(ID[i]<min_score)
            {
                min_score = ID[i];
                min_id = i;
            }
        }
    }


    printf("%04d %04d\n",min_id,max_id);
    return 0;

}

/*
总结：
1.用下标来记录ID，用值来记录成绩
2.遍历寻找最大值和最小值分别代表的id
*/


/*这里的思路是用成绩作为下标，根据下标的大小来找出最大值和最小值的ID，但是结果错误
#include <stdio.h>
#include <math.h>

int main(void)
{
    int ID[10000];
    int i,id;
    for(i=0 ; i<10000 ; i++)
        ID[i] = -1;
    int x,y; //代表坐标
    int N; //代表运动员人数
    scanf("%d",&N);
    int a = N;
    for(i=0 ; i<N ; i++)
    {
        scanf("%d %d %d",&id,&x,&y);
        int res = pow(x,2) + pow(y , 2);
        if(ID[res]==-1)
            ID[res] = id;
        else
            a--;
    }
    int shuchu[2];
    int count = 0;
    for(i=9999 ; i>=0 ; i--)
    {
        if(ID[i]!=-1)
            count++;
        if(count == 1)
            shuchu[0] = ID[i],count++;
        else if(count == a+1)
            shuchu[1] = ID[i],count++;
    }
    printf("%04d %04d\n",shuchu[1],shuchu[0]);
    return 0;

}
*/
