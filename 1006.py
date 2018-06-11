'''
时间：2018/6/11 22点23分
作者：楼浩然
题目：
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（&lt10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（&lt1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。
'''
def num_print(num):
	res=[];
	if len(num)==3:
		res.append("B"*int(num[0]));
		res.append("S"*int(num[1]));
		res.append("".join([str(i) for i in range(1,int(num[2])+1)]));
	elif len(num)==2:
		res.append("S"*int(num[0]));
		res.append("".join([str(i) for i in range(1,int(num[1])+1)]));
	else:
		res.append("".join([str(i) for i in range(1,int(num[0])+1)]));
	print("".join(res));

if __name__ == "__main__":
	num = input();
	num_print(num);
	