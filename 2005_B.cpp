/*
1005 Spell It Right (20)（20 分）
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100^).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:

12345
Sample Output:

one five
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string num[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string N;
    cin>>N;
    int sum = 0;
    for(char ch:N)
        sum += (ch - '0');
    stack<int>res;
    if(sum==0)
        res.push(sum);
    while(sum)
    {
        res.push(sum%10);
        sum /= 10;
    }
    while(!res.empty())
    {
        cout<<num[res.top()];
        res.pop();
        if(res.empty())
            cout<<"\n";
        else
            cout<<" ";
    }
    return 0;
}


//他山之玉
柳婼
#include <iostream>
using namespace std;
int main() {
    string a;
    cin >> a;
    int sum = 0;
    for (int i = 0; i < a.length(); i++)
        sum += (a[i] - '0');
    string s = to_string(sum);
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << arr[s[0] - '0'];
    for (int i = 1; i < s.length(); i++)
        cout << " " << arr[s[1] - '0'];
    return 0;
}
