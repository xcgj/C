#include <stdio.h>
int main()
{
	int a = 10;
	int *p;
	p = &a;
	//*p����˼��ָ�����ָ��a������ڴ��������
	int b = *p;
	//ָ����������ڴ��ַ���ŵ����ݸ�ֵ��bʹ�ã���b�õ���һ���µ�ַ
	*p = 20;//ͨ��ָ���ӵ��޸�ָ��ָ�������ֵ����a�ڴ��ַ���ŵ������޸��ˣ�
	int c = *p;
	printf("%d %d %d %d %u %u\n", a, b, *p, c, &a, &b);
	char arr1[10] = { 0 };
	int arr2[10] = { 0 };
	printf("%u %u %u %u\n", arr1, &arr1[0], &arr1[1], &arr1[2]);
	printf("%u %u %u %u\n", arr2, &arr2[0], &arr2[1], &arr2[2]);
	//�������������һ��Ԫ�صĵ�ַ
	return 0;
}