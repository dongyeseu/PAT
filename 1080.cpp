/*
1080 MOOC期终成绩（25 分）

如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“−1”。输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。

输入样例：
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
输出样例：
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct student
{
    string name;
    int GP=-1;
    int GM=-1;
    int GF=-1;
    int G=-1;
    int rk=0;
};
bool cmp(struct student a,struct student b)
{
    if(a.rk == b.rk)
    {
        if(a.G!=b.G)
            return a.G>b.G;
        else
            return a.name < b.name;
    }
    else
    {
        return a.rk > b.rk;
    }
}
int main()
{
    int P,M,F;
    cin>>P>>M>>F;
    vector<struct student>Rank;
    map<string,int>ID;
    int i;
    string name;
    int temp;
    int j = 0;
    for(i=0 ; i<P ; i++)
    {
        cin>>name>>temp;
        if(temp>=200)
        {
            struct student Temp;
            Temp.name = name;
            Temp.GP = temp;
            Rank.push_back(Temp);
            ID[name] = j++;
        }
    }
    for(i=0 ; i<M ; i++)
    {
        cin>>name>>temp;
        if(ID.count(name)!=0)
        {
            Rank[ID[name]].GM = temp;
        }
    }
    for(i=0 ; i<F ; i++)
    {
        cin>>name>>temp;
        if(ID.count(name)!=0)
        {
            Rank[ID[name]].GF = temp;
        }
    }
    int len = Rank.size();
    for(i=0 ; i<len ; i++)
    {
        if(Rank[i].GM > Rank[i].GF)
            Rank[i].G =int(Rank[i].GM * 0.4 + Rank[i].GF * 0.6 + 0.5);
        else
            Rank[i].G = Rank[i].GF;
        if(Rank[i].G>=60)
            Rank[i].rk = 1;
    }
    sort(Rank.begin(),Rank.end(),cmp);
    for(i=0 ; i<len ; i++)
    {
        if(Rank[i].rk==0)
            break;
        else
        {
            cout<<Rank[i].name<<" "<<Rank[i].GP<<" "<<Rank[i].GM<<" "<<Rank[i].GF<<" "<<Rank[i].G<<"\n";
        }
    }
    return 0;
}

//他山之玉
//柳婼
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct node {
    string name;
    int gp, gm, gf, g;
};
bool cmp(node a, node b) {
    return a.g != b.g ? a.g > b.g : a.name < b.name;
}
map<string, int> idx;
int main() {
    int p, m, n, score, cnt = 1;
    cin >> p >> m >> n;
    vector<node> v, ans;
    string s;
    for (int i = 0; i < p; i++) {
        cin >> s >> score;
        if (score >= 200) {
            v.push_back(node{s, score, -1, -1, 0});
            idx[s] = cnt++;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> s >> score;
        if (idx[s] != 0) v[idx[s] - 1].gm = score;
    }
    for (int i = 0; i < n; i++) {
        cin >> s >> score;
        if (idx[s] != 0) {
            int temp = idx[s] - 1;
            v[temp].gf = v[temp].g = score;
            if (v[temp].gm > v[temp].gf) v[temp].g = int(v[temp].gm * 0.4 + v[temp].gf * 0.6 + 0.5);
        }
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i].g >= 60) ans.push_back(v[i]);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
    return 0;
}
