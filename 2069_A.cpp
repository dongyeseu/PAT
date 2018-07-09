/*
1069 The Black Hole of Numbers (20)（20 分）
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089\ 9810 - 0189 = 9621\ 9621 - 1269 = 8352\ 8532 - 2358 = 6174\ 7641 - 1467 = 6174\ ... ...

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range (0, 10000).

Output Specification:

If all the 4 digits of N are the same, print in one line the equation "N

N = 0000". Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.
Sample Input 1:

6767
Sample Output 1:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:

2222
Sample Output 2:

2222 - 2222 = 0000
*/
//思路一：string型计算
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    string num;
    cin>>num;
    num.insert(num.begin(),4-num.size(),'0');
    do
    {
        string num1 = num ,num2 = num;
        sort(num1.begin(),num1.end(),cmp);
        sort(num2.begin(),num2.end());
        int res = stoi(num1) - stoi(num2);
        num = to_string(res);
        num.insert(num.begin(),4-num.size(),'0');
        cout<<num1<<" - "<<num2<<" = "<<num<<"\n";
    }while(num!="6174" || num!="0000");
    return 0;
}

//思路二：int型计算
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(char a,char b)
{
    return a>b;
}
bool cop(char a,char b)
{
    return a<b;
}
int Max(int n)
{
    vector<int>num;
    while(n)
    {
        num.push_back(n%10);
        n/=10;
    }
    sort(num.begin(),num.end(),cmp);
    int res = 0;
    for(int i : num)
        res = res*10 + i;
    return res;
}
int Min(int n)
{
    vector<int>num;
    while(n)
    {
        num.push_back(n%10);
        n/=10;
    }
    sort(num.begin(),num.end(),cop);
    int res = 0;
    for(int i : num)
        res = res*10 + i;
    return res;
}
int buqi(int n)
{
    while(n<1000)
        n *= 10;
    return n;
}
int main()
{
    int num;
    cin>>num;
    do
    {
        num = buqi(num);
        int max_num = Max(num);
        int min_num = Min(num);
        num = max_num - min_num;
        printf("%04d - %04d = %04d\n",max_num,min_num,num);
    }while(num!=6174&&num!=0);
    return 0;
}


//他山之玉
柳婼
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(char a, char b) {return a > b;}
int main() {
    string s;
    cin >> s;
    s.insert(0, 4 - s.length(), '0');
    do {
        string a = s, b = s;
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end());
        int result = stoi(a) - stoi(b);
        s = to_string(result);
        s.insert(0, 4 - s.length(), '0');
        cout << a << " - " << b << " = " << s << endl;
    } while (s != "6174" && s != "0000");
    return 0;
}
