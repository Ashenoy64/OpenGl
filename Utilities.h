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

void GenerateSpine()
{
	glPushMatrix();
		glScalef(1, 2, 1);
		glutSolidSphere(0.05, 50, 50);
		glTranslatef(0, 0.1, 0.0);
		glutSolidSphere(0.05, 50, 50);
		glTranslatef(0, 0.1, 0.0);
		glutSolidSphere(0.05, 50, 50);
	glPopMatrix();
}

void GenerateHead()
{
	glPushMatrix();
		glTranslatef(0, 0.75, 0.0);
		glutSolidSphere(0.1, 50, 50);
		glScalef(0.5, 1.5, 0.5);
		glTranslatef(0, -0.115, 0.0);
		glutSolidSphere(0.05, 50, 50);
	glPopMatrix();
}


void GenerateLeftArm()
{
	glPushMatrix();
	glTranslatef(-0.12 0.5, 0);
	glScalef(3, 0.5, 1);
	//glutSolidSphere(0.05, 50, 50);
	
	glPushMatrix();
		glRotatef(90,0,1,0);
		glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPopMatrix();
}

void GenerateLeftLeg()
{

}

void GenerateRighArm()
{

}

void GenerateRightLeg()
{

}


void GenerateSkeleton() {
	
	GenerateSpine();
	GenerateHead();
	GenerateLeftArm();
}

void MainRenderSequence(float wheelRotation, float translationX)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//ChangeCameraPosition(1.0, 2.0, 3.0);
	InitLight();

	GenerateSkeleton();

	glFlush();
}