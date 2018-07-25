/*
1138 Postorder Traversal（25 分）提问
Suppose that all the keys in a binary tree are distinct positive integers. Given the preorder and inorder traversal sequences, you are supposed to output the first number of the postorder traversal sequence of the corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 50,000), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the first number of the postorder traversal sequence of the corresponding binary tree.

Sample Input:
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
Sample Output:
3
*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
vector<int>pre,in;       //必须要使用全局变量，否则会导致内存超限
bool flag = false;
void Post(int root,int start,int ed)
{
    if(flag || start > ed)     //递归结束判断条件
        return;
    int j= start;
    while(j<ed && in[j]!=pre[root])  //确定Inorder的根节点
        j++;
    Post(root+1,start,j-1);    //左子树
    Post(root+j-start+1,j+1,ed);    //右子树
    if(flag==false)       //确定第一个post输出之后，就将flag设置为true，使递归提前结束
    {
        cout<<pre[root]<<"\n";
        flag = true;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    pre.resize(N);    //对vector容器的容积重新定义
    in.resize(N);
    int i;
    for(i=0 ; i<N ; i++)
        scanf("%d",&pre[i]);
    for(i=0 ; i<N ; i++)
        scanf("%d",&in[i]);
    Post(0,0,N-1);
    return 0;
}


//他山之玉
//柳婼
/*
分析：一道简单的前序中序转后序，而且只需要知道后序的第一个值，所以可以定义一个变量flag，当post的第一个值已经输出，则flag为true，递归出口处判断flag，可以提前return
ps：经过测试发现没有flag按照正常前序中序转后序也可以AC，但是我在考场上第一次尝试直接转没有提前退出递归的写法并没有能够AC，而是有一部分运行超时，后来增加了flag才AC。可能pat考试时更为严苛，所以对于准备pat考试的小伙伴，建议如果能够缩小运行时间尽量精益求精
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in;
bool flag = false;
void postOrder(int prel, int inl, int inr) {
    if (inl > inr || flag == true) return;
    int i = inl;
    while (in[i] != pre[prel]) i++;
    postOrder(prel+1, inl, i-1);
    postOrder(prel+i-inl+1, i+1, inr);
    if (flag == false) {
        printf("%d", in[i]);
        flag = true;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    postOrder(0, 0, n-1);
    return 0;
}
