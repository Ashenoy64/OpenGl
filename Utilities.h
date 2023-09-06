#pragma once
#include<gl/glut.h>
#include<iostream>
#include<math.h>

#define PI 3.1415926f
#define INITIALX 1.5f
#define RADIUS 0.2f
#define SPOKES 16
#define SEGMENTS 300


void ApplyPerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, 1.0, 1.0, 100.0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}


void ChangeCameraPosition(float x, float y, float z)
{
	gluLookAt(x, y, z,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);


}


void InitLight()
{

	GLfloat lightpos[] = { 0.0, 0.0, 15.0 };
	GLfloat lightcolor[] = { 0.5, 0.5, 0.5 };
	GLfloat ambcolor[] = { 0.2, 0.2, 0.2 };
	GLfloat specular[] = { 1.0, 1.0, 1.0 };

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambcolor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightcolor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glEnable(GL_COLOR_MATERIAL); // tells opengl to maintain the original color of the object
}



void MainRenderSequence(float wheelRotation, float translationX)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//ChangeCameraPosition(1.0, 2.0, 3.0);
	InitLight();

	GenerateWheel(wheelRotation, translationX);

	glFlush();
}