/*
1110 Complete Binary Tree（25 分）提问
Given a tree, you are supposed to tell if it is a complete binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤20) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each case, print in one line YES and the index of the last node if the tree is a complete binary tree, or NO and the index of the root if not. There must be exactly one space separating the word and the number.

Sample Input 1:
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
Sample Output 1:
YES 8
Sample Input 2:
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
Sample Output 2:
NO 1
*/
//复习时所作，全部正确
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;
struct node
{
    int value;
    int left=-1;
    int right=-1;
};
int N;
vector<struct node>Tree;
vector<int>CompleteTree;
void PreorderTravesel(int root,int index)
{
    if(root == -1 || index >=N)
        return;
    CompleteTree[index] = Tree[root].value;
    PreorderTravesel(Tree[root].left,2*index+1);
    PreorderTravesel(Tree[root].right,2*index+2);
}
int main()
{
    int i,root;
    string l,r;
    cin>>N;
    Tree.resize(N);
    CompleteTree.resize(N,-1);
    vector<int>Book(N,0);
    for(i=0 ; i<N ; i++)
    {
        cin>>l>>r;
        if(l!="-")
        {
            Tree[i].left = stoi(l);
            Book[Tree[i].left] = 1;
        }

        if(r != "-")
        {
            Tree[i].right = stoi(r);
            Book[Tree[i].right] = 1;
        }
        Tree[i].value = i;
    }
    for(i=0 ; i<N ; i++)
    {
        if(Book[i] == 0)
        {
            root = i;
            break;
        }
    }
    PreorderTravesel(root,0);
    for(i=0 ; i<N ; i++)
    {
        if(CompleteTree[i] == -1)
        {
            cout<<"NO "<<Tree[root].value<<"\n";
            return 0;
        }
    }
    cout<<"YES "<<CompleteTree[N-1]<<"\n";
    return 0;
}


#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

struct child
{
    int left = -1;
    int right = -1;
};

int main()
{
    int N;
    cin>>N;
    vector<struct child>Tree(N);
    vector<int>Book(N,0);
    int i;
    for(i=0 ; i<N ; i++)
    {
        string a,b;
        cin>>a>>b;
        if(a!="-")
        {
            Tree[i].left = stoi(a);
            Book[Tree[i].left] = 1;
        }
        if(b!="-")
        {
            Tree[i].right = stoi(b);
            Book[Tree[i].right] = 1;
        }
    }
    int root;
    for(i=0 ; i<N ; i++)
    {
        if(Book[i]==0)
        {
            root = i;
            break;
        }
    }
    queue<int>Res;
    Res.push(root);
    int cnt=0,lastnode=0;
    while(!Res.empty())
    {
        int Node = Res.front();
        Res.pop();
        if(Node!=-1)
        {
            lastnode = Node;
            cnt++;
        }
        else
        {
            if(cnt==N)
                printf("YES %d",lastnode);
            else
                printf("NO %d",root);
            return 0;
        }
        Res.push(Tree[Node].left);
        Res.push(Tree[Node].right);
    }
    return 0;
}

/*依然是段错误
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <cstdlib>
using namespace std;

struct TreeNode
{
    int val;
    int left = -1;
    int right = -1;
};

int N;

struct TNode
{
    int data;
    struct TNode * left;
    struct TNode * right;
};

typedef struct TNode * Position;
typedef struct TNode * SearchTree;

SearchTree CreateTree(SearchTree T)
{
    return NULL;
}

SearchTree Insert(SearchTree T,vector<struct TreeNode>Tree,int N)
{
    if(N == -1)
        return NULL;
    T = (struct TNode *)malloc(sizeof(struct TNode));
    T->data = Tree[N].val;
    T->left = Insert(T->left,Tree,Tree[N].left);
    T->right = Insert(T->right,Tree,Tree[N].right);
    return T;
}

SearchTree MakeEmpty(SearchTree T)
{
    if(T==NULL)
        return NULL;
    else
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return T;
}

int main()
{
    cin>>N;
    vector<struct TreeNode>Tree;
    vector<int>Book(N,0);
    int i;
    for(i=0 ; i<N ; i++)
    {
        char a,b;
        struct TreeNode temp;
        cin>>a>>b;
        temp.val = i;
        if(isdigit(a))
        {
            temp.left = a - '0';
            Book[temp.left] = 1;
        }
        if(isdigit(b))
        {
            temp.right = b - '0';
            Book[temp.right] = 1;

        }
        Tree.push_back(temp);
    }
    SearchTree T;
    T = CreateTree(T);
    int bg;
    for(i=0 ; i<N ; i++)
    {
        if(Book[i]==0)
            bg = i;
    }
    T = Insert(T,Tree,bg);
    queue<SearchTree>res;
    res.push(T);
    int ct=0;
    SearchTree lastnode;
    while(!res.empty())
    {
        SearchTree Node = res.front();
        res.pop();
        if(Node == NULL)
        {
            if(ct==N)
                cout<<"YES "<<lastnode->data;
            else
                cout<<"NO "<<T->data;
            return 0;
        }
        else
        {
            lastnode = Node;
            ct++;
        }
        res.push(Node->left);
        res.push(Node->right);
    }
    T = MakeEmpty(T);
    return 0;
}
*/

