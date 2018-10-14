#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
#include<SOIL/SOIL.h>
#include<FreeImage.h>
#include<malloc.h>
#include<time.h>

#define RGB(r,g,b) r/255.0f,g/255.0f,b/255.0f
#define CM2PIX 40
int cargc;char **cargv;
typedef GLfloat v[3][500];
typedef GLfloat trans[3][3];
int resx=1366,resy=766,cm2pix=40;
v  p[100][500];
v ln; int n1;
int col[100][100];
int n[100];
int wid,swid1,swid2=0,swid3;
 GLuint texture,texture2;

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
		{RGB(96,125,139)},
		{RGB(1,0,0)}
	};
typedef struct {
	GLubyte r, g, b;
} pixel;
typedef struct {
	pixel *data;
	int w, h;
} glob;
glob global;
glob bg;

int ang=0;

#define START 1
#define OVERVIEW 2
#define HELP 3
#define CREDITS 4
#define EXIT 5
#define BG 6
#define SPIN 7

#define MONO 0
#define POLY 1
#define PESO 2
#define DOLLAR 3
#define CENT 4
#define RUPEE 5
#define BUTTON 6
#define BUILD1 7
#define BUILD2 8
#define BUILD3 9
#define A 10
#define B 11
#define E 12
#define H 13
#define I 14
#define L 15
#define O 16
#define P 17
#define R 18
#define T 19
#define U 20
#define V 21
#define W 22
#define S 23
#define X 24
#define C 25
#define D 26
#define ARROW 27
#define SPINNER 28
#define ZERO 29
#define ONE 30
#define TWO 31
#define THREE 32
#define FOUR 33
#define FIVE 34
#define SIX 35
#define SEVEN 36
#define EIGHT 37
#define NINE 38
#define PIE 39
int  containsPoint(int,int,int,int,int,int);
void init();
void init2();
void startupTimer(int);
void mainScreen();
void mainScreenkb(unsigned char,int,int);
void rasterText(const char*,int ,int);
void mainScreenm(int,int,int,int);
void start();
void startkb(unsigned char, int,int);
void startm(int,int,int,int);
void overview();
void overviewkb(unsigned char, int,int);
void overviewm(int,int,int,int);
void help();
void helpkb(unsigned char, int,int);
void helpm(int,int,int,int);
void credits();
void creditskb(unsigned char, int,int);
void creditsm(int,int,int,int);
void exit1();
void exitkb(unsigned char, int,int);
void exitm(int,int,int,int);
void spinner();
void spinnerm(int , int ,int ,int);
void spinnerkb(unsigned char,int ,int);
void spinTimer(int);
void voids(unsigned char,int,int){}
pixel *read_img(const char *name, int *width, int *height,FREE_IMAGE_FORMAT type) {
	FIBITMAP *image;
	int i, j, pnum;
	RGBQUAD aPixel;
	pixel *data;

	if ((image = FreeImage_Load(type, name, 0)) == NULL) {
		return NULL;
	}
	*width = FreeImage_GetWidth(image);
	*height = FreeImage_GetHeight(image);

	data = (pixel *)malloc((*height)*(*width)*sizeof(pixel *));
	pnum = 0;
	for (i = 0; i < (*height); i++) {
		for (j = 0; j < (*width); j++) {
			FreeImage_GetPixelColor(image, j, i, &aPixel);
			data[pnum].r = (aPixel.rgbRed);
			data[pnum].g = (aPixel.rgbGreen);
			data[pnum++].b = (aPixel.rgbBlue);
		}
	}
	FreeImage_Unload(image);
	return data;
}//read_img

void multiply(trans t,v tp,int tn)
{
	v r;
	int sum,i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<tn;j++)
		{
			sum=0;
			for(k=0;k<3;k++)
				sum+=t[i][k]*tp[k][j];
			r[i][j]=sum;
		}
	}
	for(i=0;i<3;i++)
		for(j=0;j<tn;j++)
			tp[i][j]=r[i][j];
}

void strokeText(const char *txt,int x,int y)
{	int i;
	glRasterPos2f(x,y);
	for(i=0;i<strlen(txt);i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,txt[i]);
}

