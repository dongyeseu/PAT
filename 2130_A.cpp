/*
1130 Infix Expression（25 分）提问
Given a syntax tree (binary), you are supposed to output the corresponding infix expression, with parentheses reflecting the precedences of the operators.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20) which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of a node (the i-th line corresponds to the i-th node) in the format:

data left_child right_child
where data is a string of no more than 10 characters, left_child and right_child are the indices of this node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by −1. The figures 1 and 2 correspond to the samples 1 and 2, respectively.

infix1.JPG	infix2.JPG
Figure 1	Figure 2
Output Specification:
For each case, print in a line the infix expression, with parentheses reflecting the precedences of the operators. Note that there must be no extra parentheses for the final expression, as is shown by the samples. There must be no space between any symbols.

Sample Input 1:
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
Sample Output 1:
(a+b)*(c*(-d))
Sample Input 2:
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
Sample Output 2:
(a*2.35)+(-(str%871))
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    string data;
    int left = -1;
    int right = -1;
};

int R;

string DFS(vector<struct TreeNode>Tree,int root)
{
    if(root==-1)
        return "";
    if(Tree[root].right!=-1)
    {
        Tree[root].data = DFS(Tree,Tree[root].left) + Tree[root].data + DFS(Tree,Tree[root].right);
        if(root!=R)
            Tree[root].data = '(' + Tree[root].data + ')';
    }
    return Tree[root].data;
}

int main()
{
    int N,i;
    cin>>N;
    vector<struct TreeNode>Tree(N+1);
    vector<int>Book(N+1,0);
    for(i=1 ; i<=N ; i++)
    {
        cin>>Tree[i].data>>Tree[i].left>>Tree[i].right;
        if(Tree[i].left!=-1)
            Book[Tree[i].left] = 1;
        if(Tree[i].right != -1)
            Book[Tree[i].right] = 1;
    }
    for(i=1 ; i<=N ; i++)
    {
        if(Book[i] == 0)
        {
            R = i;
            break;
        }
    }
    string res = DFS(Tree,R);
    cout<<res;
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：给一个二叉树，输出中缀表达式，且加上括号表示运算的优先级～
分析：首先根据所有孩子结点编号寻找1～n中没有出现过的编号标记为root，即树的根结点～然后进行从root结点开始dfs～如果当前index == -1说明当前没有结点则返回空字符串；当right != -1说明该结点不是叶子节点(不可能存在只有左边没有右边的情况的啦，因为那不符合一个算式～左边可以是空表示0～右边不可以的～)，那么就将左右结点的val和自身的val串成字符串，保存在自己的val中～如果当前index又不是根结点，那就在左右两边加上括号～最后输出dfs(root)的结果即可～
*/
#include <iostream>
#include <vector>
using namespace std;
struct node {
    string val;
    int left, right;
};
vector<node> v;
int n, root = 1;
string dfs(int index) {
    if (index == -1) return "";
    if (v[index].right != -1) {
        v[index].val = dfs(v[index].left) + v[index].val + dfs(v[index].right);
        if (index != root) v[index].val = '(' + v[index].val + ')';
    }
    return v[index].val;
}
int main() {
    cin >> n;
    v.resize(n + 1);
    vector<bool> visit(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].val >> v[i].left >> v[i].right;
        if (v[i].left != -1) visit[v[i].left] = true;
        if (v[i].right != -1) visit[v[i].right] = true;
    }
    while (visit[root] == true) root++;
    cout << dfs(root) << endl;
    return 0;
}
