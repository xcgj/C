/*��ʹ��switch����if...else��䣬����2008��8��8����һ�죬�Ǹ����еĵڼ��졣
����һ��
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
	default:printf("�·ݴ���");
	}
	sum += day;
	if (month>=3)
	{
		if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
		{
			printf("%d��%d��%d��������ĵ�%d��\n",year,month,day,++sum);
		}
		else
		{
			printf("%d��%d��%d��������ĵ�%d��\n",year,month,day,sum);
		}
		
	}
	else
	{
		printf("%d��%d��%d��������ĵ�%d��\n",year,month,day,sum);
	}
	
	system("pause");
	return 0;
}*/
/*
�������
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
	default:printf("%d��%d��%d���Ǹ���ĵ�%d��\n", year, month, i, day);
		break;
	}
	system("pause");
	return 0;
}*/

/*ʵ�ִӿ���̨���1-10��ʹ��goto��䣬ʵ�ֵ������3֮������ѭ���塣
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
	XCGJ:printf("����forѭ����...\n");
	system("pause");
	return 0;
}*/

/*�Զ���һ��sayHello()����
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
	printf("С����Ľ������ѧϰ\n");
	return 0;
}

int Havex(int x)
{
	printf("С����Ľ�������Ѿ�����ѧϰ��%d�ſγ�\n", x);
	return 0;
}

int main()
{
	Nonx();
	Havex(8);
	system("pause");
	return 0;
}*/

