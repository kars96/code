#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<GL/glut.h>
#define PI 3.14159265
typedef GLfloat v[3][500000];
typedef GLfloat trans[3][3];
#define CM2PIX 40
v p;
int n;
trans t={{CM2PIX,0,0},
	   {0,CM2PIX,0},
	   {0,0,CM2PIX}};

void multiply()
{
	v r;
	int sum,i,j,k;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<n;j++)
		{
			sum=0;
			for(k=0;k<3;k++)
				sum+=t[i][k]*p[k][j];
			r[i][j]=sum;
		}
	}
	for(int i=0;i<3;i++)
		for(int j=0;j<n;j++)
			p[i][j]=r[i][j];
}

int main(int argc, char const *argv[])
{
	FILE* f1;
	double val=PI/180;int theta;float d=5;
	if(argc!=7)
	{
		printf("usage: bigo <radius(cm)> <from-angle> <to-angle> <thickness> <x-trans> <y-trans>\n");
		return 1;
	}
	if(argc==5)d=atof(argv[4]);
	float r=atof(argv[1]);
	float tk=atof(argv[4]);
	f1=fopen("bigo-points","w");
	int i=0;
	for(theta=atoi(argv[2]);theta<=atoi(argv[3]);theta+=d)
		{

			p[0][i]=r*cos(theta*val);
			p[1][i]=r*sin(theta*val);
			p[2][i++]=1;

			p[0][i]=(r+tk)*cos(theta*val);
			p[1][i]=(r+tk)*sin(theta*val);
			p[2][i++]=1;
			
		}
		n=i;

		multiply();
		t[1][1]=1;
		t[0][0]=1;
		t[2][2]=1;		
		t[0][2]=atof(argv[5]);
		t[1][2]=atof(argv[6]);
	multiply();
	 FILE* f=fopen("log","w");
	for(i=0;i<n-3;i+=2){
	fprintf(f," %f %f\n%f %f\n%f %f\n%f %f\n",p[0][i],p[1][i],p[0][i+1],p[1][i+1],p[0][i+3],p[1][i+3],p[0][i+2],p[1][i+2]);
	fprintf(f," %f %f\n",-111111.0,-111111.0);
	}
	fclose(f1);
	return 0;
}