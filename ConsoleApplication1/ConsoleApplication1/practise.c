/*请使用switch语句和if...else语句，计算2008年8月8日这一天，是该年中的第几天。
程序一：
#include <stdio.h>
int main()
{
	int year = 2008, month = 1, day = 8, sum;
	switch (month)
	{
	case 1:sum = 0; break;
	case 2:sum = 31; break;
	case 3:sum = 59; break;
	case 4:sum = 90; break;
	case 5:sum = 120; break;
	case 6:sum = 151; break;
	case 7:sum = 181; break;
	case 8:sum = 212; break;
	case 9:sum = 243; break;
	case 10:sum = 273 ; break;
	case 11:sum = 304; break;
	case 12:sum = 334; break;
	default:printf("月份错误");
	}
	sum += day;
	if (month>=3)
	{
		if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
		{
			printf("%d年%d月%d日是这年的第%d天\n",year,month,day,++sum);
		}
		else
		{
			printf("%d年%d月%d日是这年的第%d天\n",year,month,day,sum);
		}
		
	}
	else
	{
		printf("%d年%d月%d日是这年的第%d天\n",year,month,day,sum);
	}
	
	system("pause");
	return 0;
}*/
/*
程序二：
#include <stdio.h>
int main()
{
	int year = 2007, month = 8, day = 8;
	int i = day;
	switch (month - 1)
	{
	case 11:day += 30;
	case 10:day += 31;
	case 9:day += 30;
	case 8:day += 31;
	case 7:day += 31;
	case 6:day += 30;
	case 5:day += 31;
	case 4:day += 30;
	case 3:day += 31;
	case 2:
		if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
		{
			day += 29;
		}
		else
		{
			day += 28;
		}
	case 1:day += 31;
	default:printf("%d年%d月%d日是该年的第%d天\n", year, month, i, day);
		break;
	}
	system("pause");
	return 0;
}*/

/*实现从控制台输出1-10，使用goto语句，实现当输出完3之后跳出循环体。
#include <stdio.h>
int main()
{
	int i = 1;
	for (; i <= 10; i++)
	{
		printf("%d\n", i);
		if (i == 3)
		{
			goto XCGJ;
		}
	}
	XCGJ:printf("结束for循环了...\n");
	system("pause");
	return 0;
}*/

/*自定义一个sayHello()函数
#include <stdio.h>
int Sayhello()
{
	printf(" Hello,xcgj!\n");
	return 0;
}

int dividLine()
{
	printf("%s\n", "************");
	return 0;
}

int main()
{
	dividLine();
	Sayhello();
	dividLine();
	system("pause");
	return 0;
}*/

/*
#include <stdio.h>

int Nonx()
{
	printf("小明在慕课网上学习\n");
	return 0;
}

int Havex(int x)
{
	printf("小明在慕课网上已经参与学习了%d门课程\n", x);
	return 0;
}

int main()
{
	Nonx();
	Havex(8);
	system("pause");
	return 0;
}*/

/*计算三角形的周长
#include <stdio.h>
int getGirth(int a, int b, int c)
{
	//int cirf;
	if ((a + b) <= c || (a + c) <= b || (c + b) <= a)
	{
		printf("不构成三角形");
		return 0;
	}
	else
	{
		int cirf;	//cirf只能在此处定义吗？也可定义在if前
		cirf = a + b + c;
		return cirf;	//返回cirf的值
	}
}

int main()
{
	int a = 5;
	int b = 3;
	int c = 4;
	printf("三角形的周长是：%d\n",getGirth(a,b,c));	//此处形参和实参要一致
	system("pause");
	return 0;
}*/

/*
#include <stdio.h>
int JoneR(int x,int y,int z)
{
	int n = x + z + y;
	return n/3;
}
void JackR(int x,int y,int z)	//无返回值，用void
{
	printf("我算不出来\n");
	return;	//不返回值，只起到结束函数的作用
}
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	printf("Jone的运算结果是：%d\n", JoneR(a,b,c));
	printf("Jack的运算结果是：");
	JackR(a, b, c);
	system("pause");
	return 0;
}*/

