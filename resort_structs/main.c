#include <stdio.h>

struct A
{
    char name[10];
    int age;
};

int main(void)
{
    //1 定义结构体和结构体数组
    //2 创建文件1 fopen(), 缓冲数组buffer[], memset(),
    //fwrite(), 循环结束
    //memset() 清缓冲
    //while(1)或者while(!feof)循环, fread(), buffer接收,
    //fclose()文件1
    //buffer开始排序,
    //创建文件2 fopen()
    //fwrite()写入文件2
    //fclose()文件2
    struct A xcgj[3] = { 0 };//1
    int i = 0;
    for (i = 0; i < 3; i++)
        scanf("%s %d", &xcgj[i].name, &xcgj[i].age);
    FILE *p = fopen("E:\\C_project\\file0.txt", "wb");//写文件
    fwrite(&xcgj, sizeof(struct A), 3, p);
    fclose(p);

    struct A buffer[3] = { 0 };//有点麻烦，xcgj已经有数据了
    memset(buffer, 0, 3 * sizeof(struct A));
    p = fopen("E:\\C_project\\file0.txt", "rb");//读回数据
    fread(&buffer, sizeof(struct A), 3, p);
    fclose(p);

    for (i = 0; i < 3; i++)//检查顺序
        printf("name = %s, age = %d\n", buffer[i].name, buffer[i].age);

    printf("\n--------------------------\n");

    int j = 0;
    for(i = 0; i < 3; i++)//冒泡排序
        for(j = 1; j < 3 - i; j++)
            if (buffer[j].age < buffer[j - 1].age)
            {
                struct A temp = buffer[j];
                buffer[j] = buffer[j - 1];
                buffer[j - 1] = temp;
            }

    p = fopen("E:\\C_project\\file00.txt", "wb");//写文件
    fwrite(&buffer, sizeof(struct A), 3, p);
    fclose(p);

    memset(buffer, 0, 3 * sizeof(struct A));//验证是否排序
    p = fopen("E:\\C_project\\file00.txt", "rb");
    fread(buffer, sizeof(struct A), 3, p);
    fclose(p);
    for (i = 0; i < 3; i++)
        printf("name = %s, age = %d\n", buffer[i].name, buffer[i].age);

    printf("Program complete!\n");
    return 0;
}