void d1(int k,int mode)
{	int i,j;
	for(i=0;i<n[k];i++)
	{
		glBegin(mode);
		for(j=0;j<col[k][i];j++)
			glVertex2f(p[k][i][0][j],p[k][i][1][j]);
		glEnd();
	}		
}

void start()
{	
	glClearColor (RGB(45,145,121),0);
    glClear (GL_COLOR_BUFFER_BIT);
    
	/*glClearColor (1.0,1.0,1.0,0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTranslatef(300,10,0);
    glColor3f(1,1,1);
    glScalef(1,1,1);
    glBegin (GL_QUADS);
    glTexCoord2d(0.0,0.0);
    glVertex2d(0.0,0.0); 
    glTexCoord2d(1.0,0.0);
    glVertex2d(750.0,0.0);
    glTexCoord2d(1.0,1.0);
    glVertex2d(750.0,750.0);
    glTexCoord2d(0.0,1.0);
    glVertex2d(0.0,750.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();*/
	
    //glTranslatef(-200,0,0);
   // glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glColor3f(1,1,1);
    glPushMatrix();
	glTranslatef(10,610,0);
	d1(ARROW,9);
	glPopMatrix();
    glRasterPos2f(370,30);
	glDrawPixels(global.w, global.h, GL_RGB, GL_UNSIGNED_BYTE, (GLubyte*)global.data);
	glutSwapBuffers();
}

void startkb(unsigned char k, int x,int y)
{
	if(k=='s')
	{
	swid2=glutCreateSubWindow(wid,350,10,resy-100,resy-100);
	init2();
	glutDisplayFunc(spinner);
	glutMouseFunc(spinnerm);
	glutKeyboardFunc(spinnerkb);
	glutSetWindow(swid2);
	glutPostRedisplay();
	}

}

void startm(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN && glutGetWindow()==wid)
	{
		if(containsPoint(5,60,137,144,x,y)){
				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
	}
	
}


void spinner()
{
	glClearColor(RGB(45,145,121),0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//glCallList(SPIN);
	glScalef(.9,.9,.9);
	glPushMatrix();
	glRotatef(ang,0,0,1);
	for(int i=0;i<n[SPINNER];i++)
	{
		glBegin(9);
		glColor3fv(colr[i-1]);
		for(int j=0;j<col[SPINNER][i];j++)
			glVertex2f(p[SPINNER][i][0][j],p[SPINNER][i][1][j]);
		glEnd();
	}
	glColor3f(1,1,1);
	int i,k;
	for(i=-10,k=ONE;k<=NINE;k++,i-=30)
	{
	glPushMatrix();
	glRotatef(i,0,0,1);
	glTranslatef(210,0,0);
	glScalef(.65,.65,.65);
	d1(k,9);
	glPopMatrix();	
	}
	for(k=ZERO;k<=TWO;k++,i-=30)
	{

	glPushMatrix();
	glRotatef(i,0,0,1);
	glTranslatef(175,0,0);
	glScalef(.65,.65,.65);
	d1(ONE,9);
	glPopMatrix();	
	
	glPushMatrix();
	glRotatef(i,0,0,1);
	glTranslatef(225,0,0);
	glScalef(.65,.65,.65);
	d1(k,9);
	glPopMatrix();	
	}
	glPopMatrix();
	glLineWidth(6);
	d1(PIE,2);
	glLineWidth(1);
	glutSwapBuffers();

	//glutPostRedisplay();
}

void spinTimer(int step)
{	//printf("%d\n",ang);
	if(ang!=(360*3+30*step))
	{
	ang+=5;
	glutSetWindow(swid2);
	glutPostRedisplay();
	glutTimerFunc(5,spinTimer,step);
	}
	else
	{
		sleep(2);
		ang=0;
		glutSetWindow(wid);
		glutKeyboardFunc(startkb);
		glutMouseFunc(startm);
		glutDestroyWindow(swid2);
		glutPostRedisplay();
	}

}

void spinnerm(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN && b==GLUT_LEFT_BUTTON)
	{
		int step=rand()%12;
		glutTimerFunc(5,spinTimer,step);
	}
}

