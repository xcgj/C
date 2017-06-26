#include <stdio.h>
#include "zlib.h"


int main()
{
    gzFile file = gzopen("2.tar.gz","wb");
    if(file == NULL)
    {
        fprintf(stderr,"file can't create");
        return 1;
    }
    char buf[2048] = {0};
    FILE *fp = fopen("1.tar","rb");
    if( fp == NULL)
    {
        fprintf(stderr,"file not found\n");
        goto done;
    }
    size_t ret = 0;
    while( ret = fread(buf,1,sizeof(buf),fp) ) 
    {
        gzwrite(file,buf,ret);
        
    }
    fclose(fp);
done:

    gzclose(file);
    return 0;
}
