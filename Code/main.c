#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define XCGJ 8

void code(char *s, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++)
        *(s+i) += XCGJ;
}

int main(void)
{
    //读取视频文件，创建写入文件
    FILE *p1 = fopen("E:\\要加密的文件", "rb");//二进制读写
    FILE *p2 = fopen("E:\\生成加密文件", "wb");
    //定义缓冲大小
    char buffer[1024 * 4] = { 0 };
    //循环
    while (!feof(p1))
    {
        //清缓冲，开始拷贝文件，注意写出的大小要和写入的大小一致
        memset(buffer, 0, sizeof buffer);
        int set = fread(buffer, sizeof(char), sizeof(buffer), p1);
        code(buffer, set);
        fwrite(buffer, sizeof(char), set, p2);
        //set:从源文件读取多少字节，就往目标文件写入多少字节
    }
    //关闭文件
    fclose(p1);
    fclose(p2);
    printf("Complete\n");
    return 0;
}



void decode(char *s, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++)
        *(s + i) -= XCGJ;
}
