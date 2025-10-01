#include <GL/freeglut.h>
#include <cmath>
#include <string>

// Dino parameters
float dinoX = -0.6f, dinoY = -0.5f;
float dinoW = 0.08f, dinoH = 0.12f;
bool isJumping = false;
float jumpVel = 0.0f;
float gravity = -0.002f;

// Cactus parameters
float cactusX = 1.2f, cactusY = -0.5f;
float cactusW = 0.06f, cactusH = 0.15f;
float cactusSpeed = 0.015f;

// Score
int score = 0;
bool gameOver = false;

void drawRect(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x+w, y);
        glVertex2f(x+w, y+h);
        glVertex2f(x, y+h);
    glEnd();
}

void resetGame() {
    dinoY = -0.5f;
    isJumping = false;
    jumpVel = 0.0f;
    cactusX = 1.2f;
    score = 0;
    gameOver = false;
}

void display() {
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    // Ground
    drawRect(-1.0f, -0.5f, 2.0f, -0.5f, 0.6f, 0.6f, 0.6f);

    // Dino
    drawRect(dinoX, dinoY, dinoW, dinoH, 0.0f, 0.0f, 0.0f);

    // Cactus
    drawRect(cactusX, cactusY, cactusW, cactusH, 0.0f, 0.6f, 0.0f);

    glutSwapBuffers();
}

void update(int value) {
    if (!gameOver) {
        // Jump physics
        if (isJumping) {
            dinoY += jumpVel;
            jumpVel += gravity;
            if (dinoY <= -0.5f) {
                dinoY = -0.5f;
                isJumping = false;
                jumpVel = 0.0f;
            }
        }

        // Move cactus
        cactusX -= cactusSpeed;
        if (cactusX < -1.2f) {
            cactusX = 1.2f;
            score++;
        }

        // Collision detection
        if (dinoX < cactusX + cactusW &&
            dinoX + dinoW > cactusX &&
            dinoY < cactusY + cactusH &&
            dinoY + dinoH > cactusY) {
            gameOver = true;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 fps
}

void keyboard(unsigned char key, int, int) {
    if (key == ' ' && !isJumping && !gameOver) {
        isJumping = true;
        jumpVel = 0.04f; // jump strength
    } else if (key == 'r') {
        resetGame();
    } else if (key == 27) { // ESC
        glutLeaveMainLoop();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutCreateWindow("GLUT Dino Chrome");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
