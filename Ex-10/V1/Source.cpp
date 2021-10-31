//#include<GL/glut.h>
//#include<iostream>
//#include<vector>
//using namespace std;
//
//GLfloat X_ang = 0, Y_ang = 0;
//bool flag = true;
//vector<vector<GLfloat>> coords(8, vector<GLfloat>(3));
//
//void init(void)
//{
//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat mat_shininess[] = { 50.0 };
//	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glShadeModel(GL_SMOOTH);
//
//	glColor3f(1.0, 0.0, 0.0);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//}
//
//
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-500, 500, -500, 500, -500.0, 500.0);
//	glMatrixMode(GL_MODELVIEW);
//	glRotatef(X_ang, 0, 1, 0);
//	glRotatef(Y_ang, 1, 0, 0);
//	//glShadeModel(GL_SMOOTH);
//	//glutSolidTorus(50,100,10,20);
//	//void glutSolidCone(GLdouble base, GLdouble height,GLint slices, GLint stacks);
//	glutSolidCone(100, 400, 100, 100);
//	//glutSolidTeapot(100);
//	glFlush();
//}
//
//void timer(unsigned char c, int x, int y) {
//	X_ang += 0.2;
//	Y_ang += 0.2;
//	if (X_ang == 360) X_ang = 0;
//	if (Y_ang == 360) Y_ang = 0;
//	glutPostRedisplay();
//	//glutTimerFunc(100, timer, v);
//}
//
//
//void keyPress(int key, int x, int y) {
//	switch (key) {
//	case GLUT_KEY_RIGHT: 
//		X_ang += 0.5;
//		break;
//	case GLUT_KEY_LEFT:
//		X_ang -= 0.5;
//		break;
//	case GLUT_KEY_UP:
//		Y_ang += 0.5;
//		break;
//	case GLUT_KEY_DOWN:
//		Y_ang -= 0.5;
//		break;
//	case GLUT_KEY_HOME: 
//		flag = !flag;
//		break;
//	}
//	glutPostRedisplay();
//}
//
//
//int main_a(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Ex10: Creating a 3D Scene");
//	init();
//	glutDisplayFunc(display);
//	glutSpecialFunc(keyPress);
//	//glutTimerFunc(100, timer, 0);
//	//glutKeyboardFunc(timer);
//	glutMainLoop();
//
//	return 0;
//}