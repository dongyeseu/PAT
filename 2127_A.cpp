/*
1127 ZigZagging on a Tree（30 分）
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a 
given pair of postorder and inorder traversal sequences. And it is a simple standard routine to print the numbers in 
level-order. However, if you think the problem is too simple, then you are too naive. This time you are supposed to print
the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between
left to right and right to left. For example, for the following tree you must output: 1 11 5 8 17 12 20 15.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number 
of nodes in the binary tree. The second line gives the inorder sequence and the third line gives the postorder sequence.
All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must be separated by 
exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output:
1 11 5 8 17 12 20 15
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

vector<int>post,in;
int Tree[10000] = {0};
void GetTree(int root,int start,int ed,int index)
{
    if(start > ed)
        return;
    int j = start;
    while(j<ed && in[j]!=post[root])
        j++;
    Tree[index] = post[root];
    GetTree(root-(ed-j)-1,start,j-1,2*index);
    GetTree(root-1,j+1,ed,2*index+1);
}
int main()
{
    int N;
    cin>>N;
    post.resize(N);
    in.resize(N);
    int i;
    for(i=0 ; i<N ; i++)
        cin>>in[i];
    for(i=0 ; i<N ; i++)
        cin>>post[i];
    GetTree(N-1,0,N-1,1);
    map<int,vector<int>>Depth;
    for(i=1 ; i<10000 ; i++)
    {
        if(Tree[i] != 0)
        {
            int depth = log(i)/log(2)+1;
            Depth[depth].push_back(Tree[i]);
        }
    }
    for(auto j = Depth.begin() ; j!= Depth.end() ; j++)
    {
        if(j == Depth.begin())
            cout<<j->second[0];
        else
        {
            vector<int>Output(j->second.begin(),j->second.end());
            if(j->first % 2 != 0)
                reverse(Output.begin(),Output.end());
            for(auto c : Output)
                cout<<" "<<c;
        }
    }
    cout<<"\n";
    return 0;
}
