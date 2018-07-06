/*
1011 A+B和C (15)（15 分）
给定区间[-2^31^, 2^31^]内的3个整数A、B和C，请判断A+B是否大于C。

输入格式：

输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。

输出格式：

对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。

输入样例：

4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
输出样例：

Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/
#include <iostream>
#include <vector>
using namespace std;
bool IsHigher(long a,long b,long c)
{
    if(a + b > c)
        return true;
    else
        return false;
}

int main()
{
    int N;
    cin>>N;
    long a,b,c;
    int i;
    vector<int>res;
    for(i=0 ; i<N ; i++)
    {
        cin>>a>>b>>c;
        if(IsHigher(a,b,c))
            res.push_back(1);
        else
            res.push_back(0);
    }
    i = 1;
    for(int j : res)
    {
        if(j)
            cout<<"Case #"<<i++<<": true"<<"\n";
        else
            cout<<"Case #"<<i++<<": false"<<"\n";
    }
    return 0;

}

//记住：C++中也是可以用C的输入和输出格式的
//他山之玉
柳婼 の blog
#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: %s\n", i + 1, a + b > c ? "true" : "false");
    }
    return 0;
}