/*
#include <stdio.h>
int xcgj(int i)
{	
	if (i > 0)
	{
		i += xcgj(i - 1);
	}
	return i;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("小明第%d天记了%d个单词。\n", n, xcgj(n));
	system("pause");
	return 0;
}

/*
#include <stdio.h>
int xcgj(int i)
{
	int sum = 0;
	if (i < 10)
	{
		sum = (xcgj(i+1)+1)*2;
		
		printf("猴子第%d天剩的桃子数量是：%d\n", i, sum);
	}
	else
	{
		sum = 1;
	}
	return sum;
}
int main()
{
	int a=1;
	//scanf("%d", &a);
	xcgj(a);
	system("pause");
	return 0;
}

/*北京市出租车打车计费规则如下：
1. 每公里单价计费2.3元
2. 起步价13元(包含3公里)
3. 晚上23点(含)至次日凌晨5点(不含)打车，每公里单价计费加收20%。
4. 每次乘车加收1元钱的燃油附加税。
小明每天上下班都要打车，公司和家的距离为12公里，上午上班时间为9点，下午下班时间为6点。
请编写一个小程序计算小明每天打车的总费用。
#include <stdio.h>
float calc(int a,int b)	//a是打车距离，b是打车时间
{
	float price;
	if (a<=3)
	{
		price = 14;	
	}
	else
	{
		if (b > 5 && b < 23)
			price = (a - 3)*2.3 + 14;	
		else
			price = (a - 3)*2.3*1.2 + 14;
	}
	return price;
}
int main()
{
	int m;	//打车距离
	int n1;	//上午打车时间
	int n2;	//下午打车时间
	float sum;
	scanf("%d %d %d",&m,&n1,&n2);
	sum = calc(m, n1) + calc(m, n2);
	printf("小明每天打车的总费用为：%f\n",sum);
	system("pause");
	return 0;
}
/*
#include <stdio.h>
int main()
{
	//第一种形式
	int arrFirst[3] = { 1,2,3 };
		//第二种形式
	int arrSecond[] = { 1,2,3 };
		//第三种形式
	int arrThird[3];
	//给arrThird数组每个元素初始化
	arrThird[0] = 1;
	arrThird[1] = 2;
	arrThird[2] = 3;
	//输出第一个数组中的第二个元素
	printf("%d\n", arrFirst[1]);
	//输出第二个数组中的第二个元素
	printf("%d\n", arrSecond[1]);
	//输出第三个数组中的第二个元素
	printf("%d\n", arrThird[1]);
	system("pause");
	return 0;
}

/*将0-9之间的数字存放在数组中，用遍历的方式打印输出出来。
#include <stdio.h>
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int i=0;
	/*for (; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	/*do
	{
		printf("%d\n", arr[i++]);
	} while (i < 10);
	while (i < 10)
	{
		printf("%d\n", arr[i++]);
	}
	system("pause");
	return 0;
}

/*将数组2的第一个值与数组1的最大值交换，然后与一个for循环输出数组1的所有元素
#include <stdio.h>
void ord(int ar[])
{
	int i, j, k;
	for (i = 0; i < 10; i++)	//数组第i个位置与后面的全部数据进行比较大小
	{
		for (j = 9; j > i; j--)	//从数组最后一个位置依次向前与第i个位置比较，遇到i位置时停止比较，因为i位置之前已经排好顺序
		{
			if (ar[i] < ar[j])	//遇到大的交换数值
			{
				k = ar[i];
				ar[i] = ar[j];
				ar[j] = k;
			}
		}
	}
}
int main()
{
	int arr[10] = { 3,5,1,7,0,9,2,4,6,8 };
	int i;
	for (i = 0; i < 10; i++)
	{
		if(i != 9)	//使第九个数末尾不输出逗号
		printf("%d,",arr[i]);
		else
		printf("%d", arr[i]);
	}
	printf("\n---------------------\n");
	ord(arr);
	for (i = 0; i < 10; i++)
	{
		if (i != 9)	//使第九个数末尾不输出逗号
			printf("%d,", arr[i]);
		else
			printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}


#include <stdio.h>
int main()
{
	int arr[] = { 3,5,1,7,0,9,2,4,6,8 };
	int i, j, k;
	for (i = 8; i >= 0; i--)	//从第八个位置开始排大小
	{
		for(j=0;j<=i;j++)	//从第一个位置开始反复进行相邻两个数的大小比较
			if (arr[j] > arr[j + 1])	//右边比左边小，则交换，可看出：a.进行了升序排列。b.即便i一开始等于了8，他也能和第9个数比较，比完之后第九个数就已经排序完成
			{
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
	}
	for (i = 0; i < 10; i++)	//开始遍历数组
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}

/*小明班级有10人要参加比赛，进场时要按大小个升序排队，老师要用冒泡排序写一个小程序进行排序
#include <stdio.h>
int main()
{
	float arr[] = { 1.78, 1.77, 1.82, 1.79, 1.85, 1.75, 1.86, 1.77, 1.81, 1.80 };
	float k;
	int i, j;
	for (i = 0; i < 10; i++)
	{
		if (i != 9)
			printf("%.3f,", arr[i]);	//%.2f表示小数点后精确到两位
		else
			printf("%.3f\n---------------------------排序后---------------------------\n", arr[i]);
	}
	for (i = 1; i < 10; i++)	//这次是从后面开始往前冒泡比较，从前往后确定数值大小
	{
		for (j = 9; j >= i; j--)	//此处不能写“j>i”，否则arr[1]不会和arr[0]比较
		{
			if (arr[j]<arr[j - 1])
			{
				k = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = k;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		if(i != 9)
			printf("%.3f,", arr[i]);
		else
			printf("%.3f\n", arr[i]);
	}	
	system("pause");
	return 0;
}

#include <stdio.h>
int find(int ar[], int n)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (ar[i] == n)
		{
			return i;	//也可以加break语句跳出循环
		}
	}
	return i;	//如果数组中没有n,此时i应该等于5
}
int main()
{
	int arr[] = { 3,12,9,8,6 };
	int value = 12;
	int i = find(arr, value);
	if (i == 5)
		printf("%d在数组中不存在\n", value);
	else
		printf("%d在数组中的下标是：%d\n", value, i);
	system("pause");
	return 0;
}

#include <stdio.h>
int find(int *ar, int n)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (ar[i] == n)
		{
			return i;	
			break;	//因为break语句前，函数已经返回了i的值，所以后面跳出for循环给i赋值-1并返回的无效的？？？？？
		}
	}
	return i = -1;	
}
int main()
{
	int arr[] = { 3,12,9,8,6 };
	int value = 12;
	int i = find(arr, value);
	if (i == -1)
		printf("%d在数组中不存在\n", value);
	else
		printf("%d在数组中的下标是：%d\n", value, i);
	system("pause");
	return 0;
}

/*
在C语言中，是没有办法直接定义字符串数据类型的，但是我们可以使用数组来定义我们所要的字符串。一般有以下两种格式：

1、char 字符串名称[长度] = "字符串值";

2、char 字符串名称[长度] = {'字符1','字符2',...,'字符n','\0'};

注意：

1、[]中的长度是可以省略不写的；

2、采用第2种方式的时候最后一个元素必须是'\0'，'\0'表示字符串的结束标志；

3、采用第2种方式的时候在数组中不能写中文。

在输出字符串的时候要使用：printf(“%s”,字符数组名字);或者puts(字符数组名字);。
#include <stdio.h>
void print1(char *x)
{
	puts(x);	//自带换行的
}
void print2(char y[])
{
	printf("%s\n", y);
}
int main()
{
	char xcgj1[] = "good good study,";
	char xcgj2[] = { 'd','a','y',' ','d','a','y',' ','u','p','\0' };	//只能一个字母一个字母打，否则输出时只会打印最后一个字母
	printf("");
	print1(xcgj1);
	print2(xcgj2);
	print2(xcgj1);
	print1(xcgj2);
	system("pause");
	return 0;
}

/*
使用字符串函数注意以下事项：
1、strlen()获取字符串的长度，在字符串长度中是不包括‘\0’而且汉字和字母的长度是不一样的.

2、strcmp()在比较的时候会把字符串先转换成ASCII码再进行比较,返回的结果为0表示s1和s2的ASCII码相等,返回结果为1表示s1比s2的ASCII码大,返回结果为-1表示s1比s2的ASCII码小.
#include <stdio.h>
#include <string.h>
int main()
{
char s1[] = "a";
char s2[] = "A";
char s3[] = "a";
printf("%d\n", 'a');	//97
printf("%d\n", 'A');	//65
printf("%d ", strcmp(s1,s2));	//1???????为什么，大小写不是相差32...s1-s2
printf("%d ", strcmp(s2,s1));	//-1
printf("%d\n", strcmp(s1,s3));
system("pause");
return 0;
}

3、strcpy()拷贝之后会覆盖原来字符串,且字符串常量不能对字符进行拷贝.strcpy(s1,s2)就是复制s2,覆盖s1.
#define PI  "imooc"  这就是字符串常量

4、strcat在使用时s1与s2指的内存空间不能重叠，且s1要有足够的空间来容纳要复制的字符串.
#include <stdio.h>
int main()
{
char s1[100] = "hello ";
char s2[] = "world";
strcat(s1, s2);
printf("%s\n", s1);
system("pause");
return 0;
}
结果是：hello world


#include <stdio.h>
#include <string.h>
#define PI "imooc"
int main()
{
	char s1[] = "a";
	char s2[] = "A";
	printf("%s\n",PI);	//imooc
	printf("%s\n", strcpy(s1,s2));	//A
	printf("%s\n", strcpy(PI,s1));	//
	system("pause");
	return 0;
}*/

