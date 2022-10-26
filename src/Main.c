#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "ProcBar.h"

unsigned long get_file_size(const char *filename)  
{  
    struct stat buf;  
    if(stat(filename, &buf)<0)  
    {  
        return 0;  
    }  
    return (unsigned long)buf.st_size;  
}

void read_file_test(char *fileName)
{
    int readLength = 0;
    unsigned long readSize = 0;
    unsigned long fileSize = 0;
    float proc = 0.0;

    S_ProcBar *bar = NULL;
    int fd = 0;
    char buff[1024];

    printf("read file test start!\n");
    fileSize = get_file_size(fileName);
    printf("%s size : %ld \n",fileName,fileSize);
    bar = GetPorcBar();
    SetPorcBarText(bar,"read file test:");
    PorcBarStart(bar);

    fd = open(fileName,O_RDONLY);
    if(-1 == fd)
    {
        perror("open file faild");
        PorcBarStop(bar);
        return;
    }

    while (readLength = read(fd,buff,sizeof(buff)))
    {
        readSize += readLength;
        proc = (double)readSize / (double)fileSize;
        PorcBarUpdate(bar,(proc * 100));
    }

    PorcBarUpdate(bar,100);
    WaitProcBarCompletion();

    close(fd);

    printf("read file test end!\n");
}

int main(int argc,char *argv[])
{
    read_file_test(argv[1]);
    return 0;
}
