/*
时间：2018/6/20 18点03分
作者：楼浩然
题目：
1057 数零壹(20)（20 分）
给定一串长度不超过10^5^的字符串，本题要求你将其中所有英文字母的序号（字母a-z对应序号1-26，不分大小写）相加，得到整数N，然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，其字母序号之和为：16+1+20+2+1+19+9+3=71，而71的二进制是1000111，即有3个0、4个1。

输入格式：

输入在一行中给出长度不超过10^5^、以回车结束的字符串。

输出格式：

在一行中先后输出0的个数和1的个数，其间以空格分隔。

输入样例：

PAT (Basic)
输出样例：

3 4
*/


//最后计算0，1数量使用位运算符，大大提高运行速度
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch; // 定义输入字符
    int res=0; //定义字符相加结果
    int count[2]={0};
    while (scanf("%c",&ch) && ch!='\n')
    //while ((ch=getchar())!='\n')
    {
        if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))   //if(isalpha(ch))
        {
            ch = tolower(ch);  //tolower()是有返回值的
            res+=(ch-'a'+1); //使a-z代表1-26
        }
    }
    while(res)
    {
        count[res & 1]++;
        res>>=1;
    }
    printf("%d %d",count[0],count[1]);
    return 0;
}

/*  答案正确，但是大数据的时候运行超时

int main(void)
{
    char ch; // 定义输入字符
    int res=0; //定义字符相加结果
    while (scanf("%c",&ch) && ch!='\n')
    {
        if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))
        {
            ch = tolower(ch);  //tolower()是有返回值的
            res+=(ch-'a'+1); //使a-z代表1-26
        }
    }
    int total_1 = 1 ,total_0 = 0 ;  //分别代表res转化为二进制时1，0的个数
    while(res!=1) //最后的余数一定为1
    {
        if(res%2==1)
            total_1++;
        else
            total_0++;
        res = res/2;
    }
    printf("%d %d\n",total_0,total_1);
    return 0;
}
*/
