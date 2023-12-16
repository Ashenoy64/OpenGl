#pragma once
#include<gl/glut.h>
#include<iostream>


void sphereMouseEvent()
{

}

void sphereMouseAction()
{

}


void keyBoard()
{

}

void arrowKey()
{

}


void setMaterial(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
	GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
	GLfloat specularR, GLfloat specularG, GLfloat specularB,
	GLfloat shininess) {

	GLfloat ambient[] = { ambientR, ambientG, ambientB };
	GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB };
	GLfloat specular[] = { specularR, specularG, specularB };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}


void reshape(int width, int height) {

	/* define the viewport transformation */
	glViewport(0, 0, width, height);
}

void initLight()
{
	/* set up lights */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

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


void ApplyPerspectiveProjection(float x, float y, float z)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 1.0, 100.0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(x, y, z,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
}




void Serplenskis()
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 1.0, 100.0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0, 1.0, 3.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	double array[5][3] = {
	0.0,0.8,0.0,
	-0.8,-0.8,0.8,
	-0.8,-0.8,-0.8,
	0.8,-0.8,-0.8,
	0.8,-0.8,0.8,
	};

	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(2);
	glBegin(GL_POINTS);
	for (int i = 0;i < 5;i++)
	{
		glVertex3d(array[i][0], array[i][1], array[i][1]);
	}
	glEnd();
	glFlush();
	int count = 100000;

	double x = 0.0;
	double y = 0.0;
	double z = 0.0;


	glLineWidth(1.5);
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.8, 0.0);
	glVertex3d(-0.8, -0.8, 0.8);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex3d(0.0, 0.8, 0.0);
	glVertex3d(-0.8, -0.8, -0.8);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex3d(0.0, 0.8, 0.0);
	glVertex3d(0.8, -0.8, -0.8);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex3d(0.0, 0.8, 0.0);
	glVertex3d(0.8, -0.8, 0.8);
	glEnd();
	glFlush();



	glBegin(GL_LINES);
	glVertex3d(0.8, -0.8, -0.8);
	glVertex3d(0.8, -0.8, 0.8);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex3d(-0.8, -0.8, 0.8);
	glVertex3d(0.8, -0.8, 0.8);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex3d(-0.8, -0.8, -0.8);
	glVertex3d(0.8, -0.8, -0.8);
	glEnd();
	glFlush();


	glBegin(GL_LINES);
	glVertex3d(-0.8, -0.8, -0.8);
	glVertex3d(-0.8, -0.8, 0.8);
	glEnd();
	glFlush();


	srand((unsigned)time(NULL));
	for (int i = 0;i < count;i++)
	{
		glBegin(GL_POINTS);
		glPointSize(3);
		int vertexIndex = ((float)rand() / RAND_MAX) * 5;
		double x_middle = (array[vertexIndex][0] + x) / 2;
		double y_middle = (array[vertexIndex][1] + y) / 2;
		double z_middle = (array[vertexIndex][2] + z) / 2;
		glColor3d(x_middle, y_middle, z_middle);
		//std::cout << x_middle << "  "<< y_middle << std::endl;

		glVertex3d(x_middle, y_middle, z_middle);
		glEnd();
		glFlush();

		x = x_middle;
		y = y_middle;
		z = z_middle;

	}




}



void TeaPotAnimated(float x, float y, float z)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ApplyPerspectiveProjection(x, y, z);


	glPushMatrix();
	glColor3f(0.957, 0.643, 0.376);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(2.0, 0.0, 0.0);
	glutSolidTeapot(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.957, 0.643, 0.376);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(-2.0, 0.0, 0.0);
	glutSolidTeapot(1);
	glPopMatrix();



	glFlush();
}


void AnimatedCube(float cameraX, float cameraY, float cameraZ)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 1.0, 100.0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraX, cameraY, cameraZ,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);





	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.4, -0.4, -0.2);
	glVertex3f(-0.4, 0.4, -0.2);
	glVertex3f(0.4, -0.4, -0.2);

	glEnd();

	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0.4, -0.4, -0.2);
	glVertex3f(0.4, 0.4, -0.2);
	glVertex3f(-0.4, 0.4, -0.2);
	glEnd();


	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(0.4, -0.4, -0.2);
	glVertex3f(0.4, -0.4, -0.8);
	glVertex3f(0.4, 0.4, -0.8);
	glEnd();

	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(0.4, -0.4, -0.2);
	glVertex3f(0.4, 0.4, -0.2);
	glVertex3f(0.4, 0.4, -0.8);
	glEnd();


	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.4, 0.4, -0.2);
	glVertex3f(0.4, 0.4, -0.8);
	glVertex3f(0.4, 0.4, -0.2);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.4, 0.4, -0.2);
	glVertex3f(0.4, 0.4, -0.8);
	glVertex3f(-0.4, 0.4, -0.8);
	glEnd();





	glutSwapBuffers();
	glFlush();
}


void TeaPot(float angle)
{

	angle = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	ApplyPerspectiveProjection(0.0, 10.0, 0.0);

	glPushMatrix();
	glColor3f(0.957, 0.643, 0.376);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(2, 0, 0);
	glRotatef(angle, 1, 0, 0);
	glutSolidTeapot(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.957, 0.643, 0.376);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(-2, 0, 0);
	glRotatef(-angle, 1, 0, 0);
	glutSolidTeapot(1);
	glPopMatrix();

	glFlush();
}