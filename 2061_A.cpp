#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    string line_1,line_2,line_3,line_4;
    getline(cin,line_1);
    getline(cin,line_2);
    getline(cin,line_3);
    getline(cin,line_4);
    string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int i = 0, j = 0;
 //   int len_1 = line_1.size() , len_2 = line_2.size();
    while(!(line_1[i]==line_2[j] && line_1[i]>='A'&&line_1[i]<='G'))
    {
        i++;
        j++;
    }
    cout<<week[line_1[i]-'A']<<" ";
    i++,j++;
    while(!(line_1[i]==line_2[j]&&((line_1[i]>='A'&&line_1[i]<='N') || (line_1[i]>='0'&&line_1[i]<='9'))))
    {
        i++;
        j++;
    }
    if(line_1[i]>='0'&&line_1[i]<='9')
    {
        int r = line_1[i] - '0';
        printf("%02d:",r);
    }
    else
    {
        int r = line_1[i] - 'A' + 10;
        printf("%02d:",r);
    }
    i = 0, j = 0;
    while(!(line_3[i] == line_4[j] && ((line_3[i]>='a'&&line_3[i]<='z')||(line_3[i]>='A'&&line_3[i]<='Z'))))
    {
        i++;
        j++;
    }
    printf("%02d\n",i);
    return 0;
}


//他山之玉
//柳婼
#include <string>
#include <cctype>
using namespace std;
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int min1 = min(a.length(), b.length());
    int min2 = min(c.length(), d.length());
    string weekday[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    char t[2];
    int pos, j;
    for (int i = 0; i < min1; i++) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < min1; i++) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))) {
            t[1] = a[i];
            break;
        }
    }
    for (int i = 0; i < min2; i++) {
        if (c[i] == d[i] && isalpha(c[i])) {
            pos = i;
            break;
        }
    }
    int m = t[1] - '0';
    if (!isdigit(t[1])) m = t[1] - 'A' + 10;
    cout << weekday[t[0] - 'A'];
    printf("%02d:%02d", m, pos);
    return 0;
}
