//2. ˵һ�����������ʲô���⣬Ϊʲô����ô����?
// ��ʾ ��length����Ϊ0��ʱ�����������0�����Ǵ���

#include <stdio.h>
#pragma warning(disable:4996)
int main__2(void)
{
	unsigned int length;//û��ָ�����ͣ�����int
	scanf("%d", &length);
	int i;
	int result = 0;
	if (0 == length)
		printf("error\n");
	else
	{
		int a[5];//��������,����
		for (i = 0; i <= length - 1; i++)//��д��Ӣ����ĸO���ĳ���0
			result += a[i];
		printf("%d\n", result);
	}
	return 0;
}