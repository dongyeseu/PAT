/*
1010 一元多项式求导 (25)（25 分）
设计函数求一元多项式的导数。（注：x^n^（n为整数）的一阶导数为n*x^n-1^。）

输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。

输入样例：

3 4 -5 2 6 1 -2 0
输出样例：

12 3 -10 1 6 0
*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
    vector<int>res;
    int coef,index;
    int cnt = 0;
    while(scanf("%d %d",&coef,&index)!=EOF && index!=0)
    {
        coef = coef * index;
        index--;
        res.push_back(coef);
        res.push_back(index);
        cnt++;
    }
    if(cnt==0)
        cout<<"0 0\n";
    else{
        int i;
        for(i=0 ; i<res.size() ; i++)
            i == res.size()-1 ? (cout<<res[i]<<"\n") : (cout<<res[i]<<" ");
    }

    return 0;
}

//他山之玉
柳婼 の blog
#include <iostream>
using namespace std;
int main() {
    int a, b, flag = 0;
    while (cin >> a >> b) {
        if (b != 0) {
            if (flag == 1) cout << " ";
            cout << a * b << " " << b - 1;
            flag = 1;
        }
    }
    if (flag == 0) cout << "0 0";
    return 0;
}
