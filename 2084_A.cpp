/*
1084 Broken Keyboard (20)（20 分）
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:

7_This_is_a_test
_hs_s_a_es
Sample Output:

7TI
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int len_a = a.size();
    int len_b = b.size();
    int i=0 , j=0;
    string Broken = "";
    while(i<len_a || j<len_b)
    {
        if(j==len_b)
        {
            if(isalpha(a[i]))
                a[i] = toupper(a[i]);
            auto k = find(Broken.begin(),Broken.end(),a[i]);
            if(k==Broken.end())
                Broken += a[i];
            i++;
        }
        else if(a[i]!=b[j])
        {
            if(isalpha(a[i]))
                a[i] = toupper(a[i]);
            auto k = find(Broken.begin(),Broken.end(),a[i]);
            if(k==Broken.end())
                Broken += a[i];
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for(auto k = Broken.begin() ; k!=Broken.end();k++)
        cout<<*k;
    return 0;

}


//他山之玉
//柳婼
/*
分析：用string的find函数～遍历字符串s1，当当前字符s1[i]不在s2中，它的大写也不在ans中时，将当前字符的大写放入ans中，最后输出ans字符串即可～
*/
#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
            ans += toupper(s1[i]);
    cout << ans;
    return 0;
}
