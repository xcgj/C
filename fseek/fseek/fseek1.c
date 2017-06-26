#include <stdio.h>
#pragma warning(disable:4996)

struct A
{
	char name[10];
	int age;
};

int main_1(void)
{
	//1 定义结构体数组
	//2 获得结构体数组值
	//3 将结构体全部输入到文件中
	//4 读取文件
	//5 用fseek获取指定位置的结构体成员
	struct A test[5] = { 0 };//1
	int cir = 0;
	for (cir = 0; cir < 5; cir++)//2
	{
		printf("please input name: ");
		scanf("%s", test[cir].name);
		printf("please input age: ");
		scanf("%d", &test[cir].age);
	}
	FILE *p = fopen("E:\\C_project\\file8.txt", "w");
	fwrite(test, sizeof(struct A), 5, p);
	fclose(p);
	printf("Written complete!\n");
	p = fopen("E:\\C_project\\file8.txt", "r");//4
	struct A *buffer = malloc(sizeof(struct A));
	//while (1)
	//{
	//	memset(buffer, 0, sizeof(struct A));//不是*buffer，要写地址
	//	fread(buffer, sizeof(struct A), 1, p);
	//	if (!feof(p) == 0)
	//		break;//防止读取最后的空行
	//	//if (fread(buffer, sizeof(struct A), 1, p) == 0);
	//	//	break;//读到不满足字节数就退出
	//	printf("name = %s, age = %d\n", buffer->name, buffer->age);
	//}
	fseek(p, sizeof(struct A) * 2, SEEK_CUR);//从当前位置向下走2个结构体大小

	memset(buffer, 0, sizeof(struct A));
	fread(buffer, sizeof(struct A), 1, p);
	printf("name = %s, age = %d\n", buffer->name, buffer->age);

	fseek(p, sizeof(struct A), SEEK_SET);//从开始位置向下走1个结构体大小

	memset(buffer, 0, sizeof(struct A));
	fread(buffer, sizeof(struct A), 1, p);
	printf("name = %s, age = %d\n", buffer->name, buffer->age);

	fseek(p, 0 - sizeof(struct A), SEEK_END);//从结束位置向上走1个结构体大小

	memset(buffer, 0, sizeof(struct A));
	fread(buffer, sizeof(struct A), 1, p);
	printf("name = %s, age = %d\n", buffer->name, buffer->age);


	fclose(p);
	printf("Program succeed!\n");
	return 0;
}

