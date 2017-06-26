#include <stdio.h>
int main()
{
	int a = 10;
	int *p = &a;
	int **pp = &p;
	**pp = 100;//通过二级指针修改a的值
	//*pp = 200;//相当于将p的地址指向了编号为200的内存，pp还是正常指针，但p变成了野指针
	printf("%d\n", a);
	int ***ppp = &pp;
	***ppp = 400;
	printf("%d\n", a);
	//a = ppp;
	printf("*ppp=%d,**ppp=%d,***ppp=%d\n", *ppp, **ppp, ***ppp);//*ppp=10156924,**ppp=10156936,***ppp=400
	printf("*pp=%d,**pp=%d\n", *pp, **pp);//*pp=10156936,**pp=400
	printf("*p=%d,a=%d,&a=%d\n", *p, a, &a);//*p=400,a=400,&a=10156936
	printf("&p=%d,&pp=%d,&ppp=%d\n", &p, &pp, &ppp);//&p=10156924,&pp=10156912,&ppp=10156900
	printf("ppp=%d,pp=%d,p=%d\n", ppp, pp, p);//ppp=10156912,pp=10156924,p=10156936
	//*ppp=pp=&p	**ppp=*pp=p=&a	***ppp=**pp=*p=a
	return 0;
}




int main04()
{
	int *ar1[10];
	char *ar2[10];
	long *ar3[10];
	printf("%d,%d\n", sizeof(ar1), sizeof(ar1[0]));
	printf("%d,%d\n", sizeof(ar2), sizeof(ar2[0]));
	printf("%d,%d\n", sizeof(ar3), sizeof(ar3[0]));
	return 0;
}


int main03()
{
	int arry[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = arry;
	p[2] = 10;
	*(p + 4) = 20;
	p += 6;
	*p = 30;
	p[2] = 40;//指向arry的第8个元素
	int i = 0;
	for (i; i < 10; i++)
	{
		printf("%d,", arry[i]);
	}
	return 0;
}











int main02()
{
	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = ar;
	int i = 0;
	for (i; i < 10; i++)
	{
		p[i] = i * 2;//C语言允许指针通过数组下标的方法访问数组成员
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", ar[i]);
	}
	return 0;
}








void reverse(char *s);

int main01()
{
	char po[100] = "你咯看电视";
	printf("%s\n", po);
	reverse(po);
	printf("%s\n", po);
	return 0;
}


void reverse(char *s)
{
	char *d = s;
	char *u = s + 9;
	while (d < (u - 1))
	{
		int index = *d;
		*d = *(u - 1);
		*(u - 1) = index;
		index = *(d + 1);
		*(d + 1) = *u;
		*u = index;
		d += 2;
		u -= 2;
	}
}