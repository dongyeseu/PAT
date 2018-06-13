'''
时间：2018/6/13 22点33分
作者：楼浩然
题目：
1011 A+B和C (15)（15 分）
给定区间[-2^31^, 2^31^]内的3个整数A、B和C，请判断A+B是否大于C。

输入格式：

输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。

输出格式：

对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。

输入样例：

4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
输出样例：

Case #1: false
Case #2: true
Case #3: true
Case #4: false
'''
def pan_duan(i,a): #判断A+B>C的布尔值，并输出结果；
	a_b_c = i.split(" ");
	if int(a_b_c[0])+int(a_b_c[1])>int(a_b_c[2]):
		print("Case #%d: true"%a);
	else:
		print("Case #%d: false"%a);
	

def A_B_C(sr):      #输出结果
	total = len(sr);
	for i in range(total):
		pan_duan(sr[i],i+1);

if __name__=="__main__":
	num = int(input());
	shu_ru = [];
	for i in range(num):
		shu_ru.append(input());
	A_B_C(shu_ru);