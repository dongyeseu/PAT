/*
时间：2018/6/20 12点34分
作者：楼浩然
题目：
1079 延迟的回文数（20 分）

输入格式：
输入在一行中给出一个不超过1000位的正整数。

输出格式：
对给定的整数，一行一行输出其变出回文数的过程。每行格式如下

A + B = C
其中 A 是原始的数字，B 是 A 的逆转数，C 是它们的和。A 从输入的整数开始。重复操作直到 C 在 10 步以内变成回文数，这时在一行中输出 C is a palindromic number.；或者如果 10 步都没能得到回文数，最后就在一行中输出 Not found in 10 iterations.。

输入样例 1：
97152
输出样例 1：
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
输入样例 2：
196
输出样例 2：
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 1011  //必须这么大，否则在运算过程中会有内存溢出现象

char * Reverse(char * m)
{
    int len = strlen(m);
    int length = len;
    char * p;
    p = malloc(sizeof(char)*(len+1));
    int j = 0;
    for(j=0 ; j<len ; j++)
        p[j] = m[--length];
    p[j] = '\0';
    return p;
}

bool IsPalindromic(char * m)
{
    char * p;
    p = Reverse(m);
    if(!strcmp(p,m))
        return true;
    else
        return false;
}

char * Add(char * m,char * n)
{
    int len = strlen(m);
    char * p;
    p = malloc(sizeof(char)*(len+2));
    int mid = 0;
    p[len+1] = '\0';
    int i;
    for(i=len-1 ; i>=0 ; i--)
    {
        p[len--] = (m[i] - '0' + n[i] - '0' + mid)%10 +'0';
        mid = (m[i] - '0' + n[i] - '0' + mid)/10;
    }
    if(mid==0)
        return &p[1];
    else
    {
        p[0] = mid + '0';
        return p;
    }

}

int main(void)
{
    char a[SIZE];
    gets(a);
    char * res = a;
    int i=0 ;
    while(i<10 && !IsPalindromic(res))
    {
        char * mid;
        mid = Reverse(res);
        printf("%s + %s = ",res,mid);
        res = Add(res,mid);
        printf("%s\n",res);
        i++;
    }
    if(i<=10 && IsPalindromic(res))
        printf("%s is a palindromic number.",res);
    else
        printf("Not found in 10 iterations.\n");
    return 0;
}

/*  没有考虑到正整数位数可以达到1000位
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int Reverse(int m)
{
    int mid;
    int res = 0;
    while(m!=0)
    {
        mid = m%10;
        res = res*10 + mid;
        m = m/10;
    }
    return res;
}

bool IsPalindromic(int m)
{
    int n = Reverse(m);
    if(m==n)
        return true;
    else
        return false;
}

int main(void)
{
    int num;
    scanf("%d",&num);
    int mid;
    int res = num;
    int i=0;
    while(!IsPalindromic(res)&&i<10)
    {
        mid = Reverse(res);
        int origin = res;
        res = res + mid;
        printf("%d + %d = %d\n",origin,mid,res);
        i++;
    }
    if(i<=10 && IsPalindromic(res))
        printf("%d is a palindromic number.",res);
    else
        printf("Not found in 10 iterations.\n");
    return 0;

}
*/


//他山之玉
/*
#include <stdio.h>
#include <string.h>

int isPalindromicNumber(char n[])   //判断回文数很简答的技巧
{
    int len = strlen(n);
    for(int i = 0; i < len / 2; i++)
        if(n[i] != n[len - i - 1])
            return 0;
    return 1;
}

void addBtoA(char a[], char b[])
{
    /* Assume length of a and b are the same
    int len = strlen(a), sum, carry = 0;
    for(int i = len - 1; i >= 0; i --)
    {
        sum = a[i] - '0' + b[i] - '0' + carry;
        a[i] = sum % 10 + '0';
        carry = sum / 10;
    }
    if(carry) /* Length of a + b is larger than a or b
    {
        memmove(a + 1, a, len + 1); /* Shift to right by 1   //数组中元素整体位移的方法
        a[0] = carry + '0';         /* Add the carry to beginning
    }
}

void reverseAtoB(char a[], char b[])
{
    int len = strlen(a);
    for(int i = 0; i < len; i++)
        b[len - i - 1] = a[i];
}

int main()
{
    int i;
    char a[1011] = {0}, b[1011] = {0};

    scanf("%s", a);
    for (i = 0; i < 10 && !isPalindromicNumber(a); i++)
    {
        reverseAtoB(a, b);
        printf("%s + %s = ", a, b);
        addBtoA(a, b);
        printf("%s\n", a);
    }

    if(i == 10)
        printf("Not found in 10 iterations.");
    else
        printf("%s is a palindromic number.", a);

    return 0;
}
/*
