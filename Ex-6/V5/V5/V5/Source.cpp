#include<iostream>
#include<GL/glut.h>
#include<vector>
#include "Source.h"
using namespace std;
constexpr auto PI = 3.14;
int n;

vector<pair<int, int>> coords;
int tx, ty;
int xr, yr;
int xf, yf;
double sx, sy;
double ang, angRad;
double shx, shy, sh;
int opt_1, opt_2;
char rfl, shd;
vector<vector<double>> Transformation(3, vector<double>(3, 0)); //final TRANSFORMATION matrix
vector<vector<double>> trans_1(3, vector<double>(3, 0));
vector<vector<double>> trans_2(3, vector<double>(3, 0));		//Matrices for the 2 transformations

#include"Header.h"

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-700, 700, -700, 700);
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	draw_X_Y_plane();
	drawPolygon();
	trans_1 = executeTransformMatrix(opt_1);
	trans_2 = executeTransformMatrix(opt_2);
	draw_Transformed_Polygon(trans_1,trans_2);
	glFlush();
}
void menu_driven(int opr) {

	switch (opr) {
		case 1: { 
			cout << "\n\n\t\tTranslation factor : ";
			cin >> tx >> ty;
			break;
		}
		case 2: {
			cout << "\n\n\t\tAngle of rotation : ";
			cin >> ang;
			angRad = ang * PI / 180;
			cout << "\n\t\tRotate about : ";
			cin >> xr >> yr;
			break;
		}
		case 3: {
			cout << "\n\n\t\tScaling factor : ";
			cin >> sx >> sy;
			cout << "\n\t\tScale about : ";
			cin >> xf >> yf;
			break;
		}
		case 4: {
			cout << "\n\t\tReflect about : " ;
			cout << "\n\t\t\ta) X-axis" ;
			cout << "\n\t\t\tb) Y-axis" ;
			cout << "\n\t\t\tc) origin" ;
			cout << "\n\t\t\td) X=Y line  -> " ;
			cin >> rfl;
			break;
		}
		case 5: {
			cout << "\n\t\tShear about : " ;
			cout << "\n\t\t\ta) X-direction" ;
			cout << "\n\t\t\tb) Y-direction -> " ;
			cin >> shd;
			cout << "\n\t\t\tEnter shear parameter : ";
			cin >> sh;
			break;
		}
		default: cout << "\n\n\t\tINVALID INPUT !!!";
	}
}
int main_a(int argc, char** argv) {
	cout << "\n\t--------------------------------------------";
	cout << "\n\tEx-6 Composite Transformations and Windowing";
	cout << "\n\t--------------------------------------------";
	cout << "\n\nNo. of vertices : ";
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cout << "\n\tVertex " << i + 1 << " : ";
		cin >> x >> y;
		coords.push_back(make_pair(x, y));
	}
	cout << "\n\nOptions :-";
	cout << "\n\t1) Translation";
	cout << "\n\t2) Rotation";
	cout << "\n\t3) Scaling with respect to";
	cout << "\n\t4) Reflection with respect to";
	cout << "\n\t5) Shearing";
	cout << "\n\tSelect option -> ";

	cout << "\n\n\tOption 1 : ";
	cin >> opt_1;
	menu_driven(opt_1);

	cout << "\n\tOption 2 : ";
	cin >> opt_2;
	menu_driven(opt_2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Ex-6 Composite Transformations and Windowing");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
