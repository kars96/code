#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265
int main(int argc, char const *argv[])
{
	FILE* f1;
	double val=PI/180;int theta;
	if(argc!=2)
	{
		printf("usage: circle <radius(cm)\n");return 1;
	}
	float r=atof(argv[1]);
	f1=fopen("circle-points","w");
	for(theta=0;theta<=360;theta++)
		fprintf(f1, "%f %f\n",r*cos(theta*val) ,r*sin(theta*val));
	printf("circle-points");
	/*for(x=-r;x<r;x+=atof(argv[2]))
		fprintf(f1, "%f %f\n",x,sqrt((r*r)-(x*x)) );
	for(x=r;x>-r;x-=atof(argv[2]))
		fprintf(f1, "%f %f\n",x,-sqrt((r*r)-(x*x)) );*/
	fclose(f1);
	return 0;
}