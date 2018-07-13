/*
1093 Count PAT's (25)（25 分）
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:

Each input file contains one test case. For each case, there is only one line giving a string of no more than 10^5^ characters containing only P, A, or T.

Output Specification:

For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

Sample Input:

APPAPT
Sample Output:

2
*/

#include <string>
#include <iostream>
using namespace std;
int main()
{
    int num_p=0,num_a=0,res=0;
    string pat;
    cin>>pat;
    auto i = pat.begin() , j = pat.end();
    for( ; i!=j ; i++)
    {
        if(*i == 'P')
            num_p++;
        else if(*i == 'A')
            num_a = (num_a + num_p)%1000000007;
        else if(*i == 'T')
            res = (res+num_a)%1000000007;
    }
    cout<<res;
    return 0;
}


//他山之玉
//柳婼
/*
分析：要想知道构成多少个PAT，那么遍历字符串后对于每一A，它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数。然后把对于每一个A的结果相加即可
~~辣么就简单啦，只需要先遍历字符串数一数有多少个T~~然后每遇到一个T呢~countt–;每遇到一个P呢，countp++;然后一遇到字母A呢就countt * countp~~~把这
个结果累加到result中~~~~最后输出结果就好啦~~对了别忘记要对10000000007取余哦~~~~
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length(), result = 0, countp = 0, countt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'T')
            countt++;
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == 'P') countp++;
        if (s[i] == 'T') countt--;
        if (s[i] == 'A') result = (result + (countp * countt) % 1000000007) % 1000000007;
    }
    cout << result;
    return 0;
}
