/*
* ����ԭ������
int TranString(char *pstr)��
�������ܰ�pstr�ַ����е�Сд��ĸ�ĳɴ�д��ĸ��
*/

#include <stdio.h>

void TranString(char *pstr)
{
	char *p = pstr;
	while (*p)
	{
		if (*p <= 'z' && *p >= 'a')
			*p -= ('a' - 'A');
		p++;
	}
}

int main(void)
{
	char p[] = "ASdfghjKLpoYT";
	TranString(p);
	printf("%s\n", p);
	return 0;
}