#include<stdio.h>
#include<GL/glut.h>

double xmin=50,ymin=50,xmax=100,ymax=100;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;
//int false=0,true=1;

int ct(double p, double q, double* t1, double* t2)
{
	double t=q/p;
	if(p<0.0)
	{
		if(t>*t1) *t1=t;
		if(t>*t2) return 0;

	}
	else if(p>0.0){
		if(t<*t2) *t2=t;
		if(t<*t1) return 0;
	}
	else if (p==0.0){
		if(q<0.0)return 0;
	}
	return 1;
}
void LiangBarskyLineClipAndDraw(double x1, double y1, double x2, double y2)
{
	double dx=x2-x1, dy=y2-y1, t1=0.0, t2=1.0;
	if(ct(-dx, x1-xmin, &t1, &t2))
	if(ct(dx, xmax-x1, &t1, &t2))
	if(ct(-dy, y1-ymin, &t1, &t2))
	if(ct(dy, ymax-y1, &t1, &t2))
	{
		if(t2<1.0)
		{
			x2=x1+dx*t2;
			y2=y1+dy*t2;
		}
		if(t1>0.0)
		{
			x1=x1+dx*t1;
			y1=y1+dy*t1;
		}
		glColor3f(.5,.5,.5);
		glBegin(GL_LINES);
		glVertex2d(x1,y1);
		glVertex2d(x2,y2);
		glEnd();
		double sx=(xvmax-xvmin)/(xmax-xmin);
		double sy=(yvmax-yvmin)/(ymax-ymin);
		x2=xvmin+(x2-xmin)*sx;
		x1=xvmin+(x1-xmin)*sx;
		y2=yvmin+(y2-ymin)*sy;
		y1=yvmin+(y1-ymin)*sy;

		glBegin(GL_LINES);
		glVertex2d(x1,y1);
		glVertex2d(x2,y2);
		glEnd();

	}


}
void display()
{
	double x0=60,y0=20,x1=80,y1=120;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	    glVertex2d(x0,y0);
	    glVertex2d(x1,y1);
	glEnd();
	LiangBarskyLineClipAndDraw(x0,y0,x1,y1);
	x0=70,y0=40,x1=90,y1=90;
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	    glVertex2d(x0,y0);
	    glVertex2d(x1,y1);
	glEnd();
	LiangBarskyLineClipAndDraw(x0,y0,x1,y1);
	
	x0=60,y0=60,x1=60,y1=90;
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	    glVertex2d(x0,y0);
	    glVertex2d(x1,y1);
	glEnd();
	LiangBarskyLineClipAndDraw(x0,y0,x1,y1);
	
	x0=30,y0=60,x1=30,y1=90;
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	    glVertex2d(x0,y0);
	    glVertex2d(x1,y1);
	glEnd();
	LiangBarskyLineClipAndDraw(x0,y0,x1,y1);
	
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	  glVertex2f(xmin,ymin);
	  glVertex2f(xmax,ymin);
	  glVertex2f(xmax,ymax);
	  glVertex2f(xmin,ymax);
	glEnd();

	LiangBarskyLineClipAndDraw(x0,y0,x1,y1);


	x0=30,y0=60,x1=90,y1=130;
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	    glVertex2d(x0,y0);
	    glVertex2d(x1,y1);
	glEnd();
	LiangBarskyLineClipAndDraw(x0,y0,x1,y1);
	
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	  glVertex2f(xmin,ymin);
	  glVertex2f(xmax,ymin);
	  glVertex2f(xmax,ymax);
	  glVertex2f(xmin,ymax);
	glEnd();

	LiangBarskyLineClipAndDraw(x0,y0,x1,y1);
	glFlush();
}

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(50.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Liang Barsky Line Clipping Algorithm... 1js14cs023");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}

