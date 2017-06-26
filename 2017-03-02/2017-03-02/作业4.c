//4. 从屏幕上输入一串字符串\(长度为n\)
//统计其中出现的大写字母、小写字母、数字字符、空白字符\(' ', '\n'、'\t'等\)等的数量。
#include <stdio.h>
int main__4(void)
{
	char cha[] = "\t\t\t\t\taaaaaAAAAA12345     \n\n\n\n\n";
	int i = 0;
	int length = 0;
	while (cha[length++]);
	length--;//非零字符个数
	int A = 0;
	int a = 0;
	int number = 0;
	int space = 0;
	int n = 0;
	int t = 0;
	for (i = 0; i < length; i++)
	{
		if (cha[i] <=90 && cha[i] >= 65)//大写字母
			A++;
		if (cha[i] <= 122 && cha[i] >= 97)//小写字母
			a++;
		if (cha[i] <= 57 && cha[i] >= 48)//数字
			number++;
		if (cha[i] == ' ')//空格
			space++;
		if (cha[i] == '\n')//换行
			n++;
		if (cha[i] == '\t')//空格
			t++;
	}
	printf("大写字母=%d\n小写字母=%d\n数字字符=%d\n' '=%d\n'\\n'=%d\n'\\t'=%d\n",
		A, a, number, space, n, t);
	return 0;
}