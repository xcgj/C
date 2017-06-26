#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>//×Ö·û´®²Ù×÷¿âº¯Êý
int main01()
{
	char a[100] = "hello world";
	int len = strlen(a);
	printf("len=%d\n", len);
	char b[100] = "£ºxcgj";//Ã°ºÅÊÇÖÐÎÄ
	strncat(a, b, 1);
	printf("%s\n", a);
	return 0;
}

int main02()
{
	char a[100] = "Äã123654";
	char b[50] = "Äãhello123";
	strncpy(a, b, 3);
	puts(a);
	puts(b);
	return 0;
}

int main()
{
	char s[100]="123";
	int i = atoi(s);
	printf("%d\n", i);
	return 0;
}