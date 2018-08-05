/*
1134 Vertex Cover（25 分）
A vertex cover of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. Now given a graph with several vertex sets, you are supposed to tell if each of them is a vertex cover or not.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N and M (both no more than being the total numbers of vertices and the edges, respectively. Then M lines follow, each describes an edge by giving the indices (from 0 to N−1) of the two ends of the edge.

After the graph, a positive integer K (≤ 100) is given, which is the number of queries. Then K lines of queries follow, each in the format:
s the number of vertices in the set, and v[i]'s are the indices of the vertices.

Output Specification:
For each query, print in a line Yes if the set is a vertex cover, or No if not.

Sample Input:
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
Sample Output:
No
Yes
Yes
No
No
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
vector<vector<int>>Graph;     //使用邻接表记录所有的边
bool Cover(set<int>num,int N)
{
    int i;
    for(i=0 ; i<N ; i++) //遍历图的所有边
    {
        int j , len = Graph[i].size();
        if(len!=0)
        {
            for(j=0 ; j<len ; j++)
            {
                if(num.count(i)==0 && num.count(Graph[i][j])==0)  //当边的两个顶点都不在set中时，false
                    return false;
            }

        }
    }
    return true;
}

int main()
{
    int N,M,K;
    scanf("%d %d",&N,&M);
    int i,j,k;
    Graph.resize(N);
    for(i=0 ; i<M ; i++)
    {
        scanf("%d %d",&j,&k);
        Graph[j].push_back(k);      //有向图，减少边的个数
    }
    scanf("%d",&K);
    for(i=0 ; i<K ; i++)
    {
        set<int>Num;    //set用于判断顶点
        int T;
        cin>>T;
        for(j= 0 ; j<T ; j++)
        {
            scanf("%d",&k);
            Num.insert(k);
        }
        bool res = Cover(Num,N);
        if(res)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：给n个结点m条边，再给k个集合。对这k个集合逐个进行判断。每个集合S里面的数字都是结点编号，求问整个图所有的m条边两端的结点，是否至少一个结点
出自集合S中。如果是，输出Yes否则输出No

分析：用vector v[n]保存某结点属于的某条边的编号，比如a b两个结点构成的这条边的编号为0，则v[a].push_back(0)，v[b].push_back(0)——表示a属于0号边，
b也属于0号边。对于每一个集合做判断，遍历集合中的每一个元素，将当前元素能够属于的边的编号i对应的hash[i]标记为1，表示这条边是满足有一个结点出自集合S
中的。最后判断hash数组中的每一个值是否都是1，如果有不是1的，说明这条边的两端结点没有一个出自集合S中，则输出No。否则输出Yes～
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, k, nv, a, b, num;
    scanf("%d%d", &n, &m);
    vector<int> v[n];
    for (int i = 0;i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &nv);
        int flag = 0;
        vector<int> hash(m, 0);
        for (int j = 0; j < nv; j++) {
            scanf("%d", &num);
            for (int t = 0; t < v[num].size(); t++)
                hash[v[num][t]] = 1;
        }
        for (int j = 0; j < m; j++) {
            if (hash[j] == 0) {
                printf("No\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("Yes\n");
    }
    return 0;
}
