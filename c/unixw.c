#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;
	char *fn="/tmp/myfifo";
	mkfifo(fn,0666);
	fd=open(fn,O_WRONLY);
	write(fd,"hi",sizeof("hi"));
	close(fd);
	return 0;
}

