#include <stdio.h>
int main()
{
	int test = 0x12345678;
	printf("%p\n", &test);	//%p ��ʾһ���ڴ�ĵ�ַ;&test ����test�ĵ�ַ���

	return 0;
}
//
//int main()
//{
//	unsigned short k = -10;
//	printf("%x\n", k);	//16�������
//	return 0;
//}