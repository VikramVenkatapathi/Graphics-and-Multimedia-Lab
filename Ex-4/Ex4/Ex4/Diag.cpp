#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;


void draw_Traffic_Light() {

	GLfloat x_i, y_i, theta = 0;
	GLfloat x_c, y_c, r;
	int i;
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	//signal box
	glVertex2d(40,30);
	glVertex2d(60,30);
	glVertex2d(60,80);
	glVertex2d(40,80);
	glEnd();

	glColor3f(0.55, 0.55, 0);
	//signal pole
	glBegin(GL_QUADS);
	glVertex2d(45,0);
	glVertex2d(55,0);
	glVertex2d(55,30);
	glVertex2d(45,30);
	glEnd();

	//RED light
	x_c = 50; y_c = 70; r = 6;
	glBegin(GL_POLYGON);
	for (i = 0; i <= 10000; i++) {
		theta += 0.001;
		x_i = x_c + r * cos(theta);
		y_i = y_c + r * sin(theta);
		glColor3f(1, 0, 0);
		glVertex2d(x_i, y_i);
	}
	glEnd();

	//YELLOW light
	x_c = 50; y_c = 55; r = 6;
	glBegin(GL_POLYGON);
	for (i = 0; i <= 10000; i++) {
		theta += 0.001;
		x_i = x_c + r * cos(theta);
		y_i = y_c + r * sin(theta);
		glColor3f(1, 1, 0);
		glVertex2d(x_i, y_i);
	}
	glEnd();

	//GREEN light
	x_c = 50; y_c = 40; r = 6;
	glBegin(GL_POLYGON);
	for (i = 0; i <= 10000; i++) {
		theta += 0.001;
		x_i = x_c + r * cos(theta);
		y_i = y_c + r * sin(theta);
		glColor3f(0, 1, 0);
		glVertex2d(x_i, y_i);
	}
	glEnd();

}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glPointSize(1.0);
	draw_Traffic_Light();
	
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 10);
	glutCreateWindow("4-b : Draw diags with Circle and lines");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}