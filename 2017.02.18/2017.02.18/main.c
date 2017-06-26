#include <stdio.h>
#include <string.h>

void show(int a[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = %d\n", i, *(a + i));
	}
}

int main()
{
	int arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int *front = arr1 + 3;
	int *after = arr1 + 5;
	memcpy(front, after, 16);
	show(arr1, sizeof(arr1) / sizeof(int));
	return 0;
}




int main11()
{
	int arr1[10] = { 9,8,7,6,5,4,3,2,1 };
	int arr2[5] = { 0,1,2,3,4 };
	//show(arr1, sizeof(arr1) / sizeof(int));
	memcpy(arr1, arr2, sizeof(arr2));
	//将第二个参数拷贝到第一个参数里面，sizeof()要小于等于arr2的内存大小，单位字节，避免溢出
	show(arr1, sizeof(arr1) / sizeof(int));
	return 0;
}





int main10()
{
	int arr1[10] = { 9,8,7,6,5,4,3,2,1 };
	int arr2[5] = { 0,1,2,3,4 }; 
	show(arr1, sizeof(arr1) / sizeof(int));
	memset(arr1, 0, sizeof(arr1));
	//第一个参数设置内存地址，第二个是要设置的值，第三个是指定操作的内存大小，单位字节
	//将数组初重新始化
	show(arr1, sizeof(arr1) / sizeof(int));
	return 0;
}






int add(int a, int b);
int max(int a, int b);

int repoint(int(*p)(int, int), int a, int b)
//第一个参数是指向函数的指针
{
	return p(a, b);
	//通过指向函数的指针p调用从主函数得到的x函数，
	//将x函数的结果返回给repoint函数，
	//再将repoint函数的结果返回给主函数
}

int main09()
{
	int a = 30;
	int b = 50;
	int i = repoint(add, a, b);
	//给予repoint函数一个名叫x的函数
	//x函数就叫回调函数
	printf("%d\n", i);
	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}




#pragma warning(disable:4996)
void one()
{
	printf("1sakgkg\n");
}

void two()
{
	printf("2sgadguif\n");
}

void three()
{
	printf("3ajhdfhnlk\n");
}

void four()
{
	printf("4sjkgfjkl\n");
}

void five()
{
	printf("5hjids89\n");
}

int main08()
{
	int k = 0;
	void(*p)();
	scanf("%d", &k);
	switch (k)
	{
	case 1:
		p = one;
		break;
	case 2:
		p = two;
		break;
	case 3:
		p = three;
		break;
	case 4:
		p = four;
		break;
	default:
		p = five;
	}
	p();
	return 0;
}















int main07()
{
	int(*p)(int, int);//定义一个指向函数的指针
	int a = 10;
	int b = 20;
	int status = 0;
	scanf("%d", &status);
	if (status == 0)
		p = add;
	//直接写函数名字，代表函数的地址，将add这个函数的地址给指针变量p
	else
		p = max;
	int result = p(a, b);
	//通过指针变量p间接调用函数，调用指针指向的那个函数
	//该过程动态调用了函数
	printf("%d\n", result);
	return 0;
}

//int add(int a, int b)
//{
//	return a + b;
//}
//
//int max(int a, int b)
//{
//	return (a > b) ? a : b;
//}

/*
void (*p)(int *s, int n)
定义了一个指向函数的指针，函数的参数类型为int *和int，返回值为void

void *p(int *s, int n)
声明了一个函数名为p的函数，参数类型为int *和int，返回值为void *

定义一个参数为int *，返回值为int *的指向函数的指针
int *(*p)(int *)

int *p(int *)
声明了一个函数名为p的函数，参数类型为int *，返回值为int *

void (*p)()
定义了一个指向函数的指针，函数没有参数，返回值为void
*/














char *mystrchar(char *pt, char s)
{
	while (*pt)
	{
		if (*pt == s)
			return pt;
		pt++;
	}
	return NULL;
}