/*���������ε��ܳ�
#include <stdio.h>
int getGirth(int a, int b, int c)
{
	//int cirf;
	if ((a + b) <= c || (a + c) <= b || (c + b) <= a)
	{
		printf("������������");
		return 0;
	}
	else
	{
		int cirf;	//cirfֻ���ڴ˴�������Ҳ�ɶ�����ifǰ
		cirf = a + b + c;
		return cirf;	//����cirf��ֵ
	}
}

int main()
{
	int a = 5;
	int b = 3;
	int c = 4;
	printf("�����ε��ܳ��ǣ�%d\n",getGirth(a,b,c));	//�˴��βκ�ʵ��Ҫһ��
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
void JackR(int x,int y,int z)	//�޷���ֵ����void
{
	printf("���㲻����\n");
	return;	//������ֵ��ֻ�𵽽�������������
}
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	printf("Jone���������ǣ�%d\n", JoneR(a,b,c));
	printf("Jack���������ǣ�");
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
	printf("С����%d�����%d�����ʡ�\n", n, xcgj(n));
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
		
		printf("���ӵ�%d��ʣ�����������ǣ�%d\n", i, sum);
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

/*�����г��⳵�򳵼Ʒѹ������£�
1. ÿ���ﵥ�ۼƷ�2.3Ԫ
2. �𲽼�13Ԫ(����3����)
3. ����23��(��)�������賿5��(����)�򳵣�ÿ���ﵥ�ۼƷѼ���20%��
4. ÿ�γ˳�����1ԪǮ��ȼ�͸���˰��
С��ÿ�����°඼Ҫ�򳵣���˾�ͼҵľ���Ϊ12��������ϰ�ʱ��Ϊ9�㣬�����°�ʱ��Ϊ6�㡣
���дһ��С�������С��ÿ��򳵵��ܷ��á�
#include <stdio.h>
float calc(int a,int b)	//a�Ǵ򳵾��룬b�Ǵ�ʱ��
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
	int m;	//�򳵾���
	int n1;	//�����ʱ��
	int n2;	//�����ʱ��
	float sum;
	scanf("%d %d %d",&m,&n1,&n2);
	sum = calc(m, n1) + calc(m, n2);
	printf("С��ÿ��򳵵��ܷ���Ϊ��%f\n",sum);
	system("pause");
	return 0;
}
/*
#include <stdio.h>
int main()
{
	//��һ����ʽ
	int arrFirst[3] = { 1,2,3 };
		//�ڶ�����ʽ
	int arrSecond[] = { 1,2,3 };
		//��������ʽ
	int arrThird[3];
	//��arrThird����ÿ��Ԫ�س�ʼ��
	arrThird[0] = 1;
	arrThird[1] = 2;
	arrThird[2] = 3;
	//�����һ�������еĵڶ���Ԫ��
	printf("%d\n", arrFirst[1]);
	//����ڶ��������еĵڶ���Ԫ��
	printf("%d\n", arrSecond[1]);
	//��������������еĵڶ���Ԫ��
	printf("%d\n", arrThird[1]);
	system("pause");
	return 0;
}

/*��0-9֮������ִ���������У��ñ����ķ�ʽ��ӡ���������
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

/*������2�ĵ�һ��ֵ������1�����ֵ������Ȼ����һ��forѭ���������1������Ԫ��
#include <stdio.h>
void ord(int ar[])
{
	int i, j, k;
	for (i = 0; i < 10; i++)	//�����i��λ��������ȫ�����ݽ��бȽϴ�С
	{
		for (j = 9; j > i; j--)	//���������һ��λ��������ǰ���i��λ�ñȽϣ�����iλ��ʱֹͣ�Ƚϣ���Ϊiλ��֮ǰ�Ѿ��ź�˳��
		{
			if (ar[i] < ar[j])	//������Ľ�����ֵ
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
		if(i != 9)	//ʹ�ھŸ���ĩβ���������
		printf("%d,",arr[i]);
		else
		printf("%d", arr[i]);
	}
	printf("\n---------------------\n");
	ord(arr);
	for (i = 0; i < 10; i++)
	{
		if (i != 9)	//ʹ�ھŸ���ĩβ���������
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
	for (i = 8; i >= 0; i--)	//�ӵڰ˸�λ�ÿ�ʼ�Ŵ�С
	{
		for(j=0;j<=i;j++)	//�ӵ�һ��λ�ÿ�ʼ�������������������Ĵ�С�Ƚ�
			if (arr[j] > arr[j + 1])	//�ұ߱����С���򽻻����ɿ�����a.�������������С�b.����iһ��ʼ������8����Ҳ�ܺ͵�9�����Ƚϣ�����֮��ھŸ������Ѿ��������
			{
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
	}
	for (i = 0; i < 10; i++)	//��ʼ��������
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}

/*С���༶��10��Ҫ�μӱ���������ʱҪ����С�������Ŷӣ���ʦҪ��ð������дһ��С�����������
#include <stdio.h>
int main()
{
	float arr[] = { 1.78, 1.77, 1.82, 1.79, 1.85, 1.75, 1.86, 1.77, 1.81, 1.80 };
	float k;
	int i, j;
	for (i = 0; i < 10; i++)
	{
		if (i != 9)
			printf("%.3f,", arr[i]);	//%.2f��ʾС�����ȷ����λ
		else
			printf("%.3f\n---------------------------�����---------------------------\n", arr[i]);
	}
	for (i = 1; i < 10; i++)	//����ǴӺ��濪ʼ��ǰð�ݱȽϣ���ǰ����ȷ����ֵ��С
	{
		for (j = 9; j >= i; j--)	//�˴�����д��j>i��������arr[1]�����arr[0]�Ƚ�
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
			return i;	//Ҳ���Լ�break�������ѭ��
		}
	}
	return i;	//���������û��n,��ʱiӦ�õ���5
}
int main()
{
	int arr[] = { 3,12,9,8,6 };
	int value = 12;
	int i = find(arr, value);
	if (i == 5)
		printf("%d�������в�����\n", value);
	else
		printf("%d�������е��±��ǣ�%d\n", value, i);
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
			break;	//��Ϊbreak���ǰ�������Ѿ�������i��ֵ�����Ժ�������forѭ����i��ֵ-1�����ص���Ч�ģ���������
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
		printf("%d�������в�����\n", value);
	else
		printf("%d�������е��±��ǣ�%d\n", value, i);
	system("pause");
	return 0;
}

/*
��C�����У���û�а취ֱ�Ӷ����ַ����������͵ģ��������ǿ���ʹ������������������Ҫ���ַ�����һ�����������ָ�ʽ��

1��char �ַ�������[����] = "�ַ���ֵ";

2��char �ַ�������[����] = {'�ַ�1','�ַ�2',...,'�ַ�n','\0'};

ע�⣺

1��[]�еĳ����ǿ���ʡ�Բ�д�ģ�

2�����õ�2�ַ�ʽ��ʱ�����һ��Ԫ�ر�����'\0'��'\0'��ʾ�ַ����Ľ�����־��

3�����õ�2�ַ�ʽ��ʱ���������в���д���ġ�

������ַ�����ʱ��Ҫʹ�ã�printf(��%s��,�ַ���������);����puts(�ַ���������);��
#include <stdio.h>
void print1(char *x)
{
	puts(x);	//�Դ����е�
}
void print2(char y[])
{
	printf("%s\n", y);
}
int main()
{
	char xcgj1[] = "good good study,";
	char xcgj2[] = { 'd','a','y',' ','d','a','y',' ','u','p','\0' };	//ֻ��һ����ĸһ����ĸ�򣬷������ʱֻ���ӡ���һ����ĸ
	printf("");
	print1(xcgj1);
	print2(xcgj2);
	print2(xcgj1);
	print1(xcgj2);
	system("pause");
	return 0;
}

/*
ʹ���ַ�������ע���������
1��strlen()��ȡ�ַ����ĳ��ȣ����ַ����������ǲ�������\0�����Һ��ֺ���ĸ�ĳ����ǲ�һ����.

2��strcmp()�ڱȽϵ�ʱ�����ַ�����ת����ASCII���ٽ��бȽ�,���صĽ��Ϊ0��ʾs1��s2��ASCII�����,���ؽ��Ϊ1��ʾs1��s2��ASCII���,���ؽ��Ϊ-1��ʾs1��s2��ASCII��С.
#include <stdio.h>
#include <string.h>
int main()
{
char s1[] = "a";
char s2[] = "A";
char s3[] = "a";
printf("%d\n", 'a');	//97
printf("%d\n", 'A');	//65
printf("%d ", strcmp(s1,s2));	//1???????Ϊʲô����Сд�������32...s1-s2
printf("%d ", strcmp(s2,s1));	//-1
printf("%d\n", strcmp(s1,s3));
system("pause");
return 0;
}

3��strcpy()����֮��Ḳ��ԭ���ַ���,���ַ����������ܶ��ַ����п���.strcpy(s1,s2)���Ǹ���s2,����s1.
#define PI  "imooc"  ������ַ�������

4��strcat��ʹ��ʱs1��s2ָ���ڴ�ռ䲻���ص�����s1Ҫ���㹻�Ŀռ�������Ҫ���Ƶ��ַ���.
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
����ǣ�hello world


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

/*��һ������Ϊ10�������������棬�����˰༶10��ѧ���Ŀ��Գɼ���Ҫ���д5���������ֱ�ʵ�ּ��㿼�Ե��ܷ֣���߷֣���ͷ֣�ƽ���ֺͿ��Գɼ���������*/
#include <stdio.h>
void sum(int score[])
{
	int i, j = 0;
	for (i = 0; i < 10; i++)
	{
		j = j + score[i];
	}
	printf("�ܷ���%d\n", j);
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
	printf("��߷���%d\n", j);
}

void lowest(int score[])
{
	int i, j = score[0];
	for (i = 0; i < 10; i++)
	{
		if (j > score[i])
			j = score[i];
	}
	printf("��ͷ���%d\n", j);
}

void average(int score[])
{
	int i, j = 0;
	for (i = 0; i < 10; i++)
	{
		j += score[i];
	}
	printf("ƽ������%d\n", j / 10);
}

void downrow(int score[])
{
	int i, j, k;
	for (i = 9; i >= 0; i--)	//i����j��ѭ������
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
	printf("�������У�");
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
	printf("�������У�");
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