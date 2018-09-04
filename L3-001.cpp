/*
L3-001 凑零钱（30 分）
韩梅梅喜欢满宇宙到处逛街。现在她逛到了一家火星店里，发现这家店有个特别的规矩：你可以用任何星球的硬币付钱，但是绝不找零，当然也不能欠债。韩梅梅手边有 10
​4
​​  枚来自各个星球的硬币，需要请你帮她盘算一下，是否可能精确凑出要付的款额。

输入格式：
输入第一行给出两个正整数：N（≤10
​4
​​ ）是硬币的总个数，M（≤10
​2
​​ ）是韩梅梅要付的款额。第二行给出 N 枚硬币的正整数面值。数字间以空格分隔。

输出格式：
在一行中输出硬币的面值 V
​1
​​ ≤V
​2
​​ ≤⋯≤V
​k
​​ ，满足条件 V
​1
​​ +V
​2
​​ +...+V
​k
​​ =M。数字间以 1 个空格分隔，行首尾不得有多余空格。若解不唯一，则输出最小序列。若无解，则输出 No Solution。

注：我们说序列{ A[1],A[2],⋯ }比{ B[1],B[2],⋯ }“小”，是指存在 k≥1 使得 A[i]=B[i] 对所有 i<k 成立，并且 A[k]<B[k]。

输入样例 1：
8 9
5 9 8 7 2 3 4 1
输出样例 1：
1 3 5
输入样例 2：
4 8
7 2 4 3
输出样例 2：
No Solution
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int>value(N);
    for(int i=0 ; i<N ; i++)
        cin>>value[i];
    vector<int>F(M+1,0);
    sort(value.begin(),value.end(),cmp);
    int choice[N][M+1];
    memset(choice,0,sizeof(choice));
    for(int i=0 ; i<N ; i++)
    {
        for(int j=M ; j>=value[i] ; j--)
        {
            if(F[j] <= F[j-value[i]] + value[i])
            {
                F[j] = F[j-value[i]] + value[i];
                choice[i][j] = 1;
            }
        }
    }
    if(F[M] != M)
        cout<<F[M]<<"No Solution\n";
    else
    {
        int index = N-1;
        vector<int>Res;
        while(M>0&&index >=0)
        {
            if(choice[index][M])
            {
                Res.push_back(value[index]);
                M -= value[index];
            }
            index--;
        }
        for(int i=0 ; i<Res.size() ; i++)
        {
            if(i!=0)
                cout<<" ";
            cout<<Res[i];
        }
    }
    return 0;

}