int main06()
{
	char a[100] = "adfjdkl";
	char *p;
	p = mystrchar(a, 'k');//返回地址
	printf("%s\n", p);//为什么不是 *p ？？？？
	return 0;
}








void mystrcpy(char *q, const char *w)
{
	int len = 0;
	int i = 0;
	while (*(w + len))
		len++;
	for(; i < len; i++)
	{
		*q = *w;;
		w++;
		q++;
	}
}

void mystrcat(char *e, const char *r)
{
	while (*e)
		e++;
	int len = 0;
	while (r[len])
		len++;
	int i = 0;
	for (; i < len; i++)
	{
		*e = *r;
		e++;
		r++;
	}
}

int main05()
{
	char a[100] = "abcdabcd";
	char b[100] = "efgh";
	mystrcpy(a, b);
	puts(a);
	mystrcat(a, b);
	puts(a);
	return 0;
}




void list(int(*p)[4], int a, int b)
//void list(int p[][4], int a, int b)	等效
//指针p的第二个下标必须要写
{
	int k = 0;
	int j = 0;
	for (; k < a; k++)
	{
		for (j = 0; j < b; j++)
		{
			printf("dio[%d][%d] = %d\n", k, j, *(*(p + k) + j));
		}
	}
}

int main04()
{
	int dio[3][4] = { {1,2,3,4},{5,6,7,8},{9,0,1,2} };
	printf("sizeof(dio[0])=%d\n", sizeof(dio[0]));
	//表示第0行占用的字节数
	printf("sizeof(dio)=%d\n", sizeof(dio));
	//数组占用的总字节数
	list(dio, sizeof(dio) / sizeof(dio[0]), sizeof(dio[0]) / sizeof(int));
	//sizeof(dio) / sizeof(dio[0])	行数
	//sizeof(dio[0]) / sizeof(int)	列数
	return 0;
}




void exam(int arry[])
//void exam(int *arry) 等效
{
	printf("sizeof(arry) = %d\n", sizeof(arry));//指针
	*arry = 100;
	arry++;
	*arry = 200;
	//也可以写成：
	//arry[0]=100; 
	//arry[1]=200;
}

void print(int a[], int n)//n表示数组的维度（元素个数）
{
	int j = 0;
	for (; j < n; j++)
		printf("arr[%d] = %d\n", j, a[j]);
}

int main03()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0,1,2,3 };
	printf("sizeof(arr)=%d\n", sizeof(arr));//数组
	exam(arr);
	print(arr, sizeof(arr) / sizeof(int));
	return 0;
}





void test(int *c, int *d)
{
	int index = *c;
	*c = *d;
	*d = index;
}

int main02()
{
	int a = 5;
	int b = 8;
	test(&a, &b);
	printf("a=%d,b=%d\n", a, b);
	scanf_s("%d\n", &a);//所有需要在函数内部修改实参的值的函数，都是通过将指针作为函数参数调用实现的
	return 0;
}




int main01()
{
	int dia[3][5] = { {1,5,3,2,4}, {4,7,5,9,3}, {9,7,5,8,3}, };
	//int *a[5];//指针数组
	int(*a)[5];//定义一个指针，指向int [5]这种数据类型，是指向二维数组的指针
	a = dia;//a指向了二维数组的第一行的地址
	printf("%d\n", sizeof(a));
	printf("%d, %d\n", a, a + 2);//位移了2*sizeof(int [5])个字节
	//计算各行各列的平均值
	int k = 0;
	int j = 0;
	//行
	for (k = 0; k < 3; k++)
	{
		int sum = 0;
		for (j = 0; j < 5; j++)
		{
			sum += *(*(a + k) + j);
		}
		printf("line %d = %0.2f\n", k, (float)sum / 5);
	}
	//列
	for (j = 0; j < 5; j++)
	{
		int sum = 0;
		for (k = 0; k < 3; k++)
		{
			sum += *(*(dia + k) + j);//也可用数组名代替指针a
		}
		printf("cross %d = %0.2f\n", j, (float)sum / 3);
	}
	return 0;
}