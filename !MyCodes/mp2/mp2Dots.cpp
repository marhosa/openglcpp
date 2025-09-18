#include <GL/glut.h>

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);

    // * Center Nose
    glPointSize(13.0f);
    glBegin(GL_POINTS);
        // Center Point
        glColor3ub(255, 197, 0);
        glVertex2f(0.0f, 0.0f);
    glEnd();

    // * Head Outline
    glPointSize(9.0f);
    glBegin(GL_POINTS);
    glColor3ub(255, 0, 235);
        // Outline L
        glVertex2f(-0.36f, 0.4f);
        glVertex2f(-0.41f, 0.45f);
        glVertex2f(-0.47f, 0.38f);
        glVertex2f(-0.49f, 0.34f);
        glVertex2f(-0.565f, 0.24f);
        glVertex2f(-0.6f, 0.15f);
        glVertex2f(-0.62f, -0.04f);
        glVertex2f(-0.57f, -0.08f);
        glVertex2f(-0.46f, -0.115f);
        glVertex2f(-0.32f, -0.15f);
        glVertex2f(-0.19f, -0.17f);
        glVertex2f(-0.05f, -0.185f);
        // Outline R
        glVertex2f(0.36f, 0.4f);
        glVertex2f(0.41f, 0.45f);
        glVertex2f(0.47f, 0.38f);
        glVertex2f(0.49f, 0.34f);
        glVertex2f(0.565f, 0.24f);
        glVertex2f(0.6f, 0.15f);
        glVertex2f(0.62f, -0.04f);
        glVertex2f(0.57f, -0.08f);
        glVertex2f(0.46f, -0.115f);
        glVertex2f(0.32f, -0.15f);
        glVertex2f(0.19f, -0.17f);
        glVertex2f(0.05f, -0.185f);
    glEnd();

    // * Eyes
    glPointSize(9.0f);
    glBegin(GL_POINTS);
    glColor3ub(0, 0, 0);
        // Eyes L
        glVertex2f(-0.18f, 0.12f);
        glVertex2f(-0.25f, 0.12f);
        glVertex2f(-0.31f, 0.18f);
        glVertex2f(-0.31f, 0.08f);
        // Eyes R
        glVertex2f(0.18f, 0.12f);
        glVertex2f(0.25f, 0.12f);
        glVertex2f(0.31f, 0.18f);
        glVertex2f(0.31f, 0.08f);
    glEnd();

    // * Ribbon
    glPointSize(15.0f);
    glBegin(GL_POINTS);
    glColor3ub(255, 15, 96);
        // Ribbon R
        glVertex2f(0.50f, 0.39f);
        glVertex2f(0.50f, 0.235f);
        glVertex2f(0.57f, 0.3);
        glVertex2f(0.43f, 0.3);
    glEnd();


    // * Whiskers
    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glColor3ub(237, 237, 237);
        // Ribbon L
        glVertex2f(-0.15f, 0.07f);
        glVertex2f(-0.177f, 0.01);
        glVertex2f(-0.16f, -0.04);
        // Ribbon R
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.177f, 0.01);
        glVertex2f(0.16f, -0.04);
    glEnd();


        
    glFlush();
}





int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Drawing a Single Point");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}