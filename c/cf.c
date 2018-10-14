#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define f1 "FIFO1"
#define f2 "FIFO2"

int main(){
	int fw, fr,n ;
	char buf[1000];

	if((fr = open(f1, O_RDONLY))<0)
		printf("Unable to open f1\n");
	if((fw = open(f2, O_WRONLY))<0)
		printf("Unable to open f2\n");

	printf("enter the filename\n");
	scanf("%s", buf);

	if(write(fw, buf, strlen(buf))<0)
		printf("Unable to write\n");
	else{
		while((n = read(fr, buf, 512))>0)
			write(1, buf, n);
	}
	// close(fr);
	// close(fw);
}