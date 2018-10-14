#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265
int main(int argc, char const *argv[])
{
	FILE* f1;
	double val=PI/180;int theta;
	if(argc!=4)
	{
		printf("usage: arc <radius(cm)> <from-angle> <to-angle>\n");
		return 1;
	}
	float r=atof(argv[1]);
	f1=fopen("arc-points","w");
	for(theta=atoi(argv[2]);theta<=atoi(argv[3]);theta++)
		fprintf(f1, "%f %f\n",r*cos(theta*val) ,r*sin(theta*val));
	printf("arc-points");
	/*for(x=-r;x<r;x+=atof(argv[2]))
		fprintf(f1, "%f %f\n",x,sqrt((r*r)-(x*x)) );
	for(x=r;x>-r;x-=atof(argv[2]))
		fprintf(f1, "%f %f\n",x,-sqrt((r*r)-(x*x)) );*/
	fclose(f1);
	return 0;
}