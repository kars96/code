#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
// #include "cg2.c"
// #include "cg7.c"
// #include "cg6.c"

// #include "cgwaste.c"

#define PI 3.14159265
#define RGB(r,g,b) r/255.0f,g/255.0f,b/255.0f
#define PAVEMENT1 3
#define TRUCK 7
#define WHEEL 8
#define TREE 9
#define SQUARE 1


#define PAVEMENT2 4
#define LAWN 2
#define TYRE 5
#define MUDG 6


#define SHOPRECT 10
#define SHOPROOF 11
#define SHOPUPWIN 12
#define SHOPMIDSTRIP 13
#define SHOPBOARD 14
#define SHOPDOWNWIN 15
#define SHOPDOOR 16
#define SHOPDOWNWINRIGHT 17
#define BIN 18
#define HEAD1 22
#define BODY1 23
#define LEG1 24
#define HOUSE 25
#define COW 40
#define GRASS 41

#include "sba.c"
void display();
float sxm,sym;
void (*scene[20])()={cg2display,cg1display,cg17display,cg4display,cg3display,cg5display,cg6display,cg7display,cg8display,cg9display,cg10display,cg12display,cg14display,cg18display,cg19display,cg20display,cg21display,cg22display,display};
//int garbageCount=0;

//int dist=0,ang=0;
void circledraw(int,int);
//void bn();
void paper();
GLfloat colr[][3]={
		{RGB(244,67,54)},
		{RGB(255,87,34)},
		{RGB(255,152,0)},
		{RGB(255,193,7)},
		{RGB(0,199,140)},
		{RGB(0,150,136)},
		{RGB(3,169,244)},
		{RGB(28,134,238)},
		{RGB(63,81,181)},
		{RGB(156,39,176)},
		{RGB(233,30,90)},
		{RGB(220,20,60)},
		{RGB(96,125,139)},             //xb1pos=-350,yb1pos=-100
		{RGB(1,0,0)}
	};

int shape;/*
double val=PI/180;
int winh,winw;*/
//float xbpos=580, ybpos=200;
float xb1pos=900,yb1pos=30;//positions
float  xopos=300,yopos=100,xo1pos=900,yo1pos=190;
//float xpos=500,ypos=150;
float x1pos=700,y1pos=20,x2pos=800,y2pos=30,x3pos=200,y3pos=10,x4pos=900,y4pos=100;
/*
float h=100,k=100,theta=0.0;
int garbageFull=1;*/

float *xt,*yt;
int containsPoint(float x1,float y1,float x2,float y2,float x,float y)
{x1*=sxm,x2*=sxm,y1*=sym,y2*=sym;

  ////printf("%d %d  %d %d\n",x1,y1,x2,y2);
  if(x>=x1 && x<=(x2) && y>=y1 && y<=(y2)) return 1;
  else return 0;
}

void changeS(int x)
{
  glutDisplayFunc(scene[x]);
  glutPostRedisplay();
  if(x<18)
  glutTimerFunc(3000,changeS,++x);
}

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
	// glutSwapBuffers();
}

void strokeText(const char *txt,int x,int y)
{ //int i;
  glRasterPos2f(x,y);
  for(i=0;i<strlen(txt);i++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,txt[i]);
}

