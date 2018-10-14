#include<iostream>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
using namespace std;
int main()
{
	int fd,res;
	struct flock f1,fvar;
	char ch,type,fname[20];
	char buf[100];
	cout<<"Enter the file to be locked:"<<endl;
	cin>>fname;
	cout<<"currently running process is "<<getpid()<<endl;
	fd=open(fname,O_RDWR);
	cout<<"File descriptor:"<<fd;
	if(fd!=-1)
	{
		f1.l_pid=getpid();
		f1.l_type=F_WRLCK;
		f1.l_whence=SEEK_END;
		f1.l_start=0;
		f1.l_len=100;
		while((fcntl(fd,F_SETLK,&f1)==-1))
		{
			if(errno==EACCES || errno==EAGAIN)
			{
				cout<<"Already locked by another process"<<endl;
				(void)fcntl(fd,F_GETLK,&fvar);
				cout<<"\n file locked by:"<<fvar.l_pid<<endl;
				return 1;
			}
		}
		cout<<"Lock granted\n";
		if(lseek(fd,-50,SEEK_END)!=-1)
		{
			cout<<"Locked the file pointers to 50th byte from the end of the file\n";
			cout<<"\nfile ptr loc:"<<lseek(fd,(off_t)0,SEEK_CUR)<<endl<<endl;
			if(read(fd,&buf,50)!=-1)
			{
				cout<<"\nContent of file from last 50 byte is\n"<<endl;
				cout<<buf;
			}
		}
		cout<<"Press RETURN to unlock:"<<endl;
		getchar();
		getchar();
		fvar.l_type=F_UNLCK;
		fvar.l_pid=getpid();
		fvar.l_whence=SEEK_SET;
		fvar.l_start=0;
		fvar.l_len=0;
		if(fcntl(fd,F_SETLKW,&fvar)==-1)
			perror("FCNTL unlock error");
		else
			cout<<"successfully unlocked the file\n";
		close(fd);
	}
	else
	{
		perror("unable to open the file\n");
		return 1;
	}
}


/*Enter the file to be locked:
temp
currently running process is 3566
File descriptor:3Lock granted
Locked the file pointers to 50th byte from the end of the file

file ptr loc:6


Content of file from last 50 byte is


kengeri-uttarahalli road
srinivasapura
bangalore
�G�Press RETURN to unlock:

successfully unlocked the file
*/
