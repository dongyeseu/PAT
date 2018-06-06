'''
时间：2018/6/6 22点29分
作者：楼浩然

题目：
1004 成绩排名 (20)（20 分）
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为\

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：

Mike CS991301
Joe Math990112
'''

def sorting(info):
	b = info[0].split(" ");
	max_score = int(b[2]);
	min_score = int(b[2]);
	max_name = b[0];
	max_num = b[1];
	min_name = b[0];
	min_num = b[1];
	for i in info:
		a = i.split(" ");
		if int(a[2])>max_score:
			max_score = int(a[2]);
			max_name = a[0];
			max_num = a[1];
			if int(a[2]) < min_score:
				min_score = int(a[2]);
				min_name = a[0];
				min_num = a[1];
	if max_name != min_name:
		res = [" ".join([max_name,max_num])," ".join([min_name,min_num])];
	else:
		res = [" ".join([max_name,max_num])];
	return res;
			

if __name__=="__main__":
	num = int(input());
	information = [];
	for i in range(num):
		information.append(input());
	res = sorting(information);
	for i in res:
		print(i);
		
