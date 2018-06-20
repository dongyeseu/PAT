/*
时间：2018/6/20 09点08分
作者：楼浩然
题目：
1032 挖掘机技术哪家强(20)（20 分）
为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：

输入在第1行给出不超过10^5^的正整数N，即参赛人数。随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

输出格式：

在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。

输入样例：

6
3 65
2 80
1 100
2 70
3 40
3 0
输出样例：

2 150
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int num;    //num代表参赛人数
    scanf("%d",&num);
    int grade[num];  //每个学校参赛人数的总分
    memset(grade,0,sizeof(int)*num);  //grade数组所有元素全部初始化为0；memset头文件为string.h
    int school,score,i;
    int res=0;    //school代表参赛学校的编号；score代表每个学生的分数
    for(i=0 ; i<num ; i++){
        scanf("%d",&school);
        if(school>res)res = school;    //res代表学校的最高编号
        scanf("%d",&score);
        grade[school] += score;
    }
    int high_school = 0 ,high_score = 0;  //分别代表最高分的学校以及分数大小
    for (i=0 ; i<=res ; i++)
    {
        if (grade[i]>high_score)
        {
            high_school = i;
            high_score = grade[i];
        }
    }
    printf("%d %d",high_school,high_score);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N, iSchool, score, imax = 0;
    scanf("%d", &N);

    int *schools = (int*)calloc(N, sizeof(int));
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &iSchool, &score);
        schools[iSchool - 1] += score;
    }

    for(int i = 0; i < N; i++) 
        if(schools[i] > schools[imax])
            imax = i;

    printf("%d %d", imax + 1, schools[imax]);

    return 0;
}
*/
