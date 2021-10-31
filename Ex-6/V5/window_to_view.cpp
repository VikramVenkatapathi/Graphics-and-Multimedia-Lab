//#include<vector>
//#include<iostream>
//#include<GL/glut.h>
//#include<utility>
//#include<math.h>
//using namespace std;
//int n;
//vector<pair<int, int>> coordinates;
//
//int xw_min = 0, yw_min = 0, xw_max = 1000, yw_max = 1000;
//int xv_min, xv_max, yv_min, yv_max;
//double sx, sy;
//
//void myInit(void) {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glPointSize(4.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, 720,0, 720);
//}
//void draw_ViewPort_Window() {
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex2d(xv_min, yv_min);
//	glVertex2d(xv_min, yv_max);
//	glVertex2d(xv_max, yv_max);
//	glVertex2d(xv_max, yv_min);
//	glEnd();
//}
//void draw_Window_Object() {
//	glBegin(GL_LINE_LOOP);
//	glColor3f(1.0f, 0.0f, 0.0f);
//	for (int i = 0; i < n; i++) {
//		glVertex2d(coordinates[i].first, coordinates[i].second);
//	}
//	glEnd();
//}
//void draw_ViewPort_Object() {
//	glBegin(GL_LINE_LOOP);
//	glColor3f(1.0f, 0.0f, 1.0f);
//	for (int i = 0; i < n; i++) {
//		glVertex2d(xv_min + (coordinates[i].first - xw_min) * sx, yv_min + (coordinates[i].second - yw_min) * sy);
//	}
//	glEnd();
//}
//void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.0, 0.0);
//	draw_Window_Object();
//	draw_ViewPort_Object();
//	draw_ViewPort_Window();
//	glFlush();
//}
//int main(int argc, char** argv) {
//
//	cout << "\n\t\t--------------------------------------";
//	cout << "\n\t\tEx:6 (b) Windowing in C++ using OpenGL" ;
//	cout << "\n\t\t--------------------------------------";
//
//	cout << "\n\n\tNo. of vertices of OBJECT : ";
//	cin >> n;
//	int x, y;
//	for (int i = 0; i < n; i++) {
//		cout << "\n\tVertex_" << i + 1 << " : ";
//		cin >> x >> y;
//		coordinates.push_back(make_pair(x, y));
//	}
//	cout << "\n\tEnter Viewport details";
//	cout << "\n\n\t\tMin x & Max x : ";
//	cin >> xv_min >> xv_max;
//	cout << "\n\t\tMin y & Max y : ";
//	cin >> yv_min >> yv_max;
//
//	sx = (xv_max - xv_min) * 1.0 / (xw_max - xw_min);
//	sy = (yv_max - yv_min) * 1.0 / (yw_max - yw_min);
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(720, 720);
//	glutCreateWindow("Window to Viewport Transformation");
//	glutDisplayFunc(myDisplay);
//	myInit();
//	glutMainLoop();
//	return 0;
//}