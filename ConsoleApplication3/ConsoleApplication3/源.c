#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main01(void)
{
	char read[1024];
	FILE *p = fopen("E:\\C_project\\file.txt", "r");
	while (!feof(p))
	//foef(p):如果到达文件结尾，函数返回值为真
	//返回值为假，自动移动到下一行
	{
		memset(read, 0, sizeof(read));
		fgets(read, sizeof(read), p);
		//每次只能输出一行
		//read:内存地址，用来存放读取到的字符
		//sizeofread:存放字符的内存大小
		//p:fopen返回的文件指针
		printf("%s", read);
		//因为已经将文件读到read数组里了，所以要用read的地址输出
	}
	fclose(p);
	return 0;
}