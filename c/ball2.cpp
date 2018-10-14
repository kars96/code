#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include <GL/glut.h>
static double x=0.0;
float ballZ=0;
float ang=0;
int on;



void stroke_output(GLfloat x, GLfloat y, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(-2.5, y, 0);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}


void flying()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0f,-.5f,-13.0f);
    glRotatef(118,1.0f,0.0f,0.0f);

	//fan 
	glPushMatrix();
	glRotatef(ang,0.0f,0.0f,3.0f);
	glTranslatef(0,0,-.6);
	
	glPushMatrix();
	// glRotatef(ang,0.0f,0.0f,1.0f);
	glScaled(2.9,0.2,0.1);
	glTranslatef(0.0,0.0,16.0);
	glutSolidSphere(0.7,18,60);
	glPopMatrix();

	//2nd blade
	// glRotatef(ang,0.0f,0.0f,1.0f);
	glPushMatrix();
	glScaled(0.2,2.9,0.1);
	glTranslatef(0.0,0.0,16.0);
	glutSolidSphere(0.7,18,60);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glutWireCone(4,3,80,120);
	glPopMatrix();

    // glRotated(ang,0.0,1.0,0.0);
	glPushMatrix();
	glTranslatef(0,0,ballZ);
	
	glRotated(ang,0.0,1.0,0.0);
	glutSolidSphere(0.3,20,60);
	glPopMatrix();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void flyOn(int s)
{	
	//printf("%d\n",s);
	if(ballZ*100<=-.01) {ang -= 15.30;}
	if(s>500 && ballZ*100<=0){  ballZ+=.01; }
	else if(ballZ*100>-300){ballZ-=0.01;}

	if(ballZ*10<0)glutTimerFunc(20,flyOn,++s);
	// else on=0;
	glutPostRedisplay();
	
	
}


void flyOff(int s)
{	
	//printf("%d\n",s);
	
	if(ballZ*100<=0){ ang += 3.30; ballZ+=.01;
    glutTimerFunc(200,flyOff,++s);}
	else on=0;
	// else if(ballZ*100>-300)ballZ-=0.01;
	// else on=0;
	glutPostRedisplay();
	
	
}

void fly()
{	

	glutPostRedisplay();
}

void nofly()
{
	flyOff(1);
}


void doInit() 
{
    
	/* Background and foreground color */
    glClearColor(0.0,0.0,0.4,1.0);
    glColor3f(1.0,1.0,1.0);
    glViewport(0,0,640,480);
 
	/* Select the projection matrix and reset it then
     setup our view perspective */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);    
    /* Select the modelview matrix, which we alter with rotatef() */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(2.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void doDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-3.0f,-1.0f,-21.0f);
	stroke_output(.0, 1.1, "     J.S.S ACADEMY OF TECHNICAL EDUCATION");
	stroke_output(-1.0, 0.4, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	stroke_output(-2.0, -0.2, "               FLYING BALL");
	
	
	stroke_output(-4.0, -1.3, "BY:");
	stroke_output(-4.0, -2.7, "   Mukesh(1JS14CS053)");
	stroke_output(-4.0, -1.9, "   Nagarjun(1JS14CS054)");
	stroke_output(-2.0, -0.9, "");
	stroke_output(-2.0, -1.8, "");

	GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
	GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
	GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	

	/*light source properties*/
	GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
	GLfloat light_position[]={2.0f,0.0f,0.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	GLfloat light_position2[]={0.0f,0.0f,8.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position2);
	GLfloat light_position3[]={0.0f,5.0f,2.0f,0.5f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
	glFlush();
	glutSwapBuffers();
    
}

void menu(int id)
{
	switch(id)
	{
	
	case 1:
	glutDisplayFunc(flying);
    ballZ=0;
    ang=0;

	on=1;
	glutTimerFunc(200,flyOn,1);
		break;
	case 2:exit(0);
		break;
	
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void mykey(unsigned char key,int x,int y)
{
	
	if(key=='q'||key=='Q')
	{
		exit(0);
	}
	
	if(key=='1')
	{
		glutDisplayFunc(flying);
		on=1;
	glutTimerFunc(1000,flyOn,1);
	}
	

	if(key=='B')
	{
		glutIdleFunc(nofly);
	}
	if(key=='n' || key=='N');
	{
	  
		on=1;
	    glutTimerFunc(1000,flyOn,1);
	    

	}
	if(key=='f' || key=='F');
	{
		glutTimerFunc(1000,flyOff,1);
	}
	
}

int main(int argc, char *argv[]) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Flying ball");
    glutDisplayFunc(doDisplay);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutKeyboardFunc(mykey);
	glutCreateMenu(menu);
    glutAddMenuEntry("Flying ball",1);
	glutAddMenuEntry("Exit",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	doInit();
    glutMainLoop();
	return 0; 
}
