/*
时间：2018/6/21 09点06分
作者：楼浩然
题目：
1048 数字加密(20)（20 分）
本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。

输入样例：

1234567 368782971
输出样例：

3695Q8118
*/

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char A[101], B[101];
    char encrypt[] = "0123456789JQK";

    scanf("%s %s", A, B);
    int lenA = strlen(A);
    int lenB = strlen(B);
    int maxlen = lenA > lenB ? lenA : lenB;
    int a, b;
    int i;

    for(i = 0; i < maxlen; i++)
    {
        a = lenA + i - maxlen < 0 ? 0 : A[lenA + i - maxlen] - '0';
        b = lenB + i - maxlen < 0 ? 0 : B[lenB + i - maxlen] - '0';
        if((maxlen - i) % 2)    putchar(encrypt[(a + b) % 13]);
        else                    putchar('0' + (b - a < 0 ? b - a + 10 : b - a));
    }

    return 0;
}
*/

//好了，但是好繁琐
#include <stdio.h>
#include <string.h>
#define MAX 101
char A[MAX]; //存放A字符串
char B[MAX];//存放B字符串

void coding(char * a, char * b,int la ,int lb); //对B字符串加密

int main(void)
{
    scanf("%s %s",A,B);
    int len_A = strlen(A); //A字符串的长度
    int len_B = strlen(B);  //B字符串的长度
    if(len_A > len_B)
    {
        int le = len_A - len_B ;  //确定需要在B字符串前面添加几个0
        int i;  //循环计数
        for(i=len_B ; i>=0 ; i--)
            B[i+le] = B[i];
        for(i=0 ; i<le ; i++)
            B[i] = '0';
        len_B = len_A;
    }
    coding(A,B,len_A,len_B);
    printf("%s",B);
    return 0;
}

char yu_shu(int n)
{
    if(n==11)
        return 'Q';
    else if(n==10)
        return 'J';
    else if(n==12)
        return 'K';
    else
        return n+'0';
}

void coding(char * a, char * b,int la ,int lb)
{
    int i;//循环计数
    int length = la > lb? lb:la;
    int tem;
    for(i=1 ; i<=length ; i++)
    {
        if(i%2)
        {
            tem = (b[lb-1]-'0'+a[la-1]-'0')%13;
  //          printf("%d\n",tem);
            b[lb-1] = yu_shu(tem);
            lb--;
            la--;
        }
        else
        {
            tem = b[lb-1] - a[la-1];
            if(tem<0)
                tem+=10;
//            printf("%d\n",tem);
            b[lb-1] = tem+'0';
            lb--;
            la--;
        }
    }
}

