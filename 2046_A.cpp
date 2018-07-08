/*
1046 Shortest Distance (20)（20 分）
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N (in [3, 10^5^]), followed by N integer distances D~1~ D~2~ ... D~N~, where D~i~ is the distance between the i-th and the (i+1)-st exits, and D~N~ is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=10^4^), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 10^7^.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:

5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:

3
10
7
*/
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int N;
    cin>>N;
    int i;
    int temp;
    vector<int>num;
    int sum = 0;
    for(i=0 ; i<N ; i++)
    {
        cin>>temp;
        sum+=temp;
        num.push_back(temp);
    }
    int K;
    cin>>K;
    int first,last;

    for(i=0 ; i<K ; i++)
    {
        int min_distance = 0;
        cin>>first>>last;
        if(last == first)
            cout<<min_distance<<"\n";
        else if(last < first)
        {
            temp = first;
            first = last;
            last = temp;
        }
        int j;
        for(j=first-1 ; j<last-1 ; j++)
            min_distance += num[j];
        if(sum - min_distance < min_distance)
            min_distance = sum - min_distance;
        cout<<min_distance<<"\n";
    }
    return 0;
}


//他山之玉
//柳婼
/*
分析：简单模拟。所有结点连起来会形成一个环形。dis[i]存储第1个结点到第i个结点的下一个结点的距离。sum保存整个路径一圈的总和值。
求得结果就是dis[right – 1] – dis[left – 1]和 sum – dis[right – 1] – dis[left – 1]中较小的那一个。
注意：可能left和right的顺序颠倒了，这时候要把left和right的值交换。
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> dis(n + 1);
    int sum = 0, left, right, cnt;
    for(int i = 1; i <= n; i++) {
        int temp;
        scanf("%d", &temp);
        sum += temp;
        dis[i] = sum;
    }
    scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++) {
        scanf("%d %d", &left, &right);
        if(left > right)
            swap(left, right);
        int temp = dis[right - 1] - dis[left - 1];
        printf("%d\n", min(temp, sum - temp));
    }
    return 0;
}
