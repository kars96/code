#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#define MAXX 9
#define MAXY 9
#define DY 45
#define DX 45
GLfloat x0={75.00},y01={75.0};
GLfloat x[MAXX],y[MAXY];

void init()
{
	glClearColor(.50,.50,.50,1.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
}



void d()
{
	int c,c1;
	GLint i,j;
	c=1;
	glClear(GL_COLOR_BUFFER_BIT);
	
	for(i=0;i<MAXX;i++) x[i]=x0+i*DX;
	for(j=0;j<MAXY;j++) y[j]=y01+j*DY;
	for(i=0;i<MAXX-1;i++)
	{
		c=c%2;
		c1=c++;
		for(j=0;j<MAXY-1;j++)
		{
			
			c1=++c1%2;
			glBegin(GL_POLYGON);
			glColor3f((float)c1,(float)c1,(float)c1);
			glVertex2f(x[i],y[j]);
			glVertex2f(x[i+1],y[j]);
			glVertex2f(x[i+1],y[j+1]);
			glVertex2f(x[i],y[j+1]);	
			glEnd();
		}
	}
	for(i=0;i<MAXX-1;i++)
		for(j=0;j<MAXY-1;j++)
		{
			glColor3f(.0,.0,.0);
			glLineWidth(2);
			glBegin(GL_LINE_LOOP);
			glVertex2f(x[i],y[j]);
			glVertex2f(x[i+1],y[j]);
			glVertex2f(x[i+1],y[j+1]);
			glVertex2f(x[i],y[j+1]);	
			glEnd();
		}
	glFlush();
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_ALPHA);
	glutInitWindowSize(500,500);
	glutCreateWindow("1JS14CS037-chess board");
	glutDisplayFunc(d);
	init();
	glutMainLoop();
	return 0;
}
