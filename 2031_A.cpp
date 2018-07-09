/*
1031 Hello World for U (20)（20 分）
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:

h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n~1~ characters, then left to right along the bottom line with n~2~ characters, and finally bottom-up along the vertical line with n~3~ characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n~1~ = n~3~ = max { k| k <= n~2~ for all 3 <= n~2~ <= N } with n~1~

n~2~ + n~3~ - 2 = N.
Input Specification:

Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

Output Specification:

For each test case, print the input string in the shape of U as specified in the description.

Sample Input:

helloworld!
Sample Output:

h   !
e   d
l   l
lowor
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string u;
    cin>>u;
    int n1,n2,n3;
    int len = u.size();
    n1 = n3 = (len+2)/3;
    n2 = len+2-n1-n3;
    vector<vector<char>>print(n1);
    int mid = n2-2;
    int i;
    int z = 0;
    len--;
    for(i=0 ; i<n1 ; i++)
    {
        int j;
        if(i<n1-1)
        {
            for(j=0 ; j<n2 ; j++)
            {
                if(j==0)
                    print[i].push_back(u[z++]);
                else if(j==n2-1)
                    print[i].push_back(u[len--]);
                else
                    print[i].push_back(' ');

            }
        }
        else
        {
            for(j=0 ; j<n2 ; j++)
                print[i].push_back(u[z++]);
        }
    }
    for(i=0 ; i<n1 ; i++)
    {
        int j;
        for(j=0 ; j<n2 ; j++)
            cout<<print[i][j];
        cout<<"\n";
    }
    return 0;
}


//他山之玉
//柳婼
/*
分析：假设n = 字符串长度 + 2，因为2 * n1 + n2 = n，且要保证n2 >= n1, n1尽可能地大，分类讨论：
1. 如果n % 3 == 0，n正好被3整除，直接n1 == n2 == n3;
2. 如果n % 3 == 1，因为n2要比n1大，所以把多出来的那1个给n2
3. 如果n % 3 == 2, 就把多出来的那2个给n2
所以得到公式：n1 = n / 3，n2 = n / 3 + n % 3
把它们存储到二维字符数组中，一开始初始化字符数组为空格，然后按照u型填充进去，最后输出这个数组u。
*/
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char c[81], u[30][30];
    memset(u, ' ', sizeof(u));
    scanf("%s", c);
    int n = strlen(c) + 2;
    int n1 = n / 3;
    int n2 = n1 + n % 3;
    int index = 0;
    for(int i = 0; i < n1; i++)
        u[i][0] = c[index++];
    for(int i = 1; i <= n2 - 2; i++)
        u[n1-1][i] = c[index++];
    for(int i = n1 - 1; i >= 0; i--)
        u[i][n2-1] = c[index++];
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++)
            printf("%c", u[i][j]);
        printf("\n");
    }
    return 0;
}
