/*
1147 Heaps£¨30 ·Ö£©ÌáÎÊ
In computer science, a heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. A common implementation of a heap is the binary heap, in which the tree is a complete binary tree. (Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))

Your job is to tell if a given complete binary tree is a heap.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: M (¡Ü 100), the number of trees to be tested; and N (1 < N ¡Ü 1,000), the number of keys in each tree, respectively. Then M lines follow, each contains N distinct integer keys (all in the range of int), which gives the level order traversal sequence of a complete binary tree.

Output Specification:
For each given tree, print in a line Max Heap if it is a max heap, or Min Heap for a min heap, or Not Heap if it is not a heap at all. Then in the next line print the tree's postorder traversal sequence. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line.

Sample Input:
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56
Sample Output:
Max Heap
50 60 65 72 12 23 86 98
Min Heap
60 58 52 38 82 70 25 8
Not Heap
56 12 34 28 9 8 15 10
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int>post;
vector<int>Res;
int N;
int K;

void Max_Heap(vector<int>T,int index)
{
    if(index > N)
        return;
    if(2*index>N)
        return;
    if(2*index+1<=N && T[index]>=T[2*index] && T[index]>=T[2*index+1])
        Res.push_back(1);
    else if(2*index<=N && T[index]>=T[2*index])
        Res.push_back(1);
    else
    {
        Res.push_back(0);
        return;
    }
    Max_Heap(T,2*index);
    Max_Heap(T,2*index+1);
}

void Min_Heap(vector<int>T,int index)
{
    if(index > N)
        return;
    if(2*index>N)
        return;
    if(2*index+1<=N && T[index]<=T[2*index] && T[index]<=T[2*index+1])
        Res.push_back(1);
    else if(2*index<=N && T[index]<=T[2*index])
        Res.push_back(1);
    else
    {
        Res.push_back(0);
        return;
    }
    Min_Heap(T,2*index);
    Min_Heap(T,2*index+1);
}

void PostOrderTraversel(vector<int>T,int index)
{
    if(index>N)
        return;
    PostOrderTraversel(T,2*index);
    PostOrderTraversel(T,2*index+1);
    post.push_back(T[index]);
}

int main()
{
    cin>>K>>N;
    vector<int>T(N+1);
    int i,j;
    for(i=0 ; i<K ; i++)
    {
        for(j=1 ; j<=N ; j++)
            cin>>T[j];
        if(T[1] > T[N])
        {
            Max_Heap(T,1);
            int flag;
            for(auto z : Res)
            {
                if(z==0)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
            if(flag)
                cout<<"Max Heap\n";
            else
                cout<<"Not Heap\n";
            Res.clear();
        }
        else if(T[1] < T[N])
        {
            Min_Heap(T,1);
            int flag;
            for(auto z : Res)
            {
                if(z==0)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
            if(flag)
                cout<<"Min Heap\n";
            else
                cout<<"Not Heap\n";
            Res.clear();
        }
        PostOrderTraversel(T,1);
        int len = post.size();
        for(j=0 ; j<len ; j++)
        {
            if(j!=0)
                cout<<" "<<post[j];
            else
                cout<<post[j];
        }
        cout<<"\n";
        post.clear();
    }
    return 0;

}