void spinnerkb(unsigned char k,int x,int y)
{
	if(k==' ')
	{
	int step=rand()%12;
		glutTimerFunc(5,spinTimer,step);	
	}
}
void overview()
{
	glCallList(BG);
	glPushMatrix();
	glTranslatef(100,350,0);
	glCallList(OVERVIEW);
	glPopMatrix();
	glutSwapBuffers();
}

void overviewkb(unsigned char k, int x,int y)
{

}

void overviewm(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN)
	{
		if(containsPoint(5,60,137,144,x,y)){
				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
	}
}

void helpkb(unsigned char k, int x,int y)
{

}

void helpm(int b,int s,int x,int y)
{	
	if(s==GLUT_DOWN)
	{
		if(containsPoint(5,60,137,144,x,y)){
				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
	}
}

void credits()
{
	glCallList(BG);
	glPushMatrix();
	glTranslatef(100,520,0);
	glCallList(CREDITS);
	glPopMatrix();
	glutSwapBuffers();
}

void creditskb(unsigned char k, int x,int y)
{

}

void creditsm(int b,int s,int x,int y)
{
	if(s==GLUT_DOWN)
	{
		if(containsPoint(5,60,137,144,x,y)){
				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
	}

}
void exit1()
{	
	glClearColor(.9,.9,.9,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glColor4f(RGB(45,145,121),.75);
	glBegin(GL_QUADS);
	glVertex2f(0,400);
	glVertex2f(resx,400);
	glVertex2f(resx,700);
	glVertex2f(0,700);
	glEnd();
	glTranslatef(550,500,0);
	glScalef(1,1,1);
	glLineWidth(3);
	glColor3f(1,1,1);
	strokeText("Quit?",0,0);
	//rasterText("Are you sure you want to quit the game?",0,500);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(7*CM2PIX,4*CM2PIX,0);
	glScalef(2.5,3,3);
	glColor4f(RGB(45,145,121),.75);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((7+2)*CM2PIX,(4+.7)*CM2PIX,0);
	glScalef(.5,.5,.5);
	glColor3f(1,1,1);
	rasterText("Yes",0,0);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(20*CM2PIX,4*CM2PIX,0);
	glScalef(2.5,3,3);
	glColor4f(RGB(45,145,121),.75);
	d1(BUTTON,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef((20+2.35)*CM2PIX,(4+.7)*CM2PIX,0);
	glScalef(.5,.5,.5);
	glColor3f(1,1,1);
	rasterText("No",0,0);
	glPopMatrix();

	glutSwapBuffers();
}

void exitkb(unsigned char key, int x, int y)
{
	if(key=='y'||key=='Y' || key==13)
	{
		glutDestroyWindow(wid);
		exit(0);
	}
	if(key=='n' || key=='N' || key==27)
	{
			glutDestroyWindow(glutGetWindow());
			glutSetWindow(wid);
			glutDisplayFunc(mainScreen);
			glutKeyboardFunc(mainScreenkb);
			glutMouseFunc(mainScreenm);
			glutPostRedisplay();
	}
}
int containsPoint(int x1,int y1,int x2,int y2,int x,int y)
{
	//printf("%d %d  %d %d\n",x1,y1,x2,y2);
	if(x>=x1 && x<=(x2) && y>=y1 && y<=(y2)) return 1;
	else return 0;
}

void exitm(int b,int s ,int x, int y)
{
	if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN)
	{
		//printf("%d %d\n",x,y);
	if(containsPoint(84,131,166 ,156,x,y))
	{	

		glutDestroyWindow(wid);
		exit(0);
	}
	if(containsPoint(236,130,322,157,x,y))	
	{
			glutDestroyWindow(glutGetWindow());
			glutSetWindow(wid);
			glutDisplayFunc(mainScreen);
			glutKeyboardFunc(mainScreenkb);
			glutPostRedisplay();
	}
	}
	if(s==GLUT_DOWN)
	{
		if(containsPoint(5,60,137,144,x,y)){
				glutDisplayFunc(mainScreen);
				glutKeyboardFunc(mainScreenkb);
				glutMouseFunc(mainScreenm);
				glutPostRedisplay();
			}
	}
}

void startupTimer(int x)
{
	glutPostRedisplay();
	if(x!=0)
	glutTimerFunc(500,startupTimer,1);
}

void help()
{
	glCallList(BG);
	glTranslatef(100,440,0);
	glCallList(HELP);
	glutSwapBuffers();
}

void rasterText(const char *txt,int x,int y)
{	int i;
	glRasterPos2f(x,y);
	for(i=0;i<strlen(txt);i++){

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,txt[i]);
	}
}
void startupdisp()
{ 	int i;
	static int x=0;
	GLfloat pat[11][2]={
		{0,0},
		 {2000.000000, 0.000000},
 		{1969.000000, 347.000000},
 		{1879.000000, 684.000000},
 		{1732.000000 ,1000.000000},
 		{1532.000000, 1285.000000},
 		{1285.000000, 1532.000000},
 		{1000.000000, 1732.000000},
 		{684.000000, 1879.000000},
		{347.000000, 1969.000000},
 		{0.000000 ,2000.000000}
	};
	glClear(GL_COLOR_BUFFER_BIT );
	glLoadIdentity();
	for(i=1;i<=9;i++)
	{
		glColor3fv(colr[i-1]);
		glBegin(GL_POLYGON);
		glVertex2fv(pat[0]);
		glVertex2fv(pat[i]);
		glVertex2fv(pat[i+1]);
		glEnd();
	}
	glColor3f(1,1,1);
	rasterText("You gotta play to earn!",600,150);

	glPushMatrix();
	glTranslatef(500,383,0);
	glColor3f(1,1,1);
	d1(MONO,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(500,0,0);
	glColor3f(1,1,1);
	d1(POLY,9);
	glPopMatrix();

	if(x++%2){
		glPushMatrix();
		glTranslatef(500,10,0);
		glScalef(.15,.15,.15);
		strokeText("Press any key to continue",600,10);
		glPopMatrix();

	}
	glutSwapBuffers();
}

void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<h)
	gluOrtho2D(0.0,resx,0.0,resy*h/w);
	else
		gluOrtho2D(0.0,resx*w/h,0.0,resy);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void mainScreen()
{

	//glClear(GL_COLOR_BUFFER_BIT);
	glutTimerFunc(1000,startupTimer,0);
	int k=0;
	int i,d=0,j;
	int factor=-resx/10;
	/*
	for(i=0;i<resy;i+=resy/9)
	{	glBegin(GL_POLYGON);
			glColor3fv(colr[k]);
			glVertex2f(0,i);
			glVertex2f(resx,i);
			glColor3fv(colr[k]);
			glVertex2f(resx,i+resy/9);
			glVertex2f(0,i+resy/9);
		glEnd();
		k++;
	}*/
	glClearColor (1,1.0,1.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    /*
    glColor3f(1,1,1);
    glEnable( GL_TEXTURE_2D );
    glBindTexture(GL_TEXTURE_2D, texture2);
    glBegin (GL_QUADS);
    glTexCoord2d(0.0,0.0);
    glVertex2d(0.0,0.0); 
    glTexCoord2d(1.0,0.0);
    glVertex2d(1366.0,0.0);
    glTexCoord2d(1.0,1.0);
    glVertex2d(1366.0,763.0);
    glTexCoord2d(0.0,1.0);
     glVertex2d(0.0,763.0);
     glEnd();
     glDisable(GL_TEXTURE_2D);
     */
    //glColor3f(RGB(31,47,69));
	//glPopMatrix();
/*
	glPushMatrix();
	glTranslatef(0,5*CM2PIX,0);
	glColor3fv(colr[1]);
	glBegin(9);
	for(j=0;j<col[7][0];j++)
		glVertex2f(p[7][0][0][j],p[7][0][1][j]);
	glEnd();
	glColor3f(1,1,1);
	//glScalef(1,.5,0);
	for(i=1;i<n[7];i++)
	{
		glBegin(9);
		for(j=0;j<col[7][i];j++)
			glVertex2f(p[7][i][0][j],p[7][i][1][j]);
		glEnd();
	}	
	glPopMatrix();
*/
    	
    
     //glColor3f(1,1,1);
    
    //printf("%d %d\n",bg.h,bg.w);
     for(int i=0;i<=resy;i+=214)
     {
     	for(int j=0;j<=resx;j+=bg.w)
     	{
     	glRasterPos2f(j,i);
	glDrawPixels(bg.w, bg.h, GL_RGB, GL_UNSIGNED_BYTE, (GLubyte*)bg.data);
	}
	}


	glColor4f(RGB(45,145,121),.75);
	glBegin(GL_QUADS);
	glVertex2f(479,450);
	glVertex2f(867,450);
	glVertex2f(867,700);
	glVertex2f(479,700);
	glEnd();/*
	glLineWidth(5);
	glColor3f(RGB(164,225,156));
	glPushMatrix();
	glTranslatef(480,600,0);
	glScalef(.51,.51,.51);

	d1(MONO,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(480,400,0);
	glScalef(.51,.51,.51);
	d1(POLY,9);
	glPopMatrix();
	glLineWidth(1);
*/
	 //glColor3f(RGB(250,255,186));
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(480,600,0);
	glScalef(.5,.5,.5);
	d1(MONO,9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(480,400,0);
	glScalef(.5,.5,.5);
	d1(POLY,9);
	glPopMatrix();

	glColor4f(RGB(45,145,121),.75);
	glBegin(GL_QUADS);
	glVertex2f(479,0);
	glVertex2f(867,0);
	glVertex2f(867,420);
	glVertex2f(479,420);
	glEnd();
    //glColor3f(RGB(250,255,186));	
    glColor3f(1,1,1);
	glCallList(START);
	glCallList(OVERVIEW);
	glCallList(HELP);
	glCallList(CREDITS);
	glCallList(EXIT);
	//glColor4f(1,1,1,1);
	glutSwapBuffers();
}

void mainScreenm(int b,int s,int x,int y)
{	if(s==GLUT_DOWN)
	{
	if(containsPoint(500 ,327,691 ,375,x,y))
	{	//glEnable( GL_TEXTURE_2D );
		glutDisplayFunc(start);
		glutKeyboardFunc(startkb);
		glutMouseFunc(startm);
		glutPostRedisplay();
	}
	if(containsPoint(499, 403,839 ,452,x,y))
	{
		glutDisplayFunc(overview);
		glutKeyboardFunc(overviewkb);
		glutMouseFunc(overviewm);
		glutPostRedisplay();
	}
	if(containsPoint(497, 473,652, 530,x,y))
	{
		glutDisplayFunc(help);
		glutKeyboardFunc(helpkb);
		glutMouseFunc(helpm);
		glutPostRedisplay();
	}
	if(containsPoint(499, 552,770 ,606,x,y))
	{
		glutDisplayFunc(credits);
		glutKeyboardFunc(creditskb);
		glutMouseFunc(creditsm);
		glutPostRedisplay();
	}
	if(containsPoint(499, 626,651, 685,x,y))
	{	
		swid1=glutCreateSubWindow(wid,(resx/2)-(10*CM2PIX/2),(resy/2)-(5*CM2PIX/2),9.5*CM2PIX,5*CM2PIX);
		init();
		glutWarpPointer(177,143);
		glutDisplayFunc(exit1);
		glutKeyboardFunc(exitkb);
		glutMouseFunc(exitm);
		glutPostRedisplay();
	}
	}
}

void mainScreenkb(unsigned char key, int x, int y)
{
	if(key=='h' || key=='H')
	{	//printf("(hello)\n" );
		glutDisplayFunc(help);
		glutPostRedisplay();
	}
	if(key=='q'|| key=='Q')
	{
		swid1=glutCreateSubWindow(wid,(resx/2)-(10*CM2PIX/2),(resy/2)-(5*CM2PIX/2),10*CM2PIX,5*CM2PIX);
		glutDisplayFunc(exit1);
		glutKeyboardFunc(exitkb);
		glutMouseFunc(exitm);
		init();
		glutWarpPointer(177,143);
		glutPostRedisplay();
	}
}
void setup()
{
	FILE* f;FILE* ft; char fn[60]; GLfloat x,y;int i=0,j,flag,k,temp;
	char pointfiles[][20]={"MONO.txt","POLY.txt","PESO.txt","DOLLAR.txt","CENT.txt","RUPEE.txt","BUTTON.txt","BUILD1.txt","BUILD2.txt","BUILD3.txt","A.txt","B.txt","E.txt","H.txt","I.txt","L.txt","O.txt","P.txt","R.txt","T.txt","U.txt","V.txt","W.txt","S.txt","X.txt","C.txt","D.txt","ARROW.txt","SPINNER.txt","0.txt","1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt","9.txt","PIE.txt"};
	int numf=40;
	trans t={{CM2PIX,0,0},
	   {0,CM2PIX,0},
	   {0,0,CM2PIX}};
	time_t sec;
	time(&sec);
	srand((unsigned int)sec);

     //texture = SOIL_load_OGL_texture 	( 		"m.jpg", 		SOIL_LOAD_AUTO, 		SOIL_CREATE_NEW_ID, 		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT 	);
	//texture2 = SOIL_load_OGL_texture 	( 		"bg5.png", 		SOIL_LOAD_AUTO, 		SOIL_CREATE_NEW_ID, 		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT 	);
	global.data = read_img("m.tiff", &global.w, &global.h,FIF_TIFF);
	bg.data=read_img("bg6.tiff",&bg.w,&bg.h,FIF_TIFF);
	glShadeModel(GL_SMOOTH);
	if (global.data == NULL)
	{
		printf("Error loading image file %s\n", "m.tiff");
	exit(0);
	}
	for(k=0;k<numf;k++)
	{
		f=fopen(pointfiles[k],"r");
		if(f==NULL)
		{
			printf("Cannot open %s\n",pointfiles[k]);
			exit(1);
		}
		flag=1;
		for(i=0;i<5000;i++)
		{
			j=0;
			if(flag==0)break;
			while(1)
			{
				if(fscanf(f,"%f %f",&x,&y)==EOF){
					flag=0;
					break;
				}
				if(x==-111111.0 && y==-111111.0)
					break;
				else
				{
				p[k][i][0][j]=x;
				p[k][i][1][j]=y;
				p[k][i][2][j]=1;
				j++;
				}
			}
			col[k][i]=j;
		}
		n[k]=i;
		fclose(f);
	}
	k=0;
	for(int i=2;i<=32;i+=8)
	{
		ln[0][k]=i;
		ln[1][k]=2;
		ln[2][k++]=1;
	}
	for(int i=2;i<=18;i+=4)
	{
		ln[0][k]=32;
		ln[1][k]=i;
		ln[2][k++]=1;
	}
	for(int i=32;i>=2;i-=8)
	{
		ln[0][k]=i;
		ln[1][k]=18;
		ln[2][k++]=1;
	}
	for(int i=18;i>=2;i-=4)
	{
		ln[0][k]=2;
		ln[1][k]=i;
		ln[2][k++]=1;
	}

	
	n1=k;
	multiply(t,ln,n1);
	
	glNewList(START,GL_COMPILE);
	glPushMatrix();
	glTranslatef(500,350,0);
	glScalef(.5,.5,.5);
	d1(S,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(547,350,0);
	glScalef(.35,.35,.35);
	d1(T,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(545+35,350,0);
	glScalef(.35,.35,.35);
	d1(A,9);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(545+35+45,350,0);
	glScalef(.35,.35,.35);
	d1(R,9);
	glPopMatrix();
		glPushMatrix();
	glTranslatef(545+35+45+35,350,0);
	glScalef(.35,.35,.35);
	d1(T,9);
	glPopMatrix();
	glEndList();

	glNewList(OVERVIEW,GL_COMPILE);
	glPushMatrix();
	glTranslatef(500,265,0);
	glScalef(.5,.5,.5);
	d1(O,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(560,265,0);
	glScalef(.35,.35,.35);
	d1(V,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(560+40,265,0);
	glScalef(.35,.35,.35);
	
	d1(E,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(560+40+40,265,0);
	glScalef(.35,.35,.35);
	
	d1(R,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(560+40+40+40,265,0);
	glScalef(.35,.35,.35);
	
	d1(V,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(560+40+40+40+40,265,0);
	glScalef(.35,.35,.35);
	
	d1(I,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(560+40+40+40+40+40,265,0);
	glScalef(.35,.35,.35);
	
	d1(E,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(560+40+40+40+40+40+40,265,0);
	glScalef(.35,.35,.35);
	
	d1(W,9);
	glPopMatrix();
	glEndList();
	
	glNewList(HELP,GL_COMPILE);
	glPushMatrix();
	glTranslatef(500,179,0);
	glScalef(.5,.5,.5);
	
	d1(H,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(547,179,0);
	glScalef(.35,.35,.35);
	d1(E,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(547+40,179,0);
	glScalef(.35,.35,.35);
	d1(L,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(547+40+40,179,0);
	glScalef(.35,.35,.35);
	d1(P,9);
	glPopMatrix();
	glEndList();

	glNewList(CREDITS,GL_COMPILE);
	glPushMatrix();
	glTranslatef(500,95,0);
	glScalef(.5,.5,.5);
	
	d1(C,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500+60,95,0);
	glScalef(.35,.35,.35);
	
	d1(R,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500+60+35,95,0);
	glScalef(.35,.35,.35);
	
	d1(E,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500+60+35+35,95,0);
	glScalef(.35,.35,.35);
	
	d1(D,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500+60+35+35+35,95,0);
	glScalef(.35,.35,.35);
	
	d1(I,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500+60+35+35+35+35,95,0);
	glScalef(.35,.35,.35);
	
	d1(T,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500+60+35+35+35+35+35,95,0);
	glScalef(.35,.44,.35);
	
	d1(S,9);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(500,10,0);
	glScalef(.5,.5,.5);
	glEndList();

	glNewList(EXIT,GL_COMPILE);
	d1(E,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500+47,10,0);
	glScalef(.35,.35,.35);
	
	d1(X,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500+47+35,10,0);
	glScalef(.35,.35,.35);
	
	d1(I,9);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(500+47+35+35,10,0);
	glScalef(.35,.35,.35);
	
	d1(T,9);
	glPopMatrix();
	glEndList();

	glNewList(BG,GL_COMPILE);
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	 for(int i=0;i<=resy;i+=214)
     {
     	for(int j=0;j<=resx;j+=bg.w)
     	{
     	glRasterPos2f(j,i);
		glDrawPixels(bg.w, bg.h, GL_RGB, GL_UNSIGNED_BYTE, (GLubyte*)bg.data);
		}
	}
	glColor4f(RGB(45,145,121),.75);
	glBegin(GL_QUADS);
	glVertex2f(0,600);
	glVertex2f(resx,600);
	glVertex2f(resx,700);
	glVertex2f(0,700);
	glEnd();
	glPushMatrix();
	glColor3f(1,1,1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(10,610,0);
	d1(ARROW,9);
	glPopMatrix();
	glEndList();

	glNewList(SPIN,GL_COMPILE);
	glPushMatrix();
	//glTranslatef(0,0,0);
		for(int i=0;i<n[SPINNER];i++)
	{
		glBegin(9);
		glColor3fv(colr[i-1]);
		for(int j=0;j<col[SPINNER][i];j++)
			glVertex2f(p[SPINNER][i][0][j],p[SPINNER][i][1][j]);
		glEnd();
	}	
	glPopMatrix();
	glEndList();
}

void startupkb(unsigned char key, int x, int y)
{

	if(key)
	{
		glutDisplayFunc(mainScreen);
		glutKeyboardFunc(mainScreenkb);
		glutMouseFunc(mainScreenm);
		glutPostRedisplay();
		
	}
}

void init()
{
	glClearColor(1,1,1,1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,resx,0.0,resy);
	glMatrixMode(GL_MODELVIEW);
}
void init2()
{
	glClearColor(1,1,1,0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-resy/2+50,resy/2-50,-resy/2+50,resy/2-50);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(resx,resy);
	wid=glutCreateWindow("Monopoly");
	init();
	setup();
	//glutReshapeFunc(myReshape);
	glutDisplayFunc(startupdisp);
	//glutIdleFunc(startupdisp);
	glutTimerFunc(500,startupTimer,1);
	glutKeyboardFunc(startupkb);
	glutMainLoop();
	return 0;
}
