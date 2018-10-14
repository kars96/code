#include <string.h>
#include<stdlib.h>
#include<stdarg.h>
#include <GL/glut.h>
#include<stdio.h> 
#include<math.h>
#define TEXTID 5
#define TIMER 10

char s[500]="DECISION";
char *message = s; 
GLUquadricObj *quad;
GLfloat angle, angle1,outwicangle=-90.0,outbailangle=0.0,outbailx=1.57,outbaily=.12,outwicz=0.5;int ang=0;;
static GLfloat move=0.0,moves=-0.3,a=0,b=0,movef=-0.3, movey=.1;
static GLdouble displace=0.1;
int temp,f=0;
int disp,mess=0,stop=0;
int red=1.0, green=1.0,blue=1.0;
int redf=1.0, greenf=1.0,bluef=1.0;
float fog=0.0,r=0,g=0,bl=0,x=-2.3,y=-0.2,z=-2.0;

void front();
void outfunc();
void notoutfunc();
void pendingfunc();
void display(void);
void pitch();
void pitch()
{
GLfloat matamb97[]={0.0, green, 0.0,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb97);
//glScalef(2.0,2.0,2.0);
glutSolidCube(1.2);

}
void lite()
{
	glTranslated(0.0,0.5,0.0);
	GLfloat matamb97[]={red, green, blue,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb97);
	
		glutSolidSphere(0.09,100,100);
		
	glRotatef(a,b,a,b);
	glutWireCube(0.25);
}
		
void drawtext(double x, double y, double z, double scale, char * s)
{
		int i ;
		glPushMatrix();
		glTranslatef(x,y,z);
		glScalef(scale,scale,scale);
		for(i=0;i<(int)strlen(s);i++)
		{
				glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
		}
		glPopMatrix();
}


void sphere()
{
	glTranslated(move,movey,0.35);
	glColor3f(1.0,0.0,0.0);
	GLfloat matamb64[]={1.0f,0.0f,0.0f,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb64);
	glutSolidSphere(0.05,100,100);
}

void sphere2()
{
	glTranslated(moves,movey,0.35);
	glColor3f(1.0,0.0,0.0);
	GLfloat matamb69[]={1.0f,0.0f,0.0f,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb69);
	glutSolidSphere(0.05,100,100);
}

void sphere3()
{
	glTranslated(movef,-.25,0.35);//-.25
	glColor3f(1.0,0.0,0.0);
	GLfloat matamb69[]={1.0f,0.0f,0.0f,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb69);
	glutSolidSphere(0.05,100,100);
}

void keys (unsigned char keys, int x, int y)
{ 
    if(keys == 'c'||keys == 'C')
	{
		f=1;
    temp=0; 
    move=-0.75;
	mess=0;
	angle=0;
    message= "DECISION ";
    }

	if(keys == 'o'||keys == 'O')
	{
	temp=1;
	move=-0.75;
	angle=0;
	red=1;
	blue=1;
	green=1;
	mess=0;
	outwicangle=-90.0;
    outwicz=0.5;
	outbailx=1.57;
	outbaily=.12;
	outbailangle=0;
    message="  OUT";
	}

	if(keys == 'n'||keys == 'N')
	{
	temp=2;
	move=-0.75;
	mess=0;
	red=1;
	blue=0;
	green=1;
	angle=0;
    message="NOT OUT";
	}

	if(keys=='d'||keys=='D')
	{
	temp=0; 
    move=-0.75;
	mess=0;
	angle=0;
	red=1;
	blue=1;
	green=1;
    message= "DECISION ";
	}
}

void tick(void)
{
  glutPostRedisplay();
}


static void timer (int value)
{
	
	// move += 0.015; 
	move=sin(ang);
	movey=cos(ang);
	ang=(ang+1)%45;
	disp=0;
		if(move > 1.45) 
	{
		move = 1.45;
		disp=1;
		
	}

	moves += 0.015;  
	
	if(moves > 1.45) 
	{
		moves -= 2.4;
	
	}

   movef += 0.015;  
	
	if(movef > 1.0) 
	{
		movef -= 2.4;
        redf=0.0;
		greenf=1.0;
		bluef=0.0;
	}
	else if(movef>-0.2)
	{    
		redf=1.0;
		greenf=0.0;
		bluef=0.0;
	}
	a += 5;
	if(a > 360) a -= 360;
	b += 2;
	if(b > 360) b -= 360;

if(mess==1)	
	{	
   if(y>=0.3)
	{
      x=2.3;
	  y=0.2;
	  z=2.0;
	  stop=1;
   }
   if(stop==0)
   {
    x +=0.05;
	y +=0.009;
	z +=0.06;
   }
	
	}


    glutPostRedisplay ();
    glutTimerFunc (TIMER, timer, 0);

}

