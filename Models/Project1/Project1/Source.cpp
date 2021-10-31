#include<iostream>
#include<gl/glut.h>
#include<vector>
using namespace std;

float c_x=0, c_y=0,r=500;
void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-600.0, 600.0, -600.0, 600.0);
}
void plot_point(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + c_x, y + c_y);
	glEnd();
}
void MidPointCircleAlgo()
{
	float x = 0;
	float y = r;
	float decision = 5 / 4 - r;
	plot_point(x, y);
	while (y > x) {
		if (decision < 0) {
			x++;
			decision += 2 * x + 1;
		}
		else {
			y--;
			x++;
			decision += 2 * (x - y) + 1;
		}
		plot_point(x, y);
		plot_point(x, -y);
		plot_point(-x, y);
		plot_point(-x, -y);
		plot_point(y,x);
		plot_point(-y, x);
		plot_point(y, -x);
		plot_point(-y, -x);
	}

}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	MidPointCircleAlgo();
	glutSolidTeapot(0.5);
	glRotated(45, 1, 0, 0);
	glRotated(45, 0, 1, 0);
	glFlush();
	vector<pair<int, int>> vertices;
	vertices.push_back({ 0,0 });
	vector<vector<double>> temp(3, vector<double>(3, 0));
	vector<double> n(3, 0);
}

int main(int argc, char** argv)
{
	cout << "\n\nEnter X-coordinate   : "; cin >> c_x;
	cout << "\nEnter Y-coordinate   : "; cin >> c_y;
	cout << "\nEnter radius         : "; cin >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Models");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();

	return 0;
}