#include<stdio.h>
main()
{
	int i=20;
	printf("%d",i);
	{
		int i=30;
		printf("%d",i);
	}
	printf("%d",i);
}
