/*
时间：2018/6/27 09点35分
作者：楼浩然
题目：
1014 福尔摩斯的约会 (20)（20 分）
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：

3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
输出样例：

THU 14:04
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char Time[4][61];
    int i;
    for(i=0 ; i<4 ; i++)
        scanf("%s",&Time[i]);
    char week[7][4] = {{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"},{"SUN"}};
  //  for(i=0 ; i<7 ; i++)            //验证week输入是否有误
  //      printf("%s\n",week[i]);
    char ch1,ch2; //分别用于返回week和hour所代表的字母；
    int j;
    int dot = -1;
    int lenA = strlen(Time[0]),lenB = strlen(Time[1]),lenC = strlen(Time[2]),lenD = strlen(Time[3]);
    for(i=0 ; i<lenA ; i++)
    {
        if(Time[0][i]>='A' && Time[0][i]<='G')
        {
            if(Time[0][i] == Time[1][i])
            {
                    ch1 = Time[0][i];
                    break;

            }
        }
    }
    for(j=i+1 ; j<lenA ; j++)
    {
        if((Time[0][j]>='A'&&Time[1][j]<='N')||(Time[0][j]>='0'&&Time[0][j]<='9'))
        {

            if(Time[0][j] == Time[1][j] && j!=dot)
            {
                ch2 = Time[0][j];
                break;
            }

        }
    }
    int h;
    if(ch2>='A'&&ch2<='N')
    {
        h = ch2-'A'+10;
    }
    else
    {
        h = ch2-'0';
    }
    int w = ch1-'A';
//    printf("%c %c",ch1,ch2);
    dot = -1;
    for(i=0 ; i<lenC ; i++)
    {
        if((Time[2][i]>='A'&&Time[2][i]<'Z')||(Time[2][i]>='a'&&Time[2][i]<='z'))
        {
            if(Time[2][i] == Time[3][i])
            {
                dot = i;
                break;
            }
        }
    }
    printf("%s %02d:%02d",week[w],h,dot);


    return 0;
}
