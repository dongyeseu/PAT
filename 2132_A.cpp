/*
1132 Cut Integer（20 分）
Cutting an integer means to cut a K digits lone integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 × 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20). Then N lines follow, each gives an integer Z (10 ≤ Z <2
​31
​​ ). It is guaranteed that the number of digits of Z is an even number.

Output Specification:
For each case, print a single line Yes if it is such a number, or No if not.

Sample Input:
3
167334
2333
12345678
Sample Output:
Yes
No
No
*/

#include <string>
#include <iostream>
#include <cctype>
#include <climits>
#include <cstdio>
#include <stdlib.h>
using namespace std;
void IsCut(string m)
{
    int len = m.size();
    int k = len/2;
    auto j = m.begin();
    string a = m.substr(0,k);
  //  cout<<a<<"\n";
    string b = m.substr(k,len);
   // cout<<b<<"\n";
    long long int a_ = atoi(a.c_str());
    long long int b_ = atoi(b.c_str());
    long long int m_ = atoi(m.c_str());
    if(a_*b_==0)
        cout<<"No";
    else if(m_%(a_*b_)==0)
        cout<<"Yes";
    else
        cout<<"No";
}
int main()
{
    int N;
    cin>>N;
    int i;
    for(i=0 ; i<N ; i++)
    {
        string temp;
        cin>>temp;
        IsCut(temp);
        cout<<"\n";
    }
    return 0;
}

//他山之玉
//柳婼
/*
题目大意：给一个偶数个位的正整数num，把它从中间分成左右两个整数a、b，问num能不能被a和b的乘积整除，能的话输出yes，不能的话输出no

分析：要注意a*b如果为0的时候不能取余，否则会浮点错误～
直接用int保存num的值，计算出num的长度len，则令d = pow(10, len / 2)时，num取余d能得到后半部分的整数，num除以d能得到前半部分的整数，计算
num % (a*b)是否等于0就可以得知是否可以被整除～
*/
#include <iostream>
using namespace std;
int main() {
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        string s = to_string(num);
        int len = s.length();
        int a = stoi(s.substr(0, len/2));
        int b = stoi(s.substr(len/2));
        if (a * b != 0 && num % (a * b) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
