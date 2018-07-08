/*
1008 Elevator (20)（20 分）
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:

For each test case, print the total time on a single line.

Sample Input:

3 2 3 1
Sample Output:

41
*/
//这纯粹是一道数学问题；不需要对其排序，按照它给的列表顺序依次累加就可以了；注意：当下一层与上一层是一样时，要加上等候时间5s

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N,num;
    cin>>N;
    int i;
    vector<int>Elevator;
    for(i=0 ; i<N ; i++){
        cin>>num;
        Elevator.push_back(num);
    }
    int current_floor = 0 , total_time = 0;
    int leng = Elevator.size();
    for(i=0 ; i<leng ; i++)
    {
        if(Elevator[i] == current_floor)
            total_time += 5;
        else if(Elevator[i] > current_floor)
        {
            total_time += (Elevator[i] - current_floor)*6+5;
            current_floor = Elevator[i];
        }
        else
        {
            total_time += (current_floor - Elevator[i])*4 + 5;
            current_floor = Elevator[i];
        }

    }
    cout<<total_time<<"\n";
    return 0;
}


//他山之玉
//柳婼
/*题目：电梯从0层开始向上，给出该电梯依次按顺序停的楼层数，并且已知上升需要6秒/层，下降需要4秒/层，停下来的话需要停5秒，问走完所有需要停的楼层后总共花了多少时间～
分析：累加计算输出～*/
#include <iostream>
using namespace std;
int main() {
    int a, now = 0, sum = 0;
    cin >> a;
    while(cin >> a) {
        if(a > now)
            sum = sum + 6 * (a - now);
        else
            sum = sum + 4 * (now - a);
        now = a;
        sum += 5;
    }
    cout << sum;
    return 0;
}
