#include <stdio.h>
int main()
{
	int test = 0x12345678;
	printf("%p\n", &test);	//%p 显示一个内存的地址;&test 变量test的地址编号

	return 0;
}
//
//int main()
//{
//	unsigned short k = -10;
//	printf("%x\n", k);	//16进制输出
//	return 0;
//}