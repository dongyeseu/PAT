/*
1006 Sign In and Sign Out (25)（25 分）
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:

3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:

SC3021234 CS301133
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int Time(int h,int m,int s)
{
    return h*3600 + m*60 + s;
}

int main()
{
    int N;
    cin>>N;
    string Max_id,Min_id;
    int Max_time = -1 ,Min_time = 3600 *24 + 1;
    int i;
    for(i=0 ; i<N ; i++)
    {
        string id;
        int h1,m1,s1,h2,m2,s2;
        cin>>id;
        scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int t1 = Time(h1,m1,s1);
        if(t1<Min_time)
        {
            Min_id = id;
            Min_time = t1;
        }
        int t2 = Time(h2,m2,s2);
        if(t2>Max_time)
        {
            Max_id = id;
            Max_time = t2;
        }
    }
    cout<<Min_id<<" "<<Max_id<<"\n";
    return 0;
}

//他山之玉（哈哈哈，难得的思路一致）
柳婼
#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, minn = INT_MAX, maxn = INT_MIN;
    scanf("%d", &n);
    string unlocked, locked;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int tempIn = h1 * 3600 + m1 * 60 + s1;
        int tempOut = h2 * 3600 + m2 * 60 + s2;
        if (tempIn < minn) {
            minn = tempIn;
            unlocked = t;
        }
        if (tempOut > maxn) {
            maxn = tempOut;
            locked = t;
        }
    }
    cout << unlocked << " " << locked;
    return 0;
}