void display(void)
{
  // static int dist=0,ang=0;
   //int i;

   glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glScalef(sxm,sym,1);
   glColor3f (0.270, 0.370, .450);
glScalef(1,1,1);
glBegin(GL_POLYGON);  //sky
glColor3f (RGB(135,206,250));  
 glVertex2f (0,251); 
   glVertex2f (0,1000);
   glVertex2f (1700,1000); 
   glVertex2f (1700,251); 
    glEnd();

glPushMatrix();//house
glTranslatef(170,252,0);
glScalef(.85,.6,0);
glCallList(HOUSE);
glPopMatrix();

glColor3f (RGB(205,201,201));
glBegin(GL_POLYGON);  //lawn
   glVertex2f (0,205); 
   glVertex2f (1700,205);
   glVertex2f (1700,250); 
   glVertex2f (0,250); 
    glEnd();
   
   glColor3f(RGB(0,139,0));
 glPushMatrix();
glTranslatef(0,250,0);
for(int i=0;i<75;i++)
{
  glPushMatrix();
  glScalef(.5,.5,1);
  glCallList(LAWN);
  glPopMatrix();
  glTranslatef(20,0,0);

}
glPopMatrix();


for(int i=0;i<15;i++) //lane
{
glPushMatrix();
glTranslatef(i*100,100,0);
glColor3f(1,1,1);
glScalef(.5,.2,1);
glCallList(SQUARE);
glPopMatrix();
}

shape=9;

#define PAVEMENT 434535
glNewList(PAVEMENT,GL_COMPILE_AND_EXECUTE);
glPushMatrix();
glColor3f(RGB(139,76,57));
glTranslatef(-25,230,0);
for(int i=0;i<50;i++)
{
  glPushMatrix();
glScalef(.4,.3,1);
glCallList(PAVEMENT2);
glPopMatrix();
glTranslatef(35,0,0);
}
glPopMatrix();

glPushMatrix();
glColor3f(RGB(205,129,98));
glTranslatef(-25,230,0);
for(int i=0;i<50;i++)
{
  glPushMatrix();
glScalef(.4,.3,1);
glCallList(PAVEMENT1);
glPopMatrix();
glTranslatef(35,0,0);
}
glPopMatrix();
glEndList();

glPushMatrix();
glTranslatef(0,-20,0);
glCallList(PAVEMENT);
glPopMatrix();


glPushMatrix();
glColor3f(0,1,0);
glTranslatef(100,405,0);
glScalef(3,3,3);
glCallList(TREE);
glPopMatrix();

if(garbageFull)
{
  // printf("%d",garbageFull);
glPushMatrix();
glTranslatef(xpos,ypos,0);
paper();//paper
glPopMatrix();

glPushMatrix();
//glColor3f(.5,.3,.3);
glTranslatef(x1pos,y1pos,0);
paper();//paper 1
glPopMatrix();

glPushMatrix();
glTranslatef(x2pos,y2pos,0);
glScalef(.2,.4,.2);
paper();//paper 2
glPopMatrix();

glPushMatrix();
glTranslatef(x3pos,y3pos,0);
glScalef(.3,.6,0);
paper();//paper 3
glPopMatrix();

glPushMatrix();
glTranslatef(x4pos,y4pos,0);
paper();//paper 4
glPopMatrix();

glPushMatrix();
glTranslatef(-350,-100,0);
glTranslatef(xbpos,ybpos,0);
glScalef(.6,.7,.5);
bn();//banana peel
glPopMatrix();

glPushMatrix();
glTranslatef(-350,-100,0);
glTranslatef(xb1pos,yb1pos,0);
glScalef(.6,.7,.5);
bn();//banana peel 1
glPopMatrix();


glPushMatrix();
glTranslatef(-170,-270,0);
glTranslatef(xopos,yopos,0);
// glScalef(.5,.5,0);
bottle1();
glPopMatrix();

glPushMatrix();//bottle 1
 
 glTranslatef(-80,-120,0);
 glTranslatef(xo1pos,yo1pos,0);
glScalef(.5,.5,0);
bottle1();
glPopMatrix();


}

glPushMatrix();//dry dustbin
glTranslatef(480,80,0);
glColor3f(1,0,0);
// glScalef(.75,.75,1);
glTranslatef(-50,-50,0);
glScalef(1,1,0);
glLineWidth(6.5);
glCallList(BIN);
glColor3f(0,0,0);
glPopMatrix();

glColor3f(1,1,1);
glPushMatrix();//board
glTranslatef(610,250,0);
glScalef(.4,.15,0);
glCallList(SQUARE);
glColor3f(0,0,0);
glTranslatef(5,20,0);
glScalef(.2,.4,0);
strokeText(" BIN",0,0);
glPopMatrix();
glColor3f(RGB(0,100,0));


glPushMatrix();
glTranslatef(dist,0,0);
glScalef(2,2,2);
glTranslatef(-200,100,0);
glColor3f(RGB(0,100,0));
glCallList(TRUCK);
glPushMatrix();
glTranslatef(50,5,0);
glScalef(2,2,2);
glPushMatrix();
glRotatef(ang,0,0,1);
glCallList(TYRE);
glPopMatrix();
glColor3f(RGB(60,179,113));
glCallList(MUDG);
glPopMatrix();
glPushMatrix();
glTranslatef(140,5,0);
glScalef(2,2,2);
glPushMatrix();
glRotatef(ang,0,0,1);
glCallList(TYRE);
glPopMatrix();
glColor3f(RGB(60,179,113));
glCallList(MUDG);
glPopMatrix();

glPopMatrix();


glPushMatrix();
glTranslatef(350,250,0);
// glTranslatef(xpos,ypos,0);
glScalef(2,2,1);
// glCallList(COW);
glPopMatrix();


glutSwapBuffers();
}

