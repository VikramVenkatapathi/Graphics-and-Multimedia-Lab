/* Cohen-Sutherland Line Clipping Algorithm with Window to viewport Mapping */
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

#define reg_code int
double xmin, ymin, xmax, ymax; // Window boundaries

//bit codes for the top,bottom,right & left
const int TOP = 8;
const int BOTTOM = 4;
const int RIGHT = 2;
const int LEFT = 1;
//used to compute bit codes of a point
reg_code Compute_Reg_code(double x, double y);
void draw_output(double x0, double y0, double x1, double y1, int count);

/*Cohen - Sutherland clipping algorithm clips a line from P0 = (x0, y0) to P1 = (x1, y1)
  against a rectangle with diagonal from (xmin, ymin) to (xmax, ymax).*/

void draw_output(double x0, double y0, double x1, double y1, int count)
{

	int temp_x=0, temp_y=0;
	/*if (count == 1) {
		temp_x = 200;
		temp_y = 200;
	}
	else if (count == 2) {
		temp_x = 400;
		temp_y = 200;
	}
	else if (count == 3) {
		temp_x = 0;
		temp_y = 0;
	}
	else {
		temp_x = 200;
		temp_y = 0;
	}*/

	//glClear(GL_COLOR_BUFFER_BIT);
	//draw the line with blue color
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2d(x0 + temp_x, y0 + temp_y);
	glVertex2d(x1 + temp_x, y1 + temp_y);
	glEnd();

	//draw a red colored window
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(xmin + temp_x, ymin + temp_y);
	glVertex2f(xmax + temp_x, ymin + temp_y);
	glVertex2f(xmax + temp_x, ymax + temp_y);
	glVertex2f(xmin + temp_x, ymax + temp_y);
	glEnd();
}

void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1)
{
	int count = 0;
	//reg_codes for P0, P1, and whatever point lies outside the clip rectangle
	reg_code reg_code0, reg_code1, reg_codeOut;
	bool accept = false, done = false;
	//compute RegionCodes(RC) for the endpoints
	reg_code0 = Compute_Reg_code(x0, y0);
	reg_code1 = Compute_Reg_code(x1, y1);
	do
	{
		if (!(reg_code0 | reg_code1)) //if(RC==0000) -> Trivially accept & exit
		{
			accept = true;

			done = true;
		}
		else if (reg_code0 & reg_code1) // if(RC==1111) -> Trivially reject & exit
			done = true;
		else
		{ /*failed both tests, so calculate the line segment to clip from an
			outside point to an intersection with clip edge*/
			double x, y;
			//At least one endpoint is outside the clip rectangle; pick it.
			reg_codeOut = reg_code0 ? reg_code0 : reg_code1;
			/*Now find the intersection point;
			  use formulas y = y0 + slope * (x - x0) ; x = x0 + (1/slope)* (y - y0)*/
			if (reg_codeOut & TOP) //point is above the clip rectangle
			{
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
				count += 1;
			}
			else if (reg_codeOut & BOTTOM) //point is below the clip rectangle
			{
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
				count += 1;
			}
			else if (reg_codeOut & RIGHT)//point is to the right of clip rectangle
			{
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
				count += 1;
			}
			else //point is to the left of clip rectangle
			{
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
				count += 1;
			}
			/*Now we move outside point to intersection point to clip
			  and gets ready for next pass.*/
			if (reg_codeOut == reg_code0)
			{
				x0 = x;
				y0 = y;
				reg_code0 = Compute_Reg_code(x0, y0);
			}
			else
			{
				x1 = x;
				y1 = y;
				reg_code1 = Compute_Reg_code(x1, y1);
			}
		}
		draw_output(x0, y0, x1, y1, count);
	} while (!done);

	//draw a red colored viewport -> OUTPUT

	if (accept)
	{
		draw_output(x0, y0, x1, y1, count);
	}
	cout << "\n\tClipped Line Endpoints : (" << x0 << "," << y0 << ") ; (" << x1 << "," << y1 << ")";

}

/*Compute the bit code for a point(x, y) using the clip rectangle
  bounded diagonally by (xmin, ymin), and (xmax, ymax)*/
reg_code Compute_Reg_code(double x, double y)
{
	reg_code code = 0;
	if (y > ymax) //above the clip window - enables TOP bit
		code |= TOP;
	else if (y < ymin) //below the clip window - enables BOTTOM bit
		code |= BOTTOM;
	if (x > xmax) //to the right of clip window - enables RIGHT bit
		code |= RIGHT;
	else if (x < xmin) //to the left of clip window - enables LEFT bit
		code |= LEFT;
	return code;
}
void display()
{
	double x0, y0, x1, y1;
	//cout << "\n\n\tEnter the no. of lines to be clipped : ";
	//cin >> n_lines;
	cout << "\n\n\tEnter the line end-points : ";
	cout << "\n\t\tX_0 Y_0 : ";
	cin >> x0 >> y0;
	cout << "\n\t\tX_1 Y_1 : ";
	cin >> x1 >> y1;

	glClear(GL_COLOR_BUFFER_BIT);
	//draw the line with red color
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	/*glVertex2d(x0, y0 + 200);
	glVertex2d(x1, y1 + 200);*/
	glVertex2d(x0, y0);
	glVertex2d(x1, y1);
	glEnd();

	//draw a blue colored window
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);

	/*glVertex2d(xmin, ymin + 200);
	glVertex2d(xmax, ymin + 200);
	glVertex2d(xmax, ymax + 200);
	glVertex2d(xmin, ymax + 200);*/
	glVertex2d(xmin, ymin);
	glVertex2d(xmax, ymin);
	glVertex2d(xmax, ymax);
	glVertex2d(xmin, ymax);
	glEnd();
	CohenSutherlandLineClipAndDraw(x0, y0, x1, y1);

	glFlush();
}
void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1080.0, 1080.0, -1080.0, 1080.0);
	//gluOrtho2D(-720.0, 720.0, 720.0, 720.0);
	//gluOrtho2D(-500.0, 500.0, -500.0, 500.0);

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cohen Sutherland Line Clipping Algorithm");
	cout << "\n\t----------------------------------------";
	cout << "\n\tCohen Sutherland Line Clipping Algorithm";
	cout << "\n\t----------------------------------------";

	cout << "\n\nEnter the Clipping Window co-ods :-";
	cout << "\n\t X_min X_max : ";
	cin >> xmin >> xmax;
	cout << "\n\t Y_min Y_max : ";
	cin >> ymin >> ymax;

	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	return 0;
}