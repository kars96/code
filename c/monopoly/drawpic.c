
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
int cargc;char **cargv;
typedef GLfloat v[3][500];
typedef GLfloat trans[3][3];
#define CM2PIX 40
trans t={{1,0,0},
	   {0,1,0},
	   {0,0,1}};
int resx=1366,resy=766,cm2pix=40;
v  p[100];
int col[100];
int n;

void multiply()
{
	v r;
	int sum,i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=0;
			for(k=0;k<3;k++)
				sum+=t[i][k]*p[k][j];
			r[i][j]=sum;
		}
	}
	for(i=0;i<3;i++)
		for(j=0;j<n;j++)
			p[i][j]=r[i][j];
}

void d1()
{	int i,j;
	
	glColor3f(240/255.0f,84/255.0f,76/255.0f);
	for(i=0;i<n;i++)
	{
		glBegin(2);
		for(j=0;j<col[i];j++)
			glVertex2f(p[i][0][j],p[i][1][j]);
		glEnd();
	}
		
}


void display()
{ int i;
	char name[10]="Kar$";
	glClear(GL_COLOR_BUFFER_BIT );
	glColor3f(1,1,1);
	glRasterPos2f(1250,10);
	for(i=0;i<4;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,name[i]);
	glPointSize(4);
	d1();
	glFlush();
}

void init()
{
	glClearColor(.250,.250,.250,1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,resx,0.0,resy);
}
void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glLoadIdentity();
	if(w<h)
		glOrtho(-2,2,-2*(GLfloat)h/w,2*(GLfloat)h/w,-10,10);
	else
		glOrtho(-2*(GLfloat)w/h,2*(GLfloat)w/h,-2,2,-10,10);
}
int main(int argc,char** argv)
{

	FILE* f;FILE* ft; char fn[60]; GLfloat x,y;int i=0,j;char flag=1,temp;	
	int tempc=1;

	char *tempv[1]={" "};
	strcpy(fn,argv[1]);
	f=fopen(fn,"r");
	for(i=0;i<100;i++)
	{
		j=0;
		if(flag==0)break;
		while(1)
		{
			if(fscanf(f,"%f %f",&x,&y)==EOF){
				flag=0;
				break;
			}
			if(x==-111111.0 && y==-111111.0)
				break;
			else
			{
			p[i][0][j]=x;
			p[i][1][j]=y;
			p[i][2][j]=1;
			j++;
			}
		}
		col[i]=j;
	}
	n=i;
	cargc=argc;
	cargv=argv;
	fclose(f);
	if(argc==3)
	{
		t[0][2]=atof(argv[1]);
		t[1][2]=atof(argv[2]);
		multiply();
	}
	glutInit(&tempc,tempv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize(resx,resy);
	glutCreateWindow("Draw");
	init();
	//glutReshapeFunc(myReshape)
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
