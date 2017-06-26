#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
            //用clock_t数据类型调用clock()函数计算操作时间，单位毫秒
    clock_t t1 = clock();
            //用stat的st_size能计算文件大小，格式是数据结构
    struct stat capacity = { 0 };
            //将stat与文件关联
    stat("E:\\C_project\\copy.wmv", &capacity);
    //调用完stat函数后，文件信息就保存在了capacity结构里面
            //给指针定分配小为st_size的堆内存
            //char *buffer = calloc(capacity.st_size, sizeof(char));
    char *buffer = malloc(capacity.st_size);
            //可以memset内存空间，也可以不用，下一步即将完全填充
    //memset(buffer, 0, capacity.st_size);
            //将文件打开，缓冲到堆内存
    FILE *p = fopen("E:\\C_project\\copy.wmv", "rb");
    fread(buffer, sizeof(char), capacity.st_size, p);
            //先关闭文件，释放文件指针
    fclose(p);
            //再定义指针打开写入文件
    p = fopen("E:\\C_project\\copy1.wmv", "wb");
            //将堆内存的缓冲写入文件
    fwrite(buffer, sizeof(char), capacity.st_size, p);
            //关闭文件，释放空间
    fclose(p);
    free(buffer);
            //计算结束时间
    clock_t t2 = clock();
    printf("Program Complete, time = %u(ms)!\n", t2 - t1);
    return 0;
}

