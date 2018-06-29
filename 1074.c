/*
时间：2018/6/23 13点52分
作者：楼浩然
题目：
1074 宇宙无敌加法器（20 分）
地球人习惯使用十进制数，并且默认一个数字的每一位都是十进制的。而在 PAT 星人开挂的世界里，每个数字的每一位都是不同进制的，这种神奇的数字称为“PAT数”。每个 PAT 星人都必须熟记各位数字的进制表，例如“……0527”就表示最低位是 7 进制数、第 2 位是 2 进制数、第 3 位是 5 进制数、第 4 位是 10 进制数，等等。每一位的进制 d 或者是 0（表示十进制）、或者是 [2，9] 区间内的整数。理论上这个进制表应该包含无穷多位数字，但从实际应用出发，PAT 星人通常只需要记住前 20 位就够用了，以后各位默认为 10 进制。

在这样的数字系统中，即使是简单的加法运算也变得不简单。例如对应进制表“0527”，该如何计算“6203 + 415”呢？我们得首先计算最低位：3 + 5 = 8；因为最低位是 7 进制的，所以我们得到 1 和 1 个进位。第 2 位是：0 + 1 + 1（进位）= 2；因为此位是 2 进制的，所以我们得到 0 和 1 个进位。第 3 位是：2 + 4 + 1（进位）= 7；因为此位是 5 进制的，所以我们得到 2 和 1 个进位。第 4 位是：6 + 1（进位）= 7；因为此位是 10 进制的，所以我们就得到 7。最后我们得到：6203 + 415 = 7201。

输入格式：
输入首先在第一行给出一个 N 位的进制表（0 < N ≤ 20），以回车结束。 随后两行，每行给出一个不超过 N 位的非负的 PAT 数。

输出格式：
在一行中输出两个 PAT 数之和。

输入样例：
30527
06203
415
输出样例：
7201
*/

#include <stdio.h>
#include <string.h>

#define  SIZE 21

int main(void)
{
    char jinzhi[SIZE];
    char num_1[SIZE];
    char num_2[SIZE];
    int i;
    scanf("%s",jinzhi);
    scanf("%s",num_1);
    scanf("%s",num_2);
    int N = strlen(jinzhi); //进制的位数
    int n1 = strlen(num_1);
    int n2 = strlen(num_2); //分别表示两个数字的位数
    int n = n1>n2?n1:n2;
    char res[n+2];
    int mid = 0; //代表进数
    int sum;//代表当个位数上两个数字的和
    res[n+1] = '\0';
    for(i=1 ; i<=n ; i++)
    {
        int a = n1-i>=0?num_1[n1-i]-'0':0;
        int b = n2-i>=0?num_2[n2-i]-'0':0;

        sum = a + b + mid;
 //       printf("s %d\n",sum);
        if(sum < (jinzhi[N-i]-'0'))
        {
            res[n+1-i] = sum + '0';
            mid = 0;
    //        printf("1 %c\n",res[n+1-i]);
        }

        else
        {
            int c = sum;
            int d = jinzhi[N-i] - '0';
            if(d==0)
                d = 10;
            sum = c%d;
            res[n+1-i] = sum + '0';
            mid = c/d;
   //         printf(" 2 %c\n",res[n+1-i]);
        }
    }
    if(mid==0)
    {
        res[0] = '0';
    }
    else
        res[0] = mid+'0';
    i = 0;
    int j;
 //   printf("%s",res);
    for(i=0 ; i<n+1 ; i++)
    {
        if(res[i] == '0')
        {
            j=i;
        }
        else
        {
            j = i;
            break;
        }
    }
    for(;j<n+1;j++)
        printf("%c",res[j]);
    return 0;

}

/*
int main(void)
{
    char a[3][SIZE];
    int i;
    char ch;
    for(i=0 ; i<3 ; i++)
    {
        int j=0;
        while((ch=getchar())&&ch!='\n')
        {
            a[i][j] = ch;
            j++;
        }
        a[i][j] = '\0';
    }
    int leng_0,leng_1,leng_2,l1,l2;
    leng_0 = strlen(a[0]),l1 = leng_1 = strlen(a[1]),l2 = leng_2 = strlen(a[2]);
    int leg = leng_1>leng_2?leng_1:leng_2;
    int a_,b_,d_;
    int mid_4 = 0;
    int res[SIZE];
    int j=0;
    for(i=1 ; i<=leg ;i++)
    {
        if(i<=l1)
            a_ = (a[1][leng_1-i])-'0';
        else
            a_ = 0;
        if(i<=l2)
            b_ = a[2][leng_2-i]-'0';
        else
            b_ = 0;
        d_ = a[0][leng_0-i]-'0';
        res[j] = (a_ + b_ + mid_4)%d_;
        mid_4 = (a_ + b_ + mid_4)/d_;
        j++;
    }
    int z;
    for(z=j-1 ; z>=0 ; z--)
        scanf("%d",res[i]);
    return 0;
}

*/

/* 浮点错误
#include <stdio.h>
#define SIZE 20

int main(void)
{
    long int d;
    long int a;
    long int b;
    int mid_1,mid_2,mid_3,mid_4=0;  //分别由于存放d,a,b,res的余数
    scanf("%ld",&d);
    scanf("%ld",&a);
    scanf("%ld",&b);
    int res[SIZE];
    int i=0;
    while(a!=0 || b!=0)
    {
        mid_1 = d%10;
        d = d/10;
        mid_2 = a/10;
        a = a/10;
        mid_3 = b/10;
        b = b/10;
        res[i] = (mid_2 + mid_3 + mid_4)%mid_1;
        mid_4 = (mid_2 + mid_3 + mid_4)/mid_1;
        i++;
    }
    int j;
    long int Re=0;//最后的输出结果
    for(i=0 ; i<j ; i++)
        Re = Re*10+res[i];
    printf("%d",Re);
    return 0;
}
*/
