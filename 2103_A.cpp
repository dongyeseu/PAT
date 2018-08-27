/*
The K−P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K−P factorization of N for any positive integers N, K and P.

Input Specification:
Each input file contains one test case which gives in a line the three positive integers N (≤400), K (≤N) and P (1<P≤7). The numbers in a line are separated by a space.

Output Specification:
For each case, if the solution exists, output in the format:

N = n[1]^P + ... n[K]^P
where n[i] (i = 1, ..., K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 12

If there is no solution, simple output Impossible.
Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible
*/
#include <math.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>value,ans,tempans;
int n,k,p,maxFacSum = -1;

void init()
{
    int index = 1,temp=0;
    while(temp<=n)
    {
        value.push_back(temp);
        temp = pow(index,p);
        index++;
    }
}

void dfs(int index,int tempsum ,int tempk, int factorsum)
{
    if(tempk==k)
    {
        if(factorsum > maxFacSum && tempsum == n)
        {
            maxFacSum = factorsum;
            ans = tempans;
        }
        return ;
    }
    while(index>=1)
    {
        if(tempsum + value[index]<=n)
        {
            tempans[tempk] = index;
            dfs(index,tempsum+value[index],tempk+1,factorsum+index);
        }
        if(index==1)
            return;
        index--;
    }
}

int main()
{
    scanf("%d %d %d",&n,&k,&p);
    init();
    tempans.resize(k);
    dfs(value.size()-1,0,0,0);
    if(maxFacSum == -1)
        cout<<"Impossible\n";
    else
    {
        printf("%d = %d^%d",n,ans[0],p);
        int i, len = ans.size();
        for(i=1 ; i<len ; i++)
            printf(" + %d^%d",ans[i],p);
        cout<<"\n";
    }
    return 0;
}



//只能应对一些特殊情况，有一个测试点过不去
/*
#include <math.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int N,K,P;
    scanf("%d %d %d",&N,&K,&P);
    int N_ = N;
    vector<int>Res;
    while(K)
    {
        int temp = N/K;
        int a = (pow(temp+1,1.0/P) + pow(temp-1,1.0/P) + pow(temp,1.0/P))/3.0+0.4;

        Res.push_back(a);
        N -= pow(a,P);
        K--;
    }
    sort(Res.begin(),Res.end(),cmp);
    if(N==0)
    {
        printf("%d = %d^%d",N_,Res[0],P);
        int i, len = Res.size();
        for(i=1 ; i<len ; i++)
            printf(" + %d^%d",Res[i],P);
        cout<<"\n";
    }
    else
        cout<<"Impossible";
    return 0;
}
*/
