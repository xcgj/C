#include <stdio.h>
#pragma warning(disable:4996)
struct A
{
	int a;
	char b[100];
};

int main_out()
{
	//定义结构体空变量
	//打开文件
	//fread文件到结构体变量
	struct A xcgj;
	FILE *p = fopen("E:\\C_project\\file8.dat", "rb");
	fread(&xcgj, sizeof(xcgj), 1, p);
	fclose(p);
	printf("xcgj.a = %d\nxcgj.b = %s\n", xcgj.a, xcgj.b);
	return 0;
}


int main_in()//用fwrite将结构体写入二进制文件
{
	//定义结构体变量
	//创建文件
	//写入文件
	struct A xcgj = { 1, "c01" };
	FILE *p = fopen("E:\\C_project\\file8.dat", "wb");
	fwrite(&xcgj, sizeof(xcgj), 1, p);
	fclose(p);
	printf("Program complete\n");
	return 0;
}