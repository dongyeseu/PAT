#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int N;
    scanf("%d",&N);
    vector<int>Coupon;
    int i;
    int temp;
    for(i=0 ; i<N ; i++)
    {
        scanf("%d",&temp);   //记得使用scanf，如果使用cin会导致运行超时
        Coupon.push_back(temp);
    }
    int K;
    scanf("%d",&K);
    vector<int>Product;
    for(i=0 ; i<K ; i++)
    {
        scanf("%d",&temp);
        Product.push_back(temp);
    }
    sort(Coupon.begin(),Coupon.end(),cmp);
    sort(Product.begin(),Product.end(),cmp);
    int M = N<=K?N:K;
    int res = 0;
    for(i=0 ; i<M ; i++)
    {
        if(Coupon[i]>0 && Product[i]>0)
            res += Coupon[i]*Product[i];
        else
            break;
    }
    while(Coupon[--N]<0 && Product[--K]<0)
        res += Coupon[N]*Product[K];
    cout<<res;
    return 0;
}


//他山之玉
//柳婼

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int m, n, ans = 0, p = 0, q = 0;
    scanf("%d", &m);
    vector<int> v1(m);
    for(int i = 0; i < m; i++)
        scanf("%d", &v1[i]);
    scanf("%d", &n);
    vector<int> v2(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v2[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    while(p < m && q < n && v1[p] < 0 && v2[q] < 0) {
        ans += v1[p] * v2[q];
        p++; q++;
    }
    p = m - 1, q = n - 1;
    while(p >= 0 && q >= 0 && v1[p] > 0 && v2[q] > 0) {
        ans += v1[p] * v2[q];
        p--; q--;
    }
    printf("%d", ans);
    return 0;
}
