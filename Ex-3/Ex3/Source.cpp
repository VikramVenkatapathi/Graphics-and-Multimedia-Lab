#include <gl/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
	glPointSize(2.0f);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, X_inc, Y_inc;
	int x, y;
	float m;

	dx = x2 - x1;
	dy = y2 - y1;
	float dx_temp = float(dx), dy_temp =float(dy);
	m = dy_temp / dx_temp;
	if (m < 0)
		m *= -1;
	printf("m = %.2f",float(m));
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		printf("\n(%d,%d)", x, y);
		e = 2 * dy - dx;
		X_inc = 2 * (dy - dx);
		Y_inc = 2 * dy;
		for (i = 0; i < dx; i++) {
			if (e >= 0) {
				y += incy;
				e += X_inc;
			}
			else
				e += Y_inc;
			x += incx;
			draw_pixel(x, y);
			printf("\n(%d,%d)", x, y);
		}

	}
	else {
		draw_pixel(x, y);
		printf("\n(%d,%d)", x, y);
		e = 2 * dx - dy;
		X_inc = 2 * (dx - dy);
		Y_inc = 2 * dx;
		for (i = 0; i < dy; i++) {
			if (e >= 0) {
				x += incx;
				e += X_inc;
			}
			else
				e += Y_inc;
			y += incy;
			draw_pixel(x, y);
			printf("\n(%d,%d)", x, y);
		}
	}
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	draw_line(x1, x2, y1, y2);
	glFlush();
}

void main(int argc, char** argv) {

	printf("Enter x1 : ");
	scanf_s("%d", &x1);
	printf("Enter y1 : ");
	scanf_s("%d", &y1);
	printf("Enter x2 : ");
	scanf_s("%d", &x2); 
	printf("Enter y2 : ");
	scanf_s("%d", &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's ");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}