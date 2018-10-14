// 9. SCAN FILL :z
#include<time.h>
#include<unistd.h>
#include<stdio.h> 
 #include<GL/glut.h> 
 #include<stdlib.h>
float x1,x2,x3,x4,y11,y2,y3,y4;

void ed(float x1,float y11,float x2,float y2,int *le,int *re)
{
	float mx,x,temp;
	int i;
	if((y2-y11)<0)
	{
		temp = y11;y11=y2;y2=temp;
		temp=x1;x1=x2;x2=temp;
	}

      if((y2-y11)!=0)
	      mx=(x2-x1)/(y2-y11);
      else
	      mx=x2-x1;
      x=x1;
      for(i=y11;i<=y2;i++)
      {
	      if(x<(float)le[i])
		      le[i]=(int)x;
	      if(x>(float)re[i])
		      re[i]=(int) x;
	      x+=mx;
      } }

void dp(int x,int y,int val)
{
	glColor3f(1,1,0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void scan(float x1,float y11,float x2,float y2,float x3,float y3,float x4,float y4)
{
	int le[500],re[500]; 	int i,j;
	for(i=0;i<500;i++)
	{
		le[i]=500;
		re[i]=0;
	}
     ed(x1,y11,x2,y2,le,re);
     ed(x2,y2,x3,y3,le,re);
     ed(x3,y3,x4,y4,le,re);
     ed(x4,y4,x1,y11,le,re);
     for(j=0;j<500;j++)
     {
	     if(le[j]<=re[j]){
		     for(i=(int)le[j];i<=(int)re[j];i++)
			     dp(i,j,0);
			 glFlush();
			 usleep(10000);
	     }
     } }
void disp()
{
	x1=200,y11=200;
	x2=100;y2=300;
	x3=200;y3=400;
	x4=300;y4=300;
	

     glClear(GL_COLOR_BUFFER_BIT);
     // glLoadIdentity();
     // glScalef(1.5,.5,0);
     glColor3f(0,0,0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(x1,y11);
     glVertex2f(x2,y2);
     glVertex2f(x3,y3);
     glVertex2f(x4,y4);
     glEnd();
     scan(x1,y11,x2,y2,x3,y3,x4,y4);
     // glFlush();
}
void init()
{
	glClearColor(1,1,1,1);
	glColor3f(1,0,0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,499,0,499);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("scan line alg 1js14cs027");
	glutDisplayFunc(disp);
	init();
	glutMainLoop();
	return 0;
}
