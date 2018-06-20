/*
时间：2018/6/20 09点39分
作者：楼浩然
题目：
1038 统计同成绩学生(20)（20 分）
本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：

输入在第1行给出不超过10^5^的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。

输出格式：

在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

输入样例：

10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：

3 2 0
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    //思路：创建一个含有100个元素的元素，下标代表分数，在输入分数的时候，对分数进行技术；查找分数相当于查找下标
    int N,score,K,i;   //N代表学生人数；score代表需要查找的分数大小.K代表需要查找的分数个数；i用于循环计数
    int grade_num[101]={0} ; //下标代表分数大小，值代表该分数出现的次数
    scanf("%d",&N);
    for(i=0 ; i<N ; i++)
    {
        scanf("%d",&score);
        grade_num[score]+=1;
    }
    scanf("%d",&K);
    for(i=0 ; i<K ; i++)
    {
        scanf("%d",&score);
        printf("%d%c",grade_num[score],i!=K-1?' ':'\n');
    }

    /*
    int N; //N代表学生人数
    scanf("%d",&N);
    int grade[N];  //N位学生的分数数组
    int i,j;  //循环中计数使用
    for(i=0 ; i<N ; i++)
    {
        scanf("%d",&grade[i]);
    }
    int K;  //K代表需要查询的分数个数
    scanf("%d",&K);
    int score;    //查询的分数
    int num[K];
    memset(num,0,sizeof(int)*K);
    int check[K]; //需要查询的分数的数组


    // 该段代码也会导致大数据时运行超时
    for(i=0 ; i<K ; i++)
        scanf("%d",&check[i]);
    for(i=0 ; i<N ; i++)
    {
        for(j=0 ; j<K ; j++)
        {
            if(grade[i] == check[j])
            {
                num[j]+=1;
            }
        }
    }
    for (j=0 ; j<K-1 ; j++)
        printf("%d ",num[j]);
    printf("%d",num[K-1]);
    */

    /*  这部分代码会导致大数据时运行超时
    for (i=0 ; i<K ; i++)
    {
        scanf("%d",&score);
        for( j=0 ; j<N ; j++)
        {
            if(grade[j] == score)
                num[i]++;
        }
        printf("%d%c",num[i],i!=(K-1)?' ':'\n');
    }
    */
    return 0;
}
