/*
1038 Recover the Smallest Number (30)（30 分）
Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.

Input Specification:

Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the smallest number in one line. Do not output leading zeros.

Sample Input:

5 32 321 3214 0229 87
Sample Output:

22932132143287
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<string>num;
    int i;
    for(i=0 ; i<N ; i++)
    {
        string temp;
        cin>>temp;
        num.push_back(temp);
    }
    sort(num.begin(),num.end());
    for(i=0 ; i<N-1 ; i++)
    {
        if(num[i]+num[i+1] > num[i+1]+num[i])
            swap(num[i],num[i+1]);
    }
    string res = "";
    for(i=0 ; i<N ; i++)
        res+=num[i];
    auto j = res.begin();
    while(*j=='0')
        j = res.erase(j);
    if(res.size() == 0)
        cout<<"0";
    else
        cout<<res;
    return 0;
}
