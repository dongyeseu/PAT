/*
115 Counting Nodes in a BST（30 分）提问
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤1000) which is the size of the input sequence. Then given in the next line are the N integers in [−10001000] which are supposed to be inserted into an initially empty binary search tree.

Output Specification:
For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:

n1 + n2 = n
where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.

Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6
*/
//测试点全部通过
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode * Left;
    struct TreeNode * Right;
};

typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

SearchTree CreateSearchTree(SearchTree T)
{
    return NULL;
}

SearchTree Insert(int X , SearchTree T)
{
    if(T == NULL)
    {
        T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        T->data = X;
        T->Left = NULL;
        T->Right = NULL;
    }
    else if (X <= T->data)
    {
        T->Left = Insert(X,T->Left);
    }
    else if (X > T->data)
    {
        T->Right = Insert(X,T->Right);
    }
    return T;
}

int maxdepth = -1;
int Res[1000] = {0};
void DFS(SearchTree T,int depth)
{
    if(T == NULL)
    {
        maxdepth = max(maxdepth,depth);
        return;
    }
    Res[depth]++;
    DFS(T->Left,depth+1);
    DFS(T->Right,depth+1);
}

int main()
{
    int N;
    cin>>N;
    int i,temp;
    SearchTree T;
    T = CreateSearchTree(T);
    for(i=0 ; i<N ; i++)
    {
        cin>>temp;
        T = Insert(temp,T);
    }
    DFS(T,0);
    printf("%d + %d = %d\n",Res[maxdepth-1],Res[maxdepth-2],Res[maxdepth-1]+Res[maxdepth-2]);
    return 0;
}



//最后一个测试点答案错误
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode * Left;
    struct TreeNode * Right;
};

typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

SearchTree CreateSearchTree(SearchTree T)
{
    return NULL;
}

SearchTree Insert(int X , SearchTree T)
{
    if(T == NULL)
    {
        T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        T->data = X;
        T->Left = NULL;
        T->Right = NULL;
    }
    else if (X <= T->data)
    {
        T->Left = Insert(X,T->Left);
    }
    else if (X > T->data)
    {
        T->Right = Insert(X,T->Right);
    }
    return T;
}

int LevelTree(SearchTree T,int X)
{
    if(T == NULL)
        return 0;
    else if(T->data == X)
        return 1;
    else{
        int c1 = LevelTree(T->Left,X);
        if(c1>=1)
            return c1+1;
        int c2 = LevelTree(T->Right,X);
        if(c2>=1)
            return c2+1;
        return 0;
    }
}

int main()
{
    int N;
    cin>>N;
    int i,temp;
    SearchTree T;
    T = CreateSearchTree(T);
    vector<int>Num;
    vector<int>Res;
    map<int,int>num;
    map<int,int>S;
    int cnt = N;
    for(i=0 ; i<N ; i++)
    {
        cin>>temp;
        if(temp<=1000 && temp>=-1000)
        {
            Num.push_back(temp);
            T = Insert(temp,T);
        }
        else
        {
            cnt--;
        }

    }
    N = cnt;
    for(i=0 ; i<N ; i++)
    {
        temp = LevelTree(T,Num[i]);
        if(num.count(Num[i])==0)
        {
            num[Num[i]] = temp;
        }
        else
        {
            temp = num[Num[i]]+1;
            num[Num[i]] = temp;
        }
        Res.push_back(temp);
    }
    for(i=0 ; i<N ; i++)
    {
        S[Res[i]]++;
    }
    auto j = S.rbegin();
    i = 0;
    int n[2] = {0};
    for( ; i<2&&j!=S.rend() ; j++)
    {
        n[i] = j->second;
        i++;
    }
    cout<<n[0]<<" + "<<n[1]<<" = "<<n[0]+n[1]<<"\n";
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：输出一个二叉搜索树的最后两层结点个数a和b，以及他们的和c：“a + b = c”
分析：用链表存储，递归构建二叉搜索树，深度优先搜索，传入的参数为结点和当前结点的深度depth，如果当前结点为NULL就更新最大深度maxdepth的值并return，将每一层所对应的结点个数存储在数组num中，输出数组的最后两个的值~~~~
/*
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int v;
    struct node *left, *right;
};
node* build(node *root, int v) {
    if(root == NULL) {
        root = new node();
        root->v = v;
        root->left = root->right = NULL;
    } else if(v <= root->v)
        root->left = build(root->left, v);
    else
        root->right = build(root->right, v);
    return root;
}
vector<int> num(1000);
int maxdepth = -1;
void dfs(node *root, int depth) {
    if(root == NULL) {
        maxdepth = max(depth, maxdepth);
        return ;
    }
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
    
}
int main() {
    int n, t;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        root = build(root, t);
    }
    dfs(root, 0);
    printf("%d + %d = %d", num[maxdepth-1], num[maxdepth-2], num[maxdepth-1] + num[maxdepth-2]);
    return 0;
}
