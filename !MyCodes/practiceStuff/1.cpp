#include <GL/glut.h>
#include <iostream>
using namespace std;

// * Display
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //bg color
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(20.0); //initialize point size

    // * Begin, geometric primitive
    glBegin(GL_TRIANGLE_STRIP);

    glColor3ub(255, 0, 255);
    glVertex2f(-0.6, 0.4);
    glVertex2f(0, 0.4);
    glVertex2f(0, 0);
    glVertex2f(0.6,0.6);




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
