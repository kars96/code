#include<GL/glut.h>
void wall(double thick)
{
	glPushMatrix();
	glTranslated(0.5,0.5*thick,0.5);
	glScaled(1,thick,1);
	glutSolidCube(1.0);
	glPopMatrix();
}
void tbleg(double thick,double len)
{
	glPushMatrix();
	glTranslated(0,len/2,0);
	glScaled(thick,len,thick);
	glutSolidCube(1);
	glPopMatrix();
	}
void tbl(double topwidth,double topthick,double legthick,double leglen)
{
	glPushMatrix();
	glTranslated(0,leglen,0);
	glScaled(topwidth,.02,topwidth);
	glutSolidCube(1.0);
	glPopMatrix();
	double dist=0.95*topwidth/2-legthick/2;
	glPushMatrix();
	glTranslated(dist,0,dist);
	tbleg(legthick,leglen);
	glTranslated(0,0,-2*dist);
	tbleg(legthick,leglen);
	glTranslated(-2*dist,0,2*dist);
	tbleg(legthick,leglen);
	glTranslated(0,0,-2*dist);
	tbleg(legthick,leglen); //
	glPopMatrix();
	}
	
void dispsolid()
{
GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
GLfloat mat_shininess[]={50.0f};
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
GLfloat lightint[]={1.f,01.f,01.f,1.0f};
GLfloat lightpos[]={1.0f,.50f,.40f,0.0f};
glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightint);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
double winht=1.0;
glOrtho(-winht*64/48.0,winht*64/48.0,-winht,winht,0.1,100.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
// gluLookAt(3.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
gluLookAt( 1,001.,1,0.0,0.,.0,0.0,1.0,0.0);

glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glPushMatrix();
glTranslated(0.4,0.38,0.4);
// glRotated(30,0,1,0);
glutSolidTeapot(0.1);
glPopMatrix();
glPushMatrix();
glTranslated(0.3,0.0,0.3);
tbl(0.6,0.02,0.02,0.3);
glPopMatrix();
wall(0.02);
glPushMatrix();
glRotated(90.0,0,0,1.0);
wall(0.02);
glPopMatrix();
glPushMatrix();
glRotated(-90,1,0,0);
wall(0.02);
glPopMatrix();
glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH | GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,100);
glutCreateWindow(argv[1]);
//glutReshapeFunc(MyReshape);
//glutIdleFunc(spincube);
glutDisplayFunc(dispsolid);
//glutMouseFunc(mouse);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
// glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
glEnable(GL_NORMALIZE);
glClearColor(0.1,0.1,0.1,0.0);
glViewport(0,0,640,480);
glutMainLoop();
return 0;
}