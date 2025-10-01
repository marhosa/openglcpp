#include <GL/glut.h>
#include <iostream>
using namespace std;

// ! Settings you can modify:

// * Velocity:
float speed = 1.0f;

// * Jump Power
float jumpPower = 0.06f;

// * Gravity:
float gravity = -0.003f;

// * Ground level:
float groundY = -0.5f;




// ! Some Settings not recommended to modify:

// * Positions:
// Player Anchor Point
float player_x = 0.0f;
float player_y = groundY;
float player_vx = 0.0f;
float player_vy = 0.0f;

// Obstacle Anchor Point
float obstacle_x = -1.0f;
float obstacle_y = groundY;
float obstacle_vx = 0.02f;
float obstacle_vy = 0.0f;

// Background






// ! Below this line contains all codes to run, not reco to modify




// * Player
void PlayerKun() {
    glPointSize(20.0);

    glBegin(GL_POINTS);
    glColor3ub(0, 0, 255);
    glVertex2f(0.0 + player_x, 0.0 + player_y); // dot 1
    glEnd();
}

// * Obstacle
void Obstacle() {
    glPointSize(40.0);

    glBegin(GL_POINTS);
    glColor3ub(0, 255, 255);
    glVertex2f(0.0 + obstacle_x, 0.0 + obstacle_y); // dot 1
    glEnd();
}

// * Display
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Obstacle();
    PlayerKun();
    

    glFlush();
}

// * Update movement
void update(int value) {

    // * Player Logic:

    // Apply gravity
    player_vy += gravity;
    player_y += player_vy;

    // Stop at ground
    if (player_y < groundY) {
        player_y = groundY;
        player_vy = 0.0f;
    }



    // * Obstacle Logic:

    obstacle_x -= obstacle_vx * speed;
    if (obstacle_x <= -1) {
        obstacle_x = 1;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// * Keyboard controls
void keyboard(unsigned char key, int x, int y) {
    if (key == 119 || key == 32) { // w key
        if (player_y <= groundY + 0.001f) { 
            // only jump if on ground
            player_vy = jumpPower;
        }
    }
    if (key == 115) { // w key
        if (!(player_y <= groundY + 0.001f)) { 
            // only jump if on ground
            player_vy =  -jumpPower;
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