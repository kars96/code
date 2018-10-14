#include<stdio.h>
#include<GL/glut.h>

GLfloat v[][3]={{1,1,1},{1,-1,1},{-1,-1,1},{-1,1,1},{1,1,-1},{1,-1,-1},{-1,-1,-1},{-1,1,-1}};

void sqr(int a,int b , int c, int d)
{
	glBegin(GL_POLYGON);
	glVertex3fv(v[a]);
	glVertex3fv(v[b]);
	glVertex3fv(v[c]);
	glVertex3fv(v[d]);
	glEnd();
}

void c()
{
	glColor3f(1,0,0);
	sqr(0,1,2,3);
	glColor3f(1,1,0);
	sqr(0,4,5,1);
	glColor3f(1,0,1);
	sqr(2,1,5,6);
	glColor3f(0,0,0);
	sqr(2,3,7,6);
	glColor3f(0,01,0);
	sqr(7,4,5,6);
	glColor3f(.1,01,0.5);
	sqr(3,7,4,0);
	glutSwapBuffers();
}
float ang[3]={0,0,0};
int axis=2;
void disp()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(ang[0],1,0,0);
	glRotatef(ang[1],0,1,0);
	glRotatef(ang[2],0,0,1);
	c();
	glutSwapBuffers();
}

void s()
{
	if(ang[axis]>360)ang[axis]=0;
	else ang[axis]++;
	glutPostRedisplay();
}

void m(int btn,int state,int x,int y)
{
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		axis=2;
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		axis=0;
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
		axis=1;
	glutPostRedisplay();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w>h)
		glOrtho(-2*(float)w/h,2*(float)w/h,-2,2,-10,10);
	else
		glOrtho(-2,2,-2*(float)h/w,2*(float)h/w,-10,10);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE |GLUT_DEPTH);
	glutCreateWindow("");
	glutDisplayFunc(disp);
	glutIdleFunc(s);
	glutMouseFunc(m);
	glEnable(GL_DEPTH_TEST);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
