//  ���ַ���",avdf,,sdf,,,add,fdf,asf ssdsf,safds"��','�ָ
//  ����Ч���ַ���copy���Լ�����Ķѿռ���
//  һά��ά�ѿռ��ڴ��С������Ч�Ӵ���׼ƥ��
//  ������һ�׶��ڴ����ʧ��(NULL)����Ҫ��ȫ���ռ�����ͷţ�����Ϊ��ָ��
//  ʵ��API�ӿ�
//  ����ɹ����ӡ�ö�ά����

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getalloc(const char **origin, char ***buf, char c)//����һά��ά�ڴ�ռ�
{
	if (origin == NULL || buf == NULL)
		return -1;
	const char  **porigin1 = origin;//����ָ��
	char        **temp_p1 = origin; //�����и��ָ��1
	char        **temp_p2 = origin; //�����и��ָ��2
	char        ***pbuf1 = buf;     //����Ӵ���ָ��
	int         line = 0;			 //������Ч����
	while (**porigin1)              //��������
	{
		temp_p2 = strchr(porigin1, c);//����ָ��һ��ʼ��������Ч����
		if (temp_p2 != NULL)//�ж�p2ָ���Ƿ�Ϊ�գ�������ĩβ
		{//  ������0����ά�ȵ�ָ��','���λ�ã�p2�ƶ���strchr
			if (temp_p2 - temp_p1 > 0)//  p2 - p1�����㣬���Ⱦ���p2 - p1 + 1�����һλ��'\0'
			{
				line++;
			}
			temp_p1 = temp_p2 = temp_p2 + 1;//�и�ָ��ȫ������һλ�뿪'\0'
		}
		else//����ĩβ������ѭ������strlen(p1)�������ά�ȵĳ���
		{
			if (strlen(temp_p1) > 1)//  p2 - p1�����㣬���Ⱦ���p2 - p1 + 1�����һλ��'\0'
			{
				line++;
			}
		}//  ������1�������㣬˵����'\0'
		(*porigin1)++;
	}
	printf("%d\n", line);
	//*pbuf1 = (char**)calloc(line * sizeof(char*));
	return 0;
}

int digout()//�ַ����ָ����  �ӿ�
{

}

void print()//��ӡ
{

}

int freeall()//�ڴ��ͷ� �ӿ�
{

}


int main(void)
{
	const char  *oristr = ",avdf,,sdf,,,add,fdf,asf ssdsf,safds";
	char        **mainbuf = NULL;//�����Ӵ�����
	char        c = ',';
	int stage1 = getalloc(&oristr, &mainbuf, c);//����һά��ά�ڴ�ռ�
												//�ַ����ָ����  �ӿ�
												//��ӡ
												//�ڴ��ͷ� �ӿ�
	return 0;
}