/*在一个长度为10的整型数组里面，保存了班级10个学生的考试成绩。要求编写5个函数，分别实现计算考试的总分，最高分，最低分，平均分和考试成绩降序排序。*/
#include <stdio.h>
void sum(int score[])
{
	int i, j = 0;
	for (i = 0; i < 10; i++)
	{
		j = j + score[i];
	}
	printf("总分是%d\n", j);
}

void hightest(int score[])
{
	int i, j = score[0];
	for (i = 0; i < 10; i++)
	{
		if (j < score[i])
		{
			j = score[i];
		}
	}
	printf("最高分是%d\n", j);
}

void lowest(int score[])
{
	int i, j = score[0];
	for (i = 0; i < 10; i++)
	{
		if (j > score[i])
			j = score[i];
	}
	printf("最低分是%d\n", j);
}

void average(int score[])
{
	int i, j = 0;
	for (i = 0; i < 10; i++)
	{
		j += score[i];
	}
	printf("平均分是%d\n", j / 10);
}

void downrow(int score[])
{
	int i, j, k;
	for (i = 9; i >= 0; i--)	//i控制j的循环次数
	{
		for (j = 0; j < i; j++)
		{
			if (score[j] < score[j + 1])
			{
				k = score[j];
				score[j] = score[j + 1];
				score[j + 1] = k;
			}
		}
	}
	printf("降序排列：");
	for (i = 0; i < 10; i++)
	{
		if (i != 9)
			printf("%d,", score[i]);
		else
			printf("%d\n", score[i]);
	}
}

void uprow(int score[])
{
	int i, j, k;
	for (i = 8; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (score[j] > score[j + 1])
			{
				k = score[j];
				score[j] = score[j + 1];
				score[j + 1] = k;
			}
		}
	}
	printf("升序排列：");
	for (i = 0; i < 10; i++)
	{
		if (i != 9)
			printf("%d,", score[i]);
		else
			printf("%d\n", score[i]);
	}
}

int main()
{
	int score[10] = { 67,98,75,63,82,79,81,91,66,84 };
	sum(score);
	hightest(score);
	lowest(score);
	average(score);
	downrow(score);
	uprow(score);
	system("pause");
	return 0;
}