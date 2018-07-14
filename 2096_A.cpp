/*
1096 Consecutive Factors (20)（20 分）
Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

Input Specification:

Each input file contains one test case, which gives the integer N (1<N<2^31^).

Output Specification:

For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:

630
Sample Output:

3
5*6*7
*/

#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int max = sqrt(n);
    for(int len = 12; len >= 1; len--) {
        for(int start = 2; start <= max; start++) {
            long long int ans = 1;
            for(int i = start; i - start <= len - 1; i++)
                ans *= i;
            if(n % ans == 0) {
                printf("%d\n%d", len, start);
                for(int i = start + 1; i - start <= len - 1; i++)
                    printf("*%d", i);
                return 0;
            }
        }
    }
    printf("1\n%d", n);
    return 0;
}



#include <iostream>
#include <cmath>
using namespace std;
long int num, temp;
int main(){
    cin >> num;
    int first = 0, len = 0, maxn = sqrt(num);
    for (int i = 2; i <= maxn; i++){
        int j; temp = 1;
        for (j = i; j <= maxn; j++){
            temp *= j;
            if (num % temp != 0) break;
        }
        if (j - i > len){
            len = j - i;
            first = i;
        }
    }
    if (first == 0) cout << 1 << endl << num;
    else {
        cout << len << endl;
        for (int i = 0; i < len; i++){
            cout << first + i;
            if (i != len - 1) cout << '*';
        }
    }
    return 0;
}
