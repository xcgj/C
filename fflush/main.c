#include <stdio.h>

int main(void)
{
    //1 打开文件  fopen()
    //2 循环写入，exit退出   buffer[] while(1) memset() scanf() fprintf()
    //3 实时写入  fflush()
    //4 关闭文件  fclose()
    FILE *p = fopen("E:\\C_project\\file11.txt", "w");//1
    char buffer[100] = { 0 };
    while (1)
    {
        memset(buffer, 0, sizeof buffer);
        scanf("%s", buffer);
        if (strcmp("exit", buffer) == 0)
            break;
        fprintf(p, "%s\n", buffer);
        fflush(p);//3
        //fflush将缓冲区的内容立刻写入文件
        //优点：不会因为停电、死机等故障导致缓冲区的内容丢失
        //缺点：硬盘读写次数增加，程序效率低下，硬盘寿命变短
        //用途：有时用来修改配置文件，即刻生效，不用重启；修改一些不经常修改但很重要的数据
    }
    fclose(p);
    printf("done!\n");
    return 0;
}