void displaymess()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
  glClearColor (r, g, bl, fog);
    glColor3f(1.0,1.0,0);
    glLoadName(TEXTID);
		
	
    drawtext(-1.4,.75,0,0.003,"THIRD UMPIRE");
 
    
    glColor3f(1.0,1.0,0);
    glLoadName(TEXTID);
	GLfloat matamb65[]={0.52f,.34f,0.7f,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb65);

    drawtext(-1.43,-.2,0,0.003,message);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	

	double winht=1.0;
	glOrtho(-winht,winht,-winht,winht,0.1,100.0); 

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x,y,z,0.0,0.25,0.0,0.0,1.0,0.0);
	glutSwapBuffers();
glFlush();
}

void message1( int id)

{

		switch(id)
		{
			
		case 1 :
		
			
			mess=1;
			stop=0;
			message="FANTABULOUS";
            x=-2.3;
	        y=-0.2;
	        z=-2.0;
			break;
		
		case 2 :
			{
			mess=1;
			stop=0;
			message="EXTRAORDINARY";
            x=-2.3;
	        y=-0.2;
	        z=-2.0;
			break;
			}
				
		case 3: 
			r=1.0;
			g=1.0;
			bl=1.0;
			fog=0.0;
			break;
		case 4:
            r=0.0;
			g=0.0;
			bl=0.0;
			fog=0.0;
			break;
		case 5:
            r=0.7;
			g=0.7;
			bl=0.7;
			fog=0.0;
			break;
       case 6:f=0;
			break;
       case 7:exit(0);
			break;
		}

}


