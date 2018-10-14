#include<GL/glut.h>
#include<stdio.h>
GLfloat house[9][2]={{100,100},{400,100},{400,300},{100,300},{250,500},{200,100},{300,100},{300,200},{200,200}};
float h=100,k=100,theta;
float trans;
void drawHouse()
{
	
glColor4f(0.0,0.0,1.0,trans);
glBegin(2);
glVertex2fv(house[0]);
glVertex2fv(house[1]);
glVertex2fv(house[2]);
glVertex2fv(house[3]);
glEnd();
glColor4f(1.0,0.0,0.0,trans);
glBegin(2);
glVertex2fv(house[5]);
glVertex2fv(house[6]);
glVertex2fv(house[7]);
glVertex2fv(house[8]);
glEnd();
glColor4f(0.0,1.0,0.0,trans);
glBegin(2);
glVertex2fv(house[3]);
glVertex2fv(house[2]);
glVertex2fv(house[4]);
glEnd();
/*
glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(2,GL_FLOAT,0,house);
glColor4f(1,0,0,trans);
glDrawArrays(GL_LINE_LOOP,0,4);
glColor4f(0,1,0,trans);
glDrawArrays(GL_LINE_LOOP,4,8);
glColor4f(0,1,0,trans);
glDrawArrays(GL_LINE_LOOP,);
glDisableClientState(GL_VERTEX_ARRAY);
*/
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
trans=1;
drawHouse();
glTranslatef(h,k,0);
trans=1;
glRotatef(theta,0,0,1);
glTranslatef(-h,-k,0);
drawHouse();
glFlush();
}
void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-600,600,-600,600);
glMatrixMode(GL_MODELVIEW);
//glEnable(GL_BLEND);
//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
printf("enter rotation angle\n");
scanf("%f",&theta);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(600,600);
glutCreateWindow(argv[1]);
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
