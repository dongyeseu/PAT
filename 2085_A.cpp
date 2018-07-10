/*
1085 Perfect Sequence (25)（25 分）
Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 10^5^) is the number of integers in the sequence, and p (<= 10^9^) is the parameter. In the second line there are N positive integers, each is no greater than 10^9^.

Output Specification:

For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:

10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:

8
*/

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return a < b;
}
int main()
{
    long long N,P;
    cin>>N>>P;
    vector<long long>num;
    int i;
    int temp;
    for(i=0 ; i<N ; i++)
    {
        cin>>temp;
        num.push_back(temp);
    }
    sort(num.begin(),num.end(),cmp);
    int cnt = 0;
    int j;
    for(i=0 ,j=0; j<N ; i++)
    {

        while(j < N && num[j]<=num[i]*P)
            j++;
        if(cnt < j-i)
            cnt = j-i;
    }
    cout<<cnt;
    return 0;
}


//他山之玉
//柳婼
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
 
int main() {
	int n;
	long long p;
	cin >> n >> p;
	if (n == 0) {
		cout << n;
		return 0;
	}
	long long int *a = new long long int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int result = 1;
	for (int i = 0; i < n; i++) {
		result = max((int)(upper_bound(a, a+n, a[i] * p) - (a+i)), result);
	}
	cout << result;
	return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    long long p;
    scanf("%d%lld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int result = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + result; j < n; j++) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > result)
                    result = temp;
            } else {
                break;
            }
        }
    }
    cout << result;
    return 0;
}
