/*
1099 Build A Binary Search Tree (30)（30 分）提问
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.

The right subtree of a node contains only nodes with keys greater than or equal to the node's key.

Both the left and right subtrees must also be binary search trees.

Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.



Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:

For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:

9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:

58 25 82 11 38 67 45 73 42
*/
//复习时更简洁的写法
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
    int left;
    int right;
};
vector<struct node>Node;
vector<int>Value;
struct TreeNode
{
    int value = 0;
    struct TreeNode * Left;
    struct TreeNode * Right;
};

typedef struct TreeNode * SearchTree;

SearchTree CreateSearchTree(SearchTree T)
{
    return NULL;
}
int z = 0;
SearchTree Insert(SearchTree T,int root)
{
    if(T == NULL)
    {
        T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        T->Left = NULL;
        T->Right = NULL;
    }
    if(Node[root].left != -1)
        T->Left = Insert(T->Left,Node[root].left);
    T->value = Value[z++];
    if(Node[root].right != -1)
        T->Right = Insert(T->Right,Node[root].right);
    return T;
}
void LevelTraversel(SearchTree T)
{
    queue<SearchTree>Tree;
    Tree.push(T);
    int cnt = 0;
    while(!Tree.empty())
    {
        SearchTree Node = Tree.front();
        Tree.pop();
        if(Node->Left != NULL)
            Tree.push(Node->Left);
        if(Node->Right != NULL)
            Tree.push(Node->Right);
        if(cnt!=0)
            cout<<" ";
        cout<<Node->value;
        cnt++;
    }
    return ;
}
int main()
{
    int N,i;
    cin>>N;
    Value.resize(N);
    Node.resize(N);
    for(i=0 ; i<N ; i++)
    {
        cin>>Node[i].left>>Node[i].right;
    }
    for(i=0 ; i<N ; i++)
        cin>>Value[i];
    sort(Value.begin(),Value.end());
    SearchTree T;
    T = CreateSearchTree(T);
    T = Insert(T,0);
    LevelTraversel(T);
    return 0;
}


#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct child{
    int left;
    int right;
};

struct TreeNode
{
    int val;
    struct TreeNode * Left;
    struct TreeNode * Right;
};

typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

SearchTree CreateTree(SearchTree T)    //二叉树初始化
{
    return NULL;
}

SearchTree Insert(SearchTree T,vector<struct child>Tree,int index) //按照结构体数组构建的二叉树构建链表型搜索二叉树
{
    if(index==-1)
        return NULL;
    T = (struct TreeNode * )malloc(sizeof(struct TreeNode));
    T->val = 0;
    T->Left = Insert(T,Tree,Tree[index].left);
    T->Right = Insert(T,Tree,Tree[index].right);
    return T;
}

int j = 0;
void InOrder(SearchTree T,vector<int>Num)      //由于二叉搜索树的中序遍历数据大小从小到大，因此将数据按照中序遍历插入二叉树中
{
    if(T == NULL)
        return;
    InOrder(T->Left,Num);
    T->val = Num[j++];
    InOrder(T->Right,Num);
}

int main()
{
    int N,i,root;
    cin>>N;
    vector<struct child>Tree(N);
    vector<int>Book(N,0);
    for(i=0 ; i<N ; i++)
    {
        cin>>Tree[i].left>>Tree[i].right;
        if(Tree[i].left!=-1)
            Book[Tree[i].left] = 1;
        if(Tree[i].right != -1)
            Book[Tree[i].right] = 1;
    }
    for(i=0 ; i<N ; i++)
    {
        if(Book[i]!=1)
        {
            root = i;
            break;
        }
    }
    SearchTree T;
    T = CreateTree(T);
    T = Insert(T,Tree,root);
    vector<int>Num(N);
    for(i=0 ; i<N ; i++)
        cin>>Num[i];
    sort(Num.begin(),Num.end());
    InOrder(T,Num);
    queue<SearchTree>Res;
    Res.push(T);
    int cnt = 1;
    while(!Res.empty())     //广度优先搜索，层序遍历
    {
        SearchTree Node = Res.front();
        Res.pop();
        if(Node!=NULL)
        {
            if(cnt==1)
            {
                cout<<Node->val;
            }
            else
            {
                cout<<" "<<Node->val;
            }
            Res.push(Node->Left);
            Res.push(Node->Right);
        }
        cnt++;
    }
    return 0;

}

/*
题目大意：给出一棵二叉搜索树（给出每个结点的左右孩子），且已知根结点为0，求并且给出应该插入这个二叉搜索树的数值，求这棵二叉树的层序遍历
分析：
1. 用结构体left right value表示这棵树的结构，根据输入可知树tree[i]的left和right
2. 因为是二叉搜索树，所以中序遍历这棵树得到的结点顺序应该是给出的数值序列从小到大的排列顺序，所以把数值序列排序后，可以在中序遍历的时候直接赋值当前tree[root].value~~~
3. 然后用队列层序遍历这棵树，遍历的时候就可以输出~~~
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct TREE {
    int left, right, value;
};
vector<TREE> tree;
vector<int> v;
int t = 0;
void inorder(int root) {
    if(tree[root].left == -1 && tree[root].right == -1) {
        tree[root].value = v[t++];
        return ;
    }
    if(tree[root].left != -1) inorder(tree[root].left);
    tree[root].value = v[t++];
    if(tree[root].right != -1) inorder(tree[root].right);
}
 
int main() {
    int n;
    scanf("%d", &n);
    tree.resize(n);
    v.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d %d",&tree[i].left, &tree[i].right);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    inorder(0);
    queue<int> q;
    q.push(0);
    printf("%d", tree[0].value);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node != 0) printf(" %d", tree[node].value);
        if(tree[node].left != -1) q.push(tree[node].left);
        if(tree[node].right != -1) q.push(tree[node].right);
    }
    return 0;
}
