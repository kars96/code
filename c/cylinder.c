#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int xc=100,yc=100,r=50;
int x1=200,y01=100,x2=300,y2=100,x3=300,y3=200,x4=200,y4=200;
int i=0;
void circle_draw(int xc,int yc,int r)
{
float i,angle=0;
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
for(i=0;i<360;i+=10)
{
angle=3.14/180*i;
glVertex2f(xc+cos(angle)*r,yc+sin(angle)*r);
}
glEnd();

}
void parallelpiped(int x1,int y01,int x2,int y2,int x3,int y3,int x4,int y4)
{
glBegin(GL_LINE_LOOP);
glVertex2f(x1,y01);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glVertex2f(x4,y4);
glEnd();
}
void init()
{
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,400,0,400);
glMatrixMode(GL_MODELVIEW);
}
void d(){}
void display()
{
printf("hhhhhh\n");
glClear(GL_COLOR_BUFFER_BIT);
for(i=0;i<50;i+=3)
circle_draw(xc,yc+i,r);
for(i=0;i<40;i+=2)
parallelpiped(x1+i,y01+i,x2+i, y2+i,x3+i,y3+i,x4+i,y4+i);
//

glFlush();
}
void menu(int id)
{
//int xc=100,yc=100,r=50;
//int x1=200,y01=100,x2=300,y2=100,x3=300,y3=200,x4=200,y4=200;
//int i=0;
glClear(GL_COLOR_BUFFER_BIT);
switch(id)
{
case 1:for(i=0;i<50;i+=3)
circle_draw(xc,yc+i,r);
glutDisplayFunc(d);
break;
case 2:for(i=0;i<40;i+=2)
parallelpiped(x1+i,y01+i,x2+i, y2+i,x3+i,y3+i,x4+i,y4+i);
glutDisplayFunc(d);
break;
case 4:exit(0);break;
case 3: glutDisplayFunc(display);
glutPostRedisplay();
break;
}
glFlush();

//glutPostRedisplay();
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutCreateWindow(argv[1]);
glutCreateMenu(menu);
glutAddMenuEntry("circle",1);
glutAddMenuEntry("parallelpiped",2);

glutAddMenuEntry("both",3);
glutAddMenuEntry("exit",4);
glutAttachMenu(GLUT_RIGHT_BUTTON);
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

