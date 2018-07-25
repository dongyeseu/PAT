/*
1043 Is It a Binary Search Tree (25)（25 分）
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:

7
8 6 5 7 10 8 11
Sample Output 1:

YES
5 7 6 8 11 10 8
Sample Input 2:

7
8 10 11 8 6 7 5
Sample Output 2:

YES
11 8 10 7 5 6 8
Sample Input 3:

7
8 6 8 5 10 9 11
Sample Output 3:

NO
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int>res;

void CreateBTree_1(int *List, int *BT,int n)
{
    int i,order = 1;
    BT[1] = List[0];
    for(i=1 ;i<n ; i++)
    {
        order = 1;
        while(BT[order]!=0)
        {
            if(BT[order]>List[i])
                order = order * 2;
            else
                order = order * 2 + 1;
        }
        BT[order] = List[i];
    }
}
void CreateBTree_2(int *List, int *BT,int n)
{
    int i,order = 1;
    BT[1] = List[0];
    for(i=1 ;i<n ; i++)
    {
        order = 1;
        while(BT[order]!=0)
        {
            if(List[i]>=BT[order])
                order = order * 2;
            else
                order = order * 2 + 1;
        }
        BT[order] = List[i];
    }
}

void PreOrder(int BT[],int index)
{
    if(index>=20000 || BT[index]==0)
        return;
    res.push_back(BT[index]);
    PreOrder(BT,2*index);
    PreOrder(BT,2*index+1);
}

void PostOrder(int BT[],int index)
{
    if(index>=20000 || BT[index]==0)
        return;
    PostOrder(BT,2*index);
    PostOrder(BT,2*index+1);
    res.push_back(BT[index]);
}

int main()
{
    int N;
    cin>>N;
    int List[N];
    int i;
    for(i=0 ; i<N ; i++)
        cin>>List[i];
    int BT[20000] = {0};
    if(List[0]>List[1])
        CreateBTree_1(List,BT,N);
    else
        CreateBTree_2(List,BT,N);
    PreOrder(BT,1);
    int flag = 1;
    int len = res.size();
    for(i=0 ; i<len ; i++)
    {
        if(res[i]!=List[i] || len<N)
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        res.clear();
        PostOrder(BT,1);
        int len = res.size();
        cout<<"YES\n";
        for(i=0;i<len;i++)
        {
            if(i==0)
                cout<<res[i];
            else
                cout<<" "<<res[i];
        }
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}

//思路二，直接写出二叉搜索树
#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>
using namespace std;
queue<int>Res;
queue<int>res;
int cnt=0;
struct TreeNode
{
    int data;
    struct TreeNode * Left;
    struct TreeNode * Right;
};
typedef struct TreeNode * SearchTree;
typedef struct TreeNode * Position;

SearchTree CreateSearchTree(SearchTree T)
{
    return NULL;
}

SearchTree Insert_1(int X,SearchTree T)
{
    if(T == NULL)
    {
        T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        T->data = X;
        T->Left = NULL;
        T->Right = NULL;
    }
    else if(X < T->data)
    {
        T->Left = Insert_1(X,T->Left);
    }
    else if(X >= T->data)
    {
        T->Right = Insert_1(X , T->Right);
    }
    return T;
}

SearchTree Insert_2(int X,SearchTree T)
{
    if(T == NULL)
    {
        T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        T->data = X;
        T->Left = NULL;
        T->Right = NULL;
    }
    else if(X >= T->data)
    {
        T->Left = Insert_2(X,T->Left);
    }
    else if(X < T->data)
    {
        T->Right = Insert_2(X , T->Right);
    }
    return T;
}

void Post(SearchTree T)
{
    /*
    if(T!=NULL)
    {
        Post(T->Left);
        Post(T->Right);
        res.push(T->data);
    }
    */
    if(T == NULL)
        return;
    Post(T->Left);
    Post(T->Right);
    res.push(T->data);


}

void PreOrderTraversel(SearchTree T)
{
    if(T == NULL)
        return;
    Res.push(T->data);
    PreOrderTraversel(T->Left);
    PreOrderTraversel(T->Right);
}



int main()
{
    int N;
    cin>>N;
    int i,temp;
    SearchTree T;
    T = CreateSearchTree(T);
    vector<int>Origin;
    for(i=0 ; i<N ; i++)
    {
        cin>>temp;
        Origin.push_back(temp);
    }
    if(Origin[1]<Origin[0])
    {
        for(i=0 ; i<N ; i++)
            T = Insert_1(Origin[i],T);
    }
    else
    {
        for(i=0 ; i<N ; i++)
            T = Insert_2(Origin[i],T);
    }
    PreOrderTraversel(T);
   // cout<<Res.size();
    int flag=0;
    i=0;
    while(!Res.empty())
    {
        temp = Res.front();
        if(temp == Origin[i++])
        {
            flag = 1;
            Res.pop();
        }
        else
        {
            flag = 0;
            while(!Res.empty())
                Res.pop();
        }
    }
    if(flag == 1)
    {
        cout<<"YES\n";
        Post(T);
        i = 0;
        while(!res.empty())
        {
            if(i==0)
            {
                temp = res.front();
                cout<<temp;
                i++;
                res.pop();
            }
            else
            {
                temp = res.front();
                cout<<" "<<temp;
                i++;
                res.pop();
            }
        }
        cout<<"\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;

}

//他山之玉
//柳婼
/*
题目大意：给定一个整数键值序列，现请你编写程序，判断这是否是对一棵二叉搜索树或其镜像进行前序遍历的结果。
分析：假设它是二叉搜索树，一开始isMirror为FALSE，根据二叉搜索树的性质将已知的前序转换为后序，转换过程中，如果发现最后输出的后序数组长度不为n，那就设isMirror为true，然后清空后序数组，重新再转换一次（根据镜面二叉搜索树的性质），如果依旧转换后数组大小不等于n，就输出no否则输出yes
*/
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}
