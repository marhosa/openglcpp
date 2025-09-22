#include <GL/glut.h>
#include <iostream>
using namespace std;

// * Display
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //bg color
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(20.0); //initialize point size

    // * Begin, geometric primitive
    glBegin(GL_POINTS); 
    glColor3ub(0, 0, 0); // * Geometry Color

    glVertex2f(0.0, 0.0); //location dot 1
    glVertex2f(0.1, 0.1); //location dot 2

    glEnd(); // * End


    glFlush();
}


// * Main
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Matthew Rhomar Santos");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
