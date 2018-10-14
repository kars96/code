#include<stdio.h>
#define SIZE 16
int a[SIZE+1];

void prime(){
	int i = 2, j;
	
	while(i*i < SIZE){
		// printf("i  %d\n", i);
		if(a[i]==0){
		for(j=i+i;j<=SIZE;j+=i){
		// printf("j  %d\n", j);
			a[j]=1;
		}
	}
		i++;
	}
}

void main(){
	int i=0;
	prime();
	for(i=2;i<=SIZE;i++){
		if(a[i]==0)
		printf("%d\n",i );
	}
}