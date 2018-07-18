#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int sum;
        cin>>sum;
        int Queens[sum][sum];
        memset(Queens,0,sizeof(int)*sum*sum);
        int j;
        int flag = 1;
        for(j=0 ; j<sum ; j++)
        {
            int temp;
            cin>>temp;
            if(Queens[j][temp-1]==1)
            {
                flag = 0;
            }
            if(flag)
            {
                int k,z;
                for(k=j,z=temp-1;z<sum&&k<sum;z++,k++)
                    Queens[k][z] = 1;
                for(k=j,z=temp-1;k<sum&&z>=0;k++,z--)
                    Queens[k][z] = 1;
                for(k=j,z=temp-1;k<sum;k++)
                    Queens[k][z] = 1;
            }

        }
        if(flag)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}


//他山之玉
//柳婼
/*
题目大意：给出一个皇后图，以这样的方式给出：一个数组包含n个数字，每个数字表示该列的皇后所在的行数～判断给出的皇后图是否满足不会互相攻击（任意两个皇后都要不在同一行或者同一列，且不在斜对角线上～）
分析：用v[n]存储一张图给出的数字～对于第j个数字，判断前0～j-1个数字中是否有在同一行的（v[j] == v[t])和在斜对角线上的（abs(v[j]-v[t]) == abs(j-t)）【因为已经告诉肯定不在同一列了，所以不需要判断是否在同一列啦～】如果发现了不满足的情况，就将result由true标记为false～最后根据result是true还是false输出对应的YES还是NO即可～
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<int> v(n);
        bool result = true;
        for (int j = 0; j < n; j++) {
            cin >> v[j];
            for (int t = 0; t < j; t++) {
                if (v[j] == v[t] || abs(v[j]-v[t]) == abs(j-t)) {
                    result = false;
                    break;
                }
            }
        }
        cout << (result == true ? "YES\n" : "NO\n");
    }
    return 0;
}
