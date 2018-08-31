/*
1015 Reversible Primes (20)（20 分）
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 10^5^) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:

73 10
23 2
23 10
-2
Sample Output:

Yes
Yes
No
*/
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool IsPrime(int m)    //标准的判断是否为素数的方法，很快捷
{
    int item = (int)sqrt(m)+1;
    int k;
    if(m<=1)
        return false;
    else if(m==2 || m==3)
        return true;
    else if(m%6!=1 && m%6!=5)
        return false;
    for(k=5 ; k<=item ; k+=6)
    {
        if(m%k==0 || m%(k+2) == 0)
            return false;
    }
    return true;
}

int zhuan_huan(int N,int D)
{
    vector<int>res;
    while(N)
    {
        res.push_back(N%D);
        N /= D;
    }
    int R = 0;
    int i;
    for(i=0 ; i<res.size() ; i++)
        R = R*D + res[i];
    return R;
}

int main()
{
    int N,D;
    cin>>N;
    while(N>=0)
    {
        int n = 0;
        cin>>D;
        if(IsPrime(N))
            n++;
        N = zhuan_huan(N,D);
        if(IsPrime(N))
            n++;
        if(n==2)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        cin>>N;
    }
    return 0;
}


//他山之玉
柳婼
#include <cstdio>
#include <cmath>
using namespace std;
bool isprime(int n) {
    if(n <= 1) return false;
    int sqr = int(sqrt(n * 1.0));
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
int main() {
    int n, d;
    while(scanf("%d", &n) != EOF) {
        if(n < 0) break;
        scanf("%d", &d);
        if(isprime(n) == false) {
            printf("No\n");
            continue;
        }
        int len = 0, arr[100];
        do{
            arr[len++] = n % d;
            n = n / d;
        }while(n != 0);
        for(int i = 0; i < len; i++)
            n = n * d + arr[i];
        printf("%s", isprime(n) ? "Yes\n" : "No\n");
    }
    return 0;
}
