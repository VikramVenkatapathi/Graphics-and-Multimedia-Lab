#include <windows.h>
#include <GL\glut.h>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 400.0);
}


void myDisplay(void)
{

    glClear(GL_COLOR_BUFFER_BIT); // clears the screen
    glColor3f(0.5f, 0.5f, 0.5f);// sets the drawing colour

    glPointSize(4.0);

    //TRIANGLE
    glBegin(GL_TRIANGLES);
    glVertex2f(70.0f, 250.0f);
    glVertex2f(220.0f, 350.0f);
    glVertex2f(370.0f, 250.0f);
    glEnd();


    //POLYGON
    glBegin(GL_POLYGON);
    glVertex2f(100.0f, 250.0f);
    glVertex2f(340.0f, 250.0f);
    glVertex2f(220.0f, 350.0f);
    glVertex2f(370.0f, 250.0f);
    glEnd();




    //glEnd();

    glFlush(); // sends all output to display;

}
int main_s(int argc, char** argv)
{

    glutInit(&argc, argv); // to initialize the toolkit;

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // sets the display mode

    glutInitWindowSize(800, 600);

    glutInitWindowPosition(10, 10); // sets the starting position for the window

    glutCreateWindow("Ex_3-c"); // creates the window and sets the title

    glutDisplayFunc(myDisplay);
    myInit(); // additional initializations as necessary
    glutMainLoop(); // go into a loop until event occurs
    return 0;
}