/*
时间：2018/6/27 23点48分
作者：楼浩然
题目：
1058 选择题（20 分）
批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。

输入格式：
输入在第一行给出两个正整数 N（≤ 1000）和 M（≤ 100），分别是学生人数和多选题的个数。随后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给出一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从 1 开始编号）。如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出 Too simple。

输入样例：
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
输出样例：
3
6
5
2 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Max(int * E,int M)
{
    int i;
    int max = 0;
    for(i=0 ; i<M ; i++)
    {
        if(E[i]>max)
            max = E[i];
    }
    return max;

}

struct score{
    int perfect_score; //满分
    int choice ;//选项个数
//    int right;//正确的选项个数
    char xuanxiang[20];//选项
};

int main(void)
{
    int N,M;//分别代表学生人数和多选题个数
    scanf("%d %d",&N,&M);
    while(getchar()!='\n')
        continue;
    int i,j;//循环计数
    struct score *sco[M];
    for(i=0 ; i<M ; i++)
    {
        sco[i] = malloc(sizeof(struct score));
        scanf("%d %d",&sco[i]->perfect_score,&sco[i]->choice);
        getchar();
        scanf("%[^\n]",sco[i]->xuanxiang);
    }
    while(getchar()!='\n')
        continue;
//    for(i=0 ; i<M ; i++)
//        printf("%s\n",sco[i]->xuanxiang);      //输入没有问题
    int grade[N];
    memset(grade,0,sizeof(int)*N);
    int error[M] ;
    memset(error,0,sizeof(int)*M);
    for(i=0 ; i<N ; i++)
    {
        char student[M][20];
        char ch;
        int j=0;
        while((ch = getchar())!='\n')
        {
            if(ch=='(')
            {
                scanf("%[^)]",student[j]);
                if(!strcmp(student[j],sco[j]->xuanxiang))
                {
                    grade[i]+=sco[j]->perfect_score;
                }
                else
                {
                    error[j]++;
                }
                j++;
            }
            else
                continue;
        }
    }
    for(i=0 ; i<N ; i++)
        printf("%d\n",grade[i]);
    int max = Max(error,M);
    int xia_biao[M];
    j = 0;
    for(i=0 ; i<M ; i++)
    {
        if(error[i] == max)
            xia_biao[j++] = i+1;
    }
    if(max!=0)
    {
        printf("%d ",max);
        for(i=0 ; i<j ; i++)
            printf("%d%c",xia_biao[i],i==j-1?'\n':' ');
    }
    else
    {
        printf("Too simple\n");
    }

    return 0;
}


/*
总结：
1.使用scanf("[]")输入函数将选项作为字符串输入
2.使用strcmp（）函数来判断选项是否正确
*/




