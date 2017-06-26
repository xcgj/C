//  将字符串",avdf,,sdf,,,add,fdf,asf ssdsf,safds"以','分割，
//  把有效子字符串copy到自己分配的堆空间中
//  一维二维堆空间内存大小均与有效子串精准匹配
//  如在任一阶段内存分配失败(NULL)，需要对全部空间进行释放，并置为空指针
//  实现API接口
//  分配成功则打印该二维数组

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getalloc(const char **origin, char ***buf, char c)//分配一维二维内存空间
{
	if (origin == NULL || buf == NULL)
		return -1;
	const char  **porigin1 = origin;//辅助指针
	char        **temp_p1 = origin; //用来切割的指针1
	char        **temp_p2 = origin; //用来切割的指针2
	char        ***pbuf1 = buf;     //存放子串的指针
	int         line = 0;			 //计算有效行数
	while (**porigin1)              //遍历数组
	{
		temp_p2 = strchr(porigin1, c);//两个指针一开始都计算有效行数
		if (temp_p2 != NULL)//判断p2指针是否为空，即到达末尾
		{//  若大于0，该维度的指向','后的位置，p2移动，strchr
			if (temp_p2 - temp_p1 > 0)//  p2 - p1大于零，长度就是p2 - p1 + 1，最后一位放'\0'
			{
				line++;
			}
			temp_p1 = temp_p2 = temp_p2 + 1;//切割指针全部后移一位离开'\0'
		}
		else//到达末尾就跳出循环，用strlen(p1)计算最后维度的长度
		{
			if (strlen(temp_p1) > 1)//  p2 - p1大于零，长度就是p2 - p1 + 1，最后一位放'\0'
			{
				line++;
			}
		}//  长度是1，不计算，说明是'\0'
		(*porigin1)++;
	}
	printf("%d\n", line);
	//*pbuf1 = (char**)calloc(line * sizeof(char*));
	return 0;
}

int digout()//字符串分割、接收  接口
{

}

void print()//打印
{

}

int freeall()//内存释放 接口
{

}


int main(void)
{
	const char  *oristr = ",avdf,,sdf,,,add,fdf,asf ssdsf,safds";
	char        **mainbuf = NULL;//接收子串数组
	char        c = ',';
	int stage1 = getalloc(&oristr, &mainbuf, c);//分配一维二维内存空间
												//字符串分割、接收  接口
												//打印
												//内存释放 接口
	return 0;
}

