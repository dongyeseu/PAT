/*
1085 PAT单位排行（25 分）
每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。

输入格式：

输入样例：
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
输出样例：
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct School
{
    string name;
    int stu_num = 0;
    float score_sum = 0;
};

bool cmp(struct School a,struct School b)
{
    if((int)a.score_sum != (int)b.score_sum)
    {
        return a.score_sum > b.score_sum;
    }
    else if(a.stu_num!=b.stu_num)
    {
        return a.stu_num < b.stu_num;
    }
    else
    {
        return a.name < b.name;
    }
}

int main()
{
    int N;
    cin>>N;
    int i;
    string name;
    string school;
    vector<struct School>Rank;
    map<string,int>ID;
    int score;
    int j = 0;
    for(i=0 ; i<N ; i++)
    {
        cin>>name>>score>>school;
        for(auto &c : school)
            c = tolower(c);
        if(ID.count(school)==0)
        {
            struct School Temp;
            Temp.name = school;
            switch(name[0])
            {
            case 'T':
                Temp.score_sum += score*1.5;
                break;
            case 'A':
                Temp.score_sum += score;
                break;
            case 'B':
                Temp.score_sum += score/1.5;
                break;
            }
            Temp.stu_num++;
            ID[school] = j++;
            Rank.push_back(Temp);
        }
        else
        {
            auto k = ID.find(school);
            int index = k->second;
            Rank[index].stu_num++;
            switch(name[0])
            {
            case 'T':
                Rank[index].score_sum += score*1.5;
                break;
            case 'A':
                Rank[index].score_sum += score;
                break;
            case 'B':
                Rank[index].score_sum += score/1.5;
                break;
            }
        }
    }
    sort(Rank.begin(),Rank.end(),cmp);
    int len = Rank.size();
    cout<<len<<"\n";
    int pre = 1;
    for(i=1 ; i<=len ; i++)
    {
        if(i!=1)
        {
            if((int)Rank[i-1].score_sum!=(int)Rank[i-2].score_sum)
            {
                cout<<i<<" "<<Rank[i-1].name<<" "<<(int)Rank[i-1].score_sum<<" "<<Rank[i-1].stu_num<<"\n";
                pre = i;
            }
            else
            {
                cout<<pre<<" "<<Rank[i-1].name<<" "<<(int)Rank[i-1].score_sum<<" "<<Rank[i-1].stu_num<<"\n";
            }
        }
        else
        {
            cout<<i<<" "<<Rank[i-1].name<<" "<<(int)Rank[i-1].score_sum<<" "<<Rank[i-1].stu_num<<"\n";
            pre = i;
        }
    }
    return 0;
}


//他山之玉
//柳婼
/*
分析：两个map，一个cnt用来存储某学校名称对应的参赛人数，另一个sum计算某学校名称对应的总加权成绩。每次学校名称string school都要转化为全小写，将map中所有学校都保存在vector ans中，类型为node，node中包括学校姓名、加权总分、参赛人数。对ans数组排序，根据题目要求写好cmp函数，最后按要求输出。对于排名的处理：设立pres表示前一个学校的加权总分，如果pres和当前学校的加权总分不同，说明rank等于数组下标+1，否则rank不变～
注意：总加权分数取整数部分是要对最后的总和取整数部分，不能每次都直接用int存储，不然会有一个3分测试点不通过～
PS: 更新后的pat系统会导致之前使用map的代码最后一个测试点超时，更改为unordered_map即可AC～
*/
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
    string school;
    int tws, ns;
};
bool cmp(node a, node b) {
    if (a.tws != b.tws)
        return a.tws > b.tws;
    else if (a.ns != b.ns)
        return a.ns < b.ns;
    else
        return a.school < b.school;
}
int main() {
    int n;
    scanf("%d", &n);
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;
    for (int i = 0; i < n; i++) {
        string id, school;
        cin >> id;
        double score;
        scanf("%lf", &score);
        cin >> school;
        for (int j = 0; j < school.length(); j++)
            school[j] = tolower(school[j]);
        if (id[0] == 'B')
            score = score / 1.5;
        else if (id[0] == 'T')
            score = score * 1.5;
        sum[school] += score;
        cnt[school]++;
    }
    vector<node> ans;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
        ans.push_back(node{it->first, (int)sum[it->first], cnt[it->first]});
    sort(ans.begin(), ans.end(), cmp);
    int rank = 0, pres = -1;
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (pres != ans[i].tws) rank = i + 1;
        pres = ans[i].tws;
        printf("%d ", rank);
        cout << ans[i].school;
        printf(" %d %d\n", ans[i].tws, ans[i].ns);
    }
    return 0;
}
