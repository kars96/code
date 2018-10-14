#include <stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	FILE* f1;
	if(argc!=3)
	{
		printf("usage: rectangle <length-x(cm)> <length-y(cm)>\n");return 1;
	}
	f1=fopen("rectangle-points","w");
	fprintf(f1, "%f %f\n",0.0,0.0);
	fprintf(f1, "%f %f\n",0.0,atof(argv[2]));
	fprintf(f1, "%f %f\n",atof(argv[1]),atof(argv[2]));
	fprintf(f1, "%f %f\n",atof(argv[1]),0.0);	
	printf("rectangle-points");
	fclose(f1);
	return 0;
}