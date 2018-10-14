#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include<math.h>
#define PI 3.14159265

int sbxc=300,sbyc=370,sbr=150;
//int xc1=720,yc1=370,r1=150;
int sbxc2=680,sbyc2=490,sbr2=50;
int sbxc3=1300,sbyc3=470,sbr3=50;
#define RGB(r,g,b) r/255.0f,g/255.0f,b/255.0f
float sm1=580,sm2=270,rm=5,h1=630,h2=250,hr=80;
float nn1=650,nn2=410,nnr=150;
float x1=625,y01=200,r1=20,r2=15,hd1=330,hd2=325,hdr=30;
float l1=313.5,l2=100,lr=13.5,rr1=351.5,rr2=100,rr=13.5;
float xm=470,ym=554,rm1=30;


float aa1=450,aa2=560,aar1=25,y3=380;
float x2=407.5,y2=450,aar2=7.5,r3=13.5;
float x3=492.5,x4=433.5,x5=466.5,xg=540,yg=477,rg=18; 
float cx1=680,cy1=640,cr1=10,xc2=700,yc2=650,rc2=20,xc3=725,yc3=655,rc3=25,xc4=770,yc4=660,rc4=25,xc5=815,yc5=660,rc5=30;
int i,id,c,m,e,hu,l=0;
int p=10;
float ee1=250,ee2=300,eer=120;
float cc1=625,cc2=200,ccr=20,ccr1=15;
float xs=195,ys=450,rs=15,xe=275,ye=385,re=5,sx=285,sy=350,sr=10;
int ang=0,angle=0;
void van();
int dist=0;
double val=PI/180;

//double val=PI/180;
float winh,winw,xpos=500,ypos=150,xbpos=700,ybpos=150;

float h=100,k=100,theta=0.0;
int garbageFull=1,garbageCount=0,garbageOn;

////////////////////////////////////////////////////////////////
void cg22display(void);
void cg21display(void);
void cg20display(void);
void cg19display(void);
void cg18display(void);
void cg17display(void);
void cg14display(void);
void cg12display(void);
void cg10display(void);
void cg9display(void);
void cg8display(void);
void cg7display(void);
void cg6display(void);
void cg5display(void);
void cg4display(void);
void cg3display(void);
void cg2display(void);
void cg1display(void);

void circle_draw1(int,int,int);
void circle_draw(int,int,int);
void tricolor();
void sbtext();
void line1();
void line();
void printtext1();
void cg2buildings();
void cg2houses();
void tree();
void bottle1();
void bottle2();
void pcover();
void pcover1();
void printext();
void animtext();
void pandemictext();
void cow();
void cir(float,float,float);
void grass();
void cg3houses();
void cg3buildings();
void can();
void bn();
void pile();
void dustpile();
void cg4houses();
void cg4buildings();
void cg5semicir(float,float,float);
void wastetext();
void path();
void cloud();
void chair();
void w();
void elipse();
void textbox();
void path1();
void WASTEtext();
void p1();
void p2();
void _3ppl();
void dustbin();
void shop();
void bubble();
void india();
void cg5houses();
void cg5buildings();
void home();//text
void cg7houses();
void cg7buildings();
void citytext();
void huttext();
void cg8hut();
void hometext();
void cg10houses();
void cg10buildings();
void healthycitytext();
void sicktext();
void cg12houses();
void cg12buildings();
void dusttext();
void wasteman();
void publictext();
void dustbin1();
void dustbin2();
void man1();
void recycletext();
void yardtext();
void hutpath();
void cg20hut();
void cg20houses();
void cg20buildings();
void cg22semicir(float,float,float);
void nationtext();
void svcantext();

void cg17sky();
void cg17road();
void cg17van();
void cg17tyre();
void cg17mudg();
void cg17truck();
void cg17square();
void cg17houses();
void cg17buildings();
void garbagevantext();
/*
void circledraw(int,int);
void paper();
void strokeText();
void p4house();
void lawn1();
void lane();
void pavement();
void pav();
void p4tree();
void waste();
void drybin();
void wetbin();
void treee();
void pav1();
void pav2();
void lawn();
void binn();
void hutt();
void moveTruck(int);
void savePos(int,int);
void myMotion(int,int);
void myPassiveMotion(int,int);
void mouse(int,int,int,int);
void menu(int);
void myPassiveMotion1(int , int );
void savePos1(int , int );
void myMotion1(int , int );
int containsPoint(float ,float ,float ,float ,float ,float );*/
/////////////////////////////////////////////////////////////////////////////////////////////














/*

void savePos1(int x, int y)
{
  xbpos =  double(x);
    ybpos = winh-double(y);//-winh);
    glutPostRedisplay();
}


void myMotion1(int x, int y)/////////////////8888888888
{
    savePos1(x, y);
}
void myPassiveMotion1(int x, int y)//8888888888888888888nottheree
{
    savePos1(x, y);
}
int containsPoint(float x1,float y1,float x2,float y2,float x,float y)
{
  float sx=winw/1366;
	float sy=winh/744;
x1*=sx,x2*=sx,y1*=sy,y2*=sy;
  ////printf("%d %d  %d %d\n",x1,y1,x2,y2);
  if(x>=x1 && x<=(x2) && y>=y1 && y<=(y2)) return 1;
  else return 0;
}
void menu(int k)
{
  if(k==1 and garbageCount==2)
  {
  glutTimerFunc(100,moveTruck,1);
  }
}
void savePos(int x, int y)
{
  xpos =  double(x);
    ypos = winh-double(y);//-winh);
    glutPostRedisplay();
}
void mouse(int b, int s, int x, int y)
{
 printf("%d %d\n",x,y);

  if(b==GLUT_RIGHT_BUTTON && s==GLUT_DOWN && containsPoint(457,557,514,596,x,y))
  {
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion);
    glutMotionFunc(myMotion);
  }

  if(containsPoint(670,573,734,635,x,y))
  {
    garbageOn=1;
     glutPassiveMotionFunc(myPassiveMotion1);
    glutMotionFunc(myMotion1);
  }
  if(containsPoint(597,458,655,516,x,y))
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


void myMotion(int x, int y)
{
    savePos(x, y);
}

void myPassiveMotion(int x, int y)
{
    savePos(x, y);
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
*/

void printtext( char* s)
{
 while (*s) { 
//glutStrokeWidth(GLUT_STROKE_ROMAN,*s);
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,*s);
// glutStrokeCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,*s);       
// glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, *s);
         s++;
      }
  
}

void pandemictext()
{
   char* ani[20] = {"Waste, causes pandemic"};

glPushMatrix();
glTranslatef(150,590,0);
glScalef(0.3,0.3,0);
glPointSize(1);
 glLineWidth(2);
glColor3f(1,1,1);
    printtext(ani[0]);
glPopMatrix();


glFlush();


}

void tree()
{
glColor3f(1.000, 0.843, 0.000);
glRectf(500,100,550,350);

glBegin(GL_POLYGON);
glVertex2f(500,100);
glVertex2f(550,100);
glVertex2f(580,50);
glVertex2f(470,50);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(500,240);
glVertex2f(500,220);
glVertex2f(460,225);
glVertex2f(458,245);
glEnd();

glRectf(517.5,350,532.5,390);


glBegin(GL_POLYGON);
glVertex2f(532.5,350);
glVertex2f(592.5,380);
glVertex2f(599,365);
glVertex2f(545,335);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(589,374);
glVertex2f(604,370);
glVertex2f(609,404);
glVertex2f(592,404);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(592.5,380);
glVertex2f(632,383);
glVertex2f(639,365);
glVertex2f(599,365);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(517.5,350);
glVertex2f(510,335);
glVertex2f(430,380);
glVertex2f(437,395);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(450,370);
glVertex2f(455,420);
glVertex2f(470,415);
glVertex2f(465,365);
glEnd();

glColor3f(0.196, 0.904, 0.196);
glPointSize(10);




for(i=0;i<=180;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(490+i,640);
glEnd();
}


for(i=0;i<=200;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(470+i,620);
glEnd();
}


for(i=0;i<=280;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(450+i,600);
glEnd();
}


for(i=0;i<=340;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(430+i,580);
glEnd();
}


for(i=0;i<=340;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(400+i,560);
glEnd();
}


for(i=0;i<=340;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(360+i,540);
glEnd();
}


for(i=0;i<=340;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(340+i,520);
glEnd();
}

for(i=0;i<=640;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(300+i,500);
glEnd();
}

for(i=0;i<=600;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(260+i,480);
glEnd();
}

for(i=0;i<=600;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(240+i,460);
glEnd();
}

for(i=0;i<=600;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(240+i,440);
glEnd();
}

for(i=0;i<=620;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(220+i,420);
glEnd();
}


for(i=0;i<=200;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(200+i,400);
glEnd();
}

for(i=0;i<=80;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(660+i,400);
glEnd();
}

for(i=0;i<=200;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(200+i,380);
glEnd();
}

for(i=0;i<=100;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(640+i,380);
glEnd();
}

for(i=0;i<=180;i+=20)//7
{
glBegin(GL_POINTS);
glVertex2f(240+i,360);
glEnd();
}
for(i=0;i<=80;i+=20)//7
{
glBegin(GL_POINTS);
glVertex2f(600+i,360);
glEnd();
}

for(i=0;i<=180;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(280+i,340);
glEnd();
}
for(i=0;i<=80;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(580+i,340);
glEnd();
}
for(i=0;i<=160;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(320+i,320);
glEnd();
}
for(i=0;i<=80;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(560+i,320);
glEnd();
}

for(i=0;i<=120;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(360+i,300);
glEnd();
}

for(i=0;i<=100;i+=20)
{
glBegin(GL_POINTS);
glVertex2f(560+i,300);
glEnd();
}
for(i=0;i<=40;i+=20)
{glBegin(GL_POINTS);
glVertex2f(420+i,240);
glEnd();
}

for(i=0;i<=40;i+=20)
{glBegin(GL_POINTS);
glVertex2f(410+i,225);
glEnd();
}
for(i=0;i<=60;i+=20)
{glBegin(GL_POINTS);
glVertex2f(420+i,210);
glEnd();

glPointSize(1);
}




}
void cir(float xc,float yc,float r)
{
float i,angle=0;
//glColor3f(0.0,0.0,0.0);
glPointSize(3.5);
glBegin(GL_POLYGON);
for(i=0;i<360;i+=1)
{
angle=3.14/180*i;
glVertex2f(xc+cos(angle)*r,yc+sin(angle)*r);
}
glEnd();
glFlush();
glutPostRedisplay();
}


