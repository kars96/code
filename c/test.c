#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

typedef float point[3];

point v[]={{0,.375f,.816496f},{0,.75f,0},{-0.5f,0,0},{0.5f,0,0}};
//point v[]={{.5,.5,.5},{.5,.5,-.5},{-.5,-.5,-.5},{.5,-.5,-.5}};
int n;
void triangle(point a,point b, point c)
{//	printf("drawing..\n");
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}

void divide_triangle(point a, point b , point c,int m)
{
	point v1,v2,v3;
	int j;
	if(m>0)
	{
		for(j=0;j<3;j++) v1[j]=(a[j]+b[j])/2;
		for(j=0;j<3;j++) v2[j]=(a[j]+c[j])/2;
		for(j=0;j<3;j++) v3[j]=(c[j]+b[j])/2;
		divide_triangle(a,v1,v2,m-1);
		divide_triangle(c,v2,v3,m-1);
		divide_triangle(b,v3,v1,m-1);
	}
	else triangle(a,b,c);
}

void t(int m)
{
	glColor3f(0.9,.1,.2);
	divide_triangle(v[0],v[1],v[2],m);
	glColor3f(.8,.1,.8);
	divide_triangle(v[3],v[2],v[1],m);
	glColor3f(.2,.1,.9);
	divide_triangle(v[0],v[3],v[1],m);
	glColor3f(.3,.3,.3);
	divide_triangle(v[0],v[2],v[3],m);
}

void d()
{ float i;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	t(n);
	/*glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(1.0f,.0f,.0f);
	for(i=-1.0f;i<=1.0f;i+=0.25f)
	glVertex3f(0,i,0);
	glColor3f(.0f,.0f,1.0f);
	for(i=-1.0f;i<=1.0f;i+=0.25f)
	glVertex3f(i,0,0);
	glEnd();*/
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(1.0f,0,0);
	glVertex3f(0.0,0.0,1.0);
	glColor3f(0,1.0f,0);
	glVertex3f(0.0,0.942809,-0.333333);
	glColor3f(0,0,1.0f);
	glVertex3f(-0.816497,-.471405,-.333333);
	glColor3f(.0f,.0f,.0f);
	glVertex3f(0.816497,-.471405,-.333333);
	glEnd();
	
	glFlush();
}

void myReshape(int w,int h){
	printf("entering reshape h:%d w:%d\n",h,w);
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
		glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
		glMatrixMode(GL_MODELVIEW);
		glutPostRedisplay();
}

int main(int argc,char** argv)
{
	printf("Enter the no. of div\n");
	scanf("%d",&n);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(500,500);
	glutCreateWindow("1js14cs037 gasket");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(d);
	/*glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0f,10.0,-10.0f,10.0f,-10.0f,10.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	*/glClearColor(1,1,1,1);
	glutMainLoop();
	return 0;
}
