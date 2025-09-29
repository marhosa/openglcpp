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

    // * Attributes
    glColor3ub(0, 0, 255); //set colors to blue
    glVertex2f(0.0, 0.0); //location dot 1
    glColor3f(0, 1, 0); //set colors to green
    glVertex2f(0.1, 0.1); //location dot 2

    // * End
    glEnd();

    


    glFlush();
}


// * Main
int main(int argc, char** argv) {
  glutInit(&argc, argv); //initialize glut
  glutInitWindowSize(600, 600); //initialize window size
  glutCreateWindow("Matthew Rhomar Santos"); //create a window with a title
  glutDisplayFunc(display); //called when redrawing needed
  glutMainLoop(); //infinite event processing loop
  return 0;
}
