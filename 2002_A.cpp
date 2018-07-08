/*
1002 A+B for Polynomials (25)£¨25 ·Ö£©
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10£¬0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input

2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output

3 2 1.5 1 2.9 0 3.2
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int K1,K2;
    int index1,index2;
    float coef1,coef2;
    float Num[1001] = {0};  //记住必须使用>1000的数
    cin>>K1;
    int i;
    for(i=0 ; i<K1 ; i++)
    {
        cin>>index1>>coef1;
        Num[index1]+=coef1;
    }
    cin>>K2;
    for(i=0 ; i<K2 ; i++)
    {
        cin>>index2>>coef2;
        Num[index2]+=coef2;
    }
    int cnt = 0;
    for(i=1000 ; i>=0 ; i--)
    {
        if(Num[i]!=0)
        {
           cnt++;
        }
    }
    cout<<cnt;
     for(i=1000 ; i>=0 ; i--)
    {
        if(Num[i]!=0.0)
        {
            printf(" %d %.1f",i,Num[i]);
        }
    }
    cout<<"\n";
    return 0;
}

//他山之玉
柳婼
#include <iostream>
using namespace std;
int main() {
    float c[1001] = {0};
    int m, n, t;
    float num;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        if (c[i] != 0) cnt++;
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (c[i] != 0.0)
            printf(" %d %.1f", i, c[i]);
    }
    return 0;
}
