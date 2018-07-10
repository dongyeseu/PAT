/*
1057 Stack (30)（30 分）
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 10^5^). Then N lines follow, each contains a command in one of the following 3 formats:

Push key\ Pop\ PeekMedian

where key is a positive integer no more than 10^5^.

Output Specification:

For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.

Sample Input:

17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop

Sample Output:

Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/

//运行超时
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    vector<int>num;
    vector<int>copy_num;
    int N;
    cin>>N;
    int i;
    for(i=0 ; i<N ; i++)
    {
        string temp;
        cin>>temp;
        if(temp == "Pop")
        {
            if(num.empty())
                cout<<"Invalid\n";
            else
            {
                cout<<num.back()<<"\n";
                auto i = find(copy_num.begin(),copy_num.end(),num.back());
                num.pop_back();
                copy_num.erase(i);
            }
        }
        else if(temp == "Push")
        {
            int Integer;
            cin>>Integer;
            num.push_back(Integer);
            copy_num.push_back(Integer);
            sort(copy_num.begin(),copy_num.end(),cmp);

        }
        else if(temp == "PeekMedian")
        {
            if(num.empty())
                cout<<"Invalid\n";
            else
            {
                int Size = num.size();
                if(Size%2 == 0)
                    cout<<copy_num[Size/2-1]<<"\n";
                else
                    cout<<copy_num[Size/2]<<"\n";
            }
        }
    }
    return 0;

}
