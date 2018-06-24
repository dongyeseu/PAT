/*
时间：2018/6/24 19点16分
作者：楼浩然
题目：
1042 字符统计(20)（20 分）
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：

输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，以回车结束（回车不算在内）。

输出格式：

在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：

This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：

e 7
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1001

int cmp(const void * a, const void * b)
{
    return (*(char *)a - *(char *)b);
}

int main(void)
{
    char N[SIZE];
    gets(N);
    int len = strlen(N);
    char shuru[SIZE];
    int i,j=0;
    for(i=0 ; i<len ; i++)
    {
        if((N[i]>='A'&&N[i]<='Z')||(N[i]>='a'&&N[i]<='z'))
        {
            if(N[i]>='A'&&N[i]<='Z')
            {
                shuru[j] = tolower(N[i]);
                j++;
            }
            else
            {
                shuru[j] = N[i];
                j++;
            }
        }
    }
    shuru[j] = '\0';
    char ch;
    qsort(shuru,j,sizeof(char),cmp);
    int total = 1;  //记录整个字符串中字符最多出现的次数
    char c;  //记录出现最多的字符
    int zs=0; //记录每个字符出现的个数
    for(i=1 ; i<j ; i++)
    {
        if(shuru[i]==shuru[i-1])
        {
            if(i==1)
                zs+=2;
            else
                zs+=1;
            if(zs>total)
            {
                total = zs;
                c = shuru[i];
            }
        }
        else
        {
            zs=1;
            if(zs>total)
            {
                total = zs;
                c = shuru[i];
            }
        }
    }
    if(total==1)
        printf("%c %d",shuru[0],total);
    else
        printf("%c %d",c,total);
    return 0;


}
