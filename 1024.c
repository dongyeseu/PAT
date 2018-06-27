/*
时间：2018/6/27 13点24分
作者：楼浩然
题目：
1024 科学计数法 (20)（20 分）
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

输出格式：

对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：

+1.23400E-03
输出样例1：

0.00123400
输入样例2：

-1.2E+10
输出样例2：

-12000000000
*/
#include<stdio.h>
#define SIZE 100000
#define TEST1
int main(void)
{
        char sign;//符号
        char integer;//整数
        char frac[SIZE];//小数
        char expSign;//指数符号
        int  exp;//指数
        char ch;

        sign = getchar();
        integer = getchar();
        getchar();//跳过小数点
        int lenth = 0;
        while((ch = getchar())!='E')
        {
                frac[lenth++] = ch;
        }
        expSign = getchar();
        scanf("%d",&exp);

        #ifndef TEST1
        printf("%c%c.%sE%c%d\n",sign,integer,frac,expSign,exp);
        #endif

        if(sign == '-') printf("-");

        if(!exp)//先解决特殊情况
                printf("%c.%s\n",integer,frac);
        else if(expSign == '+')
        {
                if(exp>=lenth)//指数>=小数长度，这种情况不需要输出小数点，还可能在结尾补‘0’
                {
                        printf("%c%s",integer,frac);
                        for(int i = 0;i < exp - lenth ;i++)
                                putchar('0');
                        putchar('\n');
                }
                else
                {
                        if(integer != '0')      printf("%c",integer);
                        for(int i = 0;i<lenth;i++)
                        {
                                printf("%c",frac[i]);
                                if(i == exp-1)
                                        putchar('.');
                        }
                        putchar('\n');
                }

        }
        else//expSign == '-'
        {
                printf("0.");
                for(int i = 0; i < exp-1;i++)
                        putchar('0');
                printf("%c%s\n",integer,frac);
        }
        return 0;
}
