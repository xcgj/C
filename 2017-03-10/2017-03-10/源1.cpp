#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main___()
{
	char buf[] = "hello world itheima good";
	char tempBuf[1024];
	strcpy(tempBuf, buf);
	char * pch;
	pch = strtok(buf, " ");
	while (pch != NULL)
	{
		char *tempPtr = NULL;
		//找到第一个匹配字符在tempBuf中的地址
		tempPtr = strstr(tempBuf, pch);
		//倒置pch
		int pchLen = strlen(pch);
		for (int i = 0; i < pchLen / 2; i++)
		{
			char tempChar = pch[i];
			pch[i] = pch[pchLen - 1 - i];
			pch[pchLen - 1 - i] = tempChar;
		}
		strncat(tempPtr, pch, pchLen);
		pch = strtok(NULL, " ");
	}
	return 0;
}