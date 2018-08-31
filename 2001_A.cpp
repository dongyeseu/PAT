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
    int num_1,num_2;  //变量
    cin>>num_1>>num_2;
    int res = num_1 + num_2;    //求和
    if(res<0)res = -res , cout<<"-";  //判读正负
    string R = to_string(res);  //转换为字符串
    if(R.size()<=3)
        cout<<R;
    else{
        int mid = R.size() % 3;
        int lgt = R.size();
        int i;
        for(i=0 ; i<lgt ; i++)
        {
            cout<<R[i];
            if((i==mid-1 || (i-mid+1)%3 == 0) &&(i!=lgt-1))    //输出格式
                cout<<",";
        }
    }
    return 0;
}

//他山之玉
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int c=a+b;
    if(c<0) cout<<'-';
    c=abs(c);
    char s[20];
    sprintf(s,"%d",c);   //从int中获取字符串
    int len=strlen(s);
    //if(len<=3) {cout<<s;return 0;}
    int m=len/3,n=len%3,start=0;
    //cout<<"m="<<m<<' '<<"n="<<n<<endl;
    if(n==0) {cout<<s[0]<<s[1]<<s[2];start=3;m--;}
    else if(n==1) {cout<<s[0];start=1;}
    else if(n==2) {cout<<s[0]<<s[1];start=2;}
    while(m!=0){
        cout<<',';
        cout<<s[start]<<s[start+1]<<s[start+2];
        start+=3;
        m--;
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
