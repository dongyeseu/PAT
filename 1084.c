/*
时间：2018/7/2
作者：楼浩然
题目：
1084 外观数列（20 分）
外观数列是指具有以下特点的整数序列：

d, d1, d111, d113, d11231, d112213111, ...
它从不等于 1 的数字 d 开始，序列的第 n+1 项是对第 n 项的描述。比如第 2 项表示第 1 项有 1 个 d，所以就是 d1；第 2 项是 1 个 d（对应 d1）和 1 个 1（对应 11），所以第 3 项就是 d111。又比如第 4 项是 d113，其描述就是 1 个 d，2 个 1，1 个 3，所以下一项就是 d11231。当然这个定义对 d = 1 也成立。本题要求你推算任意给定数字 d 的外观数列的第 N 项。

输入格式：
输入第一行给出 [0,9] 范围内的一个整数 d、以及一个正整数 N（≤ 40），用空格分隔。

输出格式：
在一行中给出数字 d 的外观数列的第 N 项。

输入样例：
1 8
输出样例：
1123123111
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * Appearance(char * m)
{
    int len = strlen(m);
    char * p = malloc(sizeof(char)*len*2);
    int count=1;
    int j = 0;
    int i;
    for(i=0 ; i<len-1 ; i++)
    {
        if(m[i]!=m[i+1])
        {
            p[j++] = m[i];
            p[j++] = count + '0';
            count = 1;
        }
        else
        {
            count++;
        }
    }
    if(m[len-1]==m[len-2])
    {
        p[j++] = m[len-1];
        p[j++] = count + '0';
        p[j] = '\0';
    }
    else
    {
        p[j++] = m[len-1];
        p[j++] = '1';
        p[j] = '\0';
    }
    return p;
}

int main(void)
{
    char d[10];
    int N;
    scanf("%s %d",d,&N);
    char * p;
    if(N==1)
        p = d;
    else if(N>=2)
        p = Appearance(d);
    int i;
    for(i=1 ; i<N-1 ; i++)
    {
        p = Appearance(p);
    }
    printf("%s\n",p);

    return 0;
}

/*
1.malloc内存分配；字符串中重复字符数量的判断
2.第一项是没有经过Appearance()函数的
*/
