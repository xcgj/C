//#include <stdio.h>
//int main01()
//{
//	void *p;//����һ�����������͵�ָ�����
//	p = NULL;//��ָ���ַ��ֵΪNULL��ֵΪNULL��ָ����ǿ�ָ��
//	printf("%d\n", p);//�����ַΪ0
//	return 0;
//}

//#include <stdio.h>
//int main02()
//{
//	int a = 0;
//	int *p;
//	//p = &a;
//	*p = 2;
//	//p��һ��Ұָ��
//	//p�м�С����ָ��һ���������Ч��ַ��������
//	//�������ָ����Ч��ַ���������
//	printf("%d\n", *p);
//	//������Ҫ����Ұָ��Ĵ��ڣ����ǵ��³����������Ҫԭ��
//	//��ָ���ǺϷ��ģ�Ұָ����Σ�յ�
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
	const int *p = &a;//pָ��ֻ��ָ��һ������
	//*p = 20;//���ڲ���ͨ��*p�ķ����޸�һ��constָ��
	printf("a=%d\n", *p);//*p������һ��ֻ����ֵ�������޸�
	int b = 50;
	p = &b;//��pָ������ָ��b�ĵ�ַ
	printf("b=%d\n", *p);//ֻ��
	return 0;
}

#include <stdio.h>
int main06()
{
	int a = 10;
	int *const p = &a;//����һ������ָ��
	*p = 20;//����ͨ������ָ���޸Ļ��ȡ������ֵ
	printf("%d\n", *p);
	int b = 50;
	//p = &b;//���󣬳���ָ��һ�������ˣ��Ͳ����޸���ָ��ı���
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
	while (*j++)//���ַ�������
		len++;
	printf("len = %d\n", len);
	j--;//��while�ж�j�Ѿ��ڡ�\0�������ַʱ��j++������һ�ֽڵĵ�ַ
	while (*k)//strcat
		*j++ = *k++;
	printf("%s\n", a);
	return 0;
}