/*
1053 Path of Equal Weight（30 分）

Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
*/

//完全通过
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

vector<int>Path;//存储每个结点的父节点，根节点的父节点为-1
vector<int>node; //若为0，则为叶子结点
void DFS(int root,vector<vector<int>>Graph) //深度优先搜索过程
{
    stack<int>tree;
    tree.push(root);
    while(!tree.empty())
    {
        int nd = tree.top();
        tree.pop();
        if(node[nd])
        {
            for(auto c : Graph[nd])
            {
                Path[c] = nd;
                tree.push(c);
            }
        }
    }
}

bool cmp(vector<int>a,vector<int>b)    //路径权值排序
{
    int len = a.size()<b.size()?a.size():b.size();
    int i;
    for(i=0 ; i<len ; i++)
    {
        if(a[i]!=b[i])
            return a[i] > b[i];
    }
}

int main()
{
    vector<vector<int>>Graph; //图的存储
    int N,M,S,i,j,temp,root = 0;
    scanf("%d %d %d",&N,&M,&S);
    Graph.resize(N); //改变图、路径、结点的容量
    Path.resize(N+1);
    node.resize(N+1);
    fill(node.begin(),node.end(),0);
    vector<int>weight(N);
    vector<vector<int>>Res;
    for(i=0 ; i<N ; i++)
        scanf("%d",&weight[i]);    //输入每个结点的权值
    for(i=0 ; i<M ; i++)
    {
        int non_leaf_id,num;
        cin>>non_leaf_id>>num;
        node[non_leaf_id] = 1;
        for(j=0 ; j<num ; j++)
        {
            cin>>temp;
            Graph[non_leaf_id].push_back(temp);       //构建图
        }
    }
    Path[root] = -1;
    DFS(root,Graph);
    for(i=0 ; i<N ; i++)
    {
        if(node[i] == 0)
        {
            vector<int>weightpath;
            vector<int>idpath;
            vector<int>Book(N+1,0);
            j = i;
            int flag = 0;
            while(j!=-1)
            {
                idpath.push_back(j);
                if(Book[j])
                {
                    flag = 1;
                    break;
                }
                Book[j] = 1;
                weightpath.push_back(weight[j]);
                j = Path[j];
            }
            if(flag)
                continue;
            int weightsum = 0;
            for(auto z:idpath)
                weightsum += weight[z];
            if(weightsum == S)
            {
                reverse(weightpath.begin(),weightpath.end());
                Res.push_back(weightpath);
            }
        }
    }
    sort(Res.begin(),Res.end(),cmp);
    for(i=0 ; i<Res.size() ; i++)
    {
        for(j=0 ; j<Res[i].size() ; j++)
        {
            if(j==0)
                cout<<Res[i][j];
            else
                cout<<" "<<Res[i][j];
        }
        cout<<"\n";
    }
    return 0;
}



//最后一个测试点段错误
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<vector<int>>Graph; //图的存储
vector<int>Path;//存储每个结点的父节点，根节点的父节点为-1
vector<int>node; //若为0，则为叶子结点
void DFS(int root) //深度优先搜索过程
{
    int len = Graph[root].size();
    if(len == 0)
        return;
    int i;
    for(i=0 ; i<len ; i++)
    {
        Path[Graph[root][i]] = root;
        DFS(Graph[root][i]);
    }
}

bool cmp(vector<int>a,vector<int>b)    //路径权值排序
{
    int len = a.size()<b.size()?a.size():b.size();
    int i;
    for(i=0 ; i<len ; i++)
    {
        if(a[i]!=b[i])
            return a[i] > b[i];
    }
    if(a.size() <= b.size())
        return true;
}

int main()
{
    int N,M,S,i,j,temp,root = 0;
    scanf("%d %d %d",&N,&M,&S);
    Graph.resize(N); //改变图、路径、结点的容量
    Path.resize(N);
    node.resize(N);
    fill(node.begin(),node.end(),0);
    vector<int>weight(N);
    vector<vector<int>>Res;
    for(i=0 ; i<N ; i++)
        scanf("%d",&weight[i]);    //输入每个结点的权值
    for(i=0 ; i<M ; i++)
    {
        int non_leaf_id,num;
        cin>>non_leaf_id>>num;
        node[non_leaf_id] = 1;
        for(j=0 ; j<num ; j++)
        {
            cin>>temp;
            Graph[non_leaf_id].push_back(temp);       //构建图
        }
    }
    Path[root] = -1;
    DFS(root);
    for(i=0 ; i<N ; i++)
    {
        if(node[i] == 0)
        {
            vector<int>weightpath;
            vector<int>idpath;
            j = i;
            while(j!=-1)
            {
                idpath.push_back(j);
                weightpath.push_back(weight[j]);
                j = Path[j];
            }
            int weightsum = 0;
            for(auto z:idpath)
                weightsum += weight[z];
            if(weightsum == S)
            {
                reverse(weightpath.begin(),weightpath.end());
                Res.push_back(weightpath);
            }
        }
    }
    sort(Res.begin(),Res.end(),cmp);
    for(i=0 ; i<Res.size() ; i++)
    {
        for(j=0 ; j<Res[i].size() ; j++)
        {
            if(j==0)
                cout<<Res[i][j];
            else
                cout<<" "<<Res[i][j];
        }
        cout<<"\n";
    }
    return 0;

}




//他山之玉
//柳婼
/*
题目大意：给出树的结构和权值，找从根结点到叶子结点的路径上的权值相加之和等于给定目标数的路径，并且从大到小输出路径
分析：对于接收孩子结点的数据时，每次完全接收完就对孩子结点按照权值进行排序（序号变，根据权值变），这样保证深度优先遍历的时候直接输出就能输出从大到小的顺序。记录路径采取这样的方式：首先建立一个path数组，传入一个nodeNum记录对当前路径来说这是第几个结点（这样直接在path[nodeNum]里面存储当前结点的孩子结点的序号，这样可以保证在先判断return的时候，path是从0~numNum-1的值确实是要求的路径结点）。然后每次要遍历下一个孩子结点的之前，令path[nodeNum] = 孩子结点的序号，这样就保证了在return的时候当前path里面从0~nodeNum-1的值就是要输出的路径的结点序号，输出这个序号的权值即可，直接在return语句里面输出。
注意：当sum==target的时候，记得判断是否孩子结点是空，要不然如果不空说明没有到底部，就直接return而不是输出路径。。。（这对接下来的孩子结点都是正数才有用，负权无用）。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int target;
struct NODE {
    int w;
    vector<int> child;
};
vector<NODE> v;
vector<int> path;
void dfs(int index, int nodeNum, int sum) {
    if(sum > target) return ;
    if(sum == target) {
        if(v[index].child.size() != 0) return;
        for(int i = 0; i < nodeNum; i++)
            printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
        return ;
    }
    for(int i = 0; i < v[index].child.size(); i++) {
        int node = v[index].child[i];
        path[nodeNum] = node;
        dfs(node, nodeNum + 1, sum + v[node].w);
    }
    
}
int cmp1(int a, int b) {
    return v[a].w > v[b].w;
}
int main() {
    int n, m, node, k;
    scanf("%d %d %d", &n, &m, &target);
    v.resize(n), path.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i].w);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &node, &k);
        v[node].child.resize(k);
        for(int j = 0; j < k; j++)
            scanf("%d", &v[node].child[j]);
        sort(v[node].child.begin(), v[node].child.end(), cmp1);
    }
    dfs(0, 1, v[0].w);
    return 0;
}
