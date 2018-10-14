#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define f1 "FIFO1"
#define f2 "FIFO2"

int main(){
	int fw,fr, fd, n;
	char buf[1000];
	if(mkfifo(f1, 0777)<0)
		printf("unable to create f1");
	if(mkfifo(f2, 0777)<0)
		printf("unable to create f2");
	
	if((fw = open(f1, O_WRONLY))<0)
		printf("Unable to open f1");
	if((fr = open(f2, O_RDONLY))<0)
		printf("unable to open f2");

	if((n = read(fr, buf, 128))<0)
		printf("Unable to read\n");
	else{
		buf[n]='\0';
		printf("client requested for  %s\n", buf);
	}

	if((fd = open(buf, O_RDONLY))<0)
		printf("Unable to open %s\n", buf );
	else{
		while((n=read(fd, buf, 512))>0)
			write(fw, buf,n);
	}

	close(fr);unlink(f2);
	close(fw);unlink(f1);
}