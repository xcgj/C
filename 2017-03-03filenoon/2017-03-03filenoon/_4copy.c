#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void decode(char *, size_t);

int main(void)
{
	//读取视频文件，创建写入文件
	FILE *p1 = fopen("E:\\zh2017.2.18_c", "rb");//二进制读写
	FILE *p2 = fopen("E:\\zh2017.2.18_d", "wb");
	//定义缓冲大小
	char buffer[1024 * 4] = { 0 };
	//循环
	while (!feof(p1))
	{
		//清缓冲，开始拷贝文件，注意写出的大小要和写入的大小一致
		memset(buffer, 0, sizeof buffer);
		int set = fread(buffer, sizeof(char), sizeof(buffer), p1);
		decode(buffer, set);
		fwrite(buffer, sizeof(char), set, p2);
		//set:从源文件读取多少字节，就往目标文件写入多少字节
	}
	//关闭文件
	fclose(p1);
	fclose(p2);
	printf("Complete\n");
	return 0;
}