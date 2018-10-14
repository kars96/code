#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
#define RGB(r,g,b) r/255.0f,g/255.0f,b/255.0f
int cargc;char **cargv;
typedef GLfloat v[3][500];
typedef GLfloat trans[3][3];
#define CM2PIX 40
int resx=1366,resy=766,cm2pix=40;
v  p[100][500];
int col[10][100];
int n[10];
void d1(int k,int mode)
{	int i,j;
	glColor3f(1,1,1);
	for(i=0;i<n[k];i++)
	{
		glBegin(mode);
		for(j=0;j<col[k][i];j++)
			glVertex2f(p[k][i][0][j],p[k][i][1][j]);
		glEnd();
	}
		
}

void textBig(const char *txt,int x,int y)
{	int i;
	glColor3f(1,1,1);
	glRasterPos2f(x,y);
	for(i=0;i<strlen(txt);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,txt[i]);
}
void textSmall(const char *txt,int x,int y)
{	int i;
	glColor3f(1,1,1);
	glRasterPos2f(x,y);
	for(i=0;i<strlen(txt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,txt[i]);
}
void startupdisp()
{ int i;
	static int x=0;
	GLfloat pat[11][2]={
		{0,0},
		 {2000.000000, 0.000000},
 		{1969.000000, 347.000000},
 		{1879.000000, 684.000000},
 		{1732.000000 ,1000.000000},
 		{1532.000000, 1285.000000},
 		{1285.000000, 1532.000000},
 		{1000.000000, 1732.000000},
 		{684.000000, 1879.000000},
		{347.000000, 1969.000000},
 		{0.000000 ,2000.000000}
	};
	GLfloat colr[9][3]={
		{RGB(220,20,60)},
		{RGB(238,58,140)},
		{RGB(131,111,255)},
		{RGB(28,134,238)},
		{RGB(51,161,201)},
		{RGB(0,199,140)},
		{RGB(255,215,0)},
		{RGB(255,153,18)},
		{RGB(238,92,66)}

	};
	glClear(GL_COLOR_BUFFER_BIT );

	for(i=1;i<=9;i++)
	{
		glColor3fv(colr[i-1]);
		glBegin(GL_POLYGON);
		glVertex2fv(pat[0]);
		glVertex2fv(pat[i]);
		glVertex2fv(pat[i+1]);
		glEnd();
	}
	glFlush();
	textBig("You gotta play to earn!",600,150);
	glPointSize(4);
	glPushMatrix();
	glTranslatef(500,383,0);
	d1(0,9);
	glPopMatrix();
	//glTranslatef(-500,-383,0);
	glPushMatrix();
	glTranslatef(500,0,0);
	d1(1,9);
	glPopMatrix();
	/*glPushMatrix();
	glTranslatef(250,250,0);
	glLineWidth(5);
	d1(2,3);
	glPopMatrix();*/
	textSmall("Press any key to continue",600,10);
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

void mainScreen()
{
	GLfloat colr[10][3]={
		{RGB(238,58,140)},
		{RGB(220,20,60)},
		
		{RGB(238,92,66)},
				{1,1,1},
		{RGB(131,111,255)},
		{RGB(28,134,238)},
		{RGB(51,161,201)},
		{RGB(0,199,140)},
		{RGB(255,215,0)},
		{RGB(255,153,18)}
		
		
	};
	glClear(GL_COLOR_BUFFER_BIT);
	
	int k=0;
	int i,d=0,j;
	int factor=-resx/10;
	for(i=0;i<resy;i+=resy/2)
	{	glBegin(GL_POLYGON);
			glColor3fv(colr[k]);
			glVertex2f(0,i);
			glVertex2f(resx,i);
			glColor3fv(colr[k+1]);
			glVertex2f(resx,i+resy/2);
			glVertex2f(0,i+resy/2);
		glEnd();
		k++;
	}

	
	glFlush();
}


void mainScreenkb(unsigned char key, int x, int y)
{

}
void startup()
{
		FILE* f;FILE* ft; char fn[60]; GLfloat x,y;int i=0,j;char flag=1,temp;
	f=fopen("MONO","r");
	for(i=0;i<5000;i++)
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
			p[0][i][0][j]=x;
			p[0][i][1][j]=y;
			p[0][i][2][j]=1;
			j++;
			}
		}
		col[0][i]=j;
	}
	n[0]=i;
		fclose(f);
	f=fopen("POLY","r");flag=1;
	for(i=0;i<5000;i++)
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
			p[1][i][0][j]=x;
			p[1][i][1][j]=y;
			p[1][i][2][j]=1;
			j++;
			}
		}
		col[1][i]=j;
	}
	n[1]=i;
		fclose(f);
	/*	f=fopen("dollar","r");flag=1;
	for(i=0;i<5000;i++)
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
			p[2][i][0][j]=x;
			p[2][i][1][j]=y;
			p[2][i][2][j]=1;
			j++;
			}
		}
		col[2][i]=j;
	}
	n[2]=i;
		fclose(f);*/
}

void startupkb(unsigned char key, int x, int y)
{
	if(key)
	{
		glutDisplayFunc(mainScreen);
		glutPostRedisplay();
		glutKeyboardFunc(mainScreenkb);
	}
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize(resx,resy);
	glutCreateWindow("Monopoly");
	glutSetIconTitle("k");
	init();
	startup();
	//glutReshapeFunc(myReshape)
	glutDisplayFunc(startupdisp);
	glutKeyboardFunc(startupkb);
	glutMainLoop();
	return 0;
}
