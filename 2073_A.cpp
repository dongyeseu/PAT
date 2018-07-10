/*
1073 Scientific Notation (20)（20 分）
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,

Sample Input 1:

+1.23400E-03
Sample Output 1:

0.00123400
Sample Input 2:

-1.2E+10
Sample Output 2:

-12000000000
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    string num;
    cin>>num;
    char flag_1 = num[0];
    char flag_2;
    int len = num.size();
    string N = "";
    int i;
    for(i=1 ; i<len ; i++)
    {
        if(num[i]=='+' || num[i] == '-')
        {
            flag_2 = num[i];
            break;
        }
        else if(num[i]!='E')
            N += num[i];

    }
    string n="";
    for(i++;i<len;i++)
    {
        n+=num[i];
    }

    if(flag_2 == '-')
    {
        int n_ = atoi(n.c_str());
        N.erase(remove(N.begin(),N.end(),'.'),N.end());
        int j;
        if(flag_1 =='-')
            cout<<"-";
        for(j=0;j<n_;j++)
        {
            if(j==0)
                cout<<"0.";
            else
                cout<<"0";
        }
        cout<<N;
    }
    else
    {
        int n_ = atoi(n.c_str());
        int s = N.size();
        int j;
        int cnt = 0;
        for(j=s-1 ; j>=0 ; j--)
        {
            if(N[j]!='.')
                cnt++;
            else
                break;
        }
        N.erase(remove(N.begin(),N.end(),'.'),N.end());
        if(flag_1 == '-')
                cout<<"-";
        if(n_>=cnt)
        {
            int mid = n_ - cnt;
            cout<<N;
            int h;
            for(h=0 ; h<mid ; h++)
                cout<<"0";
        }
        else
        {
            int h;
            for(i=0 ; i<n_+1 ; i++)
                cout<<N[i];
            cout<<".";
            for(;i<cnt+1 ; i++)
                cout<<N[i];
        }
    }
    return 0;
}


//他山之玉
//柳婼
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    if (s[0] == '-') cout << "-";
    int pose = 0;
    for (int i = 1; i < len; i++)
        if (s[i] == 'E') pose = i;
    int after = 0;
    for (int i = pose + 2; i < len; i++)
        after = (s[i] - '0') + 10 * after;
    if (s[pose + 1] == '-') {
        if (0 < after) {
            cout << "0.";
            for (int i = 1; i < after; i++)
                cout << 0;
            for (int i = 1; i < pose; i++)
                if (isdigit(s[i])) cout << s[i];
        } else {
            for (int i = 1; i < pose; i++) {
                if (i == 2 - after) cout << ".";
                if (isdigit(s[i])) cout << s[i];
            }
        }
    } else {
        if (pose - 3 < after) {
            if (s[1] != '0') cout << s[1];
            for (int i = 3; i < pose; i++)
                if (isdigit(s[i])) cout << s[i];
            for (int i = 0; i < after - (pose - 3); i++)
                cout << 0;
        } else {
            if (s[1] != '0') cout << s[1];
            for (int i = 3; i < pose; i++) {
                if (i == 3 + after) cout << ".";
                if (isdigit(s[i])) cout << s[i];
            }
        }
    }
    return 0;
}
