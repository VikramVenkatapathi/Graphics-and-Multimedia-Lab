//#include <stdio.h>
//#include <iostream>
//#include <GL/glut.h>
//using namespace std;
//
//int pntX1, pntY1, r;
//
//void plot(int x, int y)
//{
//	glBegin(GL_POINTS);
//	glVertex2i(x + pntX1, y + pntY1);
//	glEnd();
//}
//
//
//void myInit(void)
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glColor3f(0.0, 0.0, 0.0);
//	glPointSize(7.0f);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-100, 100, -100, 100);
//}
//
//
//void midPointCircleAlgo()
//{
//	int x = 0;
//	int y = r;
//	float decision = 5 / 4 - r;
//	plot(x, y);
//
//	while (y > x)
//	{
//		if (decision < 0)
//		{
//			x++;
//			decision += 2 * x + 1;
//		}
//		else
//		{
//			y--;
//			x++;
//			decision += 2 * (x - y) + 1;
//		}
//		plot(x, y);
//		plot(x, -y);
//		plot(-x, y);
//		plot(-x, -y);
//		plot(y, x);
//		plot(-y, x);
//		plot(y, -x);
//		plot(-y, -x);
//	}
//
//}
//
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	midPointCircleAlgo();
//
//	glFlush();
//}
//
//void main(int argc, char** argv)
//{
//	cout << "\n   Lab Exercise 4 : \n\tMidpoint Circle Drawing Algorithm \n\tin C++ using OpenGL";
//	cout << "\n\nEnter X-coordinate   : "; cin >> pntX1;
//	cout << "\nEnter Y-coordinate   : "; cin >> pntY1;
//	cout << "\nEnter radius         : "; cin >> r;
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 10);
//	glutCreateWindow("Mid Pt Circle Drawing Algo");
//	glutDisplayFunc(myDisplay);
//	myInit();
//	glutMainLoop();
//
//}