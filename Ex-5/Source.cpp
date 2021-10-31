#include<vector>
#include<GL/glut.h>
#include<iostream>
using namespace std;

const int pi = 3.14;
int n;
int tx, ty;
int xr, yr;
int xf, yf;
double ang, angRad;
double sx, sy;
double shx, shy;
vector<pair<int, int>> coords;

void myInit(void) {
    glClearColor(0.0, 0.5, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);

    
}

void drawPolygon() {
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = coords[i].first;
        int y = coords[i].second;
        glVertex2d(x, y);
    }
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2d(-300, 0);
    glVertex2d(300, 0);
    glVertex2d(0, -300);
    glVertex2d(0, 300);
    glEnd();
}

void polygonTrans() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = coords[i].first;
        int y = coords[i].second;
        glVertex2d(x + tx, y + ty);
    }
    glEnd();
}

void rotateAboutOrigin() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = coords[i].first;
        int y = coords[i].second;
        glVertex2d(round(x * cos(angRad) - y * sin(angRad)),
            round(x * sin(angRad) + y * cos(angRad)));
    }
    glEnd();
}

void scaleAboutOrigin() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = coords[i].first;
        int y = coords[i].second;
        glVertex2d(x * sx, y * sy);
    }
    glEnd();
}

void rotateAboutPoint() {
    vector<pair<int, int>> newCoords;
    vector<vector<double>> rotate(3, vector<double>(3, 0));
    vector<double> curr(3, 0), res(3, 0);
    rotate[0][0] = cos(angRad);
    rotate[0][1] = -1 * sin(angRad);
    rotate[0][2] = xr * (1 - cos(angRad)) + yr * sin(angRad);
    rotate[1][0] = sin(angRad);
    rotate[1][1] = cos(angRad);
    rotate[1][2] = yr * (1 - cos(angRad)) - xr * sin(angRad);
    rotate[2][2] = 1;

    for (int i = 0; i < n; i++) {
        curr[0] = coords[i].first;
        curr[1] = coords[i].second;
        curr[2] = 1;
        res = vector<double>(3, 0);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[j] += rotate[j][k] * curr[k];
            }
        }
        newCoords.push_back({ round(res[0]),round(res[1]) });
    }

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = newCoords[i].first;
        int y = newCoords[i].second;
        glVertex2d(x, y);
    }
    glEnd();
}

void scaleAboutPoint() {
    vector<pair<int, int>> newCoords;
    vector<vector<double>> scale(3, vector<double>(3, 0));
    vector<double> curr(3, 0), res(3, 0);
    scale[0][0] = sx;
    scale[0][2] = xf * (1 - sx);
    scale[1][1] = sy;
    scale[1][2] = yf * (1 - sy);
    scale[2][2] = 1;

    for (int i = 0; i < n; i++) {
        curr[0] = coords[i].first;
        curr[1] = coords[i].second;
        curr[2] = 1;
        res = vector<double>(3, 0);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[j] += scale[j][k] * curr[k];
            }
        }
        newCoords.push_back({ round(res[0]),round(res[1]) });
    }

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = newCoords[i].first;
        int y = newCoords[i].second;
        glVertex2d(x, y);
    }
    glEnd();
}

void reflectAboutX() {
    vector<pair<int, int>> newCoords;
    vector<vector<double>> reflect(3, vector<double>(3, 0));
    vector<double> curr(3, 0), res(3, 0);
    reflect[0][0] = 1;
    reflect[1][1] = -1;
    reflect[2][2] = 1;

    for (int i = 0; i < n; i++) {
        curr[0] = coords[i].first;
        curr[1] = coords[i].second;
        curr[2] = 1;
        res = vector<double>(3, 0);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[j] += reflect[j][k] * curr[k];
            }
        }
        newCoords.push_back({ round(res[0]),round(res[1]) });
    }

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = newCoords[i].first;
        int y = newCoords[i].second;
        glVertex2d(x, y);
    }
    glEnd();
}

void reflectAboutY() {
    vector<pair<int, int>> newCoords;
    vector<vector<double>> reflect(3, vector<double>(3, 0));
    vector<double> curr(3, 0), res(3, 0);
    reflect[0][0] = -1;
    reflect[1][1] = 1;
    reflect[2][2] = 1;

    for (int i = 0; i < n; i++) {
        curr[0] = coords[i].first;
        curr[1] = coords[i].second;
        curr[2] = 1;
        res = vector<double>(3, 0);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[j] += reflect[j][k] * curr[k];
            }
        }
        newCoords.push_back({ round(res[0]),round(res[1]) });
    }

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = newCoords[i].first;
        int y = newCoords[i].second;
        glVertex2d(x, y);
    }
    glEnd();
}

