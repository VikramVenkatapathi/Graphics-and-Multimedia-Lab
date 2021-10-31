#include<GL/glut.h> 
void myInit_b() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glPointSize(20);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);

}
int x = 50, y = 50;
bool isRed = true;

void whiteBox(int x, int y)
{
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x, y + 50);
	glVertex2i(x + 50, y + 50);
	glVertex2i(x + 50, y);
	glEnd();
}

void redBox(int x, int y)
{
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x, y + 50);
	glVertex2i(x + 50, y + 50);
	glVertex2i(x + 50, y);
	glEnd();
}
void myDisplay_b(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(128.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);

	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			isRed = true;
		}
		else
		{
			isRed = false;
		}

		for (int j = 0; j < 8; j++)
		{
			if (isRed)
			{
				redBox(x, y);
				isRed = false;
			}
			else
			{
				whiteBox(x, y);
				isRed = true;
			}
			x += 50;
		}
		y += 50;
		x = 50;
	}

	redBox(300, 300);
	whiteBox(350, 300);
	glFlush();
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutCreateWindow("Ex_1-b");
	glutDisplayFunc(myDisplay_b);
	myInit_b();
	glutMainLoop();
	return 1;
}