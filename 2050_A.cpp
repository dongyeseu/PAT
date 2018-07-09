/*
1050 String Subtraction (20)（20 分）
Given two strings S~1~ and S~2~, S = S~1~ - S~2~ is defined to be the remaining string after taking all the characters in S~2~ from S~1~. Your task is simply to calculate S~1~ - S~2~ for any given strings. However, it might not be that simple to do it fast.

Input Specification:

Each input file contains one test case. Each case consists of two lines which gives S~1~ and S~2~, respectively. The string lengths of both strings are no more than 10^4^. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:

For each test case, print S~1~ - S~2~ in one line.

Sample Input:

They are students.
aeiou
Sample Output:

Thy r stdnts.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string line;
    string line2;
    getline(cin,line);
    getline(cin,line2);
    int len = line2.size();
    int i;
    for(i=0 ; i<len ; i++)
        line.erase(remove(line.begin(),line.end(),line2[i]),line.end());  //删除字符串中特定字符的方法
    cout<<line<<"\n";
    return 0;
}

//他山之玉
//柳婼
/*
题目大意：给出两个字符串，在第一个字符串中删除第二个字符串中出现过的所有字符并输出。
分析：用flag[256]数组变量标记str2出现过的字符为true，输出str1的时候根据flag[str1[i]]是否为true,如果是true就不输出

使用：int lens1 = strlen(s1);
int lens2 = strlen(s2);否则直接放在for循环里面会超时~
使用gets前面请使用char str[100000]而非char *str~~~
/*
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char s1[100000], s2[100000];
int main() {
    cin.getline(s1, 100000);
    cin.getline(s2, 100000);
    int lens1 = strlen(s1), lens2 = strlen(s2);
    bool flag[256] = {false};
    for(int i = 0; i < lens2; i++)
        flag[s2[i]] = true;
    for(int i = 0; i < lens1; i++) {
        if(!flag[s1[i]])
            printf("%c", s1[i]);
    }
    return 0;
}
