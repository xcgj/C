#include <stdio.h>

struct peny
{
	int age;
	int size;
	char clor[10];
};

int main()
{
	struct peny sell[3] = { { 20,30,"red" },{ 25,30,"black" },{ 30,34,"blue" } };
	int i = 0;
	//将结构数组的元素整体互换
	struct peny temp = sell[0];
	sell[0] = sell[1];
	sell[1] = temp;

	for (i = 0; i < 3; i++)
		printf("age = %d\tsize = %d\tclor = %s\n",
			sell[i].age, sell[i].size, sell[i].clor);
	return 0;
}