/*

1020 Tree Traversals (25)（25 分）
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:

7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:

4 1 6 3 5 7 2
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int>level(10000,0);

void Level(vector<int>p,vector<int>i,int root,int start,int ed ,int index)
{
    if(start>ed)
        return;
    int j=start;
    while(j<ed && p[root]!=i[j])
        j++;
    level[index] = p[root];
    Level(p,i,j-1+root-ed,start,j-1,2*index);
    Level(p,i,root-1,j+1,ed,2*index+1);
}

int main()
{
    int N;
    cin>>N;
    vector<int>post(N+1,0);
    vector<int>in(N+1,0);

    int i;
    for(i=1 ; i<=N ; i++)
        cin>>post[i];
    for(i=1 ; i<=N ; i++)
        cin>>in[i];
    Level(post,in,N,1,N,1);
    int cnt = 0;
    for(i=1 ; i<10000; i++)
    {
        if(level[i]!=0)
        {
            cnt++;
            if(cnt==1)
                cout<<level[i];
            else
                cout<<" "<<level[i];
        }
    }
    cout<<"\n";
    return 0;
}


//他山之玉
//柳婼
#include <iostream>
#include <vector>
using namespace std;
vector<int> post, in, level(100000, -1);
void pre(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    for(int i = 0; i < level.size(); i++) {
        if (level[i] != -1) {
            if (cnt != 0) printf(" ");
            printf("%d", level[i]);
            cnt++;
        }
        if (cnt == n) break;
    }
    return 0;
}


//他山之玉
#include <iostream>
#include <deque>
 
const int SIZE = 33;
using namespace std;
 
int pa[SIZE],ia[SIZE];
 
struct Node{
	Node(int a){
		value = a;
		left =NULL;
		right = NULL;
	}
	int value;
	Node *left;
	Node *right;
};
 
Node * build_tree(int start1,int end1,int start2,int end2){
//	Node * root=NULL;
	if(start1 > end1 || start2 - end2 != start1-end1)
	    return NULL;
	else {
	    int j=start2;
    	while( ia[j] != pa[end1])
	        j++;
	    Node *pNode =  new Node(ia[j]);
	    int newend1 = start1+j-1-start2;
		pNode->left = build_tree(start1,newend1,start2,j-1);
		pNode->right = build_tree(newend1+1,end1-1,j+1,end2);
		return pNode;
	}
	    
}
 
deque <Node *>dq;
 
void bfs(Node *pNode){
	printf("%d",pNode->value);
	if(pNode->left)
	    dq.push_back(pNode->left);
	if(pNode->right)
	    dq.push_back(pNode->right);
	while(!dq.empty()){
		Node *p = dq.front();
		printf(" %d",p->value);
		if(p->left)
		    dq.push_back(p->left);
		if(p->right)
		    dq.push_back(p->right);
		dq.pop_front();
	}
	printf("\n");
}
 
int main()
{
	int N;
//	freopen("test.txt","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	    scanf("%d",&pa[i]);
	for(int i=0;i<N;i++)
	    scanf("%d",&ia[i]);
    if(N==1){
    	printf("%d\n",ia[0]);
    	return 0;
	}
	Node *root = NULL;
	root = build_tree(0,N-1,0,N-1);
	bfs(root);
//	fclose(stdin);
	return 0;
}