void display(void)
{ 
  glClearColor(0.74902,0.847059,0.997059,1);
  //glClearColor (r, g, bl, fog);
	GLfloat matdif[]={0.7f,0.4f,0.2f,0.0f};
	GLfloat matspec[]={.0f,.0f,.0f,0.0f};
	GLfloat matshin[]={75.0f};
	
	glMaterialfv (GL_FRONT,GL_DIFFUSE,matdif);
	glMaterialfv (GL_FRONT,GL_SPECULAR,matspec);
	glMaterialfv (GL_FRONT,GL_SHININESS,matshin);

	GLfloat lightint[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat lightpos[]={18.0f,10.0f,1.0f,0.0f};
	glLightfv (GL_LIGHT0,GL_POSITION,lightpos);
	glLightfv (GL_LIGHT0,GL_DIFFUSE,lightint);
	
	glColor3f(1.0,0.0,0);
 glLoadName(TEXTID);
 GLfloat matamb54[]={1.0f,0.0f,0.0f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb54);
 drawtext(-1.05,.75,0,0.003,"THIRD UMPIRE");

 if (f==0)
	  front();
  else
  {  if(mess==1)
	    displaymess();

	 else if(temp==1)
	{
		outfunc();		
	}
	 else if(temp==2)
	{
		notoutfunc();		
	}
	 else if(temp==0)
	{   
		pendingfunc();
	}
    
  }

	
}


void front()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
glClearColor(0.7,0.8,0.997059,1);
  //glClearColor (r, g, bl, fog);
    //GLfloat matamb16[]={1.0f,1.0f,0.0f,1.0f};
	//glMaterialfv (GL_FRONT,GL_AMBIENT,matamb16);

    glColor3f(1.0,1.0,0);
	glLoadName(TEXTID);
	drawtext(-0.8,.9,0.0,0.0008,"COMPUTER GRARPHIC PROJECT");

	
	glLoadName(TEXTID);
	drawtext(-0.8,.55,0.0,0.0005,"PROJECT NAME");

    glLoadName(TEXTID);
	drawtext(-0.96,.40,0.0,0.0004,"' 3RD UMPIRE DISPLAY SCREEN '");
	
	glLoadName(TEXTID);
	drawtext(-0.9,0.0,0.0,0.0004,"PRESS KEY 'C' TO CONTINUE");


	
	glLoadName(TEXTID);
	drawtext(-1.0,-0.55,0.0,0.0004,"      BY : GAGANA V P");

	
	//glLoadName(TEXTID);
	//drawtext(-1.0,-0.6,0.0,0.0004,"USN : 1JS14CS025");

    glLoadName(TEXTID);
	drawtext(-1.0,-0.7,0.0,0.0004,"      BY : GRANTHALI SHASTRI");

	
	//glLoadName(TEXTID);
	//drawtext(-1.0,-0.75,0.0,0.0004,"USN : 1JS14CS029");

    glLoadName(TEXTID);
	drawtext(0.3,0.75,0.0,0.0004,"INSTRUCTIONS");

    glLoadName(TEXTID);
	drawtext(0.1,0.65,0.0,0.0004,"PRESS 'O' : OUT");

    glLoadName(TEXTID);
	drawtext(0.1,0.55,0.0,0.0004,"PRESS 'N' : NOT OUT");

    glLoadName(TEXTID);
	drawtext(0.1,0.45,0.0,0.0004,"PRESS 'D' : DECISION PENDING");

    glLoadName(TEXTID);
	drawtext(0.1,0.35,0.0,0.0004,"MOUSE ");

    glLoadName(TEXTID);
	drawtext(0.1,0.30,0.0,0.0004,"BUTTONS : DISPLAY MESSAGES");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	
	double winht=1.0;
	glOrtho(-winht,winht,-winht,winht,0.1,100.0); 

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	gluLookAt(0.0,0.2,2.0,0.0,0.25,0.0,0.0,1.0,0.0);

   
//ball
	glPushMatrix();
	sphere3();
	glPopMatrix();
	glPushMatrix();
//LITE
	glPushMatrix();
	 glTranslated(-0.1,0.7,0.0);
	GLfloat matamb97[]={redf, greenf, bluef,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb97);
	
		glutSolidSphere(0.09,100,100);
		
	glRotatef(a,b,a,b);
	glutWireCube(0.25);
    glPopMatrix();

//stumps
	glColor3f(1.0,1.0,1.0);
	glTranslated(0.4,-0.3,0.5);
	glRotatef(90.0,1.0,0.25,0.0);
	GLfloat matamb21[]={1.0f,1.f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb21);
	gluCylinder(quad,0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0,1.0,1.0);
	glTranslated(0.5,-0.3,0.5);
	glRotatef(90.0,1.0,0.05,0.0);
	GLfloat matamb31[]={0.0f,1.f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb31);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,0.0,1.0);
	glTranslated(0.65,-0.3,0.5);
	glRotatef(90.0,1.0,-0.25,0.0);
	GLfloat matamb41[]={1.0f,0.0f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb41);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();

//bails
	glPushMatrix();
	glColor3f(.3,1.0,.1);
	glTranslated(0.45,-0.3,0.48);
	glRotatef(-60,0.0,1.0,1.0);
	GLfloat matamb51[]={0.3f,1.f,.1f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb51);
	gluCylinder(quad, 0.02, 0.02, 0.1, 30, 30);
	glPopMatrix();
	

	glPushMatrix();
	glColor3f(.3,1.0,.1);
	glTranslated(.6,-0.3,0.5);
	glRotatef(-60,0.0,1.0,1.0);
	GLfloat matamb52[]={.3f,1.f,.1f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb52);
	gluCylinder(quad, 0.02, 0.02, 0.1, 30, 30);
	glPopMatrix();

	glutSwapBuffers();
		
    glFlush();
}


