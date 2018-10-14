#include<stdio.h>
#include<malloc.h>

int main()
{
	int n,**a,i,j,x,y;
	printf("enter n\n");
	scanf("%d",&n);
	a=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		a[i]=(int*)malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	x=n/2;
	y=n-1;
		for(j=1;j<=n*n;)
		{
			if(x==-1&&y==n)
			{
				x=0;y=n-2;
			}
			
			else
				{if(x==-1)x=n-1;
				if(y==n)y=0;
			}
			if(a[x][y]==0)a[x][y]=j;
			else{
				x++;y-=2;
				continue;
			}
			
			j++;
			x--;y++;
		}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j] );
	
	printf("\n");}
	for(i=0;i<n;i++)
	{
		free(a[i]);
	}
	free(a);
	return 0;

}