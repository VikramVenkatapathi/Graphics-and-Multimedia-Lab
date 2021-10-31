#include<GL/glut.h> 
void myInit_a() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f);
	glPointSize(20);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);

}
void myDisplay_a() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	/*POINT
	glBegin(GL_POINTS);
	glVertex2d(250,250);*/
	
	/*LINE
	glBegin(GL_LINES);
	glVertex2f(200, 200);
	glVertex2f(300, 300);*/

	/*LINE_STRIP
	glBegin(GL_LINE_STRIP);
	glVertex2f(200, 200);
	glVertex2f(300, 300);
	glVertex2f(400, 200);*/

	/*LINE_LOOP
	glBegin(GL_LINE_LOOP);
	glVertex2f(100.0f, 100.0f);
	glVertex2f(400.0f, 100.0f);
	glVertex2f(400.0f, 400.0f);
	glVertex2f(100.0f, 400.0f);*/

	/*TRIANGLE
	glBegin(GL_TRIANGLES);
	glVertex2f(100.0f, 100.0f);
	glVertex2f(500.0f, 100.0f);
	glVertex2f(300.0f, 300.0f);*/

	/*QUAD
	glBegin(GL_QUADS); 
	glVertex2f(300.0f, 200.0f);
	glVertex2f(400.0f, 300.0f);
	glVertex2f(300.0f, 400.0f);
	glVertex2f(200.0f, 300.0f);*/

	/*QUAD_STRIP
	glBegin(GL_QUAD_STRIP);
	glVertex2f(200.0f, 200.0f);
	glVertex2f(400.0f, 200.0f);
	glVertex2f(400.0f, 400.0f);
	glVertex2f(200.0f, 400.0f);
	glVertex2f(500.0f, 300.0f);*/

	//POLYGON
	glBegin(GL_POLYGON);
	glVertex2f(200.0f, 200.0f);
	glVertex2f(400.0f, 200.0f);
	glVertex2f(400.0f, 300.0f);
	glVertex2f(200.0f, 400.0f);
	glVertex2f(200.0f, 400.0f);

	glEnd();
	glFlush();
}
int main_a(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(230,230);
	glutCreateWindow("Ex_1-a");
	glutDisplayFunc(myDisplay_a);
	myInit_a();
	glutMainLoop();
	return 1;
}