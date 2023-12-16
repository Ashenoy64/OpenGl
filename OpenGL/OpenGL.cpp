#include<gl/glut.h>
#include<iostream>
#include"functions.h"
#include<math.h>






#define DB_PERLIN_IMPL
#define ANIMATION false


float x = 1.0;
float y = 2.0;
float z = 3.0;


bool yFlag = false;
bool zFlag = false;

float angle = 0.0;

void Animation()
{
	static int prvMs = glutGet(GLUT_ELAPSED_TIME);
	const int curMs = glutGet(GLUT_ELAPSED_TIME);
	const double  delta = (curMs - prvMs) / 1000.0;

	angle = angle + 0.01;
	glutPostRedisplay();

}

float axis = angle;
void Display()
{
	static int prvMs = glutGet(GLUT_ELAPSED_TIME);
	const int curMs = glutGet(GLUT_ELAPSED_TIME);
	const double  dt = (curMs - prvMs) / 1000.0;
	//TeaPotAnimated(2+cos(angle) * 10, dt , 2+sin(angle)*10);
	//TeaPotAnimated(0.0, 0.0, 0.0);
	//TeaPot(angle);
	Serplenskis();
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
	initLight();
	glutIdleFunc(Animation);
	//glutMouseFunc(sphereMouseEvent);
	//glutMotionFunc(sphereMouseMotion);
	//glutKeyboardFunc(keyBoard);
	//glutSpecialFunc(arrowKey);


	glutMainLoop();

}

