#include <GL\glut.h>

void myInit_c(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 400.0); 

}
void myDisplay_c(void)
{

    glClear(GL_COLOR_BUFFER_BIT); // clears the screen
    glColor3f(0.5f, 0.5f, 0.5f);// sets the drawing colour

    glPointSize(4.0);

    glBegin(GL_POLYGON);
    
    //bottom
    glVertex2i(20, 20);
    glVertex2i(320, 20);
    glVertex2i(320, 200);
    glVertex2i(20, 200);
    glEnd();


    // Window

    glColor3f(0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f);
    glPointSize(4.0);
    glRectf(60, 60, 120, 120);

    //Door
   
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);

    glVertex2i(150, 30);
    glVertex2i(210, 30);
    glVertex2i(210, 150);
    glVertex2i(150, 150);


    glEnd();

    //Triangle
    glColor3f(255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f);
    glBegin(GL_POLYGON);

    glVertex2i(20, 200);
    glVertex2i(320, 200);
    glVertex2i(170, 310);
    glEnd();

    glFlush(); // sends all output to display;

}
int main_c(int argc, char** argv)
{

    glutInit(&argc, argv); // to initialize the toolkit;

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // sets the display mode

    glutInitWindowSize(640, 480); // sets the window size

    glutInitWindowPosition(10, 10); // sets the starting position for the window

    glutCreateWindow("Ex_1-c"); // creates the window and sets the title

    glutDisplayFunc(myDisplay_c);
    myInit_c(); // additional initializations as necessary
    glutMainLoop(); // go into a loop until event occurs
    return 0;
}