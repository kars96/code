#include<stdio.h>
#include<GL/glut.h>
void d()
{	float i;
	glClearColor(.01f,0.01f,0.01f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(.45f,.45f,.45f);
	glVertex2f(0.5f,0.5f);
	glVertex2f(-.75f,.02f);
	glVertex2f(-.35,-.25f);
	glVertex2f(.45f,-.15);
	glEnd();
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1.0f,.0f,.0f);
	for(i=-1.0f;i<=1.0f;i+=0.25f)
	glVertex2f(0,i);
	glColor3f(.0f,.0f,1.0f);
	for(i=-1.0f;i<=1.0f;i+=0.25f)
	glVertex2f(i,0);
	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(320,320);
	glutCreateWindow("demo of trans.");
	glutDisplayFunc(d);
	glutMainLoop();
	return 0;
}

