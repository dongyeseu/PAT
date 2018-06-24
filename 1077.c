/*
时间:2018/6/24 11点19分
作者：楼浩然
题目：
1077 互评成绩计算（20 分）
输入样例：
6 50
42 49 49 35 38 41
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29
输出样例：
42
33
41
31
37
39
*/

#include <stdio.h>

int main(void)
{
    int N,M; //分别代表分组组数以及满分分数
    scanf("%d %d",&N,&M);
    int score[N];
    int grade_teacher;
//    int grade_student[N];
    float g2; //学生评分平均值
    int i,j; //循环计数
    for(i=0 ; i<N ; i++)
    {
        int valid = 0; //学生评分有效数
        int max_score = 0;
        int min_score = M;
        int res = 0;
        scanf("%d",&grade_teacher);
        for(j=0 ; j<N-1 ;j++)
        {
            int s;
            scanf("%d",&s);
            if(s>=0 && s<=M)
            {
                if(s>max_score)
                    max_score = s;
                if(s<min_score)
                    min_score = s;
                res+=s;
                valid++;
            }
        }
        res = res - max_score - min_score;
        g2 = res*1.0/(valid-2);
        score[i] = (g2+grade_teacher*1.)/2+0.5;
    }
    for(i=0 ; i<N ; i++)
        printf("%d\n",score[i]);
    return 0;
}
