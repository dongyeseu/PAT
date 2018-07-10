/*
1081 Rational Sum (20)（20 分）
Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

Input Specification:

Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:

For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

Sample Input 1:

5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:

3 1/3
Sample Input 2:

2
4/3 2/3
Sample Output 2:

2
Sample Input 3:

3
1/3 -1/6 1/8
Sample Output 3:

7/24
*/


//答案错误，浮点错误，格式错误，呵呵呵
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

long long Euclid(long long m, long long n)
{
    long long res;
    while(n>0)
    {
        res = m%n;
        m = n;
        n = res;
    }
    return m;
}

int main()
{
    int N;
    cin>>N;
    vector<long long>fenzi(N);
    vector<long long>fenmu(N);
    int i;
    for(i=0 ; i<N ; i++)
        scanf("%lld/%lld",&fenzi[i],&fenmu[i]);
    long long Ji = 1;
    for(i=0 ; i<N ; i++)
        Ji *= fenmu[i];
    long long sum = 0;
    for(i=0 ; i<N ; i++)
        sum += fenzi[i] * Ji /fenmu[i];
    long long Inter = sum / Ji;
    if(Inter > 0)
        cout<<Inter<<" ";
    sum = sum%Ji;
    if(sum!=0)
    {
        long long m = Euclid(sum,Ji);
        if(m!=0)
            printf("%lld/%lld",sum/m,Ji/m);
        else
            printf("%lld/%lld",sum,Ji);
    }
    else if(sum==0&&Inter==0)
        cout<<"0";
    return 0;
}
