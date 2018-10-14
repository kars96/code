#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#define MAXX 5
#define MAXY 5
#define DY 30
#define DX 30
GLfloat x0={10.0},y01={50.0};
GLfloat x[MAXX],y[MAXY];


void init()
{
	glClearColor(1.0,1.0,.50,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
}


void d()
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLint i,j;
	for(i=0;i<MAXX;i++) x[i]=x0+i*DX;
	for(j=0;j<MAXY;j++) y[j]=y01+j*DY;
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
				glColor3f(0.4,.5,.5);
		glBegin(GL_TRIANGLE_STRIP);
	// for(i=0;i<MAXX-1;i++)
	// { 
		// for(j=0;j<MAXY-1;j++)
		// {
	i=j=0;
			
			glVertex2f(x[i],y[j]);
			glVertex2f(x[i],y[j+1]);
			glVertex2f(x[i+1],y[j]);
			// glVertex2f(x[i+1],y[j+1]);
				
			
		// }
		
	// }
	glEnd();
	glFlush();
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("1JS14CS037-rectangular mesh");
	glutDisplayFunc(d);
	init();
	glutMainLoop();
	return 0;
}
