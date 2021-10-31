//#include <GL/glut.h>
//#include<iostream>
//#include<stdio.h>
//#include<vector>
//
//using namespace std;
//constexpr auto PI = 3.14;
//
////Output Window constraints
//const int WINDOW_WIDTH = 800;
//const int WINDOW_HEIGHT = 800;
//const int X_MIN = -675;
//const int X_MAX = 675;
//const int Y_MIN = -675;
//const int Y_MAX = 675;
//const int Z_MIN = -675;
//const int Z_MAX = 675;
//int option;
//
////to store the TRANSFORMATION matrix
////vector<vector<double>> Transformation(4, vector<double>(4, 0));
//
////to store the 3D object's vertices
//vector<vector<double>> vertices(24, vector<double>(3, 0));
//
//
////void draw_3D_Object(vector<vector<double>> temp, int count);
//void menu_driven();
//void disp();
//
//#include"Header.h"
//
//void init()
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);// Set background color to black and opaque
//	glOrtho(X_MIN, X_MAX, Y_MIN, Y_MAX, Z_MIN, Z_MAX);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//}
//
//void myDisplay()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear color and depth buffers
//
//	//draw X_Y_Z planes
//	glBegin(GL_LINES);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex3d(-1100, -800, 0);
//	glVertex3d(0, 0, 0);
//	glVertex3d(0, 0, 0);
//	glVertex3d(1100, 0, 0);
//	glVertex3d(0, 0, 0);
//	glVertex3d(0, 1100, 1100);
//	glEnd();
//
//	disp(); //to rotate ORIGINAL object
//	//draw_3D_Object(vertices, 0);
//	menu_driven();
//	glFlush();
//}
//
//int main(int argc, char* argv[]) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Ex-9: 3-Dimensional Projections");
//
//	//vertices = set_Vertices();
//	cout << "\n\t\t-------------------------------";
//	cout << "\n\t\tEx-9: 3-Dimensional Projections";
//	cout << "\n\t\t-------------------------------";
//	cout << "\n\n\tOptions :-";
//	cout << "\n\t\t1) Orthographic parallel projection ";
//	cout << "\n\t\t2) Perspective projection";
//	cout << "\n\n\t\tSelect option -> ";
//	cin >> option;
//
//
//	init();
//	glutDisplayFunc(myDisplay);
//	glutMainLoop();
//	return 0;
//}