// mouse.cpp
// Glenn G. Chappell
// 16 Sep 2010
//
// For CS 381 Fall 2010
// Mouse Demo

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <cstdlib>       // Do this before GL/GLUT includes
using std::exit;
#ifndef __APPLE__
# include <GL/glut.h>    // GLUT stuff, includes OpenGL headers as well
#else
# include <GLUT/glut.h>  // Apple puts glut.h in a different place
#endif
int rb=0;

// Global variables
// Keyboard
enum { ESCKEY = 27 };          // ASCII value of Escape

// Window/viewport
const int startwinsize = 400;  // Starting window width & height (pixels)
int winw, winh;                // Wid/ht of window (pixels)

// Cursor
double cursx, cursy;           // x, y pos for printing (camunits)
double cursheight;             // Height of text line (camunits)

// Object
// Square #1
double s1halfsize;             // Half of side length of square 1 (camunits)
double s1xpos;                 // x pos of square 1 center (camunits)
double s1ypos;                 // y pos of square 1 center (camunits)
bool leftMouseDown;            // True if left mouse button is down


// printBitmap
// Prints the given string at the raster position cursx, cursy
//  using GLUT bitmap fonts and the current transformation.
// Decreases cursy by cursheight.
//
// NOTE: You probably don't want any rotations in the model/view
//  transformation when calling this function.
void printBitmap(const string & msg)
{
    glRasterPos2d(cursx, cursy);
    for (string::const_iterator ii = msg.begin();
         ii != msg.end();
         ++ii)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);
    }
    cursy -= cursheight;
}


// drawSquare
// Draws a filled square, using current GL states,
//  in the x,y plane, centered at the origin, aligned w/ x & y axes,
//  with side 2.
void drawSquare()
{
    glBegin(GL_QUADS);
        glVertex2d(-1., -1.);
        glVertex2d( 1., -1.);
        glVertex2d( 1.,  1.);
        glVertex2d(-1.,  1.);
    glEnd();
}


// myDisplay
// The GLUT display function
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw objects

    // Square following mouse
    glLoadIdentity();
    if(!rb)glTranslated(s1xpos, s1ypos, 0.);
    glScaled(s1halfsize, s1halfsize, s1halfsize);
    if (leftMouseDown)
    {
        glColor3d(0.9, 0.1, 0.3);
    }
    else
    {
        glColor3d(0.1, 0.9, 0.3);
    }
    drawSquare();

    // Draw documentation
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);  // Set up simple ortho projection
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(-1., 1., -1., 1.);
    glColor3d(0., 0., 0.);        // Black text
    cursx = -0.9;                 // Start of first text line
    cursy = 0.9;
    cursheight = 0.1;             // Height of each text line
    printBitmap("The square responds to");
    printBitmap("  - the mouse position");
    printBitmap("  - the left mouse button");
    printBitmap("");
    printBitmap("Esc         Quit");
    glPopMatrix();                // Restore prev projection
    glMatrixMode(GL_MODELVIEW);

    glutSwapBuffers();
}


// myIdle
// The GLUT idle function
void myIdle()
{
    // Print OpenGL errors, if there are any (for debugging)
    if (GLenum err = glGetError())
    {
        cerr << "OpenGL ERROR: " << gluErrorString(err) << endl;
    }
}


// myKeyboard
// The GLUT keyboard function
void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ESCKEY:  // Esc: quit
        exit(0);
        break;
    }
}


// myReshape
// The GLUT reshape function
void myReshape(int w, int h)
{
    // Save window dimensions
    winw = w;
    winh = h;

    // Set up viewport
    glViewport(0, 0, w, h);

    // Set up projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1., 1., -1., 1.);

    glMatrixMode(GL_MODELVIEW);  // Always go back to model/view mode
}


// saveMousePos
// Convert given mouse pos (pixels) to cam coords,
//  save it in globals s1xpos, s1ypos, and post redisplay
// Uses globals winw, winh
void saveMousePos(int x, int y)
{
    // winw, winh saved by myReshape
    s1xpos = -1. + (1.-(-1.))*double(x)/winw;
    s1ypos = -1. + (1.-(-1.))*(double(y)-winh)/(-winh);
    glutPostRedisplay();
}


// myMouse
// The GLUT Mouse function
// If left button state has changed, then save it
// Save mouse pos
void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        leftMouseDown = (state == GLUT_DOWN);
        glutPostRedisplay();
    }
if(button==GLUT_RIGHT_BUTTON)
{
    rb=(state==GLUT_DOWN);
glutPostRedisplay();}
    saveMousePos(x, y);
}


// myMotion
// The GLUT Motion function
// Save mouse pos
void myMotion(int x, int y)
{
    saveMousePos(x, y);
}


// myPassiveMotion
// The GLUT Passive Motion function
// Save mouse pos
void myPassiveMotion(int x, int y)
{
    saveMousePos(x, y);
}


// init
// Initializes GL states
// Called by main after window creation
void init()
{
    // Objects
    s1halfsize = 0.1;
    s1xpos = 0.0;
    s1ypos = 0.0;
    leftMouseDown = false;

    // OpenGL Stuff
    glClearColor(0.7, 0.7, 0.7, 0.0);
}


int main(int argc, char ** argv)
{
    // Initialize OpenGL/GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        // NOTE: Double buffering!

    // Make a window
    glutInitWindowSize(startwinsize, startwinsize);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("CS 381 - Mouse Demo");

    // Initialize GL states & register GLUT callbacks
    init();
    glutDisplayFunc(myDisplay); 
    glutIdleFunc(myIdle);
    glutKeyboardFunc(myKeyboard);
    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutPassiveMotionFunc(myPassiveMotion);

    // Do something
    glutMainLoop();

    return 0;
}

