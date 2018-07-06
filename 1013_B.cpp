/*
1013 数素数 (20)（20 分）
令P~i~表示第i个素数。现任给两个正整数M <= N <= 10^4^，请输出P~M~到P~N~的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从P~M~到P~N~的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：

5 27
输出样例：

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool IsPrime(int m)      //判断是否为素数的快速方法
{
    int item = (int)sqrt(m) + 1;
    int j;
    if(m<=1)
        return false;
    else if(m==2 || m==3)
        return true;
    else if(m%6 != 1 && m%6 != 5)
        return false;
    for(j=5 ; j<=item ; j+=6)
    {
        if(m%j==0 || m%(j+2)==0)
            return false;
    }
    return true;
}

int main()
{
    int i,j;
    cin>>i>>j;
    vector<int>prime;
    int cnt = 0;
    int n = 2;
    while(cnt<j)
    {
        if(IsPrime(n))
        {
            prime.push_back(n);
            cnt++;
        }
        n++;
    }
    int z;
    cnt = 0;
    for(z=i-1 ; z<j-1 ; z++)
    {
        cnt++;
        if(cnt%10!=0)
            cout<<prime[z]<<" ";
        else
            cout<<prime[z]<<"\n";
    }
    cout<<prime[j-1]<<"\n";
    return 0;
}

//他山之玉
柳婼 の blog
#include <iostream>
#include <vector>
using namespace std;
bool isprime(int a) {
    for (int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}
int main() {
    int M, N, num = 2, cnt = 0;
    cin >> M >> N;
    vector<int> v;
    while (cnt < N) {
        if (isprime(num)) {
            cnt++;
            if (cnt >= M) v.push_back(num);
        }
        num++;
    }
    cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        cnt++;
        if (cnt % 10 != 1) printf(" ");
        printf("%d", v[i]);
        if (cnt % 10 == 0) printf("\n");
    }
    return 0;
}
