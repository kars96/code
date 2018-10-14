#include<stdio.h>
#include<stdlib.h>
int main()
{
	int heap[10];
	int n,root,child,i,temp;
	printf("Enter the number of elements::");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&heap[i]);
	for(i=1;i<n;i++)
	{
		child=i;
		do{
			root=(child-1)/2;
			if(heap[root]>heap[child])
			{
			}
			child=root;
		}while(child!=0);
	}
	for(i=0;i<n;i++)
		printf("%d\t",heap[i]);

	
	return 0;
}