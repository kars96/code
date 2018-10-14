#include<stdio.h>
#include<GL/glut.h>

void wall()
{	
	glPushMatrix();
	glScalef(1,1,.1);
	glutSolidCube(100);
	glPopMatrix();
}
void d()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1,1,1);
	//glTranslated(50,50,0);
	GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
GLfloat mat_shininess[]={50.0f};
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
GLfloat lightint[]={0.f,01.f,01.f,1.0f};
GLfloat lightpos[]={.0f,100.0f,150.f,0.0f};
glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);
glPushMatrix();
	// glRotatef(225,0,1,0);
	// glRotatef(45,1,0,0);
	glTranslated(50,50,0);

	wall();
	glRotatef(90,0,1,0);
	wall();
	glRotatef(90,0,0,1);
	wall();
	glPopMatrix();
	//glRotatef(45,0,1,0);
	//glutSolidCube(100);
	glDisable(GL_LIGHTING);
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex3f(0,0,101);
	glEnd();
	glFlush();
}

void init()
{
	// glViewport(0,0,200,200);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200,200,-200,200,-200,200);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(400,400);
	glutCreateWindow("cube");
	init();
	glutDisplayFunc(d);
	glutMainLoop();
}