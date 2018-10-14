#include<stdio.h>
#include "/usr/include/GL/glut.h"
GLfloat c[]={.34f,.74f,.23f};
#define RGB(r,g,b) r/255.0f,g/255.0f,b/255.0f
void display()
{
	glClearColor(0.0f,0.0f,0.0f,0.1f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(RGB(220,20,60));
	glVertex2f(-.5f,-.5f);
	glColor3f(RGB(238,58,140));
	glVertex2f(.5f,-.5f);
	glColor3f(RGB(131,111,255));
	glVertex2f(.5f,.5f);
	glColor3f(RGB(28,134,238));
	glVertex2f(-.5f,.5f);
	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{
	
	glutInit(&argc,argv);
	//glutInitWindowSize(1366,768);
//	glutInitWindowSize(768,768);
	glutCreateWindow("my first window");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
