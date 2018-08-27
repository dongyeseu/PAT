/*
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of 
postorder and inorder traversal sequences, or preorder and inorder traversal sequences. However, if only the postorder and preorder 
traversal sequences are given, the corresponding tree may no longer be unique.

Now given a pair of postorder and preorder traversal sequences, you are supposed to output the corresponding inorder traversal sequence 
of the tree. If the tree is not unique, simply output any one of them.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 30), the total number of nodes in 
the binary tree. The second line gives the preorder sequence and the third line gives the postorder sequence. All the numbers in a line
are separated by a space.

Output Specification:
For each test case, first printf in a line Yes if the tree is unique, or No if not. Then print in the next line the inorder traversal
sequence of the corresponding binary tree. If the solution is not unique, any answer would do. It is guaranteed that at least one 
solution exists. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the 
line.

Sample Input 1:
7
1 2 3 4 6 7 5
2 6 7 4 5 3 1
Sample Output 1:
Yes
2 1 6 4 7 3 5
Sample Input 2:
4
1 2 3 4
2 4 3 1
Sample Output 2:
No
2 1 3 4
*/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
bool flag = true;
vector<int>pre,post,in;

void Inorder(int preleft,int preright,int postleft,int postright)
{
    if(preleft == preright)
    {
        in.push_back(pre[preleft]);
        return;
    }
    if(pre[preleft] == post[postright])
    {
        int i = preleft + 1;
        while(i<=preright && pre[i]!=post[postright-1])
            i++;
        if(i-preleft>1)
            Inorder(preleft+1,i-1,postleft,postleft+(i-1-preleft)-1);
        else
            flag = false;
        in.push_back(post[postright]);
        Inorder(i,preright,postleft+(i-1-preleft),postright-1);
    }
}

int main()
{
    int i,j,N;
    cin>>N;
    pre.resize(N);
    post.resize(N);
    for(i=0 ; i<N ; i++)
        cin>>pre[i];
    for(i=0 ; i<N ; i++)
        cin>>post[i];
    Inorder(0,N-1,0,N-1);
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    for(i=0 ; i<N ; i++)
    {
        if(i==0)
            cout<<in[i];
        else
            cout<<" "<<in[i];
    }
    cout<<"\n";
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：给出一棵树的结点个数n，以及它的前序遍历和后序遍历，输出它的中序遍历，如果中序遍历不唯一就输出No，且输出其中一个中序即可，如果中序遍历唯一
就输出Yes，并输出它的中序
分析：用unique标记是否唯一，如果为true就表示中序是唯一的～
已知二叉树的前序和后序是无法唯一确定一颗二叉树的，因为可能会存在多种情况，这种情况就是一个结点可能是根的左孩子也有可能是根的右孩子，如果发现了一个
无法确定的状态，置unique = 0，又因为题目只需要输出一个方案，可以假定这个不可确定的孩子的状态是右孩子，接下来的问题是如何求根结点和左右孩子划分的
问题了，首先我们需要知道树的表示范围，需要四个变量，分别是前序的开始的地方prel，前序结束的地方prer，后序开始的地方postl，后序结束的地方postr，前
序的开始的第一个应该是后序的最后一个是相等的，这个结点就是根结点，以后序的根结点的前面一个结点作为参考，寻找这个结点在前序的位置，就可以根据这个位
置来划分左右孩子，递归处理。
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool unique = true;
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
	if(preLeft == preRight) {
		in.push_back(pre[preLeft]);
		return;
	}
	if (pre[preLeft] == post[postRight]) {
		int i = preLeft + 1;
		while (i <= preRight && pre[i] != post[postRight-1]) i++;
		if (i - preLeft > 1)
			getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
		else
			unique = false;
		in.push_back(post[postRight]);
		getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	getIn(0, n-1, 0, n-1);
	printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
	for (int i = 1; i < in.size(); i++)
		printf(" %d", in[i]);
	printf("\n");
	return 0;
}


#include <iostream>  
using namespace std;
const int maxn = 31;
 
int n, index = 0;
int pre[maxn], post[maxn];
bool flag = true;
 
struct Node {
	int data;
	Node *lchild, *rchild;
} *root;
 
Node *create(int preL, int preR, int postL, int postR)
{
	if (preL > preR) return NULL;//不合理就返回NULL
	Node *node = new Node;//建立根结点
	node->data = pre[preL];
	node->lchild = NULL;
	node->rchild = NULL;
	if (preL == preR)
		return node;//若只有一个节点那么直接返回即可
	int k = 0;
	for (k = preL + 1; k <= preR; k++)
	{
		if (pre[k] == post[postR - 1]) break;//从前序中找后序中子树根的位置
	}
	if (k - preL > 1)
	{
		node->lchild = create(preL + 1, k - 1, postL, postL + k - preL - 2);
		node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	else
	{
		flag = false;
		node->rchild = create(k, preR, postL + k - preL - 1, postR - 1);
	}
	return node;
}
 
void inOrder(Node *node)
{
	if (node == NULL) return;
	inOrder(node->lchild);
	if (index < n - 1)
		cout << node->data << " ";
	else cout << node->data << endl;
	index++;
	inOrder(node->rchild);
}
 
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> pre[i];
	for (int i = 0; i < n; ++i) cin >> post[i];
	root = create(0, n - 1, 0, n - 1);
	if (flag) cout << "Yes\n";
	else cout << "No\n";
	inOrder(root);
	return 0;
}

