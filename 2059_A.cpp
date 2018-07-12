/*
1059 Prime Factors (25)（25 分）
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p~1~\^k~1~ * p~2~\^k~2~ *…*p~m~\^k~m~.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p~1~\^k~1~ * p~2~\^k~2~ *…*p~m~\^k~m~, where p~i~'s are prime factors of N in increasing order, and the exponent k~i~ is the number of p~i~ -- hence when there is only one p~i~, k~i~ is 1 and must NOT be printed out.

Sample Input:

97532468
Sample Output:

97532468=2^2*11*17*101*1291
*/

//思路：用map来记录出现的素数以及其出现的次数
#include <map>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

bool IsPrime(int m)
{
    int j;
    int temp = (int)sqrt(m)+1;
    if(m<=1)
        return false;
    else if(m==2 || m==3)
        return true;
    else if(m%6!=1 && m%6!=5)
        return false;
    for(j=5 ; j<= temp ; j+=6)
    {
        if(m%(j+2)==0 ||m%j==0)
            return false;
    }
    return true;
}

int main()
{
    long long N;
    scanf("%lld",&N);
    printf("%lld=",N);
    map<int,int>Prime;
    int i;
    for(i=2 ; i<N ; i++)
    {
        if(IsPrime(i))
        {
            while(N%i==0)
            {
                Prime[i]++;
                N /= i;
            }
        }
        if(IsPrime(N))
        {
            Prime[N]++;
            break;
        }
    }
    auto k = Prime.begin(), j = Prime.end();
    if(k==j)
    {
        cout<<N;
        return 0;
    }
    for(;k!=j;k++)
    {
        if(k!=Prime.begin())
            cout<<"*";
        if(k->second!=1)
            cout<<k->first<<"^"<<k->second;
        else
            cout<<k->first;
    }
    return 0;
}

//他山之玉
//柳婼

#include <cstdio>
#include <vector>
using namespace std;
vector<int> prime(500000, 1);
int main() {
    for(int i = 2; i * i < 500000; i++)
        for(int j = 2; j * i < 500000; j++)
            prime[j * i] = 0;
    long int a;
    scanf("%ld", &a);
    printf("%ld=", a);
    if(a == 1) printf("1");
    bool state = false;
    for(int i = 2; a >= 2;i++) {
        int cnt = 0, flag = 0;
        while(prime[i] == 1 && a % i == 0) {
            cnt++;
            a = a / i;
            flag = 1;
        }
        if(flag) {
            if(state) printf("*");
            printf("%d", i);
            state = true;
        }
        if(cnt >= 2)
            printf("^%d", cnt);
    }
    return 0;
}