void moveTruck(int x)
{
  //printf("%d\n",x);
  dist++;
  ang-=1;
  if(x==900){sleep(3);garbageFull--;glutPostRedisplay();printf("%d\n", garbageFull);}
  if(x!=1792)
  glutTimerFunc(20,moveTruck,++x);
  else {
    dist=0;ang=0;
  }
  glutPostRedisplay();
}


void Initialize() {
glClearColor(0.0, 0.0, 0.0, 0.0);
// glViewport(0,0,100,100);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 100.0, 0.0, 100.0, -10.0, 10.0);
glMatrixMode(GL_MODELVIEW);
}
void reshape (int w, int h)
{
	sxm=(double)glutGet(GLUT_WINDOW_WIDTH)/1366;
sym=(double)glutGet(GLUT_WINDOW_HEIGHT)/744;
printf("%f %f \n",sxm,sym );
  winw=w;winh=h;
  // printf("%d %d \n",w,h);
  printf("qqqqqqqqqq%d %d \n",glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
glMatrixMode(GL_MODELVIEW);

}


void setup()
{
  glNewList(SQUARE , GL_COMPILE);
glBegin(GL_QUADS);
  glVertex2f(0,0);
  glVertex2f(0,100);
  glVertex2f(100,100);
  glVertex2f(100,0);
  glEnd();
glEndList();

glNewList(TRUCK,GL_COMPILE);
glBegin(GL_POLYGON);
glVertex2f(20,10);
glVertex2f(45,60);
glVertex2f(115,60);
glVertex2f(115,10);
glEnd();

glColor3f(RGB(238,154,0));
glPushMatrix();
glTranslatef(120,10,0);
glScalef(.4,.5,0);
glCallList(SQUARE);
glPopMatrix();
glColor3f(RGB(0,100,0));

glColor3f(RGB(205,200,177));
glPushMatrix();
glTranslatef(130,35,0);
glScalef(.2,.16,0);
glCallList(SQUARE);
glPopMatrix();
glColor3f(RGB(0,100,0));

glColor3f(1,1,1);
glPushMatrix();//board
glTranslatef(50,35,0);
glScalef(.5,.15,0);
glCallList(SQUARE);
glColor3f(0,0,0);
glTranslatef(5,20,0);
glScalef(.2,.4,0);
strokeText("BBMP",0,0);
glPopMatrix();
glColor3f(RGB(0,100,0));

for(int i=0;i<3;i++)//strip
{
  glPushMatrix();
  glPushMatrix();
glTranslatef(60+i*15,50,0);
glScalef(.05,.15,0);
glCallList(SQUARE);
glPopMatrix();
  glPopMatrix();

}

glColor3f(RGB(218,165,32));
glBegin(GL_POLYGON);
glVertex2f(0,5);
glVertex2f(25,60);
glVertex2f(45,60);
glVertex2f(20,5);
glEnd();

glEnd();
glEndList();

//glNewList(WHEEL,GL_COMPILE);
glNewList(TYRE,GL_COMPILE);
glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);
for( float theta=0;theta<=360;theta++)
    glVertex2f(6.5*cos(theta*val) ,6.5*sin(theta*val));
glEnd();
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glColor3f(1,1,1);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(0,0);
for( float theta=0;theta<=360;theta+=30)
    glVertex2f(3*cos(theta*val) ,3*sin(theta*val));
glEnd();
glPolygonMode(GL_FRONT,GL_FILL);

glEndList();


glNewList(MUDG,GL_COMPILE);
glColor3f(RGB(60,179,113)); //mud guard
glBegin(GL_QUADS);
for(int theta=0;theta<=180;theta+=1)
    {
      glVertex2f(3*cos(theta*val),3*sin(theta*val));
      glVertex2f((8)*cos(theta*val),(8)*sin(theta*val));
      
    }
glEnd();
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glEndList();
// glEndList();

glNewList(TREE,GL_COMPILE);//tree
glPushMatrix();
glPushMatrix();

// glTranslatef(0,-20,0);
glBegin(GL_POLYGON);//tree stem
glColor3f(RGB(139,69,0));
glVertex2f(-3,-17);
glVertex2f(3,-17);
glVertex2f(8,-52);
glVertex2f(-10,-52);
glEnd();
glPopMatrix();
glColor3f(RGB(0,205,0));
glPushMatrix();
for( int theta=0;theta<360;theta+=25)
{
    glPushMatrix();
    glTranslatef(10*cos(theta*val) ,18*sin(theta*val),0);
    glBegin(GL_POLYGON);
    for(int beta=0;beta<=360;beta++)
    glVertex2f(8*cos(beta*val) ,8*sin(beta*val));
  glEnd();
  glPopMatrix();

}
      glBegin(GL_POLYGON);
for( int theta=0;theta<360;theta+=50)
{
      glVertex2f(10*cos(theta*val) ,18*sin(theta*val));
    }
      glEnd();
glPopMatrix();
glPopMatrix();
glEndList();

glNewList(PAVEMENT1 , GL_COMPILE);
glBegin(2);
  glVertex2f(0,0);
  glVertex2f(35,40);
  glVertex2f(85,40);
  glVertex2f(50,0);
  glEnd();
glEndList();

glNewList(PAVEMENT2 , GL_COMPILE);
glBegin(9);
  glVertex2f(0,0);
  glVertex2f(35,40);
  glVertex2f(85,40);
  glVertex2f(50,0);
  glEnd();
glEndList();

glNewList(LAWN,GL_COMPILE);
glPushMatrix();
glTranslatef(-10,0,0);
glPushMatrix();
glTranslatef(20,10,0);
glBegin(GL_POLYGON);
  for(float theta=90;theta<=270;theta+=5)
    glVertex2f(10*cos(theta*val) ,10*sin(theta*val));
glEnd();
glTranslatef(15,10,0);
glPushMatrix();
glScalef(1,.5,0);
glBegin(GL_POLYGON);
  for(float theta=0;theta<=180;theta+=5)
    glVertex2f(15*cos(theta*val) ,15*sin(theta*val));
glEnd();
glPopMatrix();
glTranslatef(15,-10,0);
glBegin(GL_POLYGON);
  for(float theta=90;theta>=-90;theta-=5)
    glVertex2f(10*cos(theta*val) ,10*sin(theta*val));
glEnd();
glPopMatrix();
glBegin(GL_POLYGON);
glVertex2f(20,0);
glVertex2f(20,20);
glVertex2f(50,20);
glVertex2f(50,0);
glEnd();
glPopMatrix();
glEndList();

glNewList(BIN,GL_COMPILE);
glPushMatrix();
// glRotatef(30,1,0,0);
glLineWidth(2);
glTranslatef(200,200,0);
for(int i=0;i<20;i+=3)
{
  // if(i==0)glPolygonMode(GL_FRONT,GL_FILL);else glPolygonMode(GL_FRONT,GL_POINTS);
  glTranslatef(0,10,0);
  circledraw(20+i,10);
}
glLineWidth(1);
glPopMatrix();
glEndList();


glNewList(HOUSE,GL_COMPILE);//house
//glPushMatrix();
glColor3f(RGB(238,201,0));
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(50,200);
glVertex2f(100,150);
glVertex2f(100,0);
glEnd();

glColor3f(RGB(238,201,0));//houseroof
glBegin(GL_POLYGON);
glVertex2f(-32,150);
glVertex2f(-2,150);
glVertex2f(50,202);
glVertex2f(102,150);
glVertex2f(132,150);
glVertex2f(90,190);
glVertex2f(90,205);
glVertex2f(85,205);
glVertex2f(85,195);
glVertex2f(50,232);
glEnd();

glColor3f(RGB(142,56,142));
glBegin(GL_POLYGON);//window
glVertex2f(20,60);
glVertex2f(20,90);
glVertex2f(40,90);
glVertex2f(40,60);
glEnd();

glColor3f(RGB(238,201,0));//window strip
glBegin(GL_LINE_STRIP);
glLineWidth(4);
glVertex2f(30,90);
glVertex2f(30,60);
glEnd();
//glColor3f(RGB(142,56,142));//window strip
glBegin(GL_LINE_STRIP);
glLineWidth(4);
glVertex2f(20,75);
glVertex2f(40,75);
glEnd();

glColor3f(RGB(142,56,142));//door
glBegin(GL_QUADS);
glVertex2f(60,5);
glVertex2f(60,80);
glVertex2f(80,80);
glVertex2f(80,5);
glEnd();
glEndList();

glNewList(COW,GL_COMPILE);
glColor3f(RGB(255,255,255));
//glBegin(GL_LINE_LOOP);
glBegin(GL_POLYGON);
glVertex2f(0,15);
glVertex2f(5,15);
glVertex2f(5,35);
glVertex2f(5,70);
glVertex2f(0,60);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(5,35);
 glVertex2f(30,20);
 glVertex2f(80,20);
 glVertex2f(87,40);
 glVertex2f(91,20);
glVertex2f(104,30);
glVertex2f(85,75);
glVertex2f(70,75);
glVertex2f(65,70);
glVertex2f(5,70);
glEnd();

float i,angle=0;int r;

glBegin(GL_POLYGON);
glColor3f(0,0,0.0);
  for(i=0;i<360;i+=10)
  {r=5;
  angle=3.14/180*i;
  glVertex2f(15+cos(angle)*r,60+sin(angle)*r);
  }
glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0,0.0);
  for(i=0;i<360;i+=10)
  {r=4;
  angle=3.14/180*i;
  glVertex2f(20+cos(angle)*r,60+sin(angle)*r);
  }
glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0,0.0);
  for(i=0;i<360;i+=10)
  {r=5;
  angle=3.14/180*i;
  glVertex2f(35+cos(angle)*r,55+sin(angle)*r);
  }
glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0,0.0);
  for(i=0;i<360;i+=10)
  {r=4;
  angle=3.14/180*i;
  glVertex2f(40+cos(angle)*r,50+sin(angle)*r);
  }
glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0,0.0);
  for(i=0;i<360;i+=10)
  {r=3;
  angle=3.14/180*i;
  glVertex2f(80+cos(angle)*r,50+sin(angle)*r);
  }
glEnd();


glColor3f(RGB(255,255,255));
//glBegin(GL_LINE_LOOP);
glBegin(GL_POLYGON);
glVertex2f(12,32);//back legs
glVertex2f(10,20);
glVertex2f(14,0);
glVertex2f(18,0);
glVertex2f(20,23);
glVertex2f(27,2);
glVertex2f(31,2);
glVertex2f(25,25);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0,0.0);
  for(i=0;i<360;i+=10)
  {r=3.5;
  angle=3.14/180*i;
  glVertex2f(17+cos(angle)*r,30+sin(angle)*r);
  }
glEnd();
glColor3f(RGB(255,255,255));
glBegin(GL_POLYGON); //glBegin(GL_LINE_LOOP);
glVertex2f(63,20);//second leg
glVertex2f(66,0);
glVertex2f(69,0);
glVertex2f(72,20);
glEnd();
glBegin(GL_POLYGON);//front leg
glVertex2f(73,20);
glVertex2f(77,2);
glVertex2f(80,2);
glVertex2f(80,20);
glEnd();
//glBegin(GL_LINE_LOOP);
glBegin(GL_POLYGON);//cow head
glVertex2f(91,20);
glVertex2f(92,17);
glVertex2f(100,7);
glVertex2f(108,10);
glVertex2f(106,23);
glVertex2f(110,33);
glVertex2f(104,30);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0,0,0.0);
  for(i=0;i<360;i+=10)
  {r=1;
  angle=3.14/180*i;
  glVertex2f(100+cos(angle)*r,20+sin(angle)*r);
  }