void pendingfunc()
{ 
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
glClearColor(0.74902,0.847059,0.997059,1);
  //glClearColor (r, g, bl, fog);
pitch();
    glColor3f(1.0,0.1,0);
    glLoadName(TEXTID);
		
	
    drawtext(-1.40,.75,0,0.003,"THIRD UMPIRE");
 
    glColor3f(1.0,1.0,0);
    glLoadName(TEXTID);
	GLfloat matamb61[]={1.0f,1.0f,0.0f,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb61);

    drawtext(-1.05,-.35,0,0.003,message);

    glColor3f(1.0,0.0,0);
    glLoadName(TEXTID);
	GLfloat matamb62[]={1.0f,1.0f,0.0f,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb62);

    drawtext(-1.05,-.70,0,0.003,"PENDING");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	

	double winht=1.0;
	glOrtho(-winht,winht,-winht,winht,0.1,100.0); 

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3,0.2,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
	
//ball
	glPushMatrix();
	sphere2();
	glPopMatrix();
	glPushMatrix();

	glPushMatrix();
	red=1;
	green=1;
	blue=0;
	 lite();
    glPopMatrix();
//stumps
	glColor3f(1.0,1.0,1.0);
	glTranslated(1.5,0.10,0.5);
	glRotatef(90.0,1.0,0.25,0.0);
	GLfloat matamb21[]={1.0f,1.f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb21);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0,1.0,1.0);
	glTranslated(1.6,0.10,.49);
	glRotatef(90.0,1.0,0.25,0.0);
	GLfloat matamb31[]={0.0f,1.f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb31);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,0.0,1.0);
	glTranslated(1.7,0.10,0.48);
	glRotatef(90.0,1.0,0.25,0.0);
	GLfloat matamb41[]={1.0f,0.0f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb41);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();

    if(move>1.45) 
	{
		angle +=-10.0;
	}
	
//bails
	glPushMatrix();
	glColor3f(.3,1.0,.1);
	glTranslated(1.73,0.12,0.48);
	glRotatef(angle,1.0,0.0,0.0);
	GLfloat matamb51[]={.3f,1.f,.1f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb51);

	gluCylinder(quad, 0.02, 0.02, 0.1, 30, 30);
	glPopMatrix();
	

	glPushMatrix();
	glColor3f(.3,1.0,.1);
	glTranslated(1.57,0.12,0.48);
	glRotatef(angle,0.5,0.0,0.0);
	GLfloat matamb52[]={.3f,1.f,.1f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb52);

	gluCylinder(quad, 0.02, 0.02, 0.1, 30, 30);
	glPopMatrix();
	
	glutSwapBuffers();
		
    glFlush();
}

void outfunc()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
glClearColor(0.74902,0.847059,0.997059,1);
 //glClearColor (r, g, bl, fog);
pitch();
 glColor3f(1.0,0.0,0);
 glLoadName(TEXTID);
 GLfloat matamb6[]={1.0f,0.f,0.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb6);
 drawtext(-1.40,.75,0,0.003,"THIRD UMPIRE");
 
 if(disp==1)
 {
 glColor3f(1.0,0.0,0);
 glLoadName(TEXTID);

 GLfloat matamb1[]={1.0f,0.0f,0.0f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb1);
 drawtext(-1.05,-.5,0,0.003,message);	
 }
	  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

	double winht=1.0;
	glOrtho(-winht,winht,-winht,winht,0.1,100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3,0.2,2.0,0.0,0.25,0.0,0.0,1.0,0.0);


//lite
	glPushMatrix();
	 lite();
    glPopMatrix();

	
//ball
	glPushMatrix();
	sphere();
	glPopMatrix();

//stumps
	
	if(move>1.41)
	{
		outwicangle -=3;
		outwicz -=.007;
	}

    glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslated(1.62,-0.384,outwicz);
	glRotatef(outwicangle,1.0,0.25,0.0);
	GLfloat matamb2[]={1.0f,1.f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb2);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0,1.0,1.0);
	glTranslated(1.6,0.10,.49);
	glRotatef(90.0,1.0,0.25,0.0);
	GLfloat matamb3[]={0.0f,1.f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb3);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,0.0,1.0);
	glTranslated(1.7,0.10,0.48);
	glRotatef(90.0,1.0,0.25,0.0);
	GLfloat matamb4[]={1.0f,0.0f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb4);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();

    if(move > 1.45) 
	{
		angle += -20.0;
		outbailangle -=5;
        outbailx -=.01;
        outbaily +=.005;
glPushMatrix();
	red=1.0;
	green=0.0;
	blue=0.0;
	 lite();
    glPopMatrix();

	}
