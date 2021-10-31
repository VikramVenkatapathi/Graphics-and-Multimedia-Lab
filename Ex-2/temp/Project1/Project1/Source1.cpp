#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
#include<windows.h> 
#include<GL/GL.h> 
#include<GL/GLU.h> 
#include<stdio.h>
#include<math.h> 

float x1, x2, m, y2;

void init(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
	glPointSize(2.0f);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}
void display(void)
{
	float dy, dx, step, x, y, k, Xin, Yin;
	dx = x2 - x1;
	dy = y2 - m;

	if (abs(dx) > abs(dy))
	{
		step = abs(dx);
	}
	else
		step = abs(dy);

	Xin = dx / step;
	Yin = dy / step;

	x = x1;
	y = m;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	printf("m=%f", dy/dx);
	printf("\n(%.2f,%.2f)",x,y);
	glEnd();

	for (k = 1; k <= step; k++)
	{
		x = x + Xin;
		y = y + Yin;

		glBegin(GL_POINTS);
		glVertex2i(x, y);
		printf("\n(%f,%f)", x, y);
		glEnd();
	}


	glFlush();
}



int main(int argc, char** argv) {
	printf("Enter x1 : ");
	scanf_s("%f", &x1);
	printf("Enter y1 : ");
	scanf_s("%f", &m);
	printf("Enter x2 : ");
	scanf_s("%f", &x2);
	printf("Enter y2 : ");
	scanf_s("%f", &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}