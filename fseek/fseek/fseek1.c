#include <stdio.h>
#pragma warning(disable:4996)

struct A
{
	char name[10];
	int age;
};

int main_1(void)
{
	//1 ����ṹ������
	//2 ��ýṹ������ֵ
	//3 ���ṹ��ȫ�����뵽�ļ���
	//4 ��ȡ�ļ�
	//5 ��fseek��ȡָ��λ�õĽṹ���Ա
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
	//	memset(buffer, 0, sizeof(struct A));//����*buffer��Ҫд��ַ
	//	fread(buffer, sizeof(struct A), 1, p);
	//	if (!feof(p) == 0)
	//		break;//��ֹ��ȡ���Ŀ���
	//	//if (fread(buffer, sizeof(struct A), 1, p) == 0);
	//	//	break;//�����������ֽ������˳�
	//	printf("name = %s, age = %d\n", buffer->name, buffer->age);
	//}
	fseek(p, sizeof(struct A) * 2, SEEK_CUR);//�ӵ�ǰλ��������2���ṹ���С

	memset(buffer, 0, sizeof(struct A));
	fread(buffer, sizeof(struct A), 1, p);
	printf("name = %s, age = %d\n", buffer->name, buffer->age);

	fseek(p, sizeof(struct A), SEEK_SET);//�ӿ�ʼλ��������1���ṹ���С

	memset(buffer, 0, sizeof(struct A));
	fread(buffer, sizeof(struct A), 1, p);
	printf("name = %s, age = %d\n", buffer->name, buffer->age);

	fseek(p, 0 - sizeof(struct A), SEEK_END);//�ӽ���λ��������1���ṹ���С

	memset(buffer, 0, sizeof(struct A));
	fread(buffer, sizeof(struct A), 1, p);
	printf("name = %s, age = %d\n", buffer->name, buffer->age);


	fclose(p);
	printf("Program succeed!\n");
	return 0;
}

