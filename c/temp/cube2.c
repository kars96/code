#include<stdio.h>
#include<GL/glut.h>

GLfloat v[][3]={{1,1,1},{1,-1,1},{-1,-1,1},{-1,1,1},{1,1,-1},{1,-1,-1},{-1,-1,-1},{-1,1,-1}};
GLfloat vr[3]={0,0,5};
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
	gluLookAt(vr[0],vr[1],vr[2],0,0,0,0,1,0);
	c();
	glutSwapBuffers();
}

void s()
{
	if(ang[axis]>360)ang[axis]=0;
	else ang[axis]++;
	glutPostRedisplay();
}

void kb(char key,int x,int y)
{
	if(key=='x')vr[0]+=1;
	if(key=='X')vr[0]-=1;
	if(key=='y')vr[1]+=1;
	if(key=='Y')vr[1]-=1;
	if(key=='z')vr[2]+=1;
	if(key=='Z')vr[2]-=1;
	glutPostRedisplay();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w>h)
		glFrustum(-2*(float)w/h,2*(float)w/h,-2,2,2,10);
	else
		glFrustum(-2,2,-2*(float)h/w,2*(float)h/w,2,10);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE |GLUT_DEPTH);
	glutCreateWindow("");
	glutDisplayFunc(disp);
	//glutIdleFunc(s);
	glutKeyboardFunc(kb);
	glEnable(GL_DEPTH_TEST);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