void grass()
{
glColor3f(0.196, 0.804, 0.196);
glRectf(200,105,243,120);
glBegin(GL_POLYGON);
glVertex2f(170,150);
glVertex2f(208,120);
glVertex2f(200,105);
glEnd();
for( e=0;e<=30;e+=10)
{
glBegin(GL_POLYGON);
glVertex2f(204+e,158);
glVertex2f(212+e,120);
glVertex2f(200+e,120);
glEnd();
}
glBegin(GL_POLYGON);
glVertex2f(260,150);
glVertex2f(240,105);
glVertex2f(220,120);
glEnd();
}

void cg2houses()
{
glColor3f(0.018, 0.465, 0.70);
glRectf(100,100,250,350);
glRectf(255,100,370,300);
glRectf(100,355,250,375);
glRectf(215,380,250,400);
glRectf(370,100,410,130);
glRectf(400,100,510,270);
glRectf(510,100,530,170);
glRectf(530,100,630,320);


//windows
//glColor3f(0.502, 0.000, 0.502);
glColor3f(0.118, 0.565, 1.000);
for(i=0;i<=210;i+=30)
{
glRectf(110,110+i,240,125+i);
}

for(i=0;i<=80;i+=40)
{
glRectf(420,150+i,445,180+i);
glRectf(470,150+i,495,180+i);

}

for(i=0;i<=160;i+=40)
{
glRectf(545,130+i,565,150+i);
glRectf(595,130+i,615,150+i);
}
}

void cg2buildings()
{
glPushMatrix();
cg2houses();
glPopMatrix();

glPushMatrix();
glTranslatef(540,0,0);
cg2houses();
glPopMatrix();

glPushMatrix();
glTranslatef(1000,-20,0);
cg2houses();
glPopMatrix();

glPushMatrix();
glTranslatef(-400,0,0);
//glTranslatef(-400,-20,0);
cg2houses();
glPopMatrix();
}



void can()
{
glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2f(800,400);
glVertex2f(820,400);
glVertex2f(828,422);
glVertex2f(833,400);
glVertex2f(840,423);
glVertex2f(850,400);
glVertex2f(850,430);
glVertex2f(830,430);
glVertex2f(826,415);

glVertex2f(823,430);
glVertex2f(820,415);
glVertex2f(815,430);
glVertex2f(800,430);

glEnd();

glColor3f(0.863, 0.863, 0.863);
glBegin(GL_LINES);
glVertex2f(800,402);
glVertex2f(800,428);
glEnd();
}

void bn()
{
glLineWidth(10.0);

glColor3f(1,1,0);
glBegin(GL_LINES);
glVertex2f(600,200);
glVertex2f(570,170);
glVertex2f(570,170);
glVertex2f(585,150);

glVertex2f(600,200);
glVertex2f(610,160);
glVertex2f(610,160);
glVertex2f(605,140);

glVertex2f(600,200);
glVertex2f(590,160);
glVertex2f(590,160);
glVertex2f(599,140);

glEnd();


glColor3f(0.545, 0.271, 0.075);

glBegin(GL_LINES);

glVertex2f(600,188);
glVertex2f(600,201);
glEnd();
}

void bottle1()
{
glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(190,220);
glVertex2f(150,240);
glVertex2f(195,300);
glVertex2f(220,290);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(218,293);
glVertex2f(225,307);
glVertex2f(205,317);
glVertex2f(197,302);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(205,323);
glVertex2f(230,313);
glVertex2f(234,333);
glVertex2f(225,335);
glEnd();

glBegin(GL_LINES);
glVertex2f(227,341);
glVertex2f(234,339);
glEnd();
}

void bottle2()
{
glBegin(GL_POLYGON);
glVertex2f(400,200);
glVertex2f(420,230);
glVertex2f(360,270);
glVertex2f(340,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(345,255);
glVertex2f(355,265);
glVertex2f(330,280);
glVertex2f(320,270);

glEnd();
}


void pcover()
{
glRectf(500,200,530,240);
glBegin(GL_POLYGON);
glVertex2f(500,200);
glVertex2f(530,200);
glVertex2f(522,190);
glVertex2f(508,190);
glEnd();

glColor3f(0,0,0);
glLineWidth(1.5);
glBegin(GL_LINES);
glVertex2f(515,235);
glVertex2f(515,200);

glVertex2f(515,200);
glVertex2f(522,190);

glVertex2f(515,200);
glVertex2f(508,190);
glEnd();
}

void pcover1()
{
glColor3f(1,1,1);
glRectf(600,300,630,310);
glBegin(GL_LINE_LOOP);
glVertex2f(590,250);
glVertex2f(625,250);
glVertex2f(630,300);
glVertex2f(600,300);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(595,255);
glVertex2f(620,255);
glVertex2f(625,285);
glVertex2f(600,285);
glEnd();

glBegin(GL_LINE_LOOP);

glVertex2f(625,250);
glVertex2f(634,255);
glVertex2f(630,310);
glEnd();
}
void pile()
{

glRectf(680,630,820,650);
cir(cx1,cy1,cr1);
cir(xc2,yc2,rc2);
cir(xc3,yc3,rc3);
cir(xc4,yc4,rc4);
cir(xc5,yc5,rc5);
}     

void dustpile()
{
glPushMatrix();
glColor3f(0.184, 0.310, 0.310);
glTranslatef(-1100,-1200,0);
glScalef(2,2.3,0);
pile();
glPopMatrix();

glPushMatrix();
glColor3f( 0.412, 0.412, 0.412);
glTranslatef(-780,-880,0);
glScalef(1.8,1.8,0);
pile();
glPopMatrix();


glPushMatrix();
glTranslatef(0,50,0);
glColor3f( 1,1,1);
pcover();
glPopMatrix();


glPushMatrix();

glTranslatef(0,50,0);
glColor3f(1,0,0);
pcover1();
glPopMatrix();

glPushMatrix();

glTranslatef(-400,-150,0);
glColor3f(1,0,0);
can();
glPopMatrix();

glPushMatrix();

glTranslatef(-150,130,0);

bn();
glPopMatrix();

glPushMatrix();
glTranslatef(250,200,0);
glScalef(0.5,0.5,0);
bottle1();
glPopMatrix();

}



void cg2display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.118, 0.565, 1.000,1.0);
glLoadIdentity();
glPushMatrix();
pandemictext();
glPopMatrix();
glPushMatrix();
glTranslatef(0,100,0);
cg2buildings();
glPopMatrix();



/*
glPushMatrix();
glTranslatef(400,-50,0);
cloud();
glPopMatrix();*/


glPushMatrix();
glTranslatef(30,-150,0);
dustpile();
glPopMatrix();


glPushMatrix();
glTranslatef(750,0,0);
tree();
glPopMatrix();
/*glPushMatrix();
glTranslatef(-600,0,0);
cloud();
glPopMatrix();*/

glutSwapBuffers();
glutPostRedisplay();
 }



void animtext()
{
   char* ani[20] = {"Waste, Animal may be infected due to garbage"};
glLineWidth(2);
glPointSize(1);
glPushMatrix();
glTranslatef(150,590,0);
glScalef(0.2,0.3,0);

 glColor3f(1,1,1);
    printtext(ani[0]);
glPopMatrix();


glFlush();


}
void cow()
{

glColor3f(1,1,1);
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

}



void cg3houses()
{
glColor3f(0.018, 0.465, 0.70);
glRectf(100,100,250,350);
glRectf(255,100,370,300);
glRectf(100,355,250,375);
glRectf(215,380,250,400);
glRectf(370,100,410,130);
glRectf(400,100,510,270);
glRectf(510,100,530,170);
glRectf(530,100,630,320);


//windows
//glColor3f(0.502, 0.000, 0.502);
glColor3f(0.118, 0.565, 1.000);
for(i=0;i<=210;i+=30)
{
glRectf(110,110+i,240,125+i);
}

for(i=0;i<=80;i+=40)
{
glRectf(420,150+i,445,180+i);
glRectf(470,150+i,495,180+i);

}

for(i=0;i<=160;i+=40)
{
glRectf(545,130+i,565,150+i);
glRectf(595,130+i,615,150+i);
}
}

void cg3buildings()
{
glPushMatrix();
cg3houses();
glPopMatrix();
}


void cg3display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.118, 0.565, 1.000,1.0);
glLoadIdentity();



glPushMatrix();
glTranslatef(20,0,0);
grass();
glPopMatrix();
glPushMatrix();
glTranslatef(0,100,0);
cg3buildings();
glPopMatrix();
glPushMatrix();
glTranslatef(-90,30,0);
grass();
glPopMatrix();

glPushMatrix();
glTranslatef(40,30,0);
grass();
glPopMatrix();


//glPushMatrix();
//glTranslatef(400,-50,0);
//cloud();
//glPopMatrix();
glPushMatrix();
glScalef(2.5,2.5,0);
glTranslatef(0,50,0);
cow();
glPopMatrix();

glPushMatrix();
glTranslatef(30,-150,0);
dustpile();
glPopMatrix();


glPushMatrix();
glTranslatef(750,0,0);
tree();
glPopMatrix();
glPushMatrix();
//glTranslatef(-600,0,0);
//cloud();
//glPopMatrix();
animtext();
glutSwapBuffers();
glutPostRedisplay();
      
}



