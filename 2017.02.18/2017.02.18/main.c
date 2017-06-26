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
	//���ڶ���������������һ���������棬sizeof()ҪС�ڵ���arr2���ڴ��С����λ�ֽڣ��������
	show(arr1, sizeof(arr1) / sizeof(int));
	return 0;
}





int main10()
{
	int arr1[10] = { 9,8,7,6,5,4,3,2,1 };
	int arr2[5] = { 0,1,2,3,4 }; 
	show(arr1, sizeof(arr1) / sizeof(int));
	memset(arr1, 0, sizeof(arr1));
	//��һ�����������ڴ��ַ���ڶ�����Ҫ���õ�ֵ����������ָ���������ڴ��С����λ�ֽ�
	//�����������ʼ��
	show(arr1, sizeof(arr1) / sizeof(int));
	return 0;
}






int add(int a, int b);
int max(int a, int b);

int repoint(int(*p)(int, int), int a, int b)
//��һ��������ָ������ָ��
{
	return p(a, b);
	//ͨ��ָ������ָ��p���ô��������õ���x������
	//��x�����Ľ�����ظ�repoint������
	//�ٽ�repoint�����Ľ�����ظ�������
}

int main09()
{
	int a = 30;
	int b = 50;
	int i = repoint(add, a, b);
	//����repoint����һ������x�ĺ���
	//x�����ͽлص�����
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
	int(*p)(int, int);//����һ��ָ������ָ��
	int a = 10;
	int b = 20;
	int status = 0;
	scanf("%d", &status);
	if (status == 0)
		p = add;
	//ֱ��д�������֣��������ĵ�ַ����add��������ĵ�ַ��ָ�����p
	else
		p = max;
	int result = p(a, b);
	//ͨ��ָ�����p��ӵ��ú���������ָ��ָ����Ǹ�����
	//�ù��̶�̬�����˺���
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
������һ��ָ������ָ�룬�����Ĳ�������Ϊint *��int������ֵΪvoid

void *p(int *s, int n)
������һ��������Ϊp�ĺ�������������Ϊint *��int������ֵΪvoid *

����һ������Ϊint *������ֵΪint *��ָ������ָ��
int *(*p)(int *)

int *p(int *)
������һ��������Ϊp�ĺ�������������Ϊint *������ֵΪint *

void (*p)()
������һ��ָ������ָ�룬����û�в���������ֵΪvoid
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
	p = mystrchar(a, 'k');//���ص�ַ
	printf("%s\n", p);//Ϊʲô���� *p ��������
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
//void list(int p[][4], int a, int b)	��Ч
//ָ��p�ĵڶ����±����Ҫд
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
	//��ʾ��0��ռ�õ��ֽ���
	printf("sizeof(dio)=%d\n", sizeof(dio));
	//����ռ�õ����ֽ���
	list(dio, sizeof(dio) / sizeof(dio[0]), sizeof(dio[0]) / sizeof(int));
	//sizeof(dio) / sizeof(dio[0])	����
	//sizeof(dio[0]) / sizeof(int)	����
	return 0;
}




void exam(int arry[])
//void exam(int *arry) ��Ч
{
	printf("sizeof(arry) = %d\n", sizeof(arry));//ָ��
	*arry = 100;
	arry++;
	*arry = 200;
	//Ҳ����д�ɣ�
	//arry[0]=100; 
	//arry[1]=200;
}

void print(int a[], int n)//n��ʾ�����ά�ȣ�Ԫ�ظ�����
{
	int j = 0;
	for (; j < n; j++)
		printf("arr[%d] = %d\n", j, a[j]);
}

int main03()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0,1,2,3 };
	printf("sizeof(arr)=%d\n", sizeof(arr));//����
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
	scanf_s("%d\n", &a);//������Ҫ�ں����ڲ��޸�ʵ�ε�ֵ�ĺ���������ͨ����ָ����Ϊ������������ʵ�ֵ�
	return 0;
}




int main01()
{
	int dia[3][5] = { {1,5,3,2,4}, {4,7,5,9,3}, {9,7,5,8,3}, };
	//int *a[5];//ָ������
	int(*a)[5];//����һ��ָ�룬ָ��int [5]�����������ͣ���ָ���ά�����ָ��
	a = dia;//aָ���˶�ά����ĵ�һ�еĵ�ַ
	printf("%d\n", sizeof(a));
	printf("%d, %d\n", a, a + 2);//λ����2*sizeof(int [5])���ֽ�
	//������и��е�ƽ��ֵ
	int k = 0;
	int j = 0;
	//��
	for (k = 0; k < 3; k++)
	{
		int sum = 0;
		for (j = 0; j < 5; j++)
		{
			sum += *(*(a + k) + j);
		}
		printf("line %d = %0.2f\n", k, (float)sum / 5);
	}
	//��
	for (j = 0; j < 5; j++)
	{
		int sum = 0;
		for (k = 0; k < 3; k++)
		{
			sum += *(*(dia + k) + j);//Ҳ��������������ָ��a
		}
		printf("cross %d = %0.2f\n", j, (float)sum / 3);
	}
	return 0;
}