/*
1010 Radix (25)£¨25 ·Ö£©
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:\ N1 N2 tag radix\ Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:

6 110 1 10
Sample Output 1:

2
Sample Input 2:

1 ab 1 2
Sample Output 2:

Impossible
*/

//两个测试点错误（23')
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long Max(long long a,long long b)
{
    return a>b?a:b;
}

long long Jin_Zhi(string a,long long radix)
{
    long long res = 0;
    int i,len = a.size();
    for(i=0 ; i<len ; i++)
    {
        if(isalpha(a[i]))
        {
            res = res * radix + (a[i]-'a'+10);
        }
        else if(isdigit(a[i]))
        {
            res = res * radix + (a[i]-'0');
        }
    }
    return res;
}

int main()
{
    string num[2];
    long long flag,radix;
    cin>>num[0]>>num[1];
    cin>>flag>>radix;
    string a = num[flag - 1], b = a== num[0]?num[1]:num[0];
    long long r_1 = Jin_Zhi(a,radix);
    long long left = 2,right = Max(r_1,36);
    long long F = 0;
    while(left < right)
    {
        long long mid = (left + right)/2;
        long long res = Jin_Zhi(b,mid);
        if(res == r_1)
        {
            F = mid;
            right = mid-1;
        }
        else if(res > r_1 || res < 0)
            right = mid;
        else if(res<r_1)
            left = mid+1;
    }
    if(F)
        cout<<F<<"\n";
    else
        cout<<"Impossible\n";
    return 0;
}

//他山之玉
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
 
//字符转数字 
int trans(char c){
	if(c>='0'&&c<='9'){
		return int(c)-int('0');
	}else{
		return int(c)-int('a')+10;
	}
}
 
//字符串s进制下限 
int minradix(string s){
	int i,max = 1,a;
	for(i=0;i<s.length();i++){
		a = trans(s[i]);
		if(a > max){
			max = a;
		}
	}
	return max+1;
}
 
//将字符串s按radix进制转化后的值 
long long hextrans(string s,int radix){
	long long sl = 0;
	for(int j=0;j<s.length();j++){
		sl = sl*radix + trans(s[j]);
		if(sl < 0) break; 
	}
	return sl;
}
 
int main(){
	string a,b;
	stringstream ss;
	int tag,radix,i,j;
	long long al=0,bl=0,hex,l,mid,r;
	cin>>a>>b>>tag>>radix;
	if(tag == 1){
		if(radix != 10){
			for(i=0;i<a.length();i++){
				al = al*radix + trans(a[i]);
			}
		}else{
			ss << a;
			ss >> al; 
		}
		l = minradix(b);
		r = (al>l?al:l) + 1;
		while(l<=r){
			mid = (l+r)/2;
			hex = hextrans(b,mid);
			if(hex == al){
				cout<<mid;
				break;
			}else if(hex < 0||hex > al){
				r = mid - 1;
			}else if(hex < al){
				l = mid + 1;
			}
		}
		if(l>r) cout<<"Impossible";
	}else{
		if(radix != 10){
			for(i=0;i<b.length();i++){
				bl = bl*radix + trans(b[i]);
			}
		}else{
			ss << b;
			ss >> bl; 
		}
		l = minradix(a);
		r = (bl>l?bl:l) + 1;
		while(l<=r){
			mid = (l+r)/2;
			hex = hextrans(a,mid);
			if(hex == bl){
				cout<<mid;
				break;
			}else if(hex < 0||hex > bl){
				r = mid - 1;
			}else if(hex < bl){
				l = mid + 1;
			}
		}
		if(l>r) cout<<"Impossible";				
	}
	
	return 0;
}


//他山之玉
//柳婼
/*
分析：convert函数：给定一个数值和一个进制，将它转化为10进制。转化过程中可能产生溢出
find_radix函数：找到令两个数值相等的进制数。在查找的过程中，需要使用二分查找算法，如果使用当前进制转化得到数值比另一个大或者小于0，说明这个进制太大～
*/
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }   
    return 0;
}
