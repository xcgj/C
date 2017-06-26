//定义结构体分别读取tar文件名和tar文件长度
//转化tar文件长度
//fread 512字节以后的size长度
//fwrite到新文件
//当读到的文件名是NULL时，停止读取

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tar_header
{
	char name[100];//文件名
	char mode[8];
	char uid[8];
	char gid[8];
	char size[12]; //文件大小的八进制数的字符串形式
	char mtime[12];
	char chksum[8];
	char typeflag;
	char linkname[100];
	char magic[6];
	char version[2];
	char uname[32];
	char gname[32];
	char devmajor[8];
	char devminor[8];
	char prefix[155];
	char padding[12];
};

int otod(char *s)
{
	int o = atoi(s);
	int i = 1;
	int sum = 0;
	while (o)
	{
		sum += i * ( o % 10);
		i *= 8;
		o /= 10;
	}
	return sum;
}

int main(void)
{
	char buf[sizeof(struct tar_header)] = { 0 };
	int jump = 0;
	while (1)
	{
		FILE *p = fopen("a.tar", "r");
		if (p == NULL)
		{
			printf("err, file not found\n");
			return 0;
		}
		fseek(p, jump, SEEK_SET);
		int count = 0;
		memset(buf, 0, sizeof(struct tar_header));
		count = fread(buf, 1, sizeof(struct tar_header), p);
		if (count == 0)
			break;
		struct tar_header *head = ( struct tar_header*)buf;
		int len = otod(head->size);
		fseek(p, 512 + jump, SEEK_SET);
		char buf_data[len];
		fread(buf_data, 1, len, p);
		fclose(p);
		p = fopen(head->name, "w");
		fwrite(buf_data, 1, len, p);
		fclose(p);
		jump = ((jump + 512 + len) / 512 + 1) * 512;
	}
	return 0;
}
