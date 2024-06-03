#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    int fd;
    fd = open("ans.txt",O_RDWR|O_CREAT, 0666);
    if(fd == -1) {
        printf("open file failed!\n");
        return -1;
    }
    
    char str[20] = "hello world!";
    write(fd, str, 14);
    fsync(fd);//定义到文件头
    
    char* buf = (char*)malloc(20);
    memset(buf, 0 , 20);
    lseek(fd, 0, SEEK_SET);
    read(fd,buf,14);
    printf("%s\n", buf);
    //printf(,buf);
    free(buf);
    close(fd);
    
    return 0;
}