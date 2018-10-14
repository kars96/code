#include<stdio.h>
#include<stdlib.h>
//Implementing Shortest remaining time first algorithm using priority queue
typedef struct
{
	int p;
	int bt;
}pq;
pq q1[10];
int top=-1;

void swp(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void sort()
{
	int i,j;
	for(i=0;i<=top;i++)
	 for(j=0;j<=(top-i-1);j++)
	   {
	   	 if(q1[j].bt<q1[j+1].bt)
	   	 {
	   	 	swp(&q1[j].bt,&q1[j+1].bt);
	   	 	swp(&q1[j].p,&q1[j+1].p);
	   	 }
	   }
}

void push(int j,int *bt)
{
	q1[++top].p=j;
	q1[top].bt=bt[j];
	sort();
}

int pop()
{
	if(top==-1)
	 return -1;
	else 
		return q1[top--].p;
}

int main()
{
	int at[10];
	int bt[10];
	int pct[10];
	int btt=0;
	int tbt[10];
	int pr=-1,j,t=0,i=0,n,sumt=0,sumw=0;

	printf("Enter the number of processes(max-10)::	");
	scanf("%d",&n);
	
	printf("Enter the arrival time of the processes\n");
	for(j=0;j<n;j++)
		scanf("%d",&at[j]);
	
	printf("Enter the burst time of the processes\n");
	for(j=0;j<n;j++){
		scanf("%d",&bt[j]);
		btt+=bt[j];
		tbt[j]=bt[j];
		}
	system("clear");// use clrscr(); from conio.h in windows
	printf("Gantt chart\n");
	while(btt)
	{
		if(t==at[i])
		{
			push(i++,bt);
			if(pr!=-1&&q1[top].bt<bt[pr])
			{
				push(pr,bt);
				pr=pop();	
			}
			if(pr==-1)pr=pop();	
		}
		if(pr!=-1)
		{
			printf("t%d   \n      p%d\n",t,pr+1);
			bt[pr]--;
			btt--;
			
			if(bt[pr]==0)
			 {
			 	 pct[pr]=t+1;
			 	 pr=pop();
			 }
		}
		else 		printf("t%d   \n      \n",t);
		t++;
	}
	printf("t%d\n",t);
	printf("%5s %5s %5s %5s %5s %5s\n","pr","at","bt","pct","wt","tat");
	for(i=0;i<n;i++)
	{
	  printf("%5d %5d %5d %5d %5d %5d\n",i+1,at[i],tbt[i],pct[i],pct[i]-at[i]-tbt[i],pct[i]-at[i]);
	  sumt+=pct[i]-at[i];
	  sumw+=pct[i]-at[i]-tbt[i];
	}
	printf("AVG turn-around time is %d\n",sumt/n);
	printf("AVG waiting time is %d\n",sumw/n);
	return 1;
}