glEnd();
glEndList();

glNewList(GRASS,GL_COMPILE);
glBegin(GL_POLYGON);
//glColor3f(RGB(255,255,255));
glVertex2f(97,0);
glVertex2f(90,15);
glVertex2f(95,7);
glVertex2f(97,20);
glVertex2f(99,14);
glVertex2f(100,22);
glVertex2f(103,0);
glEnd();
glEndList();
}


//void savePos(int x, int y)
void savePos(int x,int y)
{
  *xt=(double)(x);
    *yt=winh-(double)(y);//-winh);
    glutPostRedisplay();
}


void savePos1(int x,int y)
{
  xbpos=(double)(x);
    ybpos=winh-(double)(y);//-winh);
    glutPostRedisplay();
}

void circledraw(int xr,int yr)
{
//float i,angle=0;
// glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_STRIP);
for(int theta=0;theta<360;theta++)
{
    glVertex2f( xr*cos(theta*val) ,yr*sin(theta*val));
}
glEnd();
}


void myMotion(int x, int y)
{
    savePos(x,y);
}


// myPassiveMotion
// The GLUT Passive Motion function
// Save mouse pos
void myPassiveMotion(int x,int y)
{
    savePos(x,y);
}

void myMotion1(int x,int y)
{
    savePos1(x,y);
}


