/*
学生互评作业的简单规则是这样定的：每个人的作业会被k个同学评审，得到k个成绩。系统需要去掉一个最高分和一个最低分，将剩下的分数取平均，就得到这个学生的最后成绩。本题就要求你编写这个互评系统的算分模块。

输入格式：
输入第一行给出3个正整数N（3 < N ≤10
​4
​​ ，学生总数）、k（3 ≤ k ≤ 10，每份作业的评审数）、M（≤ 20，需要输出的学生数）。随后N行，每行给出一份作业得到的k个评审成绩（在区间[0, 100]内），其间以空格分隔。

输出格式：
按非递减顺序输出最后得分最高的M个成绩，保留小数点后3位。分数间有1个空格，行首尾不得有多余空格。

输入样例：
6 5 3
88 90 85 99 60
67 60 80 76 70
90 93 96 99 99
78 65 77 70 72
88 88 88 88 88
55 55 55 55 55
输出样例：
87.667 88.000 96.000
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int SUM(vector<int>R)
{
    int Res = 0;
    for(int c : R)
        Res += c;
    return Res;
}
bool cmp(double a,double b)
{
    return a > b;
}
int main()
{
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    vector<double>Res;
    for(int i=0 ; i<N ; i++)
    {
        vector<int>Temp;
        int Max = 0,Min = 101;
        int t;
        for(int j=0 ; j<M ; j++)
        {
            cin>>t;
            if(t > Max)
                Max = t;
            if(t < Min)
                Min = t;
            Temp.push_back(t);
        }
        int S = SUM(Temp) - Min - Max;
        double r = S*1.00 / (M*1.0 - 2.0);
        Res.push_back(r);
    }
    sort(Res.begin(),Res.end(),cmp);
    for(int i=K-1 ; i>=0 ; i--)
    {
        if(i!=K-1)
            printf(" ");
        printf("%.3f",Res[i]);
    }
    return 0;
}
