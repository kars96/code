#include<stdio.h>
void abc(int a, int b)
{
	printf("%d %d\n",a,b);
}
main()
{
	int a=10;
	abc(a++,++a);
	abc(++a,a++);
	
}

