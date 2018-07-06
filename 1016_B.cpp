/*
1016 部分A+B (15)（15 分）
正整数A的“D~A~（为1位整数）部分”定义为由A中所有D~A~组成的新整数P~A~。例如：给定A = 3862767，D~A~ = 6，则A的“6部分”P~A~是66，因为A中有2个6。

现给定A、D~A~、B、D~B~，请编写程序计算P~A~ + P~B~。

输入格式：

输入在一行中依次给出A、D~A~、B、D~B~，中间以空格分隔，其中0 < A, B < 10^10^。

输出格式：

在一行中输出P~A~ + P~B~的值。

输入样例1：

3862767 6 13530293 3
输出样例1：

399
输入样例2：

3862767 1 13530293 8
输出样例2：

0
*/

#include <iostream>
using namespace std;
int main()
{
    string num1,num2;
    char i1,i2;
    cin>>num1>>i1>>num2>>i2;
    int res_1 = 0,res_2 = 0;
    int i;
    for(i=0 ; i<num1.size() ; i++)
    {
        if(num1[i] == i1)
            res_1 = res_1*10 + (i1 - '0');
    }
    for(i=0 ; i<num2.size() ; i++)
    {
        if(num2[i] == i2)
            res_2 = res_2*10 + (i2 - '0');
    }
    cout<<res_1+res_2;
    return 0;

}

//他山之玉
柳婼 の blog
#include <iostream>
using namespace std;
int main() {
    string a, b;
    int m, n, counta = 0, countb = 0, ta = 0, tb = 0;
    cin >> a >> m >> b >> n;
    for (int i = 0; i < a.length(); i++)
        if (m == (a[i] - '0')) counta++;
    for (int i = 0; i < b.length(); i++)
        if (n == (b[i] - '0')) countb++;
    if (counta != 0) ta = m;
    if (countb != 0) tb = n;
    for (int i = 1; i < counta; i++)
        ta = 10 * ta + m;
    for (int i = 1; i < countb; i++)
        tb = 10 * tb + n;
    cout << ta + tb;
    return 0;
}
