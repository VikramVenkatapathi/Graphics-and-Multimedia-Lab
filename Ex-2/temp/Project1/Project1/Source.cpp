//#include<GL/glut.h>
//#include<stdlib.h>
//#include<iostream>
//#include<windows.h> 
//#include<GL/GL.h> 
//#include<GL/GLU.h> 
//#include<stdio.h>
//#include<math.h> 
//using namespace std;
//
//float x1, x2, m, y2;
//void init(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glColor3f(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
//	glPointSize(20);
//	glEnable(GL_DEPTH_TEST);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
//
//}
//void display(void)
//{
//	float dy, dx, step, x, y, k, X_inc, Y_inc;
//	dx = x2 - x1;
//	dy = y2 - m;
//
//	if (abs(dx) > abs(dy))
//	{
//		step = abs(dx);
//	}
//	else
//		step = abs(dy);
//
//	X_inc = dx / step;
//	Y_inc = dy / step;
//
//	x = x1;
//	y = m;
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//
//	for (k = 1; k <= step; k++)
//	{
//		x = x + X_inc;
//		y = y + Y_inc;
//
//		glBegin(GL_POINTS);
//		glVertex2i(x, y);
//		cout << "\n(" << x << "," << y << ")";
//		glEnd();
//	}
//
//	glFlush();
//}
//
//
//
//void lineSegment(void)
//{
//
//	glBegin(GL_POINTS);
//
//	printf("Enter x1 : ");
//	scanf_s("%f", &x1);
//	printf("Enter y1 : ");
//	scanf_s("%f", &m);
//	printf("Enter x2 : ");
//	scanf_s("%f", &x2);
//	printf("Enter y2 : ");
//	scanf_s("%f", &y2);
//
//	glEnd();
//	glFlush();
//}
//int main_a(int argc, char* argv[]) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(500, 500);
//	glutInitWindowSize(300, 300);
//	glutCreateWindow("DDA");
//	glutDisplayFunc(lineSegment);
//	init();
//	glutMainLoop();
//	return 0;
//
//}
