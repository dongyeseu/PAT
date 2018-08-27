#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#define MAXN 1010
using namespace std;

int Graph[MAXN][MAXN];
int Visited[MAXN];

set<int>Cluster; //记录每个连通分量中顶点对应的人物编号

void DFS(int st,int N)
{
    int j;
    for(j=1 ; j<=N ; j++)
    {
        if(!Visited[j] && Graph[st][j]==1)
        {
            Visited[j] = 1;
            Cluster.insert(j);
            DFS(j,N);
        }
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    memset(Graph,0,sizeof(Graph));
    memset(Visited,0,sizeof(Visited));
    set<int>num; //记录出现的爱好的编号
    int i;
    int max_num = 0;
    map<int,vector<int>>cluster; //记录每个爱好对应的人物编号
    set<int>hobby;
    for(i=0 ; i<N ; i++)
    {
        vector<int>vertex;
        int j,num,temp;
        char ch;
        scanf("%d%c",&num,&ch);
        for(j=0 ; j<num ; j++)
        {
            scanf("%d",&temp);
            if(temp > max_num)
                max_num = temp;
            cluster[temp].push_back(i); //每个爱好对应的任务编号
            hobby.insert(temp);
            vertex.push_back(temp);  //每个人所有的爱好
        }
        for(j=0 ; j<num ; j++)
        {
            if(j!=0)
                Graph[vertex[0]][vertex[j]] = Graph[vertex[j]][vertex[0]] = 1; //每个人对应的爱好作为顶点形成边
        }
    }
    int cnt = 0;
    vector<int>Res;
    for(i=1 ; i<=max_num ; i++)
    {
        if(hobby.count(i) == 0) //如果该爱好没有出现过，不为考虑
            continue;
        if(!Visited[i])
        {
            Cluster.insert(i);
            cnt++;
            Visited[i] = 1;
            DFS(i,max_num); //深度优先搜索，确定连通分支数量
            auto z = Cluster.begin();
            set<int>People; //记录一个连通分支中所包含的人物
            for( ; z!= Cluster.end() ; z++)
            {
                int tp = *z;
                int len = cluster[tp].size();
                int k;
                for(k=0 ; k<len ; k++)
                    People.insert(cluster[tp][k]);
            }
            Res.push_back(People.size());  //记录人物数量
            Cluster.clear(); //清空，对下一组连通分支进行判断
        }
    }
    cout<<cnt<<"\n";
    sort(Res.begin(),Res.end()); //从小到大排序，因此输出时从后往前输出
    for(i=cnt-1 ; i>=0 ; i--)
    {
        if(i==cnt-1)
            cout<<Res[i];
        else
            cout<<" "<<Res[i];
    }
    return 0;
}


//思路二
//并查集

#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int Father[2010] = {0};
int Root[2010] = {0};

void Init()
{
    int i;
    for(i=0 ; i<2010 ; i++)
        Father[i] = -1;
}

int FindFather(int x)
{
    while(Father[x]!=-1)
        x = Father[x];
    return x;
}

bool cmp(int a,int b)
{
    return a>b;
}
void Union(int x,int y)
{
    int a = FindFather(x);
    int b = FindFather(y);
    if(a>=b)
        Father[a] = b;
    else
        Father[b] = a;
}

int main()
{
    int N,K,i,j,temp;
    Init();
    cin>>N;
    set<int>Social;
    for(i=0 ; i<N ; i++)
    {
        cin>>K;
        getchar();
        vector<int>Hobby;
        for(j=0 ; j<K ; j++)
        {
            cin>>temp;
            Hobby.push_back(temp+N);
        }
        for(j=0 ; j<K ; j++)
        {
            Union(i,Hobby[j]);
        }
    }

    for(i=0 ; i<N ; i++)
    {
        Root[FindFather(i)]++;
    }
    int cnt = 0;
    vector<int>Res;
    for(i=2009 ; i>=0 ; i--)
    {
        if(Root[i]!=0)
        {
            Res.push_back(Root[i]);
            cnt++;
        }
    }
    sort(Res.begin(),Res.end(),cmp);
    cout<<cnt<<"\n";
    for(i=0 ; i<Res.size() ; i++)
    {
        printf("%d%c",Res[i],i!=Res.size()-1?' ':'\n');
    }
    return 0;
}



//他山之玉
//柳婼
/*
题目大意：有n个人，每个人喜欢k个活动，如果两个人有任意一个活动相同，就称为他们处于同一个社交网络。求这n个人一共形成了多少个社交网络。
分析：并查集。先写好init、findFather、Union。
0. 每个社交圈的结点号是人的编号，而不是课程。课程是用来判断是否处在一个社交圈的。
1. course[t]表示任意一个喜欢t活动的人的编号。如果当前的课程t，之前并没有人喜欢过，那么就course[t] = i，i为它自己的编号，表示i为喜欢course[t]的一个
人的编号
2. course[t]是喜欢t活动的人的编号，那么findFather(course[t])就是喜欢这个活动的人所处的社交圈子的根结点，合并根结点和当前人的编号的结点i。
即Union(i, findFather(course[t]))，把它们处在同一个社交圈子里面
3. isRoot[i]表示编号i的人是不是它自己社交圈子的根结点，如果等于0表示不是根结点，如果不等于0，每次标记isRoot[findFather(i)]++，那么isRoot保存的就
是如果当前是根结点，那么这个社交圈里面的总人数
4. isRoot中不为0的编号的个数cnt就是社交圈圈子的个数
5. 把isRoot从大到小排列，输出前cnt个，就是社交圈人数的从大到小的输出顺序
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father, isRoot;
int cmp1(int a, int b){return a > b;}
int findFather(int x) {
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;
}
int main() {
    int n, k, t, cnt = 0;
    int course[1001] = {0};
    scanf("%d", &n);
    father.resize(n + 1);
    isRoot.resize(n + 1);
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            if(course[t] == 0)
                course[t] = i;
            Union(i, findFather(course[t]));
        }
    }
    for(int i = 1; i <= n; i++)
        isRoot[findFather(i)]++;
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) cnt++;
    }
    printf("%d\n", cnt);
    sort(isRoot.begin(), isRoot.end(), cmp1);
    for(int i = 0; i < cnt; i++) {
        printf("%d", isRoot[i]);
        if(i != cnt - 1) printf(" ");
    }
    return 0;
}
