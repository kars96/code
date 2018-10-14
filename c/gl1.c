#include<stdio.h>
#include "/usr/include/GL/glut.h"
GLfloat c[]={.34f,.74f,.23f};
void display()
{
	glClearColor(0.0f,0.0f,0.0f,0.1f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3fv(c);
	glVertex2f(-.5f,-.5f);
	glVertex2f(.5f,-.5f);
	glVertex2f(.5f,.5f);
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
