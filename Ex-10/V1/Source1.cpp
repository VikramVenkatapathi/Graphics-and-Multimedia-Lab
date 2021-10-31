#include<iostream>
#include <GL/glut.h>
using namespace std;

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glShadeModel(GL_SMOOTH);

	glColor3f(1.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
void disp(int i) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLoadIdentity();
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
	
}
void display() {

	disp(1);
	glRotatef(0, 0, 1, 0);
	glRotatef(0, 1, 0, 0);
	
	glColor3f(0.0, 1.0, 1.0);

	//glutSolidTorus(0.2, 0.4, 10, 30);
	//glutSolidTeapot(0.5);
	//glutSolidIcosahedron();
		//void glutSolidIcosahedron(void);
	glutSolidSphere(0.5,100,100);
		//void glutSolidSphere(GLdouble radius,GLint slices, GLint stacks);
	
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Ex10: 3-D Scene");

	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
