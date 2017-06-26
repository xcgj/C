#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 编写一个函数将指定字符串按照以下规则逆置。
* char buf[] = "hello world itheima good";
* 逆置之后的结果为"olleh dlrow amiehti doog";
* 将字符串中的单词逆置 ，其余的保持不变。
*/

#include <stdio.h>
#include <string.h>

void recur_verse(char *s, char *verse)
{
	if (s == NULL)  //  判断空指针
		printf("func recur_inverse error, (s == NULL)\n");
	else if (*s == '\0')
		return; //递归终止条件
	else
	{
		char *temp_s = s;
		char *temp_verse = verse;
		recur_verse(temp_s + 1, temp_verse);
		strncat(temp_verse, temp_s, 1); //逆序递归赋值
	}
}


void str_verse(char *str)
{
	if (str == NULL)  //判断空指针
		printf("func str_verse error, (str == NULL)\n");
	else
	{
		char *temp_str = str;//临时指针
		char buf_str[100] = { 0 };//提取子串
		char store_str[100] = { 0 };//子串接收并逆置
		char store_str2[100] = { 0 };//合并逆置的子串
		char *p = store_str2;
		while (*temp_str)
		{
			memset(buf_str, 0, 100 * sizeof(char));//每次循环清空buf，//提取子串
			memset(store_str, 0, 100 * sizeof(char));//子串接收并逆置
			while (*temp_str != ' ' && *temp_str)//2 当temp != ' '，赋值给buf
			{
				strncat(buf_str, temp_str, 1);
				temp_str++;
			}
			recur_verse(buf_str, store_str);//递归逆置
			strcat(store_str2, store_str);
			while (*temp_str == ' ')
			{
				strncat(store_str2, temp_str, 1);//循环结束两个都指向空格字符后一位
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

