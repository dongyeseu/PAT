/*
1077 Kuchiguse (20)（20 分）
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

Itai nyan~ (It hurts, nyan~)

Ninjin wa iyada nyan~ (I hate carrots, nyan~)

Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

Sample Input 1:

3
Itai nyan~
Ninjin wa iyada nyan~
uhhh nyan~
Sample Output 1:

nyan~
Sample Input 2:

3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:

nai
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    while(getchar()!='\n')
        continue;
    vector<string>Kuchiguse;
    string kunchi;
    int i;
    for(i=0 ; i<N ; i++)
    {
        getline(cin,kunchi);
        Kuchiguse.push_back(kunchi);
    }
    string a= "";
    for(i=0 ; i<N ; i++)
    {
        if(i!=0)
        {
            string temp = "";
            int j = a.length()-1, k = Kuchiguse[i].length()-1;
            while(a[j]==Kuchiguse[i][k])
            {
                temp = a[j]+temp;
                j--;
                k--;
                if(j<0 || k<0)    //有可能越界，要控制范围
                    break;
            }
            a = temp;
            if(temp.length()==0)
                break;
        }
        else
            a = Kuchiguse[i];
    }
    if(a.length() == 0)
        cout<<"nai\n";
    else
    {
        auto z = a.begin();
        while(*z==' ')
            z = a.erase(z);
        cout<<a;
    }
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：给定N给字符串，求他们的公共后缀，如果不存在公共后缀，就输出“nai”
分析：因为是后缀，反过来比较太麻烦，所以每输入一个字符串，就把它逆序过来再比较，就比较容易了。
首先ans = s；后来每输入的一个字符串，都和ans比较，如果后面不相同的就把它截取掉。
最后输出ans即可（要逆序输出~~，所以先将ans倒置reverse一下～）
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d\n", &n);
    string ans;
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int lens = s.length();
        reverse(s.begin(), s.end());
        if(i == 0) {
            ans = s;
            continue;
        } else {
            int lenans = ans.length();
            int minlen = min(lens, lenans);
            for(int j = 0; j < minlen; j++) {
                if(ans[j] != s[j]) {
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.length() == 0) ans = "nai";
    cout << ans;
    return 0;
}
