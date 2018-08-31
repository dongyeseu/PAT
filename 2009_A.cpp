#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int N,index;
    float coef;
    float origin[1002]={0};  //只有为0时才能将所有元素复制为0，如果为{1},则只有origin[0]=1,其他的元素依然为0
    float res[2004]={0};
    cin>>N;
    int i;
    for(i=0 ; i<N ; i++) //这里应该可以用一个set记录所有出现过的index，方便下面的遍历过程
    {
        cin>>index>>coef;
        origin[index] += coef;
    }
    cin>>N;
    for(i=0 ; i<N ; i++)
    {
        cin>>index>>coef;
        int j;
        for(j=0 ; j<1002 ;j++)
        {
            if(origin[j]!=0)
            {
                res[index+j] += origin[j] * coef;
            }
        }
    }
    int cnt = 0;
    for(i=0 ; i<2004 ; i++)
    {
        if(res[i]!=0)
            cnt++;
    }
    cout<<cnt;
    for(i=2003 ; i>=0 ; i--)
    {
        if(res[i]!=0.0)
            printf(" %d %.1f",i,res[i]);
    }
    cout<<"\n";
    return 0;
}

//他山之玉
//柳婼
/*分析：简单模拟。
double类型的arr数组保存第一组数据，ans数组保存结果。当输入第二组数据的时候，一边进行运算一边保存结果。最后按照指数递减的顺序输出所有不为0的项～
注意：因为相乘后指数可能最大为2000，所以ans数组最大要开到2001*/
#include <iostream>
using namespace std;
int main() {
    int n1, n2, a, cnt = 0;
    scanf("%d", &n1);
    double b, arr[1001] = {0.0}, ans[2001] = {0.0};
    for(int i = 0; i < n1; i++) {
        scanf("%d %lf", &a, &b); //%lf对应double,也可以使用%f
        arr[a] = b;
    }
    scanf("%d", &n2);
    for(int i = 0; i < n2; i++) {
        scanf("%d %lf", &a, &b);
        for(int j = 0; j < 1001; j++)
                ans[j + a] += arr[j] * b;
    }
    for(int i = 2000; i >= 0; i--)
        if(ans[i] != 0.0) cnt++;
    printf("%d", cnt);
    for(int i = 2000; i >= 0; i--)
        if(ans[i] != 0.0)
            printf(" %d %.1f", i, ans[i]);
    return 0;
}
