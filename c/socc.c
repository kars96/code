#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(int argc,char *argv[])
{
int create_socket,cont;
int bufsize=1024;
char *buffer=malloc(bufsize);
char fname[256];
struct sockaddr_in address;
if((create_socket=socket(AF_INET,SOCK_STREAM,0))>0)
  printf("The socket was created.....\n");
address.sin_family=AF_INET;
address.sin_port=htons(15000);
inet_pton(AF_INET,argv[1],&address.sin_addr);
if(connect(create_socket,(struct sockaddr*)&address,sizeof(address))==0)
  printf("Request accepted for the server %s\n ",argv[1]);
printf("Enter the filename:");scanf("%s",fname);
send(create_socket,fname,255,0);
printf("Request accepted......Receiving the file....\n");
printf("The contents of the file are.....\n");
while((cont=recv(create_socket,buffer,bufsize,0))>0)
{
write(1,buffer,cont);
}
printf("EOF\n");
close(create_socket);
}
