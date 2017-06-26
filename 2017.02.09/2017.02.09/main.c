//#include <stdio.h>
//int main01()
//{
//	void *p;//定义一个无数据类型的指针变量
//	p = NULL;//将指针地址赋值为NULL，值为NULL的指针就是空指针
//	printf("%d\n", p);//输出地址为0
//	return 0;
//}

//#include <stdio.h>
//int main02()
//{
//	int a = 0;
//	int *p;
//	//p = &a;
//	*p = 2;
//	//p是一个野指针
//	//p有极小概率指向一个程序的有效地址，不报错
//	//极大概率指向无效地址，程序出错
//	printf("%d\n", *p);
//	//程序中要避免野指针的存在，它是导致程序崩溃的主要原因
//	//空指针是合法的，野指针是危险的
//	return 0;
//}

#include <stdio.h>
int main02()
{
	int a = 0x524;
	char b = 4;
	int *p;
	p = &a;
	printf("%x\n", *p);
	//p = &b;
	printf("%x\n", *p);
	return 0;
}
 
#include <stdio.h>
int main05()
{
	int a = 10;
	const int *p = &a;//p指针只能指向一个常量
	//*p = 20;//现在不能通过*p的方法修改一个const指针
	printf("a=%d\n", *p);//*p现在是一个只读的值，不能修改
	int b = 50;
	p = &b;//将p指针重新指向b的地址
	printf("b=%d\n", *p);//只读
	return 0;
}

#include <stdio.h>
int main06()
{
	int a = 10;
	int *const p = &a;//定义一个常量指针
	*p = 20;//可以通过常量指针修改或读取变量的值
	printf("%d\n", *p);
	int b = 50;
	//p = &b;//错误，常量指针一旦定义了，就不能修改其指向的变量
	return 0;
}

#include <stdio.h>
#pragma warning(disable:4996)
int s2ip(char s[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	sscanf(s, "%d.%d.%d.%d", &a, &b, &c, &d);
	//printf("%d%d%d%d", a, b, c, d);
	int i = 0;
	char *p = &i;
	*p = a;
	p++;
	*p = b;
	p++;
	*p = c;
	p++;
	*p = d;
	return i;
}

void ip2s(int k)
{
	unsigned char *p = &k;
	printf("%d.%d.%d.%d\n", *p, *(p + 1), *(p + 2), *(p + 3));
}

int main08()
{
	char ip[100] = "192.168.123.1";
	int j = s2ip(ip);
	printf("%x\n", j);
	ip2s(j);
	return 0;
}


#include <stdio.h>
int main()
{
	char a[100] = "hello ";
	char b[100] = "xcgj";
	char *j = a;
	char *k = b;
	int len = 0;
	while (*j++)//求字符串长度
		len++;
	printf("len = %d\n", len);
	j--;//当while判断j已经在‘\0’这个地址时，j++又走了一字节的地址
	while (*k)//strcat
		*j++ = *k++;
	printf("%s\n", a);
	return 0;
}