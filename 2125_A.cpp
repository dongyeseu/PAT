/*
1125 Chain the Ropes（25 分）
Given some segments of rope, you are supposed to chain them into one rope. Each time you may only fold two segments into loops and chain them into one piece, as shown by the figure. The resulting chain will be treated as another segment of rope and can be folded again. After each chaining, the lengths of the original two segments will be halved.

rope.jpg

Your job is to make the longest possible rope out of N given segments.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (2≤N≤10
​4
​​ ). Then N positive integer lengths of the segments are given in the next line, separated by spaces. All the integers are no more than 10
​4
​​ .

Output Specification:
For each case, print in a line the length of the longest possible rope that can be made by the given segments. The result must be rounded to the nearest integer that is no greater than the maximum length.

Sample Input:
8
10 15 12 3 4 13 1 15
Sample Output:
14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int>num(N);
    int i;
    for(i=0 ; i<N ; i++)
        cin>>num[i];
    sort(num.begin(),num.end());
    double res = 0.0;
    for(i=0 ; i<N ; i++)
    {
        if(i==0)
            res = 1.0*num[i];
        else
            res = (res + num[i])/2.0;
    }
    printf("%d",(int)res);
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：给定一段一段的绳子，你需要把它们串成一条绳。每次串连的时候，是把两段绳子对折，再如下图所示套接在一起。这样得到的绳子又被当成是另一段绳子，
可以再次对折去跟另一段绳子串连。每次串连后，原来两段绳子的长度就会减半。给定N段绳子的长度，你需要找出它们能串成的绳子的最大长度~
分析：因为所有长度都要串在一起，每次都等于(旧的绳子长度+新的绳子长度)/2，所以越是早加入绳子长度中的段，越要对折的次数多，所以既然希望绳子长度是最
长的，就必须让长的段对折次数尽可能的短。所以将所有段从小到大排序，然后从头到尾从小到大分别将每一段依次加入结绳的绳子中，最后得到的结果才会是最长的
结果～
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int result = v[0];
    for (int i = 1; i < n; i++)
        result = (result + v[i]) / 2;
    printf("%d", result);
    return 0;
}
