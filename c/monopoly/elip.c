#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265
int main(int argc, char const *argv[])
{
	FILE* f1;
	double val=PI/180;int theta;
	if(argc!=3)
	{
		printf("usage: elipse <x(cm)> <y(cm)>\n");
		return 1;
	}
	float a=atof(argv[1]),b=atof(argv[2]);

	f1=fopen("elipse-points","w");
	for(theta=0;theta<360;theta++)
		fprintf(f1, "%f %f\n",a*cos(theta*val) ,b*sin(theta*val));
	/*for(x=-r;x<r;x+=atof(argv[2]))
		fprintf(f1, "%f %f\n",x,sqrt((r*r)-(x*x)) );
	for(x=r;x>-r;x-=atof(argv[2]))
		fprintf(f1, "%f %f\n",x,-sqrt((r*r)-(x*x)) );*/
	printf("elipse-points");
	fclose(f1);
	return 0;
}