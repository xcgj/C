//3. ����һ���༶10���˵ĳɼ����飬���ȥ��߷ֺ���ͷ�֮���ƽ���֡�
#include <stdio.h>
int main__3(void)
{
	int score[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int i = 0;
	int	max = score[0];
	for (i = 1; i < 10; i++)
		max = (max < score[i]) ? score[i] : max;
	int	min = score[0];
	for (i = 1; i < 10; i++)
		min = (min > score[i]) ? score[i] : min;
	int total = 0;
	for (i = 0; i < 10; i++)
		total += score[i];
	printf("%d\n", total);
	printf("ȥ��߷ֺ���ͷ�֮���ƽ���� = %.2f\n", (total - max - min) / 8.0);
	return 0;
}