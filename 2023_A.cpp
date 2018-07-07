/*
1023 Have Fun with Numbers (20)（20 分）
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:

1234567899
Sample Output:

Yes
2469135798
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    string origin;
    cin>>origin;
    string res = origin;
    int mid = 0;
    int lgt = origin.size();
    int i;
    for(i=lgt-1 ; i>=0 ; i--)
    {
        int R = (origin[i]-'0')*2 + mid;
        origin[i] = R%10 + '0';
        mid = R/10;
    }
    if(mid!=0)
    {
        cout<<"No\n";
        printf("%c",mid+'0');
        cout<<origin<<"\n";
    }
    else
    {
        string ori = origin;
        sort(origin.begin(),origin.end(),cmp);
        sort(res.begin(),res.end(),cmp);
   //     cout<<origin<<"\n"<<res<<"\n";
        if(res==origin)
            cout<<"Yes\n"<<ori<<"\n";
        else
            cout<<"No\n"<<ori<<"\n";
    }
    return 0;
}

//他山之玉
柳婼
#include <cstdio>
#include <string.h>
using namespace std;
int book[10];
int main() {
    char num[22];
    scanf("%s", num);
    int flag = 0, len = strlen(num);
    for(int i = len - 1; i >= 0; i--) {
        int temp = num[i] - '0';
        book[temp]++;
        temp = temp * 2 + flag;
        flag = 0;
        if(temp >= 10) {
            temp = temp - 10;
            flag = 1;
        }
        num[i] = (temp + '0');
        book[temp]--;
    }
    int flag1 = 0;
    for(int i = 0; i < 10; i++) {
        if(book[i] != 0)
            flag1 = 1;
    }
    printf("%s", (flag == 1 || flag1 == 1) ? "No\n" : "Yes\n");
    if(flag == 1) printf("1");
    printf("%s", num);
    return 0;
}
