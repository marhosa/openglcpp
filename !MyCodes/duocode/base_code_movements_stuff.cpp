#include <GL/glut.h>
#include <iostream>
using namespace std;

// ! Settings:

// * Positions:
float theTwoDots_x = 0.0f;
float theTwoDots_y = -0.5f; // start on the "ground"

// * Velocity:
float theTwoDots_vx = 0.02f;
float theTwoDots_vy = 0.00f;

// * Gravity:
float gravity = -0.002f;

// * Ground level:
float groundY = -0.5f;



// ! Below this line contains all source codes 




// * theTwoDots
void theTwoDots() {
    glPointSize(20.0);

    glBegin(GL_POINTS);
    glColor3ub(0, 0, 255);
    glVertex2f(0.0 + theTwoDots_x, 0.0 + theTwoDots_y); // dot 1
    glEnd();
}

// * Display
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    theTwoDots();

    glFlush();
}

// * Update movement
void update(int value) {
    // Move horizontally
    theTwoDots_x += theTwoDots_vx;

    // Bounce off left/right edges
    if (theTwoDots_x > 1.0f || theTwoDots_x < -1.0f) {
        theTwoDots_vx = -theTwoDots_vx;
    }

    // Apply gravity
    theTwoDots_vy += gravity;
    theTwoDots_y += theTwoDots_vy;

    // Stop at ground
    if (theTwoDots_y < groundY) {
        theTwoDots_y = groundY;
        theTwoDots_vy = 0.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// * Keyboard controls
void keyboard(unsigned char key, int x, int y) {
    if (key == 32) { // spacebar
        if (theTwoDots_y <= groundY + 0.001f) { 
            // only jump if on ground
            theTwoDots_vy = 0.05f;
        }
    }
    if (key == 27) { // ESC to exit
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Jump Simulation");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}