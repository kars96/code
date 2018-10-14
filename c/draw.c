/*USAGE: draw <input-file|command substitution> <GLprimitives code> (<transformation-file>|<x-trans(cm)> <y-trans(cm)> <scale-factor> <rotate-angle>)
GLprimitives code=>
GL_POINTS				    0
GL_LINES				    1
GL_LINE_LOOP				2
GL_LINE_STRIP				3
GL_TRIANGLES				4
GL_TRIANGLE_STRIP			5
GL_TRIANGLE_FAN				6
GL_QUADS				    7
GL_QUAD_STRIP				8
GL_POLYGON				    9

Eg.
save the cordinates(in cm) in file named test
compile this code
To draw the image using GL_POLYGON execute
./a.out test 9

NOTE: change resx, resy and CM2PIX value 
*/

//Kar$

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.14159265

int cargc;char **cargv;
typedef GLfloat v[3][500];
typedef GLfloat trans[3][3];
#define CM2PIX 40
int resx=1366,resy=766,cm2pix=40;
v p;

trans t={{CM2PIX,0,0},
	   {0,CM2PIX,0},
	   {0,0,CM2PIX}};
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
{	int i=0;
	glBegin(atoi(cargv[2]));
	glColor3f(240/255.0f,84/255.0f,76/255.0f);
	for(i=0;i<n;i++)
	{
	glVertex2f(p[0][i],p[1][i]);

	}
		glEnd();
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

	FILE* f;FILE* ft; char fn[60]; GLfloat x,y;int i=0;char flag,temp;	
	int tempc=1;
	if(argc<3 || argc>7)
	{
		printf("USAGE: draw <input-file|command substitution> <GLprimitives code> (<transformation-file>|<x-trans(cm)> <y-trans(cm)> <scale-factor> <rotate-angle>)\nGLprimitives code=>\nGL_POINTS-->0\nGL_LINES-->1\nGL_LINE_LOOP-->2\nGL_LINE_STRIP-->3\nGL_TRIANGLES-->4\nGL_TRIANGLE_STRIP-->5\nGL_TRIANGLE_FAN-->6\nGL_QUADS-->7\nGL_QUAD_STRIP-->8\nGL_POLYGON-->9\n");
//		printf("%s\n","USAGE: draw <input-file|command substitution> <GLprimitives code> (<transformation-file>|<x-trans(cm)> <y-trans(cm)> <scale-factor> <rotate-angle>)" );
	//	printf("%s\n","GL_POINTS				    0" );
		return 1;
	}
	if(strcmp(argv[1],"usage:")){ printf("error::%s\n",argv[2]); return 1;}
	char *tempv[1]={" "};
	strcpy(fn,argv[1]);
	f=fopen(fn,"r");
	do{
		if((flag=fscanf(f,"%f %f",&x,&y)!=EOF))
		{
			p[0][i]=x;
			p[1][i]=y;
			p[2][i]=1;
			
			i++;
		}
		else 	break;
	}while(1);
	cargc=argc;
	cargv=argv;
	n=i;
	multiply();
	if(argc==4)
	{	strcpy(fn,argv[3]);
		ft=fopen(fn,"r");
		while((flag=fscanf(ft,"%f %f %f %f %f %f %f %f %f",&t[0][0],&t[0][1],&t[0][2],&t[1][0],&t[1][1],&t[1][2],&t[2][0],&t[2][1],&t[2][2])!=EOF))
		{
			multiply();
		}

	}
		if(argc>=7)
	{

		t[0][0]=cos(atof(argv[6])*PI/180);
		t[0][1]=-sin(atof(argv[6])*PI/180);
		t[0][2]=0;
		t[1][2]=0;
		t[1][0]=sin(atof(argv[6])*PI/180);
		t[1][1]=cos(atof(argv[6])*PI/180);
		t[2][0]=0;
		t[2][1]=0;
		t[2][2]=1;
		multiply();

	}
	if(argc>4)
	{
		t[0][2]=atof(argv[3]);
		t[1][2]=atof(argv[4]);
		t[0][1]=0;
		t[1][0]=0;
		if(argc>=6){
		t[0][0]=atof(argv[5]);
		t[1][1]=atof(argv[5]);
	}
		multiply();
	}

	fclose(f);
	strcpy(fn,"log");
	f=fopen(fn,"w");
	for(i=0;i<n;i++)
	fprintf(f," %f %f\n",p[0][i],p[1][i]);
	fprintf(f," %f %f\n",-111111.0,-111111.0);
	fclose(f);
	glutInit(&tempc,tempv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize(resx,resy);
	glutCreateWindow("Draw");
	init();
	//glutReshapeFunc(myReshape)
	glutDisplayFunc(display);
	if(argc>=8 && strcmp(argv[7],"nd")==0)return 0;
	glutMainLoop();
	return 0;

}
