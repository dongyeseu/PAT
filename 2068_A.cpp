

//他山之玉
//柳婼
/*
题目大意：用n个硬币买价值为m的东西，输出使用方案，使得正好几个硬币加起来价值为m。从小到大排列，输出最小的那个排列方案
分析：01背包问题，因为要输出从小到大的排列，可以先把硬币面额从大到小排列，然后用bool类型的choice[i][j]数组dp[i][j]是否选取，如果选取了就令choice为
true；然后进行01背包问题求解，如果最后求解的结果不是恰好等于所需要的价值的，就输出No Soultion，否则从choice[i][j]判断选取的情况，i从n到1表示从后往
前看第i个物品的选取情况，j从m到0表示从容量m到0是否选取(j = j – w[i])，把选取情况压入arr数组中，最后输出arr数组
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010], w[10010];
bool choice[10010][110];
int cmp1(int a, int b){return a > b;}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            if(dp[j] <= dp[j-w[i]] + w[i]) {
                choice[i][j] = true;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}
