#pragma once
#include<gl/glut.h>
#include<iostream>
#include<math.h>

void ApplyPerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, 1.0, 1.0, 100.0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}


void ChangeCameraPosition(float x, float y, float z)
{
	gluLookAt(x, y, z,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);


}



void GenerateSpine()
{
	glPushMatrix();//Pelvis
		glScalef(1, 2, 1);
		glutSolidSphere(0.05, 50, 50);
		glPushMatrix();//Upper Body
			glTranslatef(0, 0.1, 0.0);
			glutSolidSphere(0.05, 50, 50);
			glTranslatef(0, 0.1, 0.0);
			glutSolidSphere(0.05, 50, 50);		
		glPopMatrix();
	glPopMatrix();
}

void GenerateHead(float x)
{
	//glTranslatef(0.1,0,0);
	glPushMatrix();//Skull
		glPushMatrix();//Head
		glRotatef(x, 0, 1,0);
			glTranslatef(0, 0.75, 0.0);
			glutSolidSphere(0.1, 50, 50);
			glPushMatrix(); //Neck
				glScalef(0.5, 1.5, 0.5);
				glTranslatef(0, -0.115, 0.0);
				glutSolidSphere(0.05, 50, 50);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}


void GenerateLeftArm()
{

	glPushMatrix();
	glTranslatef(-0.15, 0.5, 0);
	glPushMatrix();
	glScalef(3, 1, 1);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.15,-0.1,0);
	glScalef(0.5, 2, 0.5);
	glutSolidSphere(0.05,50,50);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.15, -0.3, 0.0);
	glScalef(0.5, 2, 0.5);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPopMatrix();
}


void GenerateRighArm()
{
	glPushMatrix();
	glTranslatef(0.15, 0.5, 0);
	glPushMatrix();
	glScalef(3, 1, 1);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15, -0.1, 0);
	glScalef(0.5, 2, 0.5);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15, -0.3, 0.0);
	glScalef(0.5, 2, 0.5);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();


	glPopMatrix();
}

void GenerateLeftLeg()
{
	glPushMatrix();
	glTranslatef(-0.1, -0.1, 0);
	glPushMatrix();
	glScalef(2.0, 0.5, 0.5);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1, -0.125, 0);
	glScalef(0.5, 2.5, 0.5);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1, -0.35, 0.0);
	glScalef(0.5, 2.5, 0.5);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1, -0.45, 0.0);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();


	glPopMatrix();
}


void GenerateRightLeg()
{
	glPushMatrix();
	glTranslatef(0.1, -0.1, 0);
	glPushMatrix();
	glScalef(2.0, 0.5, 0.5);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, -0.125, 0);
	glScalef(0.5, 2.5, 0.5);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, -0.35, 0.0);
	glScalef(0.5, 2.5, 0.5);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, -0.45, 0.0);
	glutSolidSphere(0.05, 50, 50);
	glPopMatrix();

	glPopMatrix();
}


void GenerateSkeleton(float angle) {
	
	
	glPushMatrix();
		GenerateSpine();
		GenerateHead(angle);
		GenerateLeftArm();
		GenerateRighArm();
		GenerateRightLeg();
		GenerateLeftLeg();
	glPopMatrix();
}

void MainRenderSequence(float angle)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	InitLight();
	GenerateSkeleton(angle);
	glFlush();
}