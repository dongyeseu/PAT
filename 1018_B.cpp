#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(char a,char c)
{
    return a<c;
}
int main()
{
    int N;
    cin>>N;
    char A,B;
    int i;
    int win = 0,lose = 0;
    vector<char>A_win;
    vector<char>B_win;
    for(i=0 ; i<N ; i++)
    {
        cin>>A>>B;
        if(A == B)
            continue;
        else if ((A=='C'&&B=='J') || (A=='J' && B=='B') || (A=='B'&&B=='C'))
        {
            win++;
            A_win.push_back(A);
        }
        else
        {
            lose++;
            B_win.push_back(B);
        }
    }
    int ping = N-win-lose;
    cout<<win<<" "<<ping<<" "<<lose<<"\n";
    cout<<lose<<" "<<ping<<" "<<win<<"\n";
    vector<int>count_A;
    count_A.push_back(count(A_win.begin(),A_win.end(),'B'));
    count_A.push_back(count(A_win.begin(),A_win.end(),'C'));
    count_A.push_back(count(A_win.begin(),A_win.end(),'J'));
    if(count_A[0]>=count_A[1] && count_A[0]>=count_A[2])
        cout<<"B ";
    else if(count_A[1]>count_A[0] && count_A[1]>=count_A[2])
        cout<<"C ";
    else
        cout<<"J ";
    vector<int>count_B;
    count_B.push_back(count(B_win.begin(),B_win.end(),'B'));
    count_B.push_back(count(B_win.begin(),B_win.end(),'C'));
    count_B.push_back(count(B_win.begin(),B_win.end(),'J'));
    if(count_B[0]>=count_B[1] && count_B[0]>=count_B[2])
        cout<<"B";
    else if(count_B[1]>count_B[0] && count_B[1]>=count_B[2])
        cout<<"C";
    else
        cout<<"J";

    return 0;
}


//他山之玉
柳婼 の blog
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int jiawin = 0, yiwin = 0;
    int jia[3] = {0}, yi[3] = {0};
    for (int i = 0; i < n; i++) {
        char s, t;
        cin >> s >> t;
        if (s == 'B' && t == 'C') {
            jiawin++;
            jia[0]++;
        } else if (s == 'B' && t == 'J') {
            yiwin++;
            yi[2]++;
        } else if (s == 'C' && t == 'B') {
            yiwin++;
            yi[0]++;
        } else if (s == 'C' && t == 'J') {
            jiawin++;
            jia[1]++;
        } else if (s == 'J' && t == 'B') {
            jiawin++;
            jia[2]++;
        } else if (s == 'J' && t == 'C') {
            yiwin++;
            yi[1]++;
        }
    }
    cout << jiawin << " " << n - jiawin - yiwin << " " << yiwin << endl << yiwin << " " << n - jiawin - yiwin << " " << jiawin << endl;
    int maxjia = jia[0] >= jia[1] ? 0 : 1;
    maxjia = jia[maxjia] >= jia[2] ? maxjia : 2;
    int maxyi = yi[0] >= yi[1] ? 0 : 1;
    maxyi = yi[maxyi] >= yi[2] ? maxyi : 2;
    char str[4] = {"BCJ"};
    cout << str[maxjia] << " " << str[maxyi];
    return 0;
}
