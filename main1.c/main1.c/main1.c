#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *replace_char(const char *str)
{
	const char *str_temp = str;
	char *buffer = (char *)calloc(100, sizeof(char));//1 2
	int len = strlen(str_temp);
	int i = 0;
	int j = 0;
	for (; i < len; i++, j++)
	{
		if ((str_temp[i] == str_temp[i + 1]) && islower(str_temp[i]))
		{
			buffer[j] = str_temp[i] - ('a' - 'A');
			i++;
		}
		else
			buffer[j] = str_temp[i];
	}
	return buffer;
}

int main(void)
{
	const char *p = "aaBBccDD";
	char *p1 = replace_char(p);
	printf("%s\n", p1);//4
	free(p1);//5
	printf("Hello World!\n");
	return 0;
}