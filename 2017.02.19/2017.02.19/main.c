#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(int argc, char *args[])
//*args[]�Ƕ�ά����
{
	if (argc != 4)
		printf("��ʽ����\n");
	else
	{
		float i = 0;
		int a = atoi(args[1]);
		int c = atoi(args[3]);
		char *s;
		//s = args[2];//args[]��ŵ��ǵ�ַ������&
		//char b = *s;//��ȡ�׵�ַ���ŵ��ڴ�ֵ,��s[0]
		switch (args[2][0])
		{
		case '+':
			i = a + c;
			break;
		case '-':
			i = a - c;
			break;
		case '*':
			i = a * c;
			break;
		case '/':
			if (c != 0)
				i = (float)a / c;
			else
			{
				printf("error\n");
				return 0;
			}
			break;
		default:
			printf("���������\n");
			return 0;
		}
		printf("%0.2f\n", i);
	}
	return 0;
}

int main02(int argc, char *args[])
{
	//system("dir");
	char get[100] = "dir";
	int i = 0;
	for (i = 1; i < argc; i++)
	{
		strcat(get, " ");
		strcat(get, *(args + i));
	}
	system(get);
	return 0;
}





int main01(int argc, char *args[])
//argc��ʾ����ִ�е�ʱ���м�����������������Ҳ��һ������
//char *args[]��һ��ָ�����飬ÿ����Ա��������char *
//*args[] ��Ա��������argc��
{
	printf("%d\n", argc);
	int i = 0;
	for (i = 0; i < argc; i++)
	{
		printf("a[%d] = %s\n", i, args[i]);
	}
	return 0;
}