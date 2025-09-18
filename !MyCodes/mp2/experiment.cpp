#include <GL/glut.h>

// * just experimenting
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);

    // Two points connected by a line
    glLineWidth(3.0f);  // make line thicker
    glBegin(GL_LINE);
        glColor3ub(255, 0, 0);    // red line
        glVertex2f(-0.5f, 0.0f);  // first point (left)
        glVertex2f(0.5f, 0.0f);   // second point (right)
        glVertex2f(0.5f, -0.6f);  //third line works if GL_LINE_STRIP
        glEnd();

    glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Connecting Two Points with a Line");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