// myPassiveMotion
// The GLUT Passive Motion function
// Save mouse pos
void myPassiveMotion1(int x,int y)
{
    savePos1(x,y);
}

//int garbageOn;

void mouse(int b, int s, int x, int y)
{
 printf("%d %d\n",x,y);
  if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN && containsPoint(457,557,514,596,x,y))
  {//paper
  	xt=&xpos,yt=&ypos;
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }
  if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN && containsPoint(657,682,707,720,x,y))
  {//paper 1 placed down
    xt=&x1pos,yt=&y1pos;
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }
  if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN && containsPoint(790,694,804,711,x,y))
  {//paper 2
    xt=&x2pos,yt=&y2pos;
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }
if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN && containsPoint(184,710,207,728,x,y))
  {//paper 3
    xt=&x3pos,yt=&y3pos;
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }
  if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN && containsPoint(864,600,904,640,x,y))
  {//paper 4
    xt=&x4pos,yt=&y4pos;
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }
  if( b==GLUT_LEFT_BUTTON && containsPoint(279,574,359,701,x,y))
  {
  	//bottle
  	xt=&xopos,yt=&yopos;
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }
  if(b==GLUT_LEFT_BUTTON && containsPoint(887,499,944,560,x,y))
  {
    //bottle 1
    xt=&xo1pos,yt=&yo1pos;
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }

  //if(containsPoint(670,573,734,635,x,y))//banana peel
  if(b==GLUT_LEFT_BUTTON && containsPoint(569,506,604,542,x,y))
  {
  	xt=&xbpos,yt=&ybpos;
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }
  if( b==GLUT_LEFT_BUTTON && containsPoint(887,673,925,713,x,y))//banana peel 1
  {
    xt=&xb1pos,yt=&yb1pos;
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }
  if( b==GLUT_LEFT_BUTTON && containsPoint(597,458,655,516,x,y))
  {
    if(garbageOn){
     glutPassiveMotionFunc(NULL);
    garbageCount++;
    glutMotionFunc(NULL);
    garbageOn=0;
    glutPostRedisplay();
  }
  }
  }


void paper()
{


glPushMatrix();
glTranslatef(-650,-600,0);

 glColor4f(1,0,0,1);
glLineWidth(2);
glScalef(3,3,0);
 glPushMatrix(); 
glBegin(GL_POLYGON);


glVertex2f(210,210);
glVertex2f(213,212);
glVertex2f(215,213);
glVertex2f(217,209);
glVertex2f(216,206);
glVertex2f(216,204);
glVertex2f(218,205);
glVertex2f(215,202);
glVertex2f(213,204);
glVertex2f(211,201);
glVertex2f(209,204);
glVertex2f(210,205);
glVertex2f(207,204);
glVertex2f(205,204);
glVertex2f(206,205);
glVertex2f(206,207);
glVertex2f(209,211);

glEnd();
glPopMatrix();
glPopMatrix();
}

void menu(int k)
{
  if(k==1 && garbageCount==8)
  {
  glutTimerFunc(100,moveTruck,1);
  }
}
int main(int iArgc, char** cppArgv) {
glutInit(&iArgc, cppArgv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1366, 768);
glutInitWindowPosition(50, 50);
glutCreateWindow("Moving Line");
Initialize();
setup();
//init ();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_GEQUAL);
  // glutTimerFunc(500,moveTruck,1);
 // glutMouseFunc(myMouse);
  // glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
//glutDisplayFunc(Draw);
// glutTimerFunc(100,makedelay,1);
 // glutDisplayFunc(display); 
 glutTimerFunc(1,changeS,0);
   glutReshapeFunc(reshape);
  int m=glutCreateMenu(menu);
  glutAddMenuEntry("Call BBMP",1);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
return 0;
}


