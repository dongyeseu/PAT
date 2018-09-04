题目大意：反转一棵二叉树，给出原二叉树的每个结点的左右孩子，输出它的层序和前序遍历
分析：
1. 反转二叉树就是存储的时候所有左右结点都交换。
2. 二叉树使用tree[i].left和tree[i].right存储每个结点的左右结点
3. 根结点是所有左右结点中没有出现的那个结点
4. 已知根结点，用队列广度优先搜索，队列里面元素出现的顺序就是层序遍历的结果，push_back到数组level里面
5. 已知根结点，用递归的方法可以把中序遍历的结果push_back到数组in里面


#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

struct node
{
    int value;
    int left = -1;
    int right = -1;
};
vector<struct node>Tree;

vector<int>Res;
void InorderTravesel(int root)
{
    if(root == -1)
        return;
    InorderTravesel(Tree[root].right);
    Res.push_back(Tree[root].value);
    InorderTravesel(Tree[root].left);
}
void LevelTravesel(int root)
{
    queue<int>T;
    T.push(root);
    while(!T.empty())
    {
        int nd = T.front();
        T.pop();
        if(Tree[nd].right != -1)
            T.push(Tree[nd].right);
        if(Tree[nd].left != -1)
            T.push(Tree[nd].left);
        Res.push_back(Tree[nd].value);
    }
    return;
}
int main()
{
    int N,i,root;
    cin>>N;
    string l,r;
    Tree.resize(N);
    vector<int>Book(N,0);
    for(i=0 ; i<N ; i++)
    {
        cin>>l>>r;
        if(l!="-")
        {
            Tree[i].left = stoi(l);
            Book[stoi(l)] = 1;
        }

        if(r!="-")
        {
            Tree[i].right = stoi(r);
            Book[stoi(r)] = 1;
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
    LevelTravesel(root);
    InorderTravesel(root);
    int len = Res.size();
    for(i=0 ; i<len ; i++)
    {
        cout<<Res[i];
        if(i==N-1 || i==len-1)
            cout<<"\n";
        else
            cout<<" ";
    }
    return 0;
}



//他山之玉
//柳婼
/*
题目大意：反转一棵二叉树，给出原二叉树的每个结点的左右孩子，输出它的层序和前序遍历
分析：
1. 反转二叉树就是存储的时候所有左右结点都交换。
2. 二叉树使用tree[i].left和tree[i].right存储每个结点的左右结点
3. 根结点是所有左右结点中没有出现的那个结点
4. 已知根结点，用队列广度优先搜索，队列里面元素出现的顺序就是层序遍历的结果，push_back到数组level里面
5. 已知根结点，用递归的方法可以把中序遍历的结果push_back到数组in里面
*/
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<int> in;
struct TREE {
    int left, right;
};
vector<TREE> tree;
void inorder(int root) {
    if(tree[root].left == -1 && tree[root].right == -1) {
        in.push_back(root);
        return ;
    }
    if(tree[root].left != -1)
        inorder(tree[root].left);
    in.push_back(root);
    if(tree[root].right != -1)
        inorder(tree[root].right);
}
int main() {
    int n, root;
    scanf("%d", &n);getchar();
    tree.resize(n);
    vector<int> book(n);
    for(int i = 0; i < n; i++) {
        char c1, c2;
        scanf("%c %c", &c1, &c2);getchar();
        tree[i].right = (c1 == '-' ? -1 : (c1 - '0'));
        tree[i].left = (c2 == '-' ? -1 : (c2 - '0'));
        if(tree[i].left != -1)
            book[tree[i].left] = 1;
        if(tree[i].right != -1)
            book[tree[i].right] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(book[i] == 0) {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    vector<int> level;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(tree[node].left != -1)
            q.push(tree[node].left);
        if(tree[node].right != -1)
            q.push(tree[node].right);
        level.push_back(node);
    }
    for(int i = 0; i < n; i++)
        printf("%d%c", level[i], i == n - 1 ? '\n' : ' ');
    inorder(root);
    printf("%d", in[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", in[i]);
    return 0;
}


//他山之玉
//这个切切实实地反转二叉树了

#include <iostream>
#include <deque>
#include <cstdio>
#include <stack>
 
 
using namespace std;
 
struct Node{
	Node():num(0),pre(-1),left(-1),right(-1){
	};
	int num,pre,left,right;
}nodes[10];
 
void Invert(int root){
	if(root ==-1 || nodes[root].left == -1 && nodes[root].right == -1)
	    return ;
	else{
		int tmp = nodes[root].left;
		nodes[root].left = nodes[root].right;
		nodes[root].right = tmp;
		Invert(nodes[root].left);
		Invert(tmp);
	}
}
 
deque<int>dq;
void Leveltravel(int root){
	printf("%d",root);
	if(nodes[root].left != -1)
	    dq.push_back(nodes[root].left);
	if(nodes[root].right != -1)
	    dq.push_back(nodes[root].right);
	while(!dq.empty()){
		int cur = dq.front();
		printf(" %d",cur);
		dq.pop_front();
		int left = nodes[cur].left;
		int right = nodes[cur].right;
		if(left != -1)
		    dq.push_back(left);
		if(right != -1)
		    dq.push_back(right);
	}
	printf("\n");
}
stack<int> ss;
 
void Inorder(int root){
	bool flag = false;
	int tmp = nodes[root].left;
	ss.push(root);
	while(!ss.empty() || tmp != -1){
		while(tmp != -1){
		    ss.push(tmp);
		    tmp = nodes[tmp].left;		
		}
		int cur = ss.top();
		ss.pop();
        if(!flag){
        	flag = true;
        	printf("%d",cur);
        }else
            printf(" %d",cur);
        tmp = nodes[cur].right;
	}
}
 
int find_root(int n){
	for(int i=0;i<n;i++)
	    if(nodes[i].pre == -1)
	        return i;
}
 
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		char ch1,ch2;
		cin >>ch1 >>ch2;
		nodes[i].num = i;
		if(ch1 != '-'){
			nodes[i].left = ch1 - '0';
			nodes[nodes[i].left].pre = i;
		}	    
		if(ch2 != '-'){
			nodes[i].right = ch2 -'0';
			nodes[nodes[i].right].pre = i;
		}
	}
	int root = find_root(N);
	Invert(root);
	Leveltravel(root);
	Inorder(root);
	return 0;
}
