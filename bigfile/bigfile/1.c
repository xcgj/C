#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#pragma warning(disable:4996)

int main_00()//paked a big file
{
	//srand & rand function produce number
	//fprintf write the number into file
	srand((unsigned int)time(NULL));
	FILE *p = fopen("E:\\C_project\\file9.txt", "w");
	for (int i = 0; i < SIZE; i++)
	{
		int a = (int)rand() % 200 + 100;//100~299
										//fwrite(&a, sizeof(int), 1, p);gibberish(messy code)
		fprintf(p, "%d\n", a);
	}
	fclose(p);
	printf("done\n");
	return 0;
}

int main()//sort the big file
{
	//1 staement an array for store the numbers
	//2 while(!feof()) ergodic the file, 
	//3 atoi(fgets()) plus the value of member if matches
	//4 ergodic the array, the print-times of the member equals the value of the member
	int sort[300] = { 0 };//1
	char buffer[100] = { 0 };
	int index = 0;
	FILE *p = fopen("E:\\C_project\\file9.txt", "r");//2
	while (!feof(p))
	{
		memset(buffer, 0, sizeof(buffer));
		fgets(buffer, sizeof(buffer), p);
		if (buffer[0] != 0)//way to ignore blank lines
		{
			index = atoi(buffer);//3
			sort[index]++;
		}
	}
	fclose(p);
	int i = 0;
	int times = 0;
	p = fopen("E:\\C_project\\file10.txt", "w");
	for (i = 0; i < 300; i++)//4
	{
		for (times = 0; times < sort[i]; times++)
		{
			//memset(buffer, 0, sizeof(buffer));
			//sprintf(buffer, "%d\n", i);
			//fwrite(buffer,sizeof(int), 1, p);
			fprintf(p, "%d\n", i);//upon three lines equal this line
		}
	}
	fclose(p);
	printf("done\n");
	return 0;
}