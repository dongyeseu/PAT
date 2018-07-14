/*
1040 Longest Symmetric String (25)（25 分）
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.

Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:

For each test case, simply print the maximum length in a line.

Sample Input:

Is PAT&TAP symmetric?
Sample Output:

11
*/
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string pat;
    getline(cin,pat);
    int num = pat.size();
    int max_length = num;
    int cnt = 0;
    for(;max_length>=1;max_length--)
    {
        int i,j;
        for(i=0 , j=i+max_length-1 ; j<=num-1 ; i++,j++)
        {
            int flag = 0;
            int z,k;
            for(z=i,k=j ;z<k ; z++,k--)
            {
                if(pat[z]!=pat[k])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            {
                cnt = max_length;
                break;
            }
        }
        if(cnt!=0)
            break;
    }
    cout<<cnt;
    return 0;
}


//他山之玉
//柳婼
/*
dp[i][j]表示s[i]到s[j]所表示的字串是否是回文字串。只有0和1
递推方程：
当s[i] == s[j] : dp[i][j] = dp[i+1][j-1]
当s[i] != s[j] : dp[i][j] =0
边界：dp[i][i] = 1, dp[i][i+1] = (s[i] == s[i+1]) ? 1 : 0
因为i、j如果从小到大的顺序来枚举的话，无法保证更新dp[i][j]的时候dp[i+1][j-1]已经被计算过。因此不妨考虑按照字串的长度和子串的初试位置进行枚举，即第一遍将长度为3的子串的dp的值全部求出，第二遍通过第一遍结果计算出长度为4的子串的dp的值…这样就可以避免状态无法转移的问题
首先初始化dp[i][i] = 1, dp[i][i+1]，把长度为1和2的都初始化好，然后从L = 3开始一直到 L <= len 根据动态规划的递归方程来判断
*/
#include <iostream>
using namespace std;
int dp[1010][1010];
int main() {
    string s;
    getline(cin, s);
    int len = s.length(), ans = 1;
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if(i < len - 1 && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    for(int L = 3; L <= len; L++) {
        for(int i = 0; i + L - 1 < len; i++) {
            int j = i + L -1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
