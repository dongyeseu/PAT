/*
时间：2018/7/7
作者：楼浩然
题目：
1001 A+B Format (20)（20 分）
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input

-1000000 9
Sample Output

-999,991
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    int num_1,num_2;
    cin>>num_1>>num_2;
    int res = num_1 + num_2;
    if(res<0)res = -res , cout<<"-";
    string R = to_string(res);
    if(R.size()<=3)
        cout<<R;
    else{
        int mid = R.size() % 3;
        int lgt = R.size();
        int i;
        for(i=0 ; i<lgt ; i++)
        {
            cout<<R[i];
            if((i==mid-1 || (i-mid+1)%3 == 0) &&(i!=lgt-1))
                cout<<",";
        }
    }
    return 0;
}


//他山之玉
柳婼
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        cout << s[i];
        if (s[i] == '-') continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
    }
    return 0;
}
