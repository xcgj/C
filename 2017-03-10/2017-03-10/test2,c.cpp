#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ��дһ��������ָ���ַ����������¹������á�
* char buf[] = "hello world itheima good";
* ����֮��Ľ��Ϊ"olleh dlrow amiehti doog";
* ���ַ����еĵ������� ������ı��ֲ��䡣
*/

#include <stdio.h>
#include <string.h>

void recur_verse(char *s, char *verse)
{
	if (s == NULL)  //  �жϿ�ָ��
		printf("func recur_inverse error, (s == NULL)\n");
	else if (*s == '\0')
		return; //�ݹ���ֹ����
	else
	{
		char *temp_s = s;
		char *temp_verse = verse;
		recur_verse(temp_s + 1, temp_verse);
		strncat(temp_verse, temp_s, 1); //����ݹ鸳ֵ
	}
}


void str_verse(char *str)
{
	if (str == NULL)  //�жϿ�ָ��
		printf("func str_verse error, (str == NULL)\n");
	else
	{
		char *temp_str = str;//��ʱָ��
		char buf_str[100] = { 0 };//��ȡ�Ӵ�
		char store_str[100] = { 0 };//�Ӵ����ղ�����
		char store_str2[100] = { 0 };//�ϲ����õ��Ӵ�
		char *p = store_str2;
		while (*temp_str)
		{
			memset(buf_str, 0, 100 * sizeof(char));//ÿ��ѭ�����buf��//��ȡ�Ӵ�
			memset(store_str, 0, 100 * sizeof(char));//�Ӵ����ղ�����
			while (*temp_str != ' ' && *temp_str)//2 ��temp != ' '����ֵ��buf
			{
				strncat(buf_str, temp_str, 1);
				temp_str++;
			}
			recur_verse(buf_str, store_str);//�ݹ�����
			strcat(store_str2, store_str);
			while (*temp_str == ' ')
			{
				strncat(store_str2, temp_str, 1);//ѭ������������ָ��ո��ַ���һλ
				temp_str++;
			}
		}
		strcpy(str, store_str2);
	}
}

int main__2(void)
{
	char p[100] = "hello world itheima good";
	str_verse(p);
	printf("%s\n", p);
	return 0;
}

