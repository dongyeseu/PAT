/*
时间;2018/6/19 15点22分
作者：楼浩然
题目：
1017 A除以B (20)（20 分）
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
输入格式：
输入在1行中依次给出A和B，中间以1空格分隔。
输出格式：
在1行中依次输出Q和R，中间以1空格分隔。
输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
char a[MAX];
char res[MAX];

int main(void)
{
    char c;
    int num;
    int i = 0;
    int Re,j,mid = 0;
    while (scanf("%c",&c) && c != ' ')
    {
        a[i] = c;
        i++;
    }
    scanf("%d",&num);
    for (j=0 ; j<i ; j++)
    {
        int temp = ((a[j]-'0')+mid*10)/num;
        mid = ((a[j]-'0')+mid*10)%num;
        res[j] = temp + '0';
    }
    Re = mid;
    int len = strlen(res);
    if(res[0] != '0'&& len > 1)
        printf("%c",res[0]);
    else if(res[0] == '0' && len == 1)
        printf("%c",res[0]);
    for ( j=1 ; j<len ; j++)
        printf("%c",res[j]);
    printf(" %d\n",Re);
    return 0;
}
