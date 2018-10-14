#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int fibo(int n)
{
	if(n<2) return n;
	return fibo(n-1)+fibo(n-2);
}

int main(){
	int f[25],n,i;
	static omp_lock_t lock[25];
	printf("Enter the value of n");
	scanf("%d",&n);
	printf("The number of threads are %d\n",omp_get_num_threads());
	for(i=0;i<n;i++)
	{	
		omp_init_lock(&lock[i]);
		omp_set_lock(&lock[i]);
	}
	
	#pragma omp parallel sections num_threads(2) private(i) shared(lock,f)
	{
		#pragma omp section
		#pragma omp critical
		for(i=0;i<n;i++)
		{
			printf("Thread %d is generating fibo(%d)\n",omp_get_thread_num(),i);
			f[i]=fibo(i);
			omp_unset_lock(&lock[i]);
		}
		
		#pragma omp section
		#pragma omp critical
		for(i=0;i<n;i++)
		{
			while(!omp_test_lock(&lock[i]));
			printf("Thread %d is printing fibo(%d)->%d\n",omp_get_thread_num(),i,f[i]);
		}
		
		#pragma omp section
		printf("thread %d is displaying total num of threads i.e %d\n",omp_get_thread_num(),omp_get_num_threads());
	}
}
