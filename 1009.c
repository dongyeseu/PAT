/*
时间：2018/6/12 23点33分
作者：楼浩然
题目：
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。
输出格式：每个测试用例的输出占一行，输出倒序后的句子。
输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
*/
#include <stdio.h>
#include <string.h>
#define SIZE 80
/* 全部测试点正确通过
int main(void)
{
    char english[SIZE][SIZE];
    int i=0;
    int j=0;
    while((english[i][j]=getchar())!='\n')
    {
        if (english[i][j]==' ')
        {
            english[i][j] = '\0';
            i++;
            j = 0;
        }
        else
            j++;
    }
    english[i][j]='\0';
    for (;i>=0;i--)
    {
        printf("%s",english[i]);
        if(i>0)
            printf(" ");
    }
    return 0;
}
*/

/*  未能通过第四个测试点
int main(void)
{
    char english[SIZE];
    char ans[SIZE][SIZE];
    fgets(english,SIZE,stdin);
    int i=0;
    while(english[i]!='\n' && english[i]!='\0')
       i++;
    if(english[i]=='\n')
        english[i]='\0';
    int length = strlen(english),n,m=0,k=0;
    for(n=0; n<length; n++)
    {
        if(english[n]!=' ')
        {
            ans[m][k++]=english[n];
        }
        else{
            ans[m][k]='\0';
            k = 0;
            m++;
        }
    }
    printf("%s",ans[m]);
    for(n=m-1;n>=0;n--)
    {
        printf(" ");
        printf("%s",ans[n]);
    }
    return 0;
}
*/
