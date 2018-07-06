/*
1007 素数对猜想 (20)（20 分）
让我们定义 d~n~ 为：d~n~ = p~n+1~ - p~n~，其中 p~i~ 是第i个素数。显然有 d~1~=1 且对于n&gt1有 d~n~ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 10^5^)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：

20
输出样例：

4
*/
#include <iostream>
#include <math.h>
using namespace std;

bool Is_Prime(int n)
{
    int i, item = (int)sqrt(n)+1;
    if(n<=1)
        return false;
    else if(n==2 || n==3)
        return true;
    else if(n%6!=1 && n%6!=5)
        return false;
    for(i=5 ; i<=item ; i+=6)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}

int main()
{
    int n,i;
    int Count = 0;
    cin>>n;
    int a,b=2;
    for(i=2 ; i<=n ; i++)
    {
        if(Is_Prime(i))
        {
            a = b;
            b = i;
            if(b-a == 2)
                Count++;
        }
    }
    cout<<Count;
    return 0;

}


//他山之玉
柳婼 の blog
#include <iostream>
using namespace std;
bool isprime(int a) {
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0) return false;
    return true;
}
int main() {
    int N, cnt = 0;
    cin >> N;
    for (int i = 5; i <= N; i++)
        if (isprime(i-2) && isprime(i)) cnt++;
    cout << cnt;
    return 0;
}
