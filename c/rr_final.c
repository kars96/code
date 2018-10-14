#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 10
//Implementing Round robin scheduling algorithm using circular queue
int q[MAXSIZE];
int f=-1,r=-1;

void add(int i)
{
	q[r=(r+1)%MAXSIZE]=i;
}
int del()
{
	if(f==r)
	return -1;
	else return q[f=(f+1)%MAXSIZE];
}
int main()
{
	int at[10];
	int bt[10];
	int tbt[10];
	int pr=0,t=0,i,n,qt,sum=0;
	int pct[10];
	int ch=1;
	
	printf("Enter the number of processes(max-10)::  ");
	scanf("%d",&n);
	
	printf("Entet the burst time of the processes\n");
	for(i=0;i<n;i++)
	 scanf("%d",&tbt[i]);
	 
	while(ch==1)
	{
		printf("Enter the quantum size ::");
		scanf("%d",&qt);
		f=r=-1;
		t=0;
		for(i=0;i<n;i++)
		{	
			add(i);
			bt[i]=tbt[i];
		}
		system("clear");
		printf("Gantt chart\n");
	
		while((pr=del())!=-1)
		{
			if(bt[pr]>qt)
			{
				printf("t%d\n\tp%d\n",t,pr+1);
				t+=qt;
				bt[pr]-=qt;
				add(pr);
			}
			else
			{
  			printf("t%d\n\tp%d\n",t,pr+1);
				t+=bt[pr];
				bt[pr]=0;
				pct[pr]=t;
			}
		}
		printf("t%d\n",t);
		printf("Quantum is %d\n",qt);
		printf("\n%3s %5s %5s\n","pr","bt","pct");
		for(i=0;i<n;i++){
	    printf("%3d %5d %5d\n\n",i+1,tbt[i],pct[i]);sum+=pct[i];
		}  
		
		printf("Try out for different quantum?[0|1]:");
		scanf("%d",&ch);	
	 }
}
