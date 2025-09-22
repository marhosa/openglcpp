#include <GL/glut.h>
#include <iostream>
using namespace std;

// * Display
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //bg color
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5.0);

    // * Letter M
    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0); //geometry color
      glVertex2f(-0.8, -0.2);
      glVertex2f(-0.8, 0.4);
      glVertex2f(-0.6, 0.2);
      glVertex2f(-0.4, 0.4);
      glVertex2f(-0.4, -0.2);
    glEnd();

    // * Letter R
    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0); //geometry color
      glVertex2f(-0.2, -0.2);
      glVertex2f(-0.2, 0.2);
      glVertex2f(-0.2, 0.4);
      glVertex2f(0.2, 0.4);
      glVertex2f(0.2, 0.2);
      glVertex2f(-0.2, 0.2);
      glVertex2f(0.2, -0.2);
    glEnd();

    // * Letter S
    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0); //geometry color
      glVertex2f(0.8, 0.4);
      glVertex2f(0.4, 0.4);
      glVertex2f(0.4, 0.2);
      glVertex2f(0.8, 0.2);
      glVertex2f(0.8, -0.2);
      glVertex2f(0.4, -0.2);
    glEnd();


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
