

#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int Father[10010] = {0};
int Root[10010] = {0};

void Init() //初始化
{
    int i;
    for(i=0 ; i<10010 ; i++)
        Father[i] = i;
}

int FindFather(int x) //寻找根节点
{
    while(Father[x]!=x)
        x = Father[x];
    return x;
}

void Union(int x,int y)    //合并
{
    int a = FindFather(x);
    int b = FindFather(y);
    if(a>=b)
        Father[a] = b;
    else
        Father[b] = a;
}

struct node     //存储结果的家庭地产结构体
{
    int ID = 10000;
    int num;
    float AVGsets;
    float AVGaera;
};

bool cmp(struct node a,struct node b) //结构体排序
{
    if(a.AVGaera != b.AVGaera)
        return a.AVGaera > b.AVGaera;
    else
        return a.ID < b.ID;
}

int main()
{
    set<int>PeopleName; //存储所有人的姓名
    map<int,int>Sets; //记录个人的房产数量
    map<int,int>Aera; //记录个人的房产面积
    int N;
    Init();
    int id,father,mother,child,k,Mestate,aera; 
    cin>>N;
    int i,j;
    for(i=0 ; i<N ; i++)  //输入及保存在相应的数据结构中
    {
        cin>>id>>father>>mother;
        PeopleName.insert(id);
        if(father!=-1)
        {
            PeopleName.insert(father);
            Union(id,father);
        }
        if(mother!=-1)
        {
            PeopleName.insert(mother);
            Union(id,mother);
        }
        cin>>k;
        for(j=0 ; j<k ; j++)
        {
            cin>>child;
            PeopleName.insert(child);
            Union(id,child);
        }
        cin>>Mestate>>aera;
        Sets[id] += Mestate;
        Aera[id] += aera;
    }
    map<int,vector<int>>Res;
    for(auto c = PeopleName.begin() ; c!=PeopleName.end() ; c++) //寻找家庭
    {
        id = FindFather(*c); //将相同家庭成员的ID存储在根节点的名下
        Res[id].push_back(*c);
        Root[id]++;
    }
    int cnt=0;
    vector<struct node>Family;
    for(i=0 ; i<10010 ; i++)
    {
        if(Root[i])
        {
            cnt++;
            int Me = 0,Ae = 0 , min_id = 10000;
            for(auto c:Res[i]) //一个家庭的所有id值
            {
                Me += Sets[c];
                Ae += Aera[c];
                if(c < min_id)
                    min_id = c;
            }
            struct node temp;
            temp.ID = min_id;
            temp.num = Res[i].size();
            temp.AVGsets = Me*1.0/temp.num;
            temp.AVGaera = Ae*1.0/temp.num;
            Family.push_back(temp);
        }
    }
    sort(Family.begin(),Family.end(),cmp);
    cout<<cnt<<"\n";
    for(i=0 ; i<cnt ; i++)
    {
        printf("%04d %d %.3f %.3f\n",Family[i].ID,Family[i].num,Family[i].AVGsets,Family[i].AVGaera);
    }
    return 0;
}

//他山之玉
/*
题目大意：给定每个人的家庭成员和其自己名下的房产，请你统计出每个家庭的人口数、人均房产面积及房产套数。首先在第一行输出家庭个数（所有有亲属关系的人都属于同一个家庭）。随后按下列格式输出每个家庭的信息：家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积。其中人均值要求保留小数点后3位。家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。
分析：用并查集。分别用两个结构体数组，一个data用来接收数据，接收的时候顺便实现了并查集的操作union，另一个数组ans用来输出最后的答案，因为要计算家庭人数，所以用visit标记所有出现过的结点，对于每个结点的父结点，people++统计人数。标记flag == true，计算true的个数cnt就可以知道一共有多少个家庭。排序后输出前cnt个就是所求答案~~~~~
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
    int id, fid, mid, num, area;
    int cid[10];
}data[1005];
struct node {
    int id, people;
    double num, area;
    bool flag = false;
}ans[10000];
int father[10000];
bool visit[10000];
int find(int x) {
    while(x != father[x])
        x = father[x];
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;
}
int cmp1(node a, node b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main() {
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)
        father[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visit[data[i].id] = true;
        if(data[i].fid != -1) {
            visit[data[i].fid] = true;
            Union(data[i].fid, data[i].id);
        }
        if(data[i].mid != -1) {
            visit[data[i].mid] = true;
            Union(data[i].mid, data[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &data[i].cid[j]);
            visit[data[i].cid[j]] = true;
            Union(data[i].cid[j], data[i].id);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }
    for(int i = 0; i < n; i++) {
        int id = find(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = true;
    }
    for(int i = 0; i < 10000; i++) {
        if(visit[i])
            ans[find(i)].people++;
        if(ans[i].flag)
            cnt++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp1);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    return 0;
}

//柳婼
#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
    int id, fid, mid, num, area;
    int cid[10];
}data[1005];
struct node {
    int id, people;
    double num, area;
    bool flag = false;
}ans[10000];
int father[10000];
bool visit[10000];
int find(int x) {
    while(x != father[x])
        x = father[x];
    return x;
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;
}
int cmp1(node a, node b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main() {
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)
        father[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
        visit[data[i].id] = true;
        if(data[i].fid != -1) {
            visit[data[i].fid] = true;
            Union(data[i].fid, data[i].id);
        }
        if(data[i].mid != -1) {
            visit[data[i].mid] = true;
            Union(data[i].mid, data[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &data[i].cid[j]);
            visit[data[i].cid[j]] = true;
            Union(data[i].cid[j], data[i].id);
        }
        scanf("%d %d", &data[i].num, &data[i].area);
    }
    for(int i = 0; i < n; i++) {
        int id = find(data[i].id);
        ans[id].id = id;
        ans[id].num += data[i].num;
        ans[id].area += data[i].area;
        ans[id].flag = true;
    }
    for(int i = 0; i < 10000; i++) {
        if(visit[i])
            ans[find(i)].people++;
        if(ans[i].flag)
            cnt++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp1);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    return 0;
}
