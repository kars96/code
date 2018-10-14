#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#define MAX 1024

int main()
{
	int fd;char buf[MAX];
	char *fn="/tmp/myfifo";
	fd=open(fn,O_RDONLY);
	read(fd,buf,MAX);
	close(fd);
	return 0;
}

