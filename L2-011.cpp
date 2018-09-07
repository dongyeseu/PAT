/*
L2-011 玩转二叉树（25 分）
给定一棵二叉树的中序遍历和前序遍历，请你先将树做个镜面反转，再输出反转后的层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。
这里假设键值都是互不相等的正整数。

输入格式：
输入第一行给出一个正整数N（≤30），是二叉树中结点的个数。第二行给出其中序遍历序列。第三行给出其前序遍历序列。数字间以空格分隔。

输出格式：
在一行中输出该树反转后的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
7
1 2 3 4 5 6 7
4 1 3 2 6 5 7
输出样例：
4 6 1 7 5 3 2
*/

//方法一;queue
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
vector<int>pre,in;
int Tree[100100] = {0};
int N;
void getlevel(int root,int start,int ed,int index)
{
    if(start > ed)
        return;
    int j = start;
    while(j<ed && pre[root] != in[j])
        j++;
    Tree[index] = pre[root];
    getlevel(root+1,start,j-1,2*index);
    getlevel(root+(j-start)+1,j+1,ed,2*index+1);
}

int main()
{
    cin>>N;
    pre.resize(N);
    in.resize(N);
    fill(Tree,Tree+100100,-1);
    for(int i=0 ; i<N ; i++)
        cin>>in[i];
    for(int i=0 ; i<N ; i++)
        cin>>pre[i];
    getlevel(0,0,N-1,1);
    queue<int>T;
    T.push(1);
    vector<int>Res;
    while(!T.empty())
    {
        int t = T.front();
        T.pop();
        Res.push_back(Tree[t]);
        if(Tree[t*2+1] != -1)
            T.push(t*2+1);
        if(Tree[t*2]!=-1)
            T.push(t*2);
    }
    int len = Res.size();
    for(int i=0 ; i<len ; i++)
    {
        if(i!=0)
            cout<<" ";
        cout<<Res[i];
    }
    return 0;
}


//方法二 从源头改变
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
vector<int>pre,in;
int Tree[10010] = {0};
int N;
void getlevel(int root,int start,int ed,int index)
{
    if(start > ed)
        return;
    int j = start;
    while(j<ed && pre[root] != in[j])
        j++;
    Tree[index] = pre[root];
    getlevel(root+1,start,j-1,2*index+1);
    getlevel(root+(j-start)+1,j+1,ed,2*index);
}

int main()
{
    cin>>N;
    pre.resize(N);
    in.resize(N);
    fill(Tree,Tree+10010,-1);
    for(int i=0 ; i<N ; i++)
        cin>>in[i];
    for(int i=0 ; i<N ; i++)
        cin>>pre[i];
    getlevel(0,0,N-1,1);
    for(int i=1 ; i<10010 ; i++)
    {
        if(Tree[i] != -1)
        {
            if(i==1)
                cout<<Tree[i];
            else
                cout<<" "<<Tree[i];
        }
    }
    return 0;
}
