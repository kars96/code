#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
float ver[8][3]={{0,0,0},{1,0,0},{1,1,0},{0,1,0},{0,0,1},{1,0,1},{1,1,1},{0,1,1}};
float v1[3]={0,0,5};
void polygon(int a,int b,int c,int d);
void polygon1();
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
printf("%f",v1[2]);
gluLookAt(v1[0],v1[1],v1[2],0,0,0,0,1,0);
polygon1();
glFlush();
}
void polygon1()
{
polygon(0,1,2,3);
polygon(4,5,6,7);
polygon(7,6,2,3);
polygon(4,5,1,0);
polygon(4,0,3,7);
polygon(5,1,2,6);
}
void polygon(int a,int b,int c,int d)
{
glBegin(GL_POLYGON);
glColor3fv(ver[a]);
glVertex3fv(ver[a]);
glColor3fv(ver[b]);
glVertex3fv(ver[b]);
glColor3fv(ver[c]);
glVertex3fv(ver[c]);
glColor3fv(ver[d]);
glVertex3fv(ver[d]);
glEnd();
}
void key(unsigned char f,int mouseX,int mouseY)
{
if(f=='x') v1[0]-=0.1;
if(f=='X') v1[0]+=0.1;
if(f=='y') v1[1]-=0.1;
if(f=='Y') v1[1]+=0.1;
if(f=='z') v1[2]-=0.1;
if(f=='Z') v1[2]+=0.1;
display();
}
void myReshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
glFrustum(-3.0,3.0,-3.0*h/w,3.0*h/w,2.0,3.0);
else
glFrustum(-3.0*w/h,3.0*w/h,-3.0,3.0,2.0,3.0);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(10,10);
glutCreateWindow(argv[1]);
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glutKeyboardFunc(key);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
} 
