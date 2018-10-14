#include<stdio.h>
#include<GL/glut.h>

void d()
{	static float i;
	glClearColor(0.0f,.0f,.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
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

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(320,320);
	glutCreateWindow("Points");
	glutDisplayFunc(d);
	glutMainLoop();
	return 0;
}
