#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <math.h>
#include<FreeImage.h>
#include <string.h>
#define PI 3.14159265
#define RGB(r,g,b) r/255.0f,g/255.0f,b/255.0f

typedef struct {
  GLubyte r, g, b;
} pixel;
typedef struct {
  pixel *data;
  int w, h;
} glob;
glob bg;

double val=PI/180;
void strokeText(const char *txt,int x,int y)
{ int i;
  glRasterPos2f(x,y);
  for(i=0;i<strlen(txt);i++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,txt[i]);
}


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
}


void display(void)
{
	static int dist=0,ang=0;
   int i;  
 glClear (GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON);  //sky
glColor3f(RGB(252,252,252));  
 glVertex2f (0,0); 
 glColor3f(RGB(255,97,0)); 
   glVertex2f (0,1000);
glColor3f(RGB(99,184,255));
   glVertex2f (1700,1000); 
   glColor3f(RGB(0,100,0)); 
   glVertex2f (1700,0); 
   glColor3f(RGB(0,100,0)); 
   glVertex2f (1700,50);
   glColor3f(RGB(0,100,0)); 
   glVertex2f (1600,0);  
    glEnd();

// glBegin(GL_POLYGON);
// glColor3f(0,0,0);
// glVertex2f(5,5);
// glVertex2f(1595,5);
// glVertex2f(1595,895);
// glVertex2f(5,995);
// glEnd();


    glColor3f(RGB(65,105,225));
glPushMatrix();//text
glTranslatef(350,670,0);
glScalef(.2931,.231,0);
glLineWidth(4.5);
strokeText("JSS MAHAVIDYAPEETA",0,0);
glPopMatrix();

 glColor3f(RGB(65,105,225));
glPushMatrix();//text
glTranslatef(150,610,0);
glScalef(.2931,.31,0);
glLineWidth(5.5);
strokeText("JSS ACADEMY OF TECHICAL EDUCATION",0,0);
glPopMatrix();

 glColor3f(RGB(65,105,225));
glPushMatrix();//text
glTranslatef(270,560,0);
glScalef(.231,.21,0);
glLineWidth(1.5);
strokeText("DEPARTMENT OF COMPUTER SCIENCE",0,0);
glPopMatrix();

 glColor3f(RGB(65,105,225));
glPushMatrix();//text
glTranslatef(360,500,0);
glScalef(.321,.31,0);
glLineWidth(2.5);
strokeText("COMPUTER GRAPHICS",0,0);
glPopMatrix();

 glColor3f(RGB(65,105,225));
glPushMatrix();//text
glTranslatef(500,460,0);
glScalef(.191231,.1932931,0);
glLineWidth(2.5);
strokeText("MINI PROJECT",0,0);
glPopMatrix();

 //glColor3f(RGB(65,105,225));
glColor3f(RGB(255,127,0));
glPushMatrix();//text
glTranslatef(250,400,0);
glScalef(.31,.31,0);
glLineWidth(3.5);
strokeText("SWACCH",0,0);
glPopMatrix();

glColor3f(RGB(248,248,255));
glPushMatrix();//text
glTranslatef(470,400,0);
glScalef(.31,.31,0);
glLineWidth(3.5);
strokeText("BH",0,0);
glPopMatrix();

glColor3f(RGB(0,0,139));
glPushMatrix();//text
glTranslatef(535,400,0);
glScalef(.31,.31,0);
glLineWidth(3.5);
strokeText("ARA",0,0);
glPopMatrix();

glColor3f(RGB(248,248,255));
glPushMatrix();//text
glTranslatef(620,400,0);
glScalef(.31,.31,0);
glLineWidth(3.5);
strokeText("TH",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(710,400,0);
glScalef(.31,.31,0);
glLineWidth(3.5);
strokeText("ABHIYAAN",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(10,300,0);
glScalef(.1921,.21,0);
glLineWidth(1.5);
strokeText("Under the guidance of:",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,250,0);
glScalef(.1921,.191,0);
glLineWidth(1);
strokeText("Ms.RASHMI B N",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,228,0);
glScalef(.13,.1,0);
glLineWidth(1.2);
strokeText("FACULTY INCHARGE",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,190,0);
glScalef(.1921,.191,0);
glLineWidth(1);
strokeText("MR.SHARANA BASAVANA GOWDA",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,175,0);
glScalef(.13,.1,0);
glLineWidth(1.3);
strokeText("ASST. PROF,",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(50,160,0);
glScalef(.13,.1,0);
glLineWidth(1.3);
strokeText("DEPARTMENT OF CSE",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(900,300,0);
glScalef(.1921,.21,0);
glLineWidth(1.5);
strokeText("TEAM:",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(950,250,0);
glScalef(.1821,.191,0);
glLineWidth(1.5);
strokeText("AISHWARYA K G",0,0);
glPopMatrix();

glColor3f(RGB(0,139,69));
glPushMatrix();//text
glTranslatef(950,190,0);
glScalef(.1921,.191,0);
glLineWidth(1.5);
strokeText("GEETHA G",0,0);
glPopMatrix();

printf("%d %d \n",bg.w,bg.h);
glRasterPos2f(0,0);

    glDrawPixels(bg.w, bg.h, GL_RGB, GL_UNSIGNED_BYTE, (GLubyte*)bg.data);

glutSwapBuffers();
}


void Initialize() {
glClearColor(0.0, 0.0, 0.0, 0.0);
glEnable (GL_BLEND);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
// glViewport(0,0,100,100);
   glLineWidth(4);
glLineWidth(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 100.0, 0.0, 100.0, -10.0, 10.0);
glMatrixMode(GL_MODELVIEW);
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
glMatrixMode(GL_MODELVIEW);

}


int main(int iArgc, char** cppArgv) {
glutInit(&iArgc, cppArgv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1366, 768);
glutInitWindowPosition(50, 50);
glutCreateWindow("Moving Line");
Initialize();
// bg.data=read_img("logo.tiff",&bg.w,&bg.h,FIF_TIFF);
//init ();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_GEQUAL);
  
 glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
  
glutMainLoop();
return 0;
}
