/*
1135 Is It A Red-Black Tree（30 分）
There is a kind of balanced binary search tree named red-black tree in the data structure. It has the following 5 properties:

(1) Every node is either red or black.
(2) The root is black.
(3) Every leaf (NULL) is black.
(4) If a node is red, then both its children are black.
(5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
For example, the tree in Figure 1 is a red-black tree, while the ones in Figure 2 and 3 are not.

rbf1.jpg	rbf2.jpg	rbf3.jpg
Figure 1	Figure 2	Figure 3
For each given binary search tree, you are supposed to tell if it is a legal red-black tree.

Input Specification:
Each input file contains several test cases. The first line gives a positive integer K (≤30) which is the total number of cases. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the preorder traversal sequence of the tree. While all the keys in a tree are positive integers, we use negative signs to represent red nodes. All the numbers in a line are separated by a space. The sample input cases correspond to the trees shown in Figure 1, 2 and 3.

Output Specification:
For each test case, print in a line "Yes" if the given tree is a red-black tree, or "No" if not.

Sample Input:
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17
Sample Output:
Yes
No
No
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

struct TreeNode     //树的结点
{
    int value; //值
    int color; //颜色
    struct TreeNode * Left; //左子树
    struct TreeNode * Right; //右子树
};

typedef struct TreeNode * RedBlackTree;
typedef struct TreeNode * Position;

int flag = 0; //0为red下面都是black；1为red下面存在red结点
set<int>Res; //记录从根节点到叶子NULL所经过的黑结点的数目
RedBlackTree CreateTree(RedBlackTree T) //建立树
{
    return NULL;
}

RedBlackTree Insert(int x , RedBlackTree T) //插入结点的值
{
    if(T == NULL)
    {
        T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        T->value = abs(x);
        if(x<0)
            T->color = 1; //红为1
        else
            T->color = 0; //黑为0
        T->Left = NULL;
        T->Right = NULL;
    }
    else
    {
        if(abs(x) < T->value)
        {
            T->Left = Insert(x,T->Left);
        }
        else if (abs(x) > T->value)
        {
            T->Right = Insert(x,T->Right);
        }
    }
    return T;
}

RedBlackTree MakeEmpty(RedBlackTree T)      //清空树
{
    if(T!=NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

void preOrderTraverse1(RedBlackTree T) //用于判断条件4
{
    if(T == NULL)
        return;
    if(T->color == 1)
    {
        if((T->Left!=NULL&&T->Left->color==1)||(T->Right!=NULL && T->Right->color==1))
        {
            flag = 1;
            return;
        }
    }
    preOrderTraverse1(T->Left);
    preOrderTraverse1(T->Right);
}

void DFS(RedBlackTree T,int depth) //深度优先搜索，用于判断条件5
{
    if(T==NULL)
    {
        Res.insert(depth);
        return ;
    }
    if(T->color == 0)
        depth++;
    DFS(T->Left,depth);
    DFS(T->Right,depth);
}

bool IsRedBlack(RedBlackTree T)
{
    if(T->color == 1) //用于判断条件2
        return false;
    preOrderTraverse1(T);
    if(flag==1)
    {
        flag = 0;
        return false;
    }
    else
    {
        Res.clear();
        DFS(T,0);
        if(Res.size()==1)
        {
            Res.clear();
            return true;
        }
        else
        {
            Res.clear();
            return false;
        }
    }
}

int main()
{
    int N,M,temp,i,j;
    cin>>N;
    RedBlackTree T;
    T = CreateTree(T);
    for(i=0 ; i<N ; i++)
    {
        cin>>M;
        for(j=0 ; j<M ; j++)
        {
            cin>>temp;
            T = Insert(temp,T);
        }
        if(IsRedBlack(T))
            printf("Yes\n");
        else
            printf("No\n");
        T = MakeEmpty(T);
    }
}


//他山之玉
//柳婼
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr;
struct node {
    int val;
    struct node *left, *right;
};
node* build(node *root, int v) {
    if(root == NULL) {
        root = new node();
        root->val = v;
        root->left = root->right = NULL;
    } else if(abs(v) <= abs(root->val))
        root->left = build(root->left, v);
    else
        root->right = build(root->right, v);
    return root;
}
bool judge1(node *root) {
    if (root == NULL) return true;
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0) return false;
        if (root->right != NULL && root->right->val < 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}
int getNum(node *root) {
    if (root == NULL) return 0;
    int l = getNum(root->left);
    int r = getNum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(node *root) {
    if (root == NULL) return true;
    int l = getNum(root->left);
    int r = getNum(root->right);
    if(l != r) return false;
    return judge2(root->left) && judge2(root->right);
}
int main() {
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        arr.resize(n);
        node *root = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
            root = build(root, arr[j]);
        }
        if (arr[0] < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
