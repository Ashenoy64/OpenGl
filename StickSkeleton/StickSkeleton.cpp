#include<gl/glut.h>
#include<iostream>
#include <math.h>
#define PI 3.14159265358979323846
#include "Utilities.h"


float angle = 0.0f;
float tx = 0.0;
float ty = 0.0;
float tz = 0.0;

float xrot = 0.0f;
float yrot = 0.0f;

float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

double valZoom = 10.0;

double camX = 0, camY = 0, camZ = 10.0;

void Animation()
{
	//static int prvMs = glutGet(GLUT_ELAPSED_TIME);
	//const int curMs = glutGet(GLUT_ELAPSED_TIME);
	//const double  delta = (curMs - prvMs) / 1000.0;
    angle = angle + 0.1;
	
	glutPostRedisplay();

}

void keyBoard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        ty = ty + 0.1;
        break;

    case 's':
        ty = ty - 0.1;
        break;

    case 'a':
        tx = tx - 0.1;
        break;

    case 'd':
        tx += 0.1;
        break;
    }
    glutPostRedisplay();

}

void arrowKey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        tz += 0.1;
        break;

    case GLUT_KEY_DOWN:
        tz -= 0.1;
        break;
    }
    camX = valZoom * (cos(xrot * PI / 180) * sin(yrot * PI / 180));
    camY = valZoom * (sin(xrot * PI / 180));
    camZ = valZoom * (cos(xrot * PI / 180) * cos(yrot * PI / 180));
    glutPostRedisplay();
}

void sphereMouseMotion(int x, int y) {
    if (mouseDown)
    {
        yrot = -(x + xdiff);
        xrot = (y + ydiff);
        if (xrot > 89) xrot = 89.0f;
        if (xrot < -89) xrot = -89.0f;

        camX = valZoom * (cos(xrot * PI / 180) * sin(yrot * PI / 180));
        camY = valZoom * (sin(xrot * PI / 180));
        camZ = valZoom * (cos(xrot * PI / 180) * cos(yrot * PI / 180));

    }
    glutPostRedisplay();
}

void sphereMouseEvent(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
    }
    else
        mouseDown = false;

    if (mouseDown)
    {
        xdiff = (yrot + x);
        ydiff = -y + xrot;
    }

    if (mouseDown)
    {
        //mouseDown = true;
        xdiff = (yrot + x);
        ydiff = -y + xrot;
    }
}


void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ApplyPerspectiveProjection();
    gluLookAt(
        camX, camY, camZ,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    );
    glTranslatef(tx, ty, tz);
    tx = 0;
    ty = 0;
    tz = 0;
    MainRenderSequence(angle);
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowSize(720, 720);

	glutInitWindowPosition(10, 10);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	glutCreateWindow("GL");


	glutDisplayFunc(Display);
	glEnable(GL_DEPTH_TEST);
    
    
	//glutIdleFunc(Animation);


    glutMouseFunc(sphereMouseEvent);
    glutMotionFunc(sphereMouseMotion);
    glutKeyboardFunc(keyBoard);
    glutSpecialFunc(arrowKey);

	glutMainLoop();

}
