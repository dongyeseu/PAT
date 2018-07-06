/*
1017 A除以B (20)（20 分）
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：

123456789050987654321 7
输出样例：

17636684150141093474 3
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string num;
    int N;
    cin>>num>>N;
    int i = 0,complement = 0,divisor;
    char merchant;
    vector<char>res;
    while(i<num.size())
    {
        if(i == 0 && num[i] - '0' < N && num.size()>1)
        {
            divisor = num[i++]-'0';
            divisor = num[i++]-'0' + divisor *10;
        }
        else
            divisor = complement*10 + num[i++] - '0';
        merchant = divisor/N + '0';
        res.push_back(merchant);
        complement = divisor % N;
    }
    for(char ch : res)
        cout<<ch;
    cout<<" "<<complement<<"\n";
    return 0;
}

//他山之玉
柳婼 の blog
#include <iostream>
using namespace std;
int main() {
    string s;
    int a, t = 0, temp = 0;
    cin >> s >> a;
    int len = s.length();
    t = (s[0] - '0') / a;
    if ((t != 0 && len > 1) || len == 1)
        cout << t;
    temp = (s[0] - '0') % a;
    for (int i = 1; i < len; i++) {
        t = (temp * 10 + s[i] - '0') / a;
        cout << t;
        temp = (temp * 10 + s[i] - '0') % a;
    }
    cout << " " << temp;
    return 0;
}
