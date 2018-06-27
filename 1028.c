/*
时间：2018/6/27 12点23分
作者：楼浩然
题目:
1028 人口普查(20)（20 分）
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：

输入在第一行给出正整数N，取值在(0, 10^5^]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：

在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：

5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：

3 Tom John
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
struct info
{
    char Name[6];
    int Year;
    int month;
    int day;
    struct info * next;
};

bool IsValid(int Y,int M,int D)
{
    if(Y>2014)
        return false;
    else if(Y==2014&&M>9)
        return false;
    else if(Y==2014&&M==9&&D>6)
        return false;
    else if(Y<1814)
        return false;
    else if(Y==1814&&M<9)
        return false;
    else if(Y==1814 && M==9 &&D<6)
        return false;
    else
        return true;
}

bool IsOld(struct info *a,struct info *b)
{
    if(b->Year>a->Year)
        return true;
    else if(b->Year == a->Year && b->month>a->month)
        return true;
    else if(b->Year == a->Year && b->month == a->month && b->day > a->day)
        return true;
    else
        return false;
}

int main(void){
    int N;//人数
    int num = 0;
    scanf("%d",&N);
    struct info *head = NULL, *current, * prev;
    int i; //循环计数
    char Na[6];
    int Y,M,D;
    for(i=0 ; i<N ; i++)
    {
        scanf("%s %d/%d/%d",Na,&Y,&M,&D);
        if(IsValid(Y,M,D))
        {
            current = (struct info *)malloc(sizeof(struct info));
            strcpy(current->Name,Na);
            current->Year = Y;
            current->month = M;
            current->day = D;
            num+=1;
            if(head==NULL)
                head = current;
            else
                prev->next = current;
            prev = current;
        }
    }
    current = head;
    struct info *min = head,*max = head;
    while(current!=NULL)
    {
        if(IsOld(min,current))
            min = current;
        if(IsOld(current,max))
            max = current;
        current = current->next;
    }
    if(num==0)
        printf("0");
    else
        printf("%d %s %s\n",num,max->Name,min->Name);
    return 0;
}







