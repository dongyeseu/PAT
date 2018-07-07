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
