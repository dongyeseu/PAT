/*
1143 Lowest Common Ancestor（30 分）提问
The lowest common ancestor (LCA) of two nodes U and V in a tree is the deepest node that has both U and V as descendants.

A binary search tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given any two nodes in a BST, you are supposed to find their LCA.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: M (≤ 1,000), the number of pairs of nodes to be tested; and N (≤ 10,000), the number of keys in the BST, respectively. In the second line, N distinct integers are given as the preorder traversal sequence of the BST. Then M lines follow, each contains a pair of integer keys U and V. All the keys are in the range of int.

Output Specification:
For each given pair of U and V, print in a line LCA of U and V is A. if the LCA is found and A is the key. But if A is one of U and V, print X is an ancestor of Y. where X is A and Y is the other node. If U or V is not found in the BST, print in a line ERROR: U is not found. or ERROR: V is not found. or ERROR: U and V are not found..

Sample Input:
6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99
Sample Output:
LCA of 2 and 5 is 3.
8 is an ancestor of 7.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.
*/


#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
map<int,bool>Res;
int main()
{
    int N,K,i,temp;
    cin>>N>>K;
    vector<int>Num;
    for(i=0 ; i<K ; i++)
    {
        cin>>temp;
        Num.push_back(temp);
        Res[temp] = true;
    }
    for(i=0 ; i<N ; i++)
    {
        int u,v,a;
        cin>>u>>v;
        if(Res.count(u)==0 && Res.count(v)==0)
            printf("ERROR: %d and %d are not found.\n",u,v);
        else if(Res.count(u)==0 && Res.count(v)!=0)
            printf("ERROR: %d is not found.\n",u);
        else if(Res.count(v)==0 && Res.count(u)!=0)
            printf("ERROR: %d is not found.\n",v);
        else
        {
            int j;
            for(j=0 ; j<K ; j++)
            {
                a = Num[j];
                if((Num[j]>u&&Num[j]<v) || (Num[j]>v && Num[j]<u) || (Num[j]==u) || (Num[j]==v))
                {
                    break;
                }
            }
            if(a!=u && a!=v)
                printf("LCA of %d and %d is %d.\n",u,v,a);
            else
                printf("%d is an ancestor of %d.\n",a,a==u?v:u);

        }
    }
    return 0;
}



//段错误？？？why
/*
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

typedef TreeNode * Position;
typedef TreeNode * SearchTree;
map<int,int>Res;
SearchTree CreateSearchTree(SearchTree T)
{
    return NULL;
}

SearchTree Insert(int X,SearchTree T)
{
    if(T == NULL)
    {
        T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        T->data = X;
        T->left = NULL;
        T->right = NULL;
    }
    else if (X < T->data)
        T->left = Insert(X,T->left);
    else if(X > T->data)
        T->right = Insert(X,T->right);
}

Position Find(int X,SearchTree T)
{
    if(T==NULL)
        return NULL;
    if(X == T->data)
    {
        Res[T->data]++;
        return T;
    }
    else if(X < T->data)
    {
        Res[T->data]++;
        return Find(X,T->left);
    }
    else if(X > T->data)
    {
        Res[T->data]++;
        return Find(X,T->right);
    }
}

int main()
{
    int N,K,temp,i;
    cin>>N>>K;
    SearchTree T;
    T = CreateSearchTree(T);
    for(i=0 ; i<K ; i++)
    {
        cin>>temp;
        T = Insert(temp,T);
    }
    for(i=0 ; i<N ; i++)
    {
        int U,V,A;
        cin>>U>>V;
        Position U_index,V_index;
        U_index = Find(U,T);
        V_index = Find(V,T);
        if(U_index==NULL && V_index == NULL)
        {
            printf("ERROR: %d and %d are not found.\n",U,V);
        }
        else if(U_index==NULL && V_index!=NULL)
        {
            printf("ERROR: %d is not found.\n",U);
        }
        else if(V_index==NULL && U_index!=NULL)
        {
            printf("ERROR: %d is not found.\n",V);
        }
        else
        {
            if(U<T->data && V<T->data)
            {
                auto k = Res.begin();
                for( ; k->second!= 2 ; k++);
                A = k->first;
            }
            else
            {
                auto k = Res.rbegin();
                for( ; k->second!= 2 ; k++);
                A = k->first;
            }
            if(A == U)
            {
                printf("%d is an ancestor of %d.\n",U,V);
            }
            else if(A == V)
            {
                printf("%d is an ancestor of %d.\n",V,U);
            }
            else
            {
                printf("LCA of %d and %d is %d.\n",U,V,A);
            }
        }
        Res.clear();
    }
}
*/


/*运行超时，段错误
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdio>
using namespace std;
vector<int>Level(1000000,0);   //二叉树
int N,M; //分别代表需要判断的对数以及二叉树的结点数

void Insert(int x,int index)
{
    if(Level[index] == 0)
        Level[index] = x;
    else if(x < Level[index])
        Insert(x,index*2);
    else if(x > Level[index])
        Insert(x,index*2+1);
}


int Find(vector<int>L,int X,int index)
{
    if(L.empty())
        return -1;
    if(L[index] == 0 )
        return -1;
    if(X == L[index])
        return index;
    else if(X > L[index])
        return Find(L,X,2*index+1);
    else if(X < L[index])
        return Find(L,X,2*index);
}

int main()
{
    int i;
    cin>>N>>M;
    vector<int>Pre(M+1);    //先序遍历的二叉树的元素
    for(i=1 ; i<=M ; i++)
    {
        cin>>Pre[i];
    }
    for(i=1 ; i<=M; i++)
        Insert(Pre[i],1);
    for(i=0 ; i<N ; i++)
    {
        int U,V,A,U_index,V_index;
        cin>>U>>V;
        U_index = Find(Level,U,1);
        V_index = Find(Level,V,1);
        if(U_index==-1 && V_index == -1)
        {
            printf("ERROR: %d and %d are not found.\n",U,V);
        }
        else if(U_index==-1 && V_index!=-1)
        {
            printf("ERROR: %d is not found.\n",U);
        }
        else if(V_index==-1 && U_index!=-1)
        {
            printf("ERROR: %d is not found.\n",V);
        }
        else
        {
            while(U_index != V_index)
            {
                if(U_index > V_index)
                    U_index = U_index / 2;
                else
                    V_index = V_index / 2;
            }
            A = Level[U_index];
            if(A == U)
            {
                printf("%d is an ancestor of %d.\n",U,V);
            }
            else if(A == V)
            {
                printf("%d is an ancestor of %d.\n",V,U);
            }
            else
            {
                printf("LCA of %d and %d is %d.\n",U,V,A);
            }
        }
    }
    return 0;
}
*/
