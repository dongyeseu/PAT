/*
1064 Complete Binary Search Tree (30)（30 分）
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:

10
1 2 3 4 5 6 7 8 9 0
Sample Output:

6 3 8 1 5 7 9 0 2 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int>BT(10000,-1);

void CreateBTree(int List[],int start,int ed,int index)
{
    if(start > ed)
        return;
    int n = ed - start + 1;
    int level = log(n+1) / log(2);
    int leaf = n - (pow(2,level)-1);
    int mid = start + pow(2,level-1)-1 + min((int)pow(2,level-1),leaf);
    BT[index] = List[mid];
    CreateBTree(List,start,mid-1,index*2);
    CreateBTree(List,mid+1,ed,index*2+1);
}

int main()
{
    int N;
    cin>>N;
    vector<int>Origin(N);
    int i;
    for(i=0 ; i<N ; i++)
        cin>>Origin[i];
    sort(Origin.begin(),Origin.end());
    int List[N];
    for(i=0 ; i<N ; i++)
        List[i] = Origin[i];
    CreateBTree(List,0,N-1,1);
    cout<<BT[1];
    for(i=2 ; i<=N ; i++)
    {
        cout<<" "<<BT[i];
    }
    return 0;
}





//他山之玉
//柳婼
/*
题目大意：给一串构成树的序列，已知该树是完全二叉搜索树，求它的层序遍历的序列
分析：总得概括来说，已知中序，可求root下标，可以求出层序。
1. 因为二叉搜索树的中序满足：是一组序列的从小到大排列，所以只需排序所给序列即可得到中序
2. 因为根据完全二叉树的结点数，可以求出它的根结点在中序中对应的下标
3. 如此，已知了中序，又可以根据结点数求出根结点的下标，就可以递归求出左右子树的根结点的下标
4. i结点的左孩子为2 * i + 1，右孩子2 * i + 2，就可以根据结点下标和中序数组赋值level数组
5. 最后输出所有结点的层序数组level
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> in, level;
void levelorder(int start, int end, int index) {
    if(start > end) return ;
    int n = end - start + 1;
    int l = log(n + 1) / log(2); // 除了最后一层的层数
    int leave = n - (pow(2, l) - 1);// 最后一层的叶子节点数
    int root = start + (pow(2, l - 1) - 1) + min((int)pow(2, l - 1), leave); // pow(2, l - 1) - 1是除了root结点所在层和最后一层外，左子树的结点个数，pow(2, l - 1) 是l+1层最多拥有的属于根结点左子树的结点个数，min(pow(2, l - 1), leave)是最后一个结点真正拥有的属于根结点左子树上的结点个数
    level[index] = in[root];
    levelorder(start, root - 1, 2 * index + 1);
    levelorder(root + 1, end, 2 * index + 2);
}
int main() {
    int n;
    scanf("%d", &n);
    in.resize(n);
    level.resize(n);
    for(int i = 0 ; i < n; i++)
        scanf("%d", &in[i]);
    sort(in.begin(), in.end());
    levelorder(0, n - 1, 0);
    printf("%d", level[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", level[i]);
    return 0;
}

//（二）
/*
思路：
满二叉树各个节点的位置数（层序遍历）：
left=2*root；
right=2*root+1；
其中一层中节点个数等于最右边节点的位置数，也就是2的层数次方
参照以上知识点，按照中序遍历的方法（左根右）建立该满二叉树
递归代码如下：
int dg(int root)
{
    if(root>n) return 0;//寻找叶子节点
    int l=2*root;//左子树位置
    int r=2*root+1;//右子树位置
    dg(l);//中序遍历：左
    b[root]=a[k++];//中序遍历：中
    dg(r);//中序遍历：右
}
最后记得：数据从小到大排列的顺序也就是二叉搜索树的中序遍历的顺序。
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n=0,k;
int a[1000]={0};
int b[1000]={0};
bool compare(int a,int b)
{
     return a<b;
}
int dg(int root)
{
    if(root>n) return 0;
    int l=2*root;
    int r=2*root+1;
    dg(l);
    b[root]=a[k++];
    dg(r);
}
int main()
{
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,compare);
        k=0;
        dg(1);
        printf("%d",b[1]);
        for(int i=2;i<=n;i++)
        {
            printf(" %d",b[i]);
        }
    return 0;
}
