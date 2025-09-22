#include <GL/glut.h>
#include <iostream>
using namespace std;

// * Display
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //bg color
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(20.0); //initialize point size
    glBegin(GL_POINTS); // * Begin, geometric primitive

    glColor3ub(0, 0, 0); //geometry color
    glVertex2f(0.0, 0.0); //location

    glColor3ub(1, 0, 0); //geometry color
    glVertex2f(0.1, 0.1); //location

    glEnd(); // * End


    glFlush();
}


// * Main
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Connecting Two Points with a Line");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
