/*
1101 Quick Sort (25)（25 分）
There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?

For example, given N = 5 and the numbers 1, 3, 2, 4, and 5. We have:

1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;\

3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;\

2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;\

and for the similar reason, 4 and 5 could also be the pivot.\

Hence in total there are 3 pivot candidates.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<= 10^5^). Then the next line contains N distinct positive integers no larger than 10^9^. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:

5
1 3 2 4 5
Sample Output:

3
1 4 5
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,i;
    cin>>N;
    int num[N];
    for(i=0 ; i<N ; i++)
        cin>>num[i];
    map<int,int>Temp;
    vector<int>res;
    int Min,Max;
    for(i=0 ; i<N ; i++)
    {
        if(i==0)
        {
            Min = num[i];
            Temp[num[i]]++;
        }
        else
        {
            if(num[i]>Min)
            {
                Min = num[i];
                Temp[num[i]]++;
            }
        }
    }
    for(i=N-1 ; i>=0 ; i--)
    {
        if(i==N-1)
        {
            Max = num[N-1];
            if(Temp.count(num[N-1])!=0)
            {
                res.push_back(num[N-1]);
            }
        }
        else
        {
            if(num[i]<Max)
            {
                Max = num[i];
                if(Temp.count(num[i])!=0)
                {
                    res.push_back(num[i]);
                }
            }
        }
    }
    reverse(res.begin(),res.end());
    cout<<res.size()<<"\n";
    for(auto j = res.begin() ; j!=res.end() ;j++)
    {
        if(j!=res.begin())
            cout<<" "<<*j;
        else
            cout<<*j;
    }
    cout<<"\n";
    return 0;
}







//他山之玉
//柳婼
/*
分析：对原序列sort排序，逐个比较，当当前元素没有变化并且它左边的所有值的最大值都比它小的时候就可以认为它一定是主元（很容易证明正确性的，毕竟无论如何
当前这个数要满足左边都比他大右边都比他小，那它的排名【当前数在序列中处在第几个】一定不会变）。如果硬编码就直接运行超时了。。后来才想到这种方法。。
一开始有一个测试点段错误。。后来才想到因为输出时候v[0]是非法内存。。改正后格式错误。。（好像可以说明那个第2个测试点是0个主元？。。）然后——加了最后
一句printf(“\n”);才正确。。（大部分测试用例结尾不输出换行符都可以通过。只有一个出现格式错误，是由于该测试点为特例，其结果为0。没有换行符其结果只有
一行～）
*/
#include <iostream>
#include <algorithm>
#include <vector>
int a[100000], b[100000];
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);
    int v[100000], max = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] == b[i] && b[i] > max)
            v[cnt++] = b[i];
        if (b[i] > max)
            max = b[i];
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}
