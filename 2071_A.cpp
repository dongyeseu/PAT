/*
1071 Speech Patterns (25)（25 分）
People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

Input Specification:

Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return '\n'. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].

Output Specification:

For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.

Note that words are case insensitive.

Sample Input:

Can1: "Can a can can a can?  It can!"
Sample Output:

can 5
*/
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    char ch;
    map<string,int>Speech;
    string a = "";
    while((ch = getchar())&&ch!='\n')
    {
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))   //这里可以使用函数isalnum(),在头文件cctype中
        {
            a+=tolower(ch);
        }
        else
        {
            if(a!="")
            {
                Speech[a]++;
                a = "";
            }
            else
                continue;
        }
    }
    if(a!="")
        Speech[a]++;
    string R;
    int max_num = 0;
    for(auto i = Speech.begin() ; i!=Speech.end() ; i++)
    {
        if(i->second > max_num)
        {
            R = i->first;
            max_num = i->second;
        }
    }
    cout<<R<<" "<<max_num<<"\n";
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：统计单词个数~~大小写字母+数字的组合才是合法的单词，给出一个字符串，求出现的合法的单词的个数最多的那个单词，以及它出现的次数。如果有并列的，那么输出字典序里面的第一个~~~
分析：用map很简单的~不过呢~有几个注意点~~：
1. 大小写不区分，所以统计之前要先s[i] = tolower(s[i]);
2. [0-9 A-Z a-z]可以简写为cctype头文件里面的一个函数isalnum~~
3. 必须用getline读入一长串的带空格的字符串~~
4. 一定要当t不为空的时候m[t]++，因为t为空也会被统计的！！！~~~
5. 最重要的是～如果i已经到了最后一位，不管当前位是不是字母数字，都得将当前这个t放到map里面（只要t长度不为0）～
*/

#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int main() {
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for(int i = 0; i < s.length(); i++) {
        if(isalnum(s[i])) {
            s[i] = tolower(s[i]);
            t += s[i];
        }
        if(!isalnum(s[i]) || i == s.length() - 1){
            if(t.length() != 0) m[t]++;
            t = "";
        }
    }
    int maxn = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second > maxn) {
            t = it->first;
            maxn = it->second;
        }
    }
    cout << t << " " << maxn;
    return 0;
}
