#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
typedef GLfloat p[3];
p v[]={{0,-1,1/sqrt(2)},{0,1,1/sqrt(2)},{-1,0,-1/sqrt(2)},{1,0,-1/sqrt(2)}};
int n;
void triangle(p a, p b, p c)
{
		glBegin(GL_POLYGON);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
		glEnd();
}

void dt(p a, p b, p c, int m)
{	int i=0;
	p t1,t2,t3;
	if(m!=0)
	{
		for(i=0;i<3;i++)
		{
			t1[i]=(a[i]+b[i])/2;
			t2[i]=(c[i]+b[i])/2;
			t3[i]=(a[i]+c[i])/2;
		}
		dt(a,t1,t3,m-1);
		dt(t1,b,t2,m-1);
		dt(t3,t2,c,m-1);
	}
	else
		triangle(a,b,c);
}

void t()
{
	glColor3f(1,0,0);
	dt(v[0],v[1],v[2],n);
	glColor3f(0,1,0);
	dt(v[0],v[2],v[3],n);
	glColor3f(0,0,1);
	dt(v[0],v[3],v[1],n);
	glColor3f(0,0,0);
	dt(v[1],v[2],v[3],n);
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(h>w)
	{
		gluOrtho2D(-2,2,-2*(float)h/w,2*(float)h/w);
	}
	else
	gluOrtho2D(-2*(float)w/h,2*(float)w/h,-2,2);	
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
int ang=0;
void disp()
{	
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(ang,0,0,1);
	t();
	glFlush();
}
void rot()
{
	ang=(ang+1);
	glutPostRedisplay();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	printf("N:\n");
	scanf("%d",&n);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutCreateWindow("");
	glutReshapeFunc(reshape);
	glutDisplayFunc(disp);
	init();
	//glutIdleFunc(rot);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}


