#include <GL/glut.h>
using namespace std;

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT);

    // --- Drawing Commands ---
    // Set the point size to make them visible
    glPointSize(10.0f);

    // Start a drawing block for points
    glBegin(GL_POINTS);

    // Point 1: Red, top-left
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-0.5f, 0.5f);

    // Point 2: Green, top-right
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(0.5f, 0.5f);

    // Point 3: Blue, bottom-left
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex2f(-0.5f, -0.5f);

    // Point 4: Yellow, bottom-right
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex2f(0.5f, -0.5f);

    glEnd(); // End the drawing block
    // --- End of Drawing ---

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Drawing Multiple Colored Points");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
