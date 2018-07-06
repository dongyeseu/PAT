/*
1006 换个格式输出整数 (15)（15 分）
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（&lt10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（&lt1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：

234
输出样例1：

BBSSS1234
输入样例2：

23
输出样例2：

SS123
*/
#include <iostream>
#include <string>
using namespace std;

void Bai(int n)
{
    int i;
    for(i=0 ; i<n ; i++)
        cout<<"B";
}

void Shi(int n)
{
    int i;
    for(i=0 ; i<n ; i++)
        cout<<"S";
}
void Ge(int n)
{
    int i;
    for(i=1 ; i<=n ; i++)
        cout<<i;
}

int main()
{
    string num;
    cin>>num;
    int m = num.size();
    switch(m)
    {
    case 3:
        Bai(num[0]-'0');
        Shi(num[1]-'0');
        Ge(num[2]-'0');
        break;
    case 2:
        Shi(num[0]-'0');
        Ge(num[1]-'0');
        break;
    case 1:
        Ge(num[0]-'0');
        break;

    }
    return 0;
}


//他山之玉
柳婼 の blog
#include <iostream>
using namespace std;
int main() {
    int a, i = 0;
    cin >> a;
    int b[3] = {0};
    while (a != 0) {
        b[i++] = a % 10;
        a = a / 10;
    }
    for (int k = 0; k < b[2]; k++)
        cout << "B";
    for (int k = 0; k < b[1]; k++)
        cout << "S";
    for (int k = 0; k < b[0]; k++)
        cout << k + 1;
    return 0;
}
