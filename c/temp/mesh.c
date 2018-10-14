#include<stdio.h>
#include<GL/glut.h>
#define nx 5
#define ny 5
int id,is;
GLfloat v[(nx+1)][(ny+1)][2];
calc()
{int i,j;
	int x=25,y=25;
	for(i=0;i<nx;i++)
		for(j=0;j<ny;j++)
		{
			v[i][j][0]=x+i*10;
			v[i][j][1]=y+j*10;
		}
}
void disp()
{
	int i,j;
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	for(i=0;i<nx-1;i++)
	{
		
		for(j=0;j<ny-1;j++)
		{
			glBegin(GL_LINE_LOOP);
		glVertex2fv(v[i][j]);
		glVertex2fv(v[i][j+1]);
		glVertex2fv(v[i+1][j+1]);
		glVertex2fv(v[i+1][j]);
		
		glEnd();
		}
	}
	glFlush();
}

void init(int x,int y)
{
	glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0,x,0,y);
}
void kb(unsigned char k,int x,int y)
{
	if(k=='a')
		glutDestroyWindow(id);
}
void menu(int id)
{
	if(id==3)printf("hi");
}
int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(1000,600);

		calc();
	id=glutCreateWindow("h");
	glutDisplayFunc(disp);
	init(500,500);
		glutInitWindowSize(200,200);
	is=glutCreateWindow("f");
	glutDisplayFunc(disp);
	glutKeyboardFunc(kb);
	glutCreateMenu(menu);
	glutAddMenuEntry("hi",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init(200,200);
	glutMainLoop();
	return 0;
}