/*有3个测试点段错误
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

struct TreeNode
{
    int val;
    int left = -1;
    int right = -1;
};

int N;
int cnt;
int Res[1000000];


void Insert(int index,vector<struct TreeNode>Tree,int N)
{
    if(N==-1)
        return;
    Res[index] = Tree[N].val;
    cnt++;
    Insert(2*index,Tree,Tree[N].left);
    Insert(2*index+1,Tree,Tree[N].right);
}

int main()
{
    cin>>N;
    vector<struct TreeNode>Tree;
    int i;
    for(i=0 ; i<N ; i++)
    {
        char a,b;
        struct TreeNode temp;
        cin>>a>>b;
        temp.val = i;
        if(isdigit(a))
            temp.left = a - '0';
        if(isdigit(b))
            temp.right = b - '0';
        Tree.push_back(temp);
    }
    for(i=0 ; i<N ; i++)
    {
        cnt = 0;
        memset(Res,-1,sizeof(int)*10000);
        Insert(1,Tree,i);
        if(cnt==N)
        {
            int flag = 0;
            int j;
            for(j=1 ; j<=N ; j++)
            {
                if(Res[j]==-1)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
            if(flag)
                cout<<"YES "<<Res[N];
            else
                cout<<"NO "<<Res[1];
            return 0;
        }
    }
    return 0;
}
*/




/* 也是3个测试点段错误
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

struct TreeNode
{
    int val;
    int left = -1;
    int right = -1;
};

int N;
int cnt;
vector<int>Res(30,-1);


void Insert(int index,vector<struct TreeNode>Tree,int k)
{
    if(k==-1)
        return;
    if(index<=30)
        Res[index] = Tree[k].val;
    else
        Res[30] = Tree[k].val;
    cnt++;
    Insert(2*index,Tree,Tree[k].left);
    Insert(2*index+1,Tree,Tree[k].right);
}

int main()
{
    cin>>N;
    vector<struct TreeNode>Tree;
    int i;
    for(i=0 ; i<N ; i++)
    {
        char a,b;
        struct TreeNode temp;
        cin>>a>>b;
        temp.val = i;
        if(isdigit(a))
            temp.left = a - '0';
        if(isdigit(b))
            temp.right = b - '0';
        Tree.push_back(temp);
    }
    for(i=0 ; i<N ; i++)
    {
        cnt = 0;
        Insert(1,Tree,i);
        if(cnt==N)
        {
            int flag = 0;
            int j;
            for(j=1 ; j<=N ; j++)
            {
                if(Res[j]==-1)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
            if(flag)
                cout<<"YES "<<Res[N];
            else
                cout<<"NO "<<Res[1];
            return 0;
        }
    }
    return 0;
}
*/


//他山之玉
//柳婼
/*
题目大意：给出一个n表示有n个结点，这n个结点为0~n-1，给出这n个结点的左右孩子，求问这棵树是不是完全二叉树
分析：先用结构体tree[i].left和tree[i].right保存第i结点的左右孩子，然后遍历找出没有出现过的结点，这个结点就是根节点
已知根结点和每个结点的左右孩子，根据二叉树的层序遍历的方法（广度优先搜索，使用队列）遍历这棵二叉树，每遍历一个结点就cnt++，如果发现有-1，判断当前cnt是否和n相等，如果不等，说明该结点不是最后一个结点，返回NO，否则YES
*/
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct TREE {
    int left, right;
};
int main() {
    int n, root = 0;
    scanf("%d", &n);
    vector<TREE> tree(n);
    vector<int> book(n);
    for(int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if(l == "-") {
            tree[i].left = -1;
        } else {
            tree[i].left = stoi(l);
            book[tree[i].left] = 1;
        }
        if(r == "-"){
            tree[i].right = -1;
        } else {
            tree[i].right = stoi(r);
            book[tree[i].right] = 1;
        }   
    }
    for(int i = 0; i < n; i++) {
        if(book[i] == 0) {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    int cnt = 0, lastnode = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node != -1) {
            lastnode = node;
            cnt++;
        }else {
            if(cnt != n)
                printf("NO %d", root);
            else
                printf("YES %d", lastnode);
            return 0;
        }
        q.push(tree[node].left);
        q.push(tree[node].right);
    }
    return 0;
}
