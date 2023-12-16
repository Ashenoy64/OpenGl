#include<gl/glut.h>
#include<iostream>
#include <iostream>
#include "Utilities.h"

#define ChangeInAngle 0.008f

float angle = 0.0f;
float x = 0.0f;

void Animation()
{
	static int prvMs = glutGet(GLUT_ELAPSED_TIME);
	const int curMs = glutGet(GLUT_ELAPSED_TIME);
	const double  delta = (curMs - prvMs) / 1000.0;

	angle += ChangeInAngle;
	x += 2 * PI * RADIUS * ChangeInAngle /360 ;
	glutPostRedisplay();

}



void Display()
{
	MainRenderSequence(angle,x);
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	//initialize window size
	glutInitWindowSize(720, 720);

	//initialize window posiotion
	glutInitWindowPosition(10, 10);

	//initialize window to display rgb	
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	//create the window
	glutCreateWindow("GL");


	glutDisplayFunc(Display);
	glEnable(GL_DEPTH_TEST);
	
	glutIdleFunc(Animation);


	glutMainLoop();

}
