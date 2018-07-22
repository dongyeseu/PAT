/*
1137 Final Grading（25 分）
For a student taking the online course "Data Structures" on China University MOOC (http://www.icourse163.org/), to be qualified for a certificate, he/she must first obtain no less than 200 points from the online programming assignments, and then receive a final grade no less than 60 out of 100. The final grade is calculated by G=(G
​mid−term
​​ ×40%+G
​final
​​ ×60%) if G
​mid−term
​​ >G
​final
​​ , or G
​final
​​  will be taken as the final grade G. Here G
​mid−term
​​  and G
​final
​​  are the student's scores of the mid-term and the final exams, respectively.

The problem is that different exams have different grading sheets. Your job is to write a program to merge all the grading sheets into one.

Input Specification:
Each input file contains one test case. For each case, the first line gives three positive integers: P , the number of students having done the online programming assignments; M, the number of students on the mid-term list; and N, the number of students on the final exam list. All the numbers are no more than 10,000.

Then three blocks follow. The first block contains P online programming scores G
​p
​​ 's; the second one contains M mid-term scores G
​mid−term
​​ 's; and the last one contains N final exam scores G
​final
​​ 's. Each score occupies a line with the format: StudentID Score, where StudentID is a string of no more than 20 English letters and digits, and Score is a nonnegative integer (the maximum score of the online programming is 900, and that of the mid-term and final exams is 100).

Output Specification:
For each case, print the list of students who are qualified for certificates. Each student occupies a line with the format:

StudentID G
​p
​​  G
​mid−term
​​  G
​final
​​  G

If some score does not exist, output "−1" instead. The output must be sorted in descending order of their final grades (G must be rounded up to an integer). If there is a tie, output in ascending order of their StudentID's. It is guaranteed that the StudentID's are all distinct, and there is at least one qullified student.

Sample Input:
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
Sample Output:
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
*/


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

struct student{
    string name;
    int GP = -1;
    int GM = -1;
    int GF = 0;
    int score;
};

bool cmp(struct student a,struct student b)
{
    if(a.score!=b.score)
        return a.score > b.score;
    else
        return a.name < b.name;
}

int main()
{
    int P,M,F;
    int i,j=0;
    scanf("%d %d %d",&P,&M,&F);
    string id;
    int gp,gm,gf;
    vector<struct student>Rank;
    map<string,int>ID;
    for(i=0 ; i<P ; i++)
    {
        cin>>id>>gp;
        if(gp>=200)
        {
            struct student temp;
            temp.name = id;
            temp.GP = gp;
            Rank.push_back(temp);
            ID[id] = j++;
        }
    }
    for(i=0 ; i<M ; i++)
    {
        cin>>id>>gm;
        if(ID.count(id)!=0)
        {
            int z = ID[id];
            Rank[z].GM = gm;
        }
    }
    for(i=0 ; i<F ; i++)
    {
        cin>>id>>gf;
        if(ID.count(id)!=0)
        {
            int z = ID[id];
            Rank[z].GF = gf;
        }
    }
    int len = Rank.size();
    for(i=0 ; i<len ; i++)
    {
        if(Rank[i].GM >Rank[i].GF)
            Rank[i].score = (int)(Rank[i].GM * 0.4 + Rank[i].GF * 0.6 + 0.5);
        else
            Rank[i].score = Rank[i].GF;
    }
    sort(Rank.begin(),Rank.end(),cmp);
    for(i=0 ; i<len ; i++)
    {
        if(Rank[i].score>=60)
        {
            if(Rank[i].GF == 0)
                Rank[i].GF = -1;
            cout<<Rank[i].name<<" "<<Rank[i].GP<<" "<<Rank[i].GM<<" "<<Rank[i].GF<<" "<<Rank[i].score<<"\n";
        }
    }
    return 0;
}

//他山之玉
//柳婼
/*
分析：1 因为所有人必须要G编程>=200分，所以用v数组保存所有G编程>=200的人，（一开始gm和gf都为-1），用map映射保存名字所对应v中的下标（为了避免与“不存在”混淆，保存下标+1，当为0时表示该学生的姓名在v中不存在）
2 G期中中出现的名字，如果对应的map并不存在（==0），说明该学生编程成绩不满足条件，则无须保存该学生信息。将存在的人的期中考试成绩更新
3 G期末中出现的名字，也必须保证在map中存在。先更新G期末和G总为新的成绩，当G期末<G期中时再将G总更新为(G期中x 40% + G期末x 60%)
4 将v数组中所有G总满足条件的放入ans数组中，对ans排序（总分递减，总分相同则姓名递增），最后输出ans中的学生信息
*/
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
