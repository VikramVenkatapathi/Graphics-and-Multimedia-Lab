#include<vector>
#include<GL/glut.h>
#include<iostream>
using namespace std;

const int pi = 3.14;
int n,opt=0;
int tx, ty; //translation factors
int xr, yr; //rotation factors
int xf, yf; //scaling factors
double ang, angRad; //radian angle
double sx, sy; 
double shx, shy; //shear factors
vector<pair<int, int>> vertices;
#include"temp_header.h"

void myInit(void) {

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}



int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 150);
    
    glutCreateWindow("Ex5 - 2D Transformations");
    cout << "\n\t------------------------";
    cout << "\n\tEx5 - 2D Transformations";
    cout << "\n\t------------------------";
    cout << "\nNo. of Vertices : ";
    cin >> n;

    int x, y;
    for (int i = 0; i < n; i++) {
        cout << "\nVertex_" << i + 1 << " : ";
        cin >> x >> y;
        vertices.push_back({ x,y });
    }
    cout << "\nOptions :-";
    cout << "\n\t1) Translation";
    cout << "\n\t2) Rotation";
    cout << "\n\t3) Scaling with respect to";
    cout << "\n\t4) Reflection with respect to";
    cout << "\n\t5) Shearing";
    cout << "\n\tSelect option -> ";
    
    cin >> opt;
    glutDisplayFunc(menu_driven);
    myInit();
    glutMainLoop();
    return 0;
}
