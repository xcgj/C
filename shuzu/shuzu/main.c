#include <stdio.h>
int main01()//ͳ�ƻ�Ϻ�����ĸ���ַ�������
{
	char arr[100] = "��s��hiy��c��";
	int lenth = 0;
	while (arr[lenth++]);//ͳ������ʵ��ʹ���ֽڳ��ȣ������ַ���ĩβ��0
	lenth--;//ͳ����������ֽڳ��ȣ�����=13
	int lenstr = 0;
	int loop = 0;
	while(loop <= lenth-1)//loopȡֵ:0-12��lenthȡֵ:1-13,���1
	{
		lenstr++;//ͳ���ַ�����
		if (arr[loop] < 0)//�����ֽ���+2
		{
			loop += 2;
		}
		else//��ĸ�ֽ���+1
		{			
			loop++;
		}
	}
	printf("%d\n", lenstr);
	return 0;
}

int main02()
{
	char arr[100] = "��s��hiy��c��";
	int len = 0;//�ַ�����
	int i = 0;//ѭ������
	while (arr[i])//ֵΪ����ֹ
	{
		if (arr[i] < 0)//�������ֽ�һλ
			i++;
		i++;//���Ǻ�����������
		len++;
	}
	printf("The lenth of the arr is:%d\n", len);
	return 0;
}

int main()//ȥ���ַ������ո�
{
	char arr[100] = "�� y   ";
	int len = 0;
	while (arr[len++]);
	len--;//�ֽ���
	len--;//����0�±�
	while (arr[len--] == ' ');
	arr[len + 2] = 0;
	printf("(%s)\n", arr);
	return 0;
}