void reflectAboutOrigin() {
    vector<pair<int, int>> newCoords;
    vector<vector<double>> reflect(3, vector<double>(3, 0));
    vector<double> curr(3, 0), res(3, 0);
    reflect[0][0] = -1;
    reflect[1][1] = -1;
    reflect[2][2] = 1;

    for (int i = 0; i < n; i++) {
        curr[0] = coords[i].first;
        curr[1] = coords[i].second;
        curr[2] = 1;
        res = vector<double>(3, 0);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[j] += reflect[j][k] * curr[k];
            }
        }
        newCoords.push_back({ round(res[0]),round(res[1]) });
    }

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = newCoords[i].first;
        int y = newCoords[i].second;
        glVertex2d(x, y);
    }
    glEnd();
}

void reflectXequalsY() {
    vector<pair<int, int>> newCoords;
    vector<vector<double>> reflect(3, vector<double>(3, 0));
    vector<double> curr(3, 0), res(3, 0);
    reflect[0][0] = 1;
    reflect[1][1] = 1;
    reflect[2][2] = 1;

    for (int i = 0; i < n; i++) {
        curr[0] = coords[i].first;
        curr[1] = coords[i].second;
        curr[2] = 1;
        res = vector<double>(3, 0);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[j] += reflect[j][k] * curr[k];
            }
        }
        newCoords.push_back({ round(res[0]),round(res[1]) });
    }

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    for (int i = 0; i < n; i++) {
        int x = newCoords[i].first;
        int y = newCoords[i].second;
        glVertex2d(x, y);
    }
    glEnd();
}

void shearAlongX() {
    vector<pair<int, int>> newCoords;
    vector<vector<double>> shear(3, vector<double>(3, 0));
    vector<double> curr(3, 0), res(3, 0);
    shear[0][0] = 1;
    shear[1][1] = 1;
    shear[2][2] = 1;
    shear[0][1] = shx;

    for (int i = 0; i < n; i++) {
        curr[0] = coords[i].first;
        curr[1] = coords[i].second;
        curr[2] = 1;
        res = vector<double>(3, 0);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[j] += shear[j][k] * curr[k];
            }
        }
        newCoords.push_back({ round(res[0]),round(res[1]) });
    }

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    cout << "\nAlong X :";
    for (int i = 0; i < n; i++) {
        int x = newCoords[i].first;
        int y = newCoords[i].second;
        cout << "\n\t" << x <<" " << y;

        glVertex2d(x, y);
    }
    glEnd();
}

void shearAlongY() {
    vector<pair<int, int>> newCoords;
    vector<vector<double>> shear(3, vector<double>(3, 0));
    vector<double> curr(3, 0), res(3, 0);
    shear[0][0] = 1;
    shear[1][1] = 1;
    shear[2][2] = 1;
    shear[1][0] = shy;

    for (int i = 0; i < n; i++) {
        curr[0] = coords[i].first;
        curr[1] = coords[i].second;
        curr[2] = 1;
        res = vector<double>(3, 0);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[j] += shear[j][k] * curr[k];
            }
        }
        newCoords.push_back({ round(res[0]),round(res[1]) });
    }

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    cout << "\nAlong Y :";
    for (int i = 0; i < n; i++) {
        int x = newCoords[i].first;
        int y = newCoords[i].second;
        cout << "\n\t" << x << " " << y;
        glVertex2d(x, y);
    }
    glEnd();
}

void trans2D() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawPolygon();
    /*polygonTrans();
    rotateAboutOrigin();
    rotateAboutPoint();
    scaleAboutOrigin();
    scaleAboutPoint();
    reflectAboutX();
    reflectAboutY();
    reflectAboutOrigin();
    reflectXequalsY();*/
    shearAlongX();
    shearAlongY();
    glFlush();
}

int main(int argc, char** argv) {
    cout << "2D transformation on polygon" << endl;
    cout << "No. of Vertices : ";
    cin >> n;

    int x, y;
    for (int i = 0; i < n; i++) {
        cout << "Vertex" << i + 1 << " : ";
        cin >> x >> y;
        coords.push_back({ x,y });
    }

    /*cout << "\nTranslation factor : ";
    cin >> tx >> ty;

    cout << "\nAngle of rotation : ";
    cin >> ang;
    angRad = ang * pi / 180;

    cout << "Rotate about : ";
    cin >> xr >> yr;

    cout << "\nScaling factor : ";
    cin >> sx >> sy;

    cout << "Scale about : ";
    cin >> xf >> yf;*/

    cout << "\nShear amount : ";
    cin >> shx >> shy;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Ex5 - 2D Transformations");
    glutDisplayFunc(trans2D);
    myInit();
    glutMainLoop();
    return 0;
}
