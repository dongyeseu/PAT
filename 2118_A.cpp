/*
1118 Birds in Forest（25 分）

Sample Input:
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
Sample Output:
2 10
Yes
No
*/
//并查集
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int IsRoot[11000] = {0};
int Parent[11000] = {0};

void Init()
{
    int i;
    for(i=0 ; i<11000 ; i++)
        Parent[i] = i;
}

int FindFather(int x)
{
    while(Parent[x]!=x)
        x = Parent[x];
    return x;
}

void Union(int x,int y)
{
    int a = FindFather(x);
    int b = FindFather(y);
    if(a>=b)
        Parent[a] = b;
    else
        Parent[b] = a;
}

int main()
{
    int N,M,K;
    cin>>N;
    int i,j,k;
    set<int>Birds;
    Init();
    for(i=0 ; i<N ; i++)
    {
        cin>>M;
        vector<int>Picture;
        for(j=0 ; j<M ; j++)
        {
            cin>>k;
            Birds.insert(k);
            Picture.push_back(k);
        }
        for(j=1 ; j<Picture.size() ; j++)
        {
            Union(Picture[0],Picture[j]);
        }
    }
    for(auto z = Birds.begin() ; z!=Birds.end() ; z++)
    {
        IsRoot[FindFather(*z)]++;
    }
    int cnt = 0;
    for(i=0 ; i<11000 ; i++)
    {
        if(IsRoot[i])
            cnt++;
    }
    printf("%d %d\n",cnt,Birds.size());
    cin>>K;
    for(i=0 ; i<K ; i++)
    {
        int st,ed;
        cin>>st>>ed;
        if(FindFather(st) == FindFather(ed))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}


//有两个测试点段错误，还未找到原因
//思路：图存储，深度优先搜索
#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <set>
#define MAXN 110
using namespace std;

int Graph[MAXN][MAXN] = {0};
int Book[MAXN] = {0};

void DFS(int root,int len)
{
    Book[root] = 1;
    int i;
    for(i=1 ; i<=len ; i++)
    {
        if(!Book[i] && Graph[root][i]==1)
        {
            DFS(i,len);
        }
    }
}

int main()
{
    int N,M,K,i,j,k;
    cin>>N;
    set<int>Birds;
    for(i=0 ; i<N ; i++)
    {
        cin>>M;
        vector<int>picture;
        for(j=0 ; j<M ; j++)
        {
            cin>>k;
            picture.push_back(k);
            Birds.insert(k);
        }
        for(j=0 ; j<M ; j++)
        {
            for(k=j+1 ; k<M ; k++)
            {
                Graph[picture[j]][picture[k]] = Graph[picture[k]][picture[j]] = 1;
            }
        }
        picture.clear();
    }
    int cnt = 0 , len = Birds.size();
    for(i=1 ; i<=len ; i++)
    {
        if(!Book[i])
        {
            DFS(i,len);
            cnt++;
        }
    }
    cout<<cnt<<" "<<len<<"\n";
    cin>>K;
    for(i=0 ; i<K ; i++)
    {
        int st,ed;
        cin>>st>>ed;
        memset(Book,0,sizeof(Book));
        DFS(st,len);
        if(Book[ed] == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
