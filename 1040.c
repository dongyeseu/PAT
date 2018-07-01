/*
时间：2018/6/30
作者：楼浩然
题目：
1040 有几个PAT（25）（25 分）
字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。

现给定字符串，问一共可以形成多少个PAT？

输入格式：

输入只有一行，包含一个字符串，长度不超过10^5^，只包含P、A、T三种字母。

输出格式：

在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：

APPAPT
输出样例：

2
*/

//思路：每个A对应的PA组合数量是A之前P的数量；每个T对应的PAT组合数量是T之前所有A对应的PA组合数量的累加；所有的PAT组合数量是所有T对应的PAT组合数量的累加
#include <stdio.h>

#define LIM 1000000007

int main(void)
{
    int P=0,PA=0,PAT=0;
    char ch;
    while((ch=getchar())!='\n')
    {
        if(ch=='P')
        {
            P++;
            P = P % LIM;
        }
        else if(ch == 'A')
        {
            PA = (PA + P)%LIM;
        }
        else
            PAT = (PAT + PA) % LIM;
    }
    printf("%d",PAT);
    return 0;
}




//思路：那么遍历字符串后对于每一A，它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数
/*
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length(), result = 0, countp = 0, countt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'T')
            countt++;
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == 'P') countp++;
        if (s[i] == 'T') countt--;
        if (s[i] == 'A') result = (result + (countp * countt) % 1000000007) % 1000000007;
    }
    cout << result;
    return 0;
}
*/

