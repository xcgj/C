#include <stdio.h>
#include <ctype.h>

void swap(char *a, char *b)
{
	char *p = a;
	char *q = b;
	while (p < q)
	{
		char temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
}

void reverse(char *s)
{
	char *p = s;
	char *q = NULL;
	char *r = NULL;
	while (*p)//遍历时p指向非0
	{
		if (q == NULL)
			q = p;
		r = p;
		p++;
		if (!*p || isspace(*p))//遇到0或空字符，开始交换
		{
			swap(q, r);
			q = r = NULL;
			p++;
		}
	}
}

int main(void)
{
	char s[100] = "Hello World!\n";
	reverse(s);
	printf("%s\n", s);
	return 0;
}