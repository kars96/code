#include<stdio.h>
#include<stdlib.h>
#define MAXPROC 10
#define MAXRES 10

typedef struct 
{
	int _alloc[MAXRES];
	int _maxneed[MAXRES];
	int _need[MAXRES];
}process;
process p[MAXPROC];
int tr,tp;
int availres[MAXRES],maxres[MAXRES];

FILE *fp;
#define wrmat(xyz) \
 for(i=0;i<tp;i++) \
{ \
	printf("p%-4d",i);\
	for(j=0;j<tr;j++)\
	printf("%4d",p[i]._##xyz[j]);\
	printf("\n");\
}

#define rdmat(xyz) \
	for(i=0;i<tp;i++)\
	{\
	 for(j=0;j<tr;j++)\
	  fscanf(fp,"%d",&p[i]._##xyz[j]);\
	 }
	 
void rdarr(int* xyz){
int i,j;
   for(i=0;i<tr;i++)
    fscanf(fp,"%d",&xyz[i]);
    }

void rdarr2(int* xyz){
int i,j;
   for(i=0;i<tr;i++)
    scanf("%d",&xyz[i]);
    }
 
 
void wrarr(int* xyz){
int i,j;
	for(i=0;i<tr;i++)
		printf("%d\t",xyz[i]);
}
int lteq();
void input();
void print();
int safestate();
void req();
void freeres();		
int lteq(int *a,int* b,int n)
{
int i,j;
	for(i=0;i<n;i++)
		if(a[i]>b[i]) return 0;
	return 1;
}

void input()
{
int i,j;	
	fp=fopen("ipr","r");
	printf("\nEnter the num of resources::  ");
	fscanf(fp,"%d",&tr);
	
	printf("\nEnter the max instances for each resources\n");
	rdarr(maxres);
	
	printf("\nEnter the number of processes:: ");
	fscanf(fp,"%d",&tp);
	
	printf("\nEnter the max needs matrix\n");
	rdmat(maxneed)
	
 	printf("\nEnter the allocation matrix\n");
 	rdmat(alloc)
 	
 	for(i=0;i<tp;i++)
 		for(j=0;j<tr;j++)
 			p[i]._need[j]=p[i]._maxneed[j]-p[i]._alloc[j];
 	
 	printf("\nEnter the available instances of each resources\n");
 	rdarr(availres);
 	print();
 	if(!safestate())
 	{
 		printf("error:incorrect Inputs. TRy again!!\n");
 		input();
 	}
 }
 
 
 void print()
 {
 int i,j;
 	printf("tp=%d Tr=%d\n",tp,tr);
 	printf("\nMax res array\n");
 	wrarr(maxres);
 	
 	printf("\nAvail res array\n");
 	wrarr(availres);
 	
 	printf("\nallocation matrix\n");
 	wrmat(alloc)
 	
 	printf("\nMax needs matrix\n");
 	wrmat(maxneed);
 	
 	printf("\nNeeds matrix\n");
 	wrmat(need);
} 	
 	
int safestate()
{
	int i,j;	
	int flag,finish[tp],work[tr],n=0,sseq[tp];
	for(i=0;i<tr;i++)
		work[i]=availres[i];
	for(i=0;i<tp;i++)
		finish[i]=0;
	while(1)
	{	
		flag=0;
		for(i=0;i<tp;i++)
		{	
			if(lteq(p[i]._need,work,tr) && !finish[i])
			{
				flag=1;finish[i]=1;sseq[n++]=i;
				for(j=0;j<tr;j++)	work[j]+=p[i]._alloc[j];
			}
		}
		if(n==tp){
			printf("\n//system is in safestate\n");
			printf("\nThe safe sequence is\n");
			for(i=0;i<tp;i++)
				printf("->P%d",sseq[i]);
			return 1;
			}
		else if(flag==0)
		{
			printf("//system is in unsafe state\n");
			return 0;
		}
		else printf("n=%d\n",n);
	}
}

void freeres()
{ 
int i,j;
	int temp,pid;
	printf("\nEnter the pid of the process to release its resources:: ");
	scanf("%d",&pid);
	printf("\nP%d is _allocated with the following instances of resources\n",pid);
	wrarr(p[pid]._alloc);
	printf("Enter the no. of instances of resources to be freed\n");
	for(i=0;i<tr;i++)
	{
		scanf("%d",&temp);
		p[pid]._alloc[i]-=temp;
		availres[i]+=temp;
		p[pid]._need[i]=p[pid]._maxneed[i]-p[pid]._alloc[i];
	}
	//system("clear");
	print();
}
	
void req()
{
int i,j;
	int temp[tr],pid;
	printf("\nEnter the ppid of requesting process::  ");
	scanf("%d",&pid);
	printf("\nEnter the no. of instances of each resources to be a_allocated to P%d\n",pid);
	rdarr2(temp);
	
	if(!lteq(temp,p[pid]._need,tr))
		printf("\nRequest rejected...\nRequest exceeds the max _need of this process\n");
	else if (!lteq(temp,availres,tr))
		printf("Request rejected..\nInsufficient resources!!\n");
	else
	{
		for(i=0;i<tr;i++)
		{
			p[pid]._alloc[i]+=temp[i];
			p[pid]._need[i]=p[pid]._maxneed[i]-p[pid]._alloc[i];
			availres[i]-=temp[i];
			//system("clear");
		}
		if(safestate())
		{				
		printf("\nRequest committed\n");
		print();
		}
		else
		{
			for(i=0;i<tr;i++)
			{
				p[pid]._alloc[i]-=temp[i];
				p[pid]._need[i]=p[pid]._maxneed[i]-p[pid]._alloc[i];
				availres[i]+=temp[i];
				printf("\nRequest was rejected since //system may get into unsafe state.\nTry again after freeing resources\n");
			}
		}				
	}
}

int main()
{
	int ch;
	do
	{
		printf(" \t\n0.Input\n1.Print\n2.safe\n3.Free resources\n4.New req\n5.exit\n");
		printf("Enter the choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: input();
						break;
			case 1: print();
						break;
			case 2: safestate();
						break;
			case 3: freeres();
						break;
			case 4: req();
						break;
			default: exit(0);
		}
	}while(1);
}