//bails
	glPushMatrix();
	glColor3f(.3,1.0,.1);
	glTranslated(1.73,0.12,0.48);
	glRotatef(angle,1.0,0.0,0.0);
	GLfloat matamb5[]={.3f,1.f,.1f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb5);

	gluCylinder(quad, 0.02, 0.02, 0.1, 30, 30);
	glPopMatrix();
	

	glPushMatrix();
	glColor3f(.3,1.0,.1);
	glTranslated(outbailx,outbaily,0.48);
	glRotatef(outbailangle,0.5,0.03,0.5);
	GLfloat matamb10[]={.3f,1.f,.1f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb10);
	gluCylinder(quad, 0.02, 0.02, 0.1, 60, 10);
	glPopMatrix();

	glutSwapBuffers();
    glFlush();	
}


void notoutfunc()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
glClearColor(0.74902,0.847059,0.997059,1);
 //glClearColor (r, g, bl, fog);
pitch();
 glColor3f(1.0,0.0,0);
 glLoadName(TEXTID);
 drawtext(-1.40,.75,0,0.003,"THIRD UMPIRE");
 
 glPushMatrix();
	 lite();
 glPopMatrix();

 if(move>1.35)
 {
 glColor3f(0.0,1.0,0);
 glLoadName(TEXTID);
 GLfloat matamb60[]={0.0f,1.0f,0.0f,1.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb60);
 drawtext(-1.05,-.5,0,0.003,message);
 	glPushMatrix();
	red=0;
	blue=0;
	green=1;
	 lite();
glPopMatrix();
 }
 	  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

	double winht=1.0;
	glOrtho(-winht,winht,-winht,winht,0.1,100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3,0.2,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
	
	
	glPushMatrix();
	sphere();
	glPopMatrix();

//stumps
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslated(1.5,0.10,0.5);
	glRotatef(90.0,1.0,0.25,0.0);
	GLfloat matamb7[]={1.0f,1.f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb7);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,1.0);
	glTranslated(1.6,0.10,.49);
	glRotatef(90.0,1.0,0.25,0.0);
	GLfloat matamb8[]={0.0f,1.f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb8);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,0.0,1.0);
	glTranslated(1.7,0.10,0.48);
	glRotatef(90.0,1.0,0.25,0.0);
	GLfloat matamb9[]={1.0f,0.0f,1.f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb9);
	gluCylinder(quad, 0.02, 0.02, 0.5, 50, 50);
	glPopMatrix();

//bails
	glPushMatrix();
	glColor3f(.3,1.0,.1);
	glTranslated(1.73,0.12,0.48);
	glRotatef(0,1.0,0.0,0.0);
	GLfloat matamb11[]={.3f,1.f,.1f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb11);
	gluCylinder(quad, 0.02, 0.02, 0.1, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(.3,1.0,.1);
	glTranslated(1.57,0.12,0.48);
	glRotatef(0,0.5,0.0,0.0);
	GLfloat matamb12[]={.3f,1.f,.1f,0.0f};
	glMaterialfv (GL_FRONT,GL_AMBIENT,matamb12);
	gluCylinder(quad, 0.02, 0.02, 0.1, 50, 50);
	glPopMatrix();

	glutSwapBuffers();
	glFlush();
}

void init (void) 
{
   glClearColor(0.74902,0.847059,0.997059,1);
   glShadeModel (GL_FLAT); 
   quad = gluNewQuadric ();
   gluQuadricDrawStyle(quad,GLU_FILL); 
}


void reshape(int w, int h)
{  
   glLineWidth(4.0);
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION|GL_MODELVIEW);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
} 


 int main(int argc, char **argv)
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(1200, 780);
  glutCreateWindow("GLUT bitmap font example");
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutCreateMenu(message1);
  glutAddMenuEntry("FANTABULOUS", 1);
  glutAddMenuEntry("EXTRAORDINARY", 2); 
  glutAddMenuEntry("WHITE BACKGROUND",3);
  glutAddMenuEntry("BLACK BACKGROUND",4);
  glutAddMenuEntry("GREY BACKGROUND",5);
  glutAddMenuEntry("BACK TO MAIN",6);
  glutAddMenuEntry("QUIT",7);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glEnable (GL_LIGHTING);
  glEnable (GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
  
  glutIdleFunc(tick);

  glutKeyboardFunc(keys);
  glutTimerFunc (TIMER, timer, 0);
  init();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glutMainLoop();
  return 0;           /* ANSI C requires main to return int. */
}
