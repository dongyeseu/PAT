/*
时间：2018/6/20 11点55分
作者：楼浩然
题目：
1041 考试座位号(15)（15 分）
每个PAT考生在参加考试时都会被分配两个座位号，一个是试机座位，一个是考试座位。正常情况下，考生在入场时先得到试机座位号码，入座进入试机状态后，系统会显示该考生的考试座位号码，考试时考生需要换到考试座位就座。但有些考生迟到了，试机已经结束，他们只能拿着领到的试机座位号码求助于你，从后台查出他们的考试座位号码。

输入格式：

输入第一行给出一个正整数N（<=1000），随后N行，每行给出一个考生的信息：“准考证号 试机座位号 考试座位号”。其中准考证号由14位数字组成，座位从1到N编号。输入保证每个人的准考证号都不同，并且任何时候都不会把两个人分配到同一个座位上。

考生信息之后，给出一个正整数M（<=N），随后一行中给出M个待查询的试机座位号码，以空格分隔。

输出格式：

对应每个需要查询的试机座位号码，在一行中输出对应考生的准考证号和考试座位号码，中间用1个空格分隔。

输入样例：

4
10120150912233 2 4
10120150912119 4 1
10120150912126 1 3
10120150912002 3 2
2
3 4
输出样例：

10120150912002 2
10120150912119 1
*/

#include <stdio.h>

//思路：以试机座位号作为下标，将准考证号和考试座位号存入二维数组array[N+1][1]中，查询试机座位号时，直接输出该下标的值
int main(void)
{
    int N,K,S; //N代表考生人数;K代表要查询准考证的人数；S为查询时输入的试机号
    scanf("%d",&N);
    char card_1[N+2][16];  //以试机号作为下标，存储准考证号
    int card_2[N+2][1]; //以试机号作为下标，存储考试座位号
    char zhun_kao_zheng[16];
    int shi_ji,zuo_wei; //分别代表准考证号，试机座位号，考试座位号的编号
    int i,j; // 用于循环计数
    for(i=0 ; i<N ; i++)
    {
        scanf("%s",zhun_kao_zheng);
        scanf("%d %d",&shi_ji,&zuo_wei);
        for(j=0 ; j<=14 ; j++)
            card_1[shi_ji][j] = zhun_kao_zheng[j];
        card_2[shi_ji][0] = zuo_wei;
    }
    scanf("%d",&K);
    for (i=0 ; i<K ; i++)
    {
        scanf("%d",&S);
        printf("%s %d\n",card_1[S],card_2[S][0]);
    }
    return 0;
}


/*  自定义结构体，但是查询方式不可取
#include<stdio.h>
struct form{
    char sn[50];
    int test;
    int exam;
} stu[1010];
int main()
{
    int i,n,k,as[1010],j;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%s %d %d",stu[i].sn,&stu[i].test,&stu[i].exam);
        getchar();
    }
    scanf("%d",&k);
    getchar();
    for(i=0;i<k;i++)
    {
        scanf("%d",&as[i]);
        for(j=0;j<n;j++)
        {
            if(as[i]==stu[j].test)
            {
                printf("%s %d",stu[j].sn,stu[j].exam);
                break;
            }
        }
        if(i!=k-1)
        printf("\n");
    }
    return 0;
}
*/