void cg4houses()
{
glColor3f(0.000, 0.000, 0.545);
glRectf(100,100,250,350);
glRectf(255,100,370,300);
glRectf(100,355,250,375);
glRectf(215,380,250,400);
glRectf(370,100,410,130);
glRectf(400,100,510,270);
glRectf(510,100,530,170);
glRectf(530,100,630,320);


//windows
glColor3f(0.000, 0.014, 1.000);
for(i=0;i<=210;i+=30)
{
glRectf(110,110+i,240,125+i);
}

for(i=0;i<=80;i+=40)
{
glRectf(420,150+i,445,180+i);
glRectf(470,150+i,495,180+i);

}

for(i=0;i<=160;i+=40)
{
glRectf(545,130+i,565,150+i);
glRectf(595,130+i,615,150+i);
}
}



void cg4buildings()
{
glPushMatrix();
cg4houses();
glPopMatrix();

glPushMatrix();
glTranslatef(540,0,0);
cg4houses();
glPopMatrix();

glPushMatrix();
glTranslatef(1000,-20,0);
cg4houses();
glPopMatrix();

glPushMatrix();
glTranslatef(-400,-20,0);
cg4houses();
glPopMatrix();
}

void wastetext()
{
   char* waste[20] = {"WASTE,"};
 char* wt[20]={"Decrease the place of blondess"};
//char* l3[20]={"SURROUNDING CLEAN!"};
glLineWidth(2);
glPointSize(1);
glPushMatrix();
glTranslatef(50,590,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(waste[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(250,590,0);
glScalef(0.2,0.2,0);
glColor3f(1,1,1);
    printtext(wt[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}



void path()
{
glColor3f(0.018, 0.065, 1.000);//light blue//path
glRectf(0,0,1600,200);

glColor3f(0.412, 0.412, 0.412);//grey//path
glRectf(0,200,1600,270);

glColor3f(0.545, 0.000, 0.545);//textboxpurple
glRectf(0,550,900,650);


}



void cloud()
{
glColor3f(0.529, 0.808, 0.922);
glRectf(680,630,820,650);
cir(cx1,cy1,cr1);
cir(xc2,yc2,rc2);
cir(xc3,yc3,rc3);
cir(xc4,yc4,rc4);
cir(xc5,yc5,rc5);
}      

void chair()
{
glColor3f(1.000, 0.171, 0.000);
glLineWidth(8);
glBegin(GL_LINES);
glVertex2f(500,480);
glVertex2f(600,480);
glVertex2f(500,468);
glVertex2f(600,468);
glVertex2f(500,455);
glVertex2f(600,455);
glVertex2f(490,415);
glVertex2f(610,415);

glVertex2f(500,415);//legs
glVertex2f(500,375);
glVertex2f(520,415);
glVertex2f(520,395);
glVertex2f(580,415);//legs
glVertex2f(580,395);
glVertex2f(600,415);
glVertex2f(600,375);


glEnd();

glBegin(GL_POLYGON);
glVertex2f(500,445);
glVertex2f(600,445);
glVertex2f(610,415);
glVertex2f(490,415);
glEnd();
}




void w()
{
for(i=0;i<=680;i+=300)
{
glPushMatrix();
//glTranslatef(-300+i,0+i/20,0);
glTranslatef(-300+i,-50+i/20,0);
glScalef(0.6,0.6,0);
bn();
glPopMatrix();
}
for(i=0;i<=400;i+=200)
{
glPushMatrix();

glTranslatef(-200+i,-240+i/5,0);
glScalef(0.6,0.6,0);
can();
glPopMatrix();
}
glColor3f(1,1,1);
for(i=0;i<=850;i+=400)
{
glPushMatrix();

glScalef(0.5,0.5,0);
glTranslatef(200+i,-200+i/10,0);
bottle1();
glPopMatrix();
}

for(i=0;i<=850;i+=200)
{
glPushMatrix();
glTranslatef(700+i,-40+i/20,0);
glScalef(0.5,0.5,0);
bottle2();
glPopMatrix();
}
for(i=0;i<=300;i+=100)
{
glPushMatrix();
glColor3f(1,1,1);
glTranslatef(100+i,40,0);
glScalef(0.5,0.5,0);
bottle2();
glPopMatrix();
}

for(i=0;i<=300;i+=100)
{
glPushMatrix();
glColor3f(1,1,1);
glTranslatef(500+i,0+i/20,0);
glScalef(0.5,0.5,0);
pcover();
glPopMatrix();
}

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(100,-20,0);
glScalef(0.5,0.5,0);
pcover();
glPopMatrix();

for(i=0;i<=300;i+=100)
{
glPushMatrix();
glTranslatef(100+i,-20+i/15,0);
glScalef(0.5,0.5,0);
pcover1();
glPopMatrix();
}
}


void cg4display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor( 	0.000, 0.014, 1.000,1.0);
glLoadIdentity();

glPushMatrix();
glTranslatef(0,170,0);
cg4buildings();
glPopMatrix();

glPushMatrix();
path();
glPopMatrix();

for(i=0;i<=900;i+=300)
{
glPushMatrix();
glTranslatef(100+i,220,0);
glScalef(0.2,0.2,0);
dustpile();
glPopMatrix();
}
glPushMatrix();
glTranslatef(-80,-200,0);
glScalef(1.8,1,0);
chair();
glPopMatrix();

glPushMatrix();
glTranslatef(-780,-200,0);
glScalef(1.8,1,0);
chair();
glPopMatrix();

glPushMatrix();
cloud();
glPopMatrix();

glPushMatrix();
wastetext();
glPopMatrix();

//
glPushMatrix();
w();
glPopMatrix();


//
glPushMatrix();
glTranslatef(600,0,0);
tree();
glPopMatrix();

glutSwapBuffers();
glutPostRedisplay();
      
}

void cg5semicir(float xc,float yc,float r)
{
float i,angle=0;
//glColor3f(0.0,0.0,0.0);
glPointSize(3.5);
glBegin(GL_POINTS);
for(i=0;i<180;i+=1)
{
angle=3.14/180*i;
glVertex2f(xc+cos(angle)*r,yc+sin(angle)*r);
}
glEnd();
glFlush();
glutPostRedisplay();
}

void elipse(float xc,float yc,float r)
{
float i,angle=0;
glColor3f(1,1,1);
glPointSize(3.5);
glBegin(GL_POLYGON);
for(i=0;i<360;i+=1)
{
angle=3.14/180*i;
glVertex2f(xc+cos(angle)*(r+55),yc+sin(angle)*r);
}
glEnd();
glFlush();
glutPostRedisplay();
}


void cg5houses()
{
glColor3f(0.000, 0.000, 0.545);
glRectf(100,100,250,350);
glRectf(255,100,370,300);
glRectf(100,355,250,375);
glRectf(215,380,250,400);
glRectf(370,100,410,130);
glRectf(400,100,510,270);
glRectf(510,100,530,170);
glRectf(530,100,630,320);


//windows
glColor3f(0.000, 0.014, 1.000);
for(i=0;i<=210;i+=30)
{
glRectf(110,110+i,240,125+i);
}

for(i=0;i<=80;i+=40)
{
glRectf(420,150+i,445,180+i);
glRectf(470,150+i,495,180+i);

}

for(i=0;i<=160;i+=40)
{
glRectf(545,130+i,565,150+i);
glRectf(595,130+i,615,150+i);
}
}



void cg5buildings()
{
glPushMatrix();
cg5houses();
glPopMatrix();

glPushMatrix();
glTranslatef(540,0,0);
cg5houses();
glPopMatrix();

glPushMatrix();
glTranslatef(1000,-20,0);
cg5houses();
glPopMatrix();

glPushMatrix();
glTranslatef(-400,-20,0);
cg5houses();
glPopMatrix();
}

void textbx()
{
glColor3f(0.545, 0.000, 0.545);//textboxpurple
glRectf(0,550,900,650);
}

void path1()
{
glColor3f(0.312, 0.312, 0.312);
glBegin(GL_POLYGON);
glVertex2f(260,340);
glVertex2f(310,340);
glVertex2f(385,0);
glVertex2f(180,0);
glEnd();
}


void WASTEtext()
{
   char* was[20] = {"WASTE,"};
 char* it[20]={"it dispel the people"};
char* shop[20]={"SHOP"};
 char* its[20]={"it's to dirty"};
char* i[20]={"i don't want"};
 char* to[20]={"to go there"};
glLineWidth(2);
glPointSize(1);
glPushMatrix();
glTranslatef(50,590,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(was[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(250,590,0);
glScalef(0.2,0.2,0);

 glColor3f(1,1,1);
    printtext(it[0]);
glPopMatrix();
glPushMatrix();
 glColor3f(1,1,1);
glTranslatef(1037,592,0);
glScaled(0.2,0.2,0);
    printtext(shop[0]);
glPopMatrix();
glPushMatrix();
 glColor3f(0,0,0);
glTranslatef(200,370,0);
glScalef(0.2,0.2,0);
    printtext(its[0]);
glPopMatrix();

glPushMatrix();
 glColor3f(0,0,0);
glTranslatef(200,320,0);
glScalef(0.2,0.2,0);
    printtext(i[0]);
glPopMatrix();

glPushMatrix();
 glColor3f(0,0,0);
glTranslatef(200,280,0);
glScalef(0.2,0.2,0);
    printtext(to[0]);
glPopMatrix();
glFlush();
//glutPostRedisplay();

}


void p1()
{
glPushMatrix();
glColor3f(1,1,1);//head
cir(aa1,aa2,aar1);
cir(x2,y2,aar2);
cir(x3,y2,aar2);
cir(x4,y3,r3);
cir(x5,y3,r3);
glPopMatrix();

glPushMatrix();
//glColor3f(0.0,0.0,0.0);
glRectf(400,500,500,525);
glRectf(400,450,415,500);
glRectf(420,445,480,500);
glRectf(485,450,500,500);
glRectf(420,380,447,445);
glRectf(453,380,480,445);
glPopMatrix();
}


void p2()
{
glPushMatrix();
glColor3f(1,1,1);//head
cir(xg,yg,rg);

glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);
glVertex2f(510,390);
glVertex2f(570,390);
glVertex2f(540,450);
glEnd();
glPopMatrix();

glPushMatrix();
glRectf(547.5,373.5,559.5,390);
glRectf(525.5,373.5,537.5,390);
glPopMatrix();



glPushMatrix();//left hand
glBegin(GL_POLYGON);
glVertex2f(500,460);
glVertex2f(540,450);
glVertex2f(540,435);
glVertex2f(490,448);

glEnd();
glPopMatrix();

glPushMatrix();//right hand
glBegin(GL_POLYGON);
glVertex2f(540,450);
glVertex2f(580,460);
glVertex2f(590,448);
glVertex2f(540,435);
glEnd();
glPopMatrix();
}

void _3ppl()
{
glPushMatrix();
p1();
glPopMatrix();

p2();

glPushMatrix();
glTranslatef(180,0,0);
p1();
glPopMatrix();
}



void dustbin()
{
glColor3f(1.000, 0.843, 0.000);
glRectf(500,400,650,410);

glBegin(GL_POLYGON);
glVertex2f(510,400);
glVertex2f(640,400);
glVertex2f(625,190);
glVertex2f(525,190);
glEnd();

/*glBegin(GL_POLYGON);
glVertex2f(640,410);
glVertex2f(660,510);
glVertex2f(670,508);
glVertex2f(650,410);
glEnd();*/

glColor3f(0.000, 0.014, 1.000);
cir(cc1,cc2,ccr);

glColor3f(1.000, 0.843, 0.000);
cir(cc1,cc2,ccr1);


}

void shop()
{


glColor3f(1.000, 0.843, 0.000);
 glBegin(GL_POLYGON);
glVertex2f(200,500);
glVertex2f(365,500);
glVertex2f(385,470);
glVertex2f(180,470);
glEnd();

glRectf(180,450,385,470);
glRectf(240,500,250,520);
glRectf(315,500,325,520);
glRectf(220,520,345,550);


for(c=0;c<=180;c+=35)
{
cir(xs+c,ys,rs);
}
glColor3f(0.600, 0.196, 0.800);//purple
glRectf(225,525,340,545);

glColor3f(0,1,0);//green
glRectf(180,330,385,430);

glColor3f(0,0,1.0);
glRectf(195,345,370,430);

glColor3f(0.196, 0.804, 0.196);//darkgreen
glRectf(210,360,355,430);

glColor3f( 0.678, 1.000, 0.184);//grassgreen
glRectf(260,330,310,400);

glColor3f(1,1,1);
for(m=0;m<=21;m+=20)
{
cir(xe+m,ye,re);

}
glColor3f(1,1,1);
cg5semicir(sx,sy,sr);
}

void bubble()
{
elipse(ee1,ee2,eer);
glPushMatrix();
glTranslatef(-225,80,0);
cir(cc1,cc2,ccr);
glPopMatrix();

glPushMatrix();
glScalef(0.5,0.5,0);
glTranslatef(230,340,0);
glColor3f(1,1,1);
cir(cc1,cc2,ccr);
glPopMatrix();
}




void cg5display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.000, 0.014, 1.000,1.0);
glLoadIdentity();

glPushMatrix();
glTranslatef(0,200,0);
cg5buildings();
glPopMatrix();


glPushMatrix();
glTranslatef(650,-200,0);
glScaled(1.5,1.5,0);
shop();
glPopMatrix();

glPushMatrix();
textbx();
glPopMatrix();



glPushMatrix();
glTranslatef(-600,0,0);
cloud();
glPopMatrix();

glPushMatrix();
glTranslatef(790,-50,0);
path1();
glPopMatrix();

for(i=0;i<=300;i+=300)
{
glPushMatrix();
glTranslatef(850+i,80+i/4,0);
glScalef(0.2,0.2,0);
dustpile();
glPopMatrix();
}

glPushMatrix();

glTranslatef(80,-300,0);
_3ppl();
glPopMatrix();


glPushMatrix();
glScaled(0.3,0.3,0);
glTranslatef(2350,800,0);
dustbin();
glPopMatrix();

glPushMatrix();
glTranslatef(70,20,0);
bubble();
glPopMatrix();

glPushMatrix();
WASTEtext();
glPopMatrix();
//bottles

glPushMatrix();
glScalef(0.5,0.5,0);
glTranslatef(2200,0,0);
bottle1();
glPopMatrix();

glPushMatrix();
glScalef(0.5,0.5,0);
glTranslatef(2100,120,0);
bottle1();
glPopMatrix();

glPushMatrix();
glTranslatef(900,0,0);
glScalef(0.5,0.5,0);
bottle2();
glPopMatrix();

glPushMatrix();
glTranslatef(700,90,0);
glScalef(0.5,0.5,0);
bottle2();
glPopMatrix();

glPushMatrix();
glTranslatef(900,0,0);
glScalef(0.5,0.5,0);
pcover();
glPopMatrix();


glPushMatrix();
glTranslatef(700,0,0);
glScalef(0.5,0.5,0);
pcover1();
glPopMatrix();

glPushMatrix();
glTranslatef(900,60,0);
glScalef(0.5,0.5,0);
pcover1();
glPopMatrix();
//bottles


glutSwapBuffers();
glutPostRedisplay();
      
}


void home()
{
   char* what[20] = {"What we want"};
 char* in[20]={"in our INDIA?"};
//char* l3[20]={"SURROUNDING CLEAN!"};
glLineWidth(2.5);
glPointSize(1);
glPushMatrix();
glTranslatef(50,380,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(what[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(540,380,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(in[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}





void cg6display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(1,0.2,0 ,1.0);
glLoadIdentity();

glPushMatrix();
glTranslated(600,100,0);
glScaled(0.8,0.8,0);
india();
glPopMatrix();

home();
glutSwapBuffers();
glutPostRedisplay();
      
}


void india()
{
  glColor3f( 	1.000, 0.647, 0.000);
glPointSize(5.0);
glBegin(GL_POINTS);

glVertex2f(500,450);
glVertex2f(500+p,450);
glVertex2f(500+3*p,450);
//glVertex2f(500,450);
glEnd();

glBegin(GL_POINTS);
for(i=0;i<30;i+=10)
{glVertex2f(500+p+i,450-p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<40;i+=10)
{glVertex2f(500+i,450-2*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<20;i+=10)
{glVertex2f(500+i+p,450-3*p);
}glEnd();


glBegin(GL_POINTS);
for(i=0;i<40;i+=10)
{glVertex2f(500+i+p,450-4*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<60;i+=10)
{glVertex2f(500+i-p,450-5*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<150;i+=10)
{glVertex2f(500+i-2*p,450-6*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<100;i+=10)
{glVertex2f(500+i-p,450-7*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<120;i+=10)
{glVertex2f(500+i-3*p,450-8*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<100;i+=10)
{glVertex2f(500+i-2*p,450-9*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<70;i+=10)
{glVertex2f(500+i,450-10*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<60;i+=10)
{glVertex2f(500+i,450-11*p);
}glEnd();
glBegin(GL_POINTS);
for(i=0;i<50;i+=10)
{glVertex2f(500+i,450-12*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<30;i+=10)
{glVertex2f(500+i+p,450-13*p);
glVertex2f(500+i+p,450-14*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<20;i+=10)
{glVertex2f(500+i+2*p,450-15*p);
}glEnd();

glBegin(GL_POINTS);
glVertex2f(500+2*p,450-16*p);
glEnd();


glBegin(GL_POINTS);
for(i=0;i<20;i+=10)
glVertex2f(500+12*p+i,450-4*p);
glEnd();

glBegin(GL_POINTS);
for(i=0;i<30;i+=10)
{
glVertex2f(500+11*p+i,450-5*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<30;i+=10)
{glVertex2f(500+10*p+i,450-7*p);
}glEnd();

glBegin(GL_POINTS);
for(i=0;i<20;i+=10)
{glVertex2f(500+10*p+i,450-8*p);
}glEnd();
glPointSize(1);
}



void citytext()
{
   char* what[20] = {"What we want"};
 char* in[20]={"in our CITY?"};
//char* l3[20]={"SURROUNDING CLEAN!"};
glLineWidth(2.5);
glPointSize(1);
glPushMatrix();
glTranslatef(50,380,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(what[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(540,380,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(in[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}






void cg7display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(1,0.2,0 ,1.0);
glLoadIdentity();

glPushMatrix();
glTranslatef(0,-80,0);
cg7buildings();
glPopMatrix();

glPushMatrix();
glTranslated(600,100,0);
glScaled(0.8,0.8,0);
india();
glPopMatrix();

glPushMatrix();
citytext();
glPopMatrix();

glutSwapBuffers();
glutPostRedisplay();
      
}


void cg7houses()
{
glColor3f(1.000, 0.471, 0.000 );
glRectf(100,100,250,350);
glRectf(255,100,370,300);
glRectf(100,355,250,375);
glRectf(215,380,250,400);
glRectf(370,100,410,130);
glRectf(400,100,510,270);
glRectf(510,100,530,170);
glRectf(530,100,630,320);


//windows
glColor3f(1,0.2,0 );
for(i=0;i<=210;i+=30)
{
glRectf(110,110+i,240,125+i);
}

for(i=0;i<=80;i+=40)
{
glRectf(420,150+i,445,180+i);
glRectf(470,150+i,495,180+i);

}

for(i=0;i<=160;i+=40)
{
glRectf(545,130+i,565,150+i);
glRectf(595,130+i,615,150+i);
}
}

void cg7buildings()
{
glPushMatrix();
cg7houses();
glPopMatrix();

glPushMatrix();
glTranslatef(540,0,0);
cg7houses();
glPopMatrix();

glPushMatrix();
glTranslatef(1000,-20,0);
cg7houses();
glPopMatrix();

glPushMatrix();
glTranslatef(-400,-20,0);
cg7houses();
glPopMatrix();
}



void hometext()
{
   char* what[20] = {"What we want"};
 char* in[20]={"in our HOME?"};
//char* l3[20]={"SURROUNDING CLEAN!"};
glLineWidth(2.5);
glPointSize(1);
glPushMatrix();
glTranslatef(50,380,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(what[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(540,380,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(in[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}

void cg8display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(1,0.2,0 ,1.0);
glLoadIdentity();

glPushMatrix();
glTranslated(600,100,0);
glScaled(0.8,0.8,0);
india();
glPopMatrix();
glPushMatrix();
hometext();
glPopMatrix();

for(hu=0;hu<1000;hu+=400)
{
glPushMatrix();
  glTranslatef(100+hu,0,0);
glScaled(2.0,1.0,0);
cg8hut();
glPopMatrix();
}

glutSwapBuffers();
glutPostRedisplay();
      
}

void cg8hut()
{

glColor3f(RGB(165,42,42));
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(50,200);
glVertex2f(100,150);
glVertex2f(100,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-32,110);
glVertex2f(-15,110);
glVertex2f(50,215);
glVertex2f(115,110);
glVertex2f(132,110);
glVertex2f(50,252);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(90,100);
glVertex2f(100,0);
glVertex2f(100,205);
glVertex2f(90,205);
glEnd();

//glPushMatrix();
glLineWidth(4);
glColor3f (RGB(205,51,51)); //houseroof
glBegin(GL_LINE_LOOP);
glVertex2f(-32,110);
glVertex2f(0,110);
glVertex2f(50,200);
glVertex2f(100,110);
glVertex2f(132,110);
glVertex2f(50,252);
glEnd();
//glPopMatrix();

glColor3f (RGB(228,0,0)); //glColor3f(RGB(142,56,142));
glBegin(GL_POLYGON);//window
glVertex2f(20,60);
glVertex2f(20,90);
glVertex2f(40,90);
glVertex2f(40,60);
glEnd();

glColor3f(RGB(165,42,42));//glColor3f (RGB(228,0,0)); //glColor3f(RGB(238,201,0));//window strip
glBegin(GL_LINE_STRIP);
glLineWidth(4);
glVertex2f(30,90);
glVertex2f(30,60);
glEnd();
//window strip
glBegin(GL_LINE_STRIP);
glLineWidth(6);
glVertex2f(20,75);
glVertex2f(40,75);
glEnd();

glColor3f(RGB(228,0,0));//glColor3f (RGB(238,99,99)); //glColor3f(RGB(142,56,142));//door
glBegin(GL_QUADS);
glVertex2f(60,7);
glVertex2f(60,80);
glVertex2f(85,80);
glVertex2f(85,7);
glEnd();
}


void cg9hut()
{

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(50,200);
glVertex2f(100,150);
glVertex2f(100,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-32,110);
glVertex2f(-15,110);
glVertex2f(50,215);
glVertex2f(115,110);
glVertex2f(132,110);
glVertex2f(50,252);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(90,100);
glVertex2f(100,0);
glVertex2f(100,205);
glVertex2f(90,205);
glEnd();

//glPushMatrix();
glLineWidth(4);
glColor3f (0.502, 0.000, 0.502); //houseroof
glBegin(GL_LINE_LOOP);
glVertex2f(-32,110);
glVertex2f(0,110);
glVertex2f(50,200);
glVertex2f(100,110);
glVertex2f(132,110);
glVertex2f(50,252);
glEnd();
//glPopMatrix();

glColor3f (0.502, 0.000, 0.502); //glColor3f(RGB(142,56,142));
glBegin(GL_POLYGON);//window
glVertex2f(20,60);
glVertex2f(20,90);
glVertex2f(40,90);
glVertex2f(40,60);
glEnd();

glColor3f(1,1,0);//glColor3f (RGB(228,0,0)); //glColor3f(RGB(238,201,0));//window strip
glBegin(GL_LINE_STRIP);
glLineWidth(4);
glVertex2f(30,90);
glVertex2f(30,60);
glEnd();
//window strip
glBegin(GL_LINE_STRIP);
glLineWidth(6);
glVertex2f(20,75);
glVertex2f(40,75);
glEnd();

glColor3f(0.502, 0.000, 0.502);//glColor3f (RGB(238,99,99)); //glColor3f(RGB(142,56,142));//door
glBegin(GL_QUADS);
glVertex2f(60,7);
glVertex2f(60,80);
glVertex2f(85,80);
glVertex2f(85,7);
glEnd();
}

void huttext()
{
   char* wew[20] = {" WE WANT"};
 char* bch[20]={"BEAUTIFUL, CLEAN AND HEALTHY"};
char* home[20]={"HOME"};
glLineWidth(2.5);
glPointSize(1);
glPushMatrix();
glTranslatef(50,380,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
glTranslatef(1640,720,0);
    printtext(wew[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(250,380,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(bch[0]);
glPopMatrix();


 glPushMatrix();
glTranslatef(640,330,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(home[0]);
glPopMatrix();
glFlush();
glutPostRedisplay();

}

void cg9display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.502, 0.000, 0.502 ,1.0);
glLoadIdentity();



glPushMatrix();
 glTranslatef(500,100,0);
glScaled(3.5,2.0,0);
cg9hut();
glPopMatrix();


glPushMatrix();
huttext();
glPopMatrix();

glutSwapBuffers();
glutPostRedisplay();
      
}



void healthycitytext()
{
glLineWidth(1.5);
char* wewant[20] = {"WE WANT"};
   char* bea[20] = {"BEAUTIFUL, CLEAN AND HEALTHY"};
char* city[20] = {"CITY"};
glColor3f(1.000, 0.843, 0.00);
glPointSize(1);
glPushMatrix();
glScalef(0.4,0.3,0);
glTranslatef(1450,2000,0);
printtext(wewant[0]);
glPopMatrix(); 

glColor3f(1.000, 1,1);
glPushMatrix();
glScalef(0.3,0.3,0);
glTranslatef(600,1500,0);
printtext(bea[0]);
glPopMatrix(); 

glPushMatrix();
glScalef(0.4,0.3,0);
glTranslatef(1530,1300,0);
printtext(city[0]);
glPopMatrix(); 

glFlush();
glutPostRedisplay();

}



void cg10houses()
{
glColor3f(0.9,0.9,0);
glRectf(100,100,250,350);
glRectf(255,100,370,300);
glRectf(100,355,250,375);
glRectf(215,380,250,400);
glRectf(370,100,410,130);
glRectf(400,100,510,270);
glRectf(510,100,530,170);
glRectf(530,100,630,320);


//windows
glColor3f(0.502, 0.000, 0.502);
for(i=0;i<=210;i+=30)
{
glRectf(110,110+i,240,125+i);
}

for(i=0;i<=80;i+=40)
{
glRectf(420,150+i,445,180+i);
glRectf(470,150+i,495,180+i);

}

for(i=0;i<=160;i+=40)
{
glRectf(545,130+i,565,150+i);
glRectf(595,130+i,615,150+i);
}
}



void cg10buildings()
{
glPushMatrix();
cg10houses();
glPopMatrix();

glPushMatrix();
glTranslatef(540,0,0);
cg10houses();
glPopMatrix();

glPushMatrix();
glTranslatef(1000,-20,0);
cg10houses();
glPopMatrix();

glPushMatrix();
glTranslatef(-400,-20,0);
cg10houses();
glPopMatrix();
}


void cg10display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.502, 0.000, 0.502,1.0);
glLoadIdentity();
glPushMatrix();
glTranslatef(0,-80,0);
cg10buildings();
glPopMatrix();
healthycitytext();

glFlush();
glutSwapBuffers();
glutPostRedisplay();
     
}



void sicktext()
{
   char* we[20] = {"WE WANT"};
 char* no[20]={"NO ONE TO GET SICK"};
//char* l3[20]={"SURROUNDING CLEAN!"};
glLineWidth(2);
glPointSize(1);
glPushMatrix();
glTranslatef(450,590,0);
glScalef(0.4,0.4,0);

 glColor3f(1,1,1);
    printtext(we[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(350,530,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(no[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}


void cg12houses()
{
glColor3f( 0.194, 0.000, 0.310);
glRectf(100,100,250,350);
glRectf(255,100,370,300);
glRectf(100,355,250,375);
glRectf(215,380,250,400);
glRectf(370,100,410,130);
glRectf(400,100,510,270);
glRectf(510,100,530,170);
glRectf(530,100,630,320);


//windows
//glColor3f(0.502, 0.000, 0.502);
glColor3f(0.294, 0.000, 0.510);
for(i=0;i<=210;i+=30)
{
glRectf(110,110+i,240,125+i);
}

for(i=0;i<=80;i+=40)
{
glRectf(420,150+i,445,180+i);
glRectf(470,150+i,495,180+i);

}

for(i=0;i<=160;i+=40)
{
glRectf(545,130+i,565,150+i);
glRectf(595,130+i,615,150+i);
}
}

void cg12buildings()
{
glPushMatrix();
cg12houses();
glPopMatrix();

glPushMatrix();
glTranslatef(540,0,0);
cg12houses();
glPopMatrix();

glPushMatrix();
glTranslatef(1000,-20,0);
cg12houses();
glPopMatrix();

glPushMatrix();
glTranslatef(-400,-20,0);
cg12houses();
glPopMatrix();
}
void cg12display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.294, 0.000, 0.510,1.0);
glLoadIdentity();

glPushMatrix();
glTranslatef(0,100,0);
cg12buildings();
glPopMatrix();

glPushMatrix();
glTranslatef(20,0,0);
grass();
glPopMatrix();

glPushMatrix();
glTranslatef(-90,30,0);
grass();
glPopMatrix();

glPushMatrix();
glTranslatef(40,30,0);
grass();
glPopMatrix();

glPushMatrix();
glTranslatef(200,-350,0);
//glScalef(1,0.8,0);
_3ppl();
glPopMatrix();
glPushMatrix();
glTranslatef(400,-50,0);
cloud();
glPopMatrix();
glPushMatrix();
glScalef(2.5,2.5,0);
glTranslatef(0,50,0);
cow();
glPopMatrix();
glPushMatrix();
glTranslatef(750,0,0);
tree();
glPopMatrix();
glPushMatrix();
glTranslatef(-600,0,0);
cloud();
glPopMatrix();
sicktext();
glutSwapBuffers();
glutPostRedisplay();
      
}


void dusttext()
{
   char* throw1[20] = {"Throw garbage in"};
 char* bin[20]={"DUSTBIN"};
glLineWidth(5);
glPointSize(1);
//char* l3[20]={"SURROUNDING CLEAN!"};
glPushMatrix();
glTranslatef(250,380,0);
glScalef(0.3,0.5,0);

 glColor3f(1.000, 0.843, 0.000);
    printtext(throw1[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(530,300,0);
glScalef(0.3,0.5,0);


    printtext(bin[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}


void wasteman()
{
 glColor3f(1,1,1);
glBegin(GL_POLYGON);//body
glVertex2f(300,300);
glVertex2f(369,295);
glVertex2f(365,190);
glVertex2f(300,200);
glEnd();

glRectf(300,100,327,200);//lftleg
cir(l1,l2,lr);
glRectf(338,100,365,200);//rtleg
cir(rr1,rr2,rr);
glBegin(GL_POLYGON);
glVertex2f(300,300);
glVertex2f(305,285);
glVertex2f(375,305);
glVertex2f(372,320);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(372,320);
glVertex2f(442,355);
glVertex2f(427,340);
glVertex2f(375,305);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(340,300);
glVertex2f(340,285);
glVertex2f(390,275);
glVertex2f(400,290);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(390,275);
glVertex2f(435,315);
glVertex2f(445,325);
glVertex2f(380,285);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(407,345);
glVertex2f(452,370);
glVertex2f(492,350);
glVertex2f(430,305);
glEnd();

cir(hd1,hd2,hdr);

glRectf(500,250,520,270);
glRectf(480,280,490,290);
glRectf(530,280,540,290);
glRectf(485,230,500,245);
glRectf(530,220,540,230);
}

void dustbin2()
{
glColor3f(1.000, 0.843, 0.000);
glRectf(500,400,650,410);

glBegin(GL_POLYGON);
glVertex2f(510,400);
glVertex2f(640,400);
glVertex2f(625,190);
glVertex2f(525,190);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(640,410);
glVertex2f(660,510);
glVertex2f(670,508);
glVertex2f(650,410);
glEnd();

glColor3f(0.545, 0.000, 0.545);
cir(x1,y01,r1);

glColor3f(1.000, 0.843, 0.000);
cir(x1,y01,r2);


}


void cg14display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.545, 0.000, 0.545,1.0);
glLoadIdentity();
glPushMatrix();
glTranslatef(600,-100,0);
dustbin2();
glPopMatrix();

glPushMatrix();
glTranslatef(650,100,0);
wasteman();
glPopMatrix();

glPushMatrix();
dusttext();
glPopMatrix();

glPushMatrix();
glTranslatef(860,180,0);
glScalef(.5,.5,0);
pcover1();
glPopMatrix();

glPushMatrix();
glTranslatef(680,120,0);
pcover();
glPopMatrix();

glPushMatrix();
glTranslatef(1050,250,0);
glScalef(.5,.5,0);
bottle1();
glPopMatrix();


glPushMatrix();
glTranslatef(1000,250,0);
glScalef(.6,.6,0);
bottle2();
glPopMatrix();

glutSwapBuffers();
glutPostRedisplay();
      
}


void cg18display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.545, 0.000, 0.545,1.0);
glLoadIdentity();
publictext();
glPushMatrix();
glTranslatef(700,-200,0);
man1();
glPopMatrix();
glPushMatrix();
glTranslatef(700,-240,0);
dustbin1();
glPopMatrix();
glutSwapBuffers();
glutPostRedisplay();
      
}



void dustbin1()
{
glLineWidth(5);
glColor3f(1.000, 0.843, 0.000);
glBegin(GL_LINE_LOOP);
glVertex2f(300,300);
glVertex2f(400,300);
glVertex2f(415,450);
glVertex2f(285,450);
glEnd();

glBegin(GL_LINES);
for(l=0;l<=100;l+=15)
{
glVertex2f(300+l,300);
glVertex2f(300+3+l,450);
}
glEnd();


glBegin(GL_LINES);

for(l=0;l<=15;l+=2)
{glVertex2f(300-l,300+l*10);
glVertex2f(400+l,300+l*10);
}
glEnd();

}

void man1()
{

glBegin(GL_TRIANGLES);//hand
glColor3f(1,1,1);


glVertex2f(350,520);
glVertex2f(500,520);
glVertex2f(480,490);
glEnd();


glBegin(GL_TRIANGLES);//rghtlg

glVertex2f(550,430);
glVertex2f(540,300);
glVertex2f(510,425);
glEnd();



glBegin(GL_POLYGON);//body


glVertex2f(500,520);
glVertex2f(455,500);
glVertex2f(490,420);
glVertex2f(550,430);
glEnd();

glBegin(GL_POLYGON);//lftlg

glVertex2f(490,420);
glVertex2f(530,427);
glVertex2f(480,300);
glEnd();

cir(xm,ym,rm1);


glBegin(GL_POLYGON);//paper
glColor3f(1.000, 0.843, 0.000);
glVertex2f(350,500);
glVertex2f(380,460);
glVertex2f(360,420);
glVertex2f(320,450);
glEnd();

}



void publictext()
{
   char* usep[20] = {"Use PUBLIC DUSTBIN"};
 char* inp[20]={"in PUBLIC place"};
//char* l3[20]={"SURROUNDING CLEAN!"};
glLineWidth(5);
glPointSize(1);
glPushMatrix();
glTranslatef(150,380,0);
glScalef(0.3,0.5,0);

 glColor3f(1.000, 0.843, 0.000);
    printtext(usep[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(230,300,0);
glScalef(0.3,0.5,0);


    printtext(inp[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}

void recycletext()
{
   char* thr[20] = {"Throw recycle things in"};
 char* re[20]={"recycle box"};
glLineWidth(5);
glPointSize(1);
//char* l3[20]={"SURROUNDING CLEAN!"};
glPushMatrix();
glTranslatef(-450,380,0);
glScalef(0.3,0.5,0);

 glColor3f(1.000, 0.843, 0.000);
    printtext(thr[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(-85,260,0);
glScalef(0.3,0.5,0);


    printtext(re[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}



void cg19display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.545, 0.000, 0.545,1.0);
glLoadIdentity();

glPushMatrix();
glTranslatef(790,50,0);
bottle2();
glPopMatrix();


glPushMatrix();
glScaled(1.3,1.1,0);
glTranslatef(300,-150,0);
dustbin2();
glPopMatrix();



glPushMatrix();
glTranslatef(550,100,0);
pcover1();
glPopMatrix();

glPushMatrix();
glTranslatef(550,100,0);
recycletext();
glPopMatrix();

glPushMatrix();
glTranslatef(570,190,0);
pcover();
glPopMatrix();

glPushMatrix();
glScaled(0.5,.5,0);
glTranslatef(1960,400,0);
bottle1();
glPopMatrix();

glutSwapBuffers();
glutPostRedisplay();
      
}


void cg20display(void)
{ 
 int c;
 glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.502, 0.000, 0.502,1);
glMatrixMode(GL_MODELVIEW);
	//glShadeModel(GL_SMOOTH);
	glLoadIdentity();
glPushMatrix();
glTranslatef(0,100,0);
cg20buildings();
glPopMatrix();
hutpath();
yardtext();
glPushMatrix();
  glTranslatef(500,200,0);
glScaled(2.5,1.5,0);
cg20hut();
glPopMatrix();

glPushMatrix();
glTranslatef(600,0,0);
tree();
glPopMatrix();

glPopMatrix();
glutSwapBuffers();

      glutPostRedisplay();
}


void nationtext()
{
   char* what[20] = {"Can we do it for our NATION?"};
 char* que[20]={"?"};
glLineWidth(5);
glPointSize(1);//char* l3[20]={"SURROUNDING CLEAN!"};
glPushMatrix();
glTranslatef(200,180,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(what[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(540,380,0);
glScalef(0.3,0.3,0);

 glColor3f( 	0.118, 0.565, 1.000);
glLineWidth(2);
glTranslatef(115,-100,0);
glScalef(5,5,0);
    printtext(que[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}

void cg21display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor( 	0.118, 0.565, 1.000,1);
glLoadIdentity();
glPushMatrix();
glColor3f(1,1,1);
cir(nn1,nn2,nnr);
glPopMatrix();

nationtext();
glutSwapBuffers();
glutPostRedisplay();
      
}

void yardtext()
{int a=580,c=0;
   char* cln_yard[20] = {"Clean Your Courtyard"};
glLineWidth(2);
glPointSize(1);
glColor3f(1.000, 0.843, 0.00);
glPushMatrix();
glScalef(0.3,0.3,0);
glTranslatef(900,2000,0);
printtext(cln_yard[0]);
glPopMatrix(); 
glFlush();
glutPostRedisplay();

}
void hutpath()
{
//path

glColor3f(1.000, 1,1);
glBegin(GL_POLYGON);
glVertex2f(640,200);
glVertex2f(720,200);
glVertex2f(820,0);
glVertex2f(540,0);


glEnd();

}
void cg20hut()
{


glColor3f(1.000, 0.843, 0.00);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(50,200);
glVertex2f(100,150);
glVertex2f(100,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-32,110);
glVertex2f(-15,110);
glVertex2f(50,215);
glVertex2f(115,110);
glVertex2f(132,110);
glVertex2f(50,252);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(90,100);
glVertex2f(100,0);
glVertex2f(100,205);
glVertex2f(90,205);
glEnd();

//glPushMatrix();
glLineWidth(4);
glColor3f (0.302, 0.000, 0.302); //houseroof
glBegin(GL_LINE_LOOP);
glVertex2f(-32,110);
glVertex2f(0,110);
glVertex2f(50,200);
glVertex2f(100,110);
glVertex2f(132,110);
glVertex2f(50,252);
glEnd();
//glPopMatrix();

glColor3f (0.302, 0.000, 0.302); //glColor3f(RGB(142,56,142));
glBegin(GL_POLYGON);//window
glVertex2f(20,60);
glVertex2f(20,90);
glVertex2f(40,90);
glVertex2f(40,60);
glEnd();

glColor3f(1.000, 0.843, 0.00);//glColor3f (RGB(228,0,0)); //glColor3f(RGB(238,201,0));//window strip
glBegin(GL_LINE_STRIP);
glLineWidth(4);
glVertex2f(30,90);
glVertex2f(30,60);
glEnd();
//window strip
glBegin(GL_LINE_STRIP);
glLineWidth(6);
glVertex2f(20,75);
glVertex2f(40,75);
glEnd();

glColor3f(0.302, 0.000, 0.302);//glColor3f (RGB(238,99,99)); //glColor3f(RGB(142,56,142));//door
glBegin(GL_QUADS);
glVertex2f(60,7);
glVertex2f(60,80);
glVertex2f(85,80);
glVertex2f(85,7);
glEnd();
}

void cg20houses()
{
glColor3f(0.302, 0.000, 0.302);
glRectf(100,100,250,350);
glRectf(255,100,370,300);
glRectf(100,355,250,375);
glRectf(215,380,250,400);
glRectf(370,100,410,130);
glRectf(400,100,510,270);
glRectf(510,100,530,170);
glRectf(530,100,630,320);


//windows
glColor3f(0.502, 0.000, 0.502);
for(i=0;i<=210;i+=30)
{
glRectf(110,110+i,240,125+i);
}

for(i=0;i<=80;i+=40)
{
glRectf(420,150+i,445,180+i);
glRectf(470,150+i,495,180+i);

}

for(i=0;i<=160;i+=40)
{
glRectf(545,130+i,565,150+i);
glRectf(595,130+i,615,150+i);
}
}



void cg20buildings()
{
glPushMatrix();
cg20houses();
glPopMatrix();

glPushMatrix();
glTranslatef(540,0,0);
cg20houses();
glPopMatrix();

glPushMatrix();
glTranslatef(1000,-20,0);
cg20houses();
glPopMatrix();

glPushMatrix();
glTranslatef(-400,-20,0);
cg20houses();
glPopMatrix();
}


void cg22semicir(float xc,float yc,float r)
{
float i,angle=0;
//glColor3f(0.0,0.0,0.0);
glPointSize(3.5);
glBegin(GL_POINTS);
for(i=180;i<360;i+=1)
{
angle=3.14/180*i;
glVertex2f(xc+cos(angle)*r,yc+sin(angle)*r);
}
glEnd();
glFlush();
glutPostRedisplay();
}



void svcantext()
{
   char* clean[20] = {"Clean India"};
 char* yes[20]={"YES WE CAN!"};
//char* l3[20]={"SURROUNDING CLEAN!"};
glLineWidth(5);
glPointSize(1);
glPushMatrix();
glTranslatef(450,380,0);
glScalef(0.3,0.5,0);

 glColor3f(1,1,1);
    printtext(clean[0]);
glPopMatrix();

 glPushMatrix();
glTranslatef(450,330,0);
glScalef(0.3,0.3,0);

 glColor3f(1,1,1);
    printtext(yes[0]);
glPopMatrix();

glFlush();
glutPostRedisplay();

}






void cg22display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(0.118, 0.565, 1.000 ,1.0);
glLoadIdentity();
glColor3f(1,1,1);
glPushMatrix();
glTranslated(450,200,0);
glScaled(0.7,0.7,0);

india();
glPopMatrix();

svcantext();

glRectf(450,370,800,375);
cir(sm1,sm2,rm);
cir(sm1+100,sm2,rm);
cg22semicir(h1,h2,hr);
glutSwapBuffers();
glutPostRedisplay();
      
}


void tricolor()
{




	//orange
	glColor3f(1,0.647,0);
	glRectf(0,520,1600,1000);	

	
	glColor3f(1,1,1);
glRectf(0,180,1600,520);


//green
glColor3f(0,0.502,0);
glRectf(0,0,1600,180);

//saffron
	glColor3f(1,0.647,0);
glRectf(450,368,570,373);

//green small
	glColor3f(0,0.502,0);
glRectf(450,358,570,363);

circle_draw(sbxc,sbyc,sbr);
circle_draw(sbxc+420,sbyc,sbr);
//circle_draw(xc1,yc1,r1);
circle_draw1(sbxc2,sbyc2,sbr2);
circle_draw1(sbxc3,sbyc3,sbr3);

//poly();
//poly1();

glPushMatrix();

//glTranslatef(870,0,0);
line();
glPopMatrix();
glPushMatrix();
line1();
glPopMatrix();
glPushMatrix();

sbtext();
glPopMatrix();
glFlush();
glutPostRedisplay();
}

void circle_draw1(int xc,int yc,int r)
{
float i,angle=0;
glColor3f(0.0,0.0,0.0);
glPointSize(3.5);
glBegin(GL_POINTS);
for(i=0;i<90;i+=1)
{
angle=3.14/180*i;
glVertex2f(xc+cos(angle)*r,yc+sin(angle)*r);
}
glEnd();
glFlush();
glutPostRedisplay();
}
void line1()
{
glLineWidth(3.5);
glBegin(GL_LINES);
	//green
	glColor3f(0,0,0);
	glVertex2f(870,370);
	glVertex2f(1300,520);//540
	

	glEnd();
glFlush();
glutPostRedisplay();
}
void line()
{
glLineWidth(3.5);
glBegin(GL_LINES);
	//green
	glColor3f(0,0,0);
	glVertex2f(150,370);
	glVertex2f(680,540);
	

	glEnd();
glFlush();
glutPostRedisplay();}

void printtext1(/*void* font,*/ char* s)
{

      while (*s) {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,*s);       
// glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, *s);
         s++;
      }
  
}
void sbtext()
{
   char* ek[20] = {"EK KHADHAM SWACHHATA KI ORE"};
 char* swach[10]={"SWACHH"};
char* bharat[10]={"BHARAT"};

   GLfloat x, y, ystep, yild, stroke_scale;


   glColor3f(0,0,0);

glRasterPos2f(390,190);

 printtext1(ek[0]);

glRasterPos2f(230,370);
//glScalef(170,370,0);

     printtext1(swach[0]);

glRasterPos2f(660,370);

     printtext1(bharat[0]);
glFlush();
glutPostRedisplay();

}
void circle_draw(int xc,int yc,int r)
{
float i,angle=0;
glColor3f(0.0,0.0,0);
glBegin(GL_LINE_LOOP);
for(i=0;i<360;i+=10)
{
angle=3.14/180*i;
glVertex2f(xc+cos(angle)*r,yc+sin(angle)*r);
}
glEnd();
glFlush();
glutPostRedisplay();
}

void cg1display(void)
{ 
 
 glClear(GL_COLOR_BUFFER_BIT);
  
glClearColor(1.0,1.0,1.0,1.0);
glLoadIdentity();
tricolor();
//sbtext();

glutSwapBuffers();
//glutPostRedisplay();
      
}


void cg17sky()
{
glBegin(GL_POLYGON);  //sky
glColor3f(RGB(142,56,142));  
 glVertex2f (0,251); 
 //glColor3f(RGB(0,0,0)); 
   glVertex2f (0,1000);
//glColor3f(RGB(0,0,0));
   glVertex2f (1700,1000); 
  // glColor3f(RGB(142,56,142)); 
   glVertex2f (1700,251); 
    glEnd();
}
void garbagevantext()
{
glLineWidth(2);
glPointSize(1);
char* gvan[20]={"USE GARBAGE VEHICLE"};
glColor3f(1,1,1);
glPushMatrix();//text
glTranslatef(100,550,0);
glScalef(.41,.41,0);
glLineWidth(1.5);
printtext(gvan[0]);
glPopMatrix();

}

void cg17road()
{
glBegin(GL_POLYGON);  //road
glColor3f (RGB(0,0,0));  
 glVertex2f (0,0); 
   glVertex2f (0,261);
   glVertex2f (1700,261); 
   glVertex2f (1700,0); 
    glEnd();

for(int i=0;i<15;i++) //road divider lane
{
glPushMatrix();
glTranslatef(i*100,100,0);
glRotatef(15,1,0,1);
glColor3f(1,1,1);
glScalef(.5,.2,1);
cg17square();
glPopMatrix();
}

}


void cg17van()
{
//////////////////////////////////////////////////////
glPushMatrix();
glTranslatef(dist,0,0);
glScalef(3,3,3);
glTranslatef(200,50,0);
glColor3f(RGB(0,100,0));
cg17truck();
//glCallList(TRUCK);
glPushMatrix();
glTranslatef(50,5,0);
glScalef(2,2,2);
glPushMatrix();
glRotatef(ang,0,0,1);
cg17tyre();
//glCallList(cg17tyre);
glPopMatrix();
glColor3f(RGB(60,179,113));
cg17mudg();
//glCallList(MUDG);
glPopMatrix();
glPushMatrix();
glTranslatef(140,5,0);
glScalef(2,2,2);
glPushMatrix();
glRotatef(ang,0,0,1);

cg17tyre();
//glCallList(TYRE);
glPopMatrix();
glColor3f(RGB(60,179,113));
cg17mudg();
//glCallList(MUDG);
glPopMatrix();



}
void cg17tyre()
{
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

}

void cg17mudg()
{
glColor3f(RGB(60,179,113)); //mud guard
glBegin(GL_QUADS);
for(int theta=0;theta<=180;theta+=1)
    {
      glVertex2f(3*cos(theta*val),3*sin(theta*val));
      glVertex2f((8)*cos(theta*val),(8)*sin(theta*val));
      
    }
glEnd();
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void cg17truck()
{
char* bbmp[16]={"BBMP"};
//body
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
cg17square();//glCallList(SQUARE);orange
glPopMatrix();
glColor3f(RGB(0,100,0));

glColor3f(RGB(205,200,177));
glPushMatrix();
glTranslatef(130,35,0);
glScalef(.2,.16,0);
//glCallList(SQUARE);
cg17square();//window blue
glPopMatrix();
glColor3f(RGB(0,100,0));

glColor3f(1,1,1);
glPushMatrix();//board
glTranslatef(50,35,0);
glScalef(.5,.15,0);
cg17square();//white board
glColor3f(0,0,0);
glTranslatef(5,20,0);
glScalef(.2,.4,0);
printtext(bbmp[0]);
glPopMatrix();
glColor3f(RGB(0,100,0));

for( i=0;i<3;i++)//strip
{
  glPushMatrix();
  glPushMatrix();
glTranslatef(60+i*15,50,0);
glScalef(.05,.15,0);
cg17square();//topsquares
//glCallList(SQUARE);
glPopMatrix();
  glPopMatrix();

}
///back
//glPushMatix();
glColor3f(RGB(218,165,32));
glBegin(GL_POLYGON);
glVertex2f(0,5);
glVertex2f(25,60);
glVertex2f(45,60);
glVertex2f(20,5);
glEnd();

//glEnd();


}
void cg17square()
{
glBegin(GL_QUADS);
  glVertex2f(0,0);
  glVertex2f(0,100);
  glVertex2f(100,100);
  glVertex2f(100,0);
  glEnd();
}

void cg17houses()
{
glColor3f(0.018, 0.465, 0.70);
glRectf(100,100,250,350);
glRectf(255,100,370,300);
glRectf(100,355,250,375);
glRectf(215,380,250,400);
glRectf(370,100,410,130);
glRectf(400,100,510,270);
glRectf(510,100,530,170);
glRectf(530,100,630,320);


//windows
//glColor3f(0.502, 0.000, 0.502);
glColor3f(0.118, 0.565, 1.000);
for(i=0;i<=210;i+=30)
{
glRectf(110,110+i,240,125+i);
}

for(i=0;i<=80;i+=40)
{
glRectf(420,150+i,445,180+i);
glRectf(470,150+i,495,180+i);

}

for(i=0;i<=160;i+=40)
{
glRectf(545,130+i,565,150+i);
glRectf(595,130+i,615,150+i);
}
}

void cg17buildings()
{
glPushMatrix();
cg17houses();
glPopMatrix();

glPushMatrix();
glTranslatef(540,0,0);
cg17houses();
glPopMatrix();

glPushMatrix();
glTranslatef(1000,-20,0);
cg17houses();
glPopMatrix();

glPushMatrix();
glTranslatef(-400,0,0);
//glTranslatef(-400,-20,0);
cg17houses();
glPopMatrix();
}

void cg17display(void)
{
	//static int dist=0,ang=0;
   //int i;  
 glClear (GL_COLOR_BUFFER_BIT);
glPushMatrix();
cg17sky();
glPopMatrix();
glPushMatrix();
glTranslatef(0,100,0);
cg17buildings();
glPopMatrix();
glPushMatrix();
cg17road();
glPopMatrix();
glPushMatrix();
cg17van();
glPopMatrix();


glPushMatrix();
garbagevantext();
glPopMatrix();

glutSwapBuffers();
}
/*
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

void strokeText(const char *txt,int x,int y)
{ int i;
  glRasterPos2f(x,y);
  for(i=0;i<strlen(txt);i++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,txt[i]);
}
void p4house()
{
glPushMatrix();//house
glTranslatef(170,252,0);
glScalef(.85,.6,0);
hutt();
//glCallList(HOUSE);
glPopMatrix();
}


void lawn1()
{
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
  lawn();
//glCallList(LAWN);
  glPopMatrix();
  glTranslatef(20,0,0);

}
glPopMatrix();

}

void lane()
{
for(int i=0;i<15;i++) //lane
{
glPushMatrix();
glTranslatef(i*100,100,0);
glColor3f(1,1,1);
glScalef(.5,.2,1);
square();
//glCallList(SQUARE);
glPopMatrix();
}

//shape=9;
}
//#define PAVEMENT 434535

void pavement()
{
//glNewList(PAVEMENT,GL_COMPILE_AND_EXECUTE);
glPushMatrix();
glColor3f(RGB(139,76,57));
glTranslatef(-25,230,0);
for(int i=0;i<50;i++)
{
  glPushMatrix();
glScalef(.4,.3,1);
pav2();
//glCallList(PAVEMENT2);
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
pav1();
//glCallList(PAVEMENT1);
glPopMatrix();
glTranslatef(35,0,0);
}
glPopMatrix();
//glEndList();
}
void pav(){
glPushMatrix();
glTranslatef(0,-20,0);
pavement();
//glCallList(PAVEMENT);
glPopMatrix();
}

void p4tree()
{

glPushMatrix();
glColor3f(0,1,0);
glTranslatef(100,405,0);
glScalef(3,3,3);
treee();
//glCallList(TREE);
glPopMatrix();
}
//////////////////////////////////////////////////
void waste()
{
if(garbageFull)
{
  // printf("%d",garbageFull);
glPushMatrix();
glTranslatef(xpos,ypos,0);
paper();
glPopMatrix();
glPushMatrix();
glTranslatef(xbpos,ybpos,0);
// paper();
bn();
glPopMatrix();
}
}
////////////////////////////////////////////////////////////
void drybin()
{
glPushMatrix();//dry dustbin
glTranslatef(480,80,0);
glColor3f(1,0,0);
glScalef(.75,.75,0);
glLineWidth(6.5);
binn();
//glCallList(BIN);
glColor3f(0,0,0);
glPopMatrix();


glColor3f(1,1,1);
glPushMatrix();//board
glTranslatef(610,250,0);
glScalef(.4,.15,0);
square();
//glCallList(SQUARE);
glColor3f(0,0,0);
glTranslatef(5,20,0);
glScalef(.2,.4,0);
strokeText(" DRY",0,0);
glPopMatrix();
glColor3f(RGB(0,100,0));
}

void wetbin()
{

glColor3f(0,01,0);//wet dustbin
glPushMatrix();
// glRotatef(45,0,01,0);
glTranslatef(540,80,0);
glScalef(.75,.75,0);
binn();
//glCallList(BIN);
glPopMatrix();


glColor3f(1,1,1);
glPushMatrix();//board
glTranslatef(670,250,0);
glScalef(.4,.15,0);
square();
//glCallList(SQUARE);
glColor3f(0,0,0);
glTranslatef(5,20,0);
glScalef(.2,.4,0);
strokeText(" WET",0,0);
glPopMatrix();
glColor3f(RGB(0,100,0));

}



void treee()
{
//glNewList(TREE,GL_COMPILE);//tree
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
//glEndList();
}

void pav1()
{
//glNewList(PAVEMENT1 , GL_COMPILE);
glBegin(2);
  glVertex2f(0,0);
  glVertex2f(35,40);
  glVertex2f(85,40);
  glVertex2f(50,0);
  glEnd();
//glEndList();
}
void pav2()
{
//glNewList(PAVEMENT2 , GL_COMPILE);
glBegin(9);
  glVertex2f(0,0);
  glVertex2f(35,40);
  glVertex2f(85,40);
  glVertex2f(50,0);
  glEnd();
//glEndList();
}
void lawn()
{
//glNewList(LAWN,GL_COMPILE);
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
//glEndList();
}


void circledraw(int xr,int yr)
{
float i,angle=0;
// glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_STRIP);
for(int theta=0;theta<360;theta++)
{
    glVertex2f( xr*cos(theta*val) ,yr*sin(theta*val));
}
glEnd();
}

void binn()
{
//glNewList(BIN,GL_COMPILE);
glPushMatrix();
// glRotatef(30,1,0,0);
glLineWidth(2);
glTranslatef(200,200,0);
for( i=0;i<20;i+=3)
{
  // if(i==0)glPolygonMode(GL_FRONT,GL_FILL);else glPolygonMode(GL_FRONT,GL_POINTS);
  glTranslatef(0,10,0);
  circledraw(20+i,10);
}
glLineWidth(1);
glPopMatrix();
//glEndList();
}


void hutt()
{
//glNewList(HOUSE,GL_COMPILE);//house
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
//glEndList();
}

void p4display(void)
{
  // static int dist=0,ang=0;
   int i;   glClear (GL_COLOR_BUFFER_BIT);
glPushMatrix();
sky();
glPopMatrix();

glPushMatrix();
lane();
glPopMatrix();

glPushMatrix();
lawn1();
glPopMatrix();

glPushMatrix();
pav();
glPopMatrix();

glPushMatrix();
p4tree();
glPopMatrix();

glPushMatrix();
waste();
glPopMatrix();


glPushMatrix();
drybin();
wetbin();
glPopMatrix();


glPushMatrix();
van();
glPopMatrix();


glPushMatrix();
p4house();
glPopMatrix();
glutSwapBuffers();
}*/
