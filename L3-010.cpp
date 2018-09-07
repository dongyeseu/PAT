/*
将一系列给定数字顺序插入一个初始为空的二叉搜索树（定义为左子树键值大，右子树键值小），你需要判断最后的树是否一棵完全二叉树，并且给出其
层序遍历的结果。

输入格式：
输入第一行给出一个不超过20的正整数N；第二行给出N个互不相同的正整数，其间以空格分隔。

输出格式：
将输入的N个正整数顺序插入一个初始为空的二叉搜索树。在第一行中输出结果树的层序遍历结果，数字间以1个空格分隔，行的首尾不得有多余空格。第
二行输出YES，如果该树是完全二叉树；否则输出NO。

输入样例1：
9
38 45 42 24 58 30 67 12 51
输出样例1：
38 45 24 58 42 30 12 67 51
YES
输入样例2：
8
38 24 12 45 58 67 42 51
输出样例2：
38 45 24 58 42 12 67 51
NO
*/


#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int>Tree(100010,0);
void Insert(int X,int index)
{
    if(Tree[index] == 0)
    {
        Tree[index] = X;
        return;
    }
    else if(Tree[index] < X)
    {
        Insert(X,2*index);
    }
    else if(Tree[index] > X)
    {
        Insert(X,2*index+1);
    }
}
int main()
{
    int N,temp;
    cin>>N;
    for(int i=0 ; i<N ; i++)
    {
        cin>>temp;
        Insert(temp,1);
    }
    bool flag = true;
    for(int i=1 ; i<=N ; i++)
    {
        if(Tree[i] == 0)
        {
            flag = false;
            break;
        }
    }
    int cnt = 0;
    for(int i=1 ; i<100010 ; i++)
    {
        if(Tree[i] != 0)
        {
            if(i!=1)
                cout<<" ";
            cout<<Tree[i];
            cnt++;
            if(cnt == N)
                break;
        }
    }
    cout<<"\n";
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
