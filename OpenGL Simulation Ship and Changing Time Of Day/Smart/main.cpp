#include <bits/stdc++.h>
#include <windows.h>
#include <GL/gl.h>
#include <Mmsystem.h>
#include <fstream>
#include <GL/freeglut.h>


using namespace std;
#pragma comment(lib, "Winmm.lib")
#define int GLint
#define PI 3.1416

// Global Variables
bool playSoundFlag = true;
float boatPos1 = 990, boatPos2 = -100, boatPos3 = 600;
float boatSpeed1 = 2.9f, boatSpeed2 = 2.5f, boatSpeed3 = 1.95f;
float cloudPos1 = 200, cloudPos2 = 400, cloudPos3 = -250, cloudPos4 = 50, cloudPos5 = 490;
float cloudSpeed = 2.0f;
float sunPosX = 620, sunPosY = 310;
float sunSpeedX = 0.5f, sunSpeedY = 1.0f;

// Circle Function
void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    GLint triangleAmount = 60;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

// Cloud Model-1
void drawCloudModel1() {
    glColor3ub(54, 74, 156);
    glPushMatrix();
    drawCircle(320, 210, 15);
    drawCircle(340, 225, 16);
    drawCircle(360, 210, 16);
    drawCircle(330, 210, 16);
    drawCircle(340, 210, 16);
    drawCircle(350, 210, 16);
    glPopMatrix();
}

// Cloud Model-2
void drawCloudModel2() {
    glColor3ub(54, 74, 156);
    glPushMatrix();
    drawCircle(305, 205, 10);
    drawCircle(320, 210, 15);
    drawCircle(334, 207, 10);
    drawCircle(320, 207, 10);
    glPopMatrix();
}

// Cloud Model-3
void drawCloudModel3() {
    glColor3f(1.25, 0.924, 0.930);
    glPushMatrix();
    drawCircle(300, 200, 15);
    drawCircle(320, 210, 15);
    drawCircle(340, 220, 16);
    drawCircle(360, 210, 15);
    drawCircle(380, 200, 15);
    drawCircle(360, 190, 20);
    drawCircle(320, 190, 20);
    drawCircle(340, 190, 20);
    glPopMatrix();
}

// Big Hill
void drawBigHill() {
    glColor3ub(34, 139, 34);
    glBegin(GL_POLYGON);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(330, 70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(172, 174, 176);
    glVertex2i(200, 225);
    glVertex2i(230, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 190);
    glVertex2i(190, 180);
    glVertex2i(170, 190);
    glEnd();
}

// Small Hill
void drawSmallHill() {
    glColor3ub(34, 139, 34);
    glBegin(GL_POLYGON);
    glVertex2i(250, 100);
    glVertex2i(310, 175);
    glVertex2i(370, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(172, 174, 176);
    glVertex2i(290, 150);
    glVertex2i(310, 175);
    glVertex2i(330, 150);
    glVertex2i(325, 140);
    glVertex2i(310, 150);
    glVertex2i(300, 140);
    glEnd();
}

// Tilla Model-1
void drawTillaModel1() {
    glBegin(GL_POLYGON);
    glColor3ub(15, 59, 11);
    glVertex2i(125, 70);
    glVertex2i(150, 80);
    glVertex2i(160, 90);
    glVertex2i(170, 90);
    glVertex2i(180, 100);
    glVertex2i(190, 105);
    glVertex2i(200, 108);
    glVertex2i(300, 110);
    glVertex2i(300, 70);
    glEnd();
}

// Tilla Model-2
void drawTillaModel2() {
    glColor3ub(15, 59, 11);
    glPushMatrix();
    drawCircle(430, 90, 30);
    drawCircle(420, 87, 30);
    drawCircle(410, 80, 30);
    drawCircle(400, 80, 30);
    drawCircle(390, 70, 30);
    drawCircle(445, 80, 30);
    drawCircle(455, 75, 30);
    drawCircle(465, 70, 30);
    drawCircle(470, 65, 30);
    drawCircle(480, 60, 30);
    drawCircle(485, 55, 20);
    glPopMatrix();
}

// House
void drawHouse() {
    glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(285, 105);
    glVertex2i(285, 130);
    glVertex2i(380, 115);
    glVertex2i(380, 105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
    glVertex2i(285, 105);
    glVertex2i(285, 120);
    glVertex2i(380, 105);
    glVertex2i(380, 105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
    glVertex2i(290, 70);
    glVertex2i(290, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
    glVertex2i(310, 70);
    glVertex2i(350, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(330, 70);
    glVertex2i(330, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(295, 75);
    glVertex2i(295, 90);
    glVertex2i(310, 90);
    glVertex2i(310, 75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(312, 75);
    glVertex2i(312, 90);
    glVertex2i(327, 90);
    glVertex2i(327, 75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(355, 75);
    glVertex2i(355, 90);
    glVertex2i(370, 90);
    glVertex2i(370, 75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(250, 90);
    glVertex2i(257, 104);
    glVertex2i(290, 104);
    glVertex2i(290, 90);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
    glVertex2i(255, 70);
    glVertex2i(255, 90);
    glVertex2i(290, 90);
    glVertex2i(290, 70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(270, 70);
    glVertex2i(270, 85);
    glVertex2i(285, 85);
    glVertex2i(285, 70);
    glEnd();
}

// Boat Model
void drawBoatModel() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2i(400, 100);
    glVertex2i(395, 95);
    glVertex2i(455, 95);
    glVertex2i(450, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 0, 0);
    glVertex2i(410, 100);
    glVertex2i(410, 107);
    glVertex2i(445, 107);
    glVertex2i(445, 100);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(430, 107);
    glVertex2i(430, 115);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2i(430, 115);
    glVertex2i(432, 110);
    glVertex2i(428, 110);
    glEnd();
}

// Draw Sun
void drawSun() {
    glColor3f(1.0, 0.75, 0.0);
    drawCircle(sunPosX, sunPosY, 35);
}

// River
void drawRiver() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 149, 182);
    glVertex2i(0, 70);
    glVertex2i(0, 0);
    glVertex2i(1000, 0);
    glVertex2i(1000, 70);
    glEnd();
}

// Update Sun Position
void updateSunPosition(int value) {
    if (sunPosY >= -100) {
        sunPosX -= sunSpeedX;
        sunPosY -= sunSpeedY;
    } else {
        sunPosX = 620;
        sunPosY = 310;
    }
    glutPostRedisplay();
    glutTimerFunc(30, updateSunPosition, 0);
}

// Display Callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSun();
    drawRiver();
    drawHouse();
    drawBigHill();
    drawSmallHill();
    drawTillaModel1();
    drawTillaModel2();
    drawCloudModel1();
    drawCloudModel2();
    drawCloudModel3();
    drawBoatModel();
    glFlush();
}

// Main Function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Scenery");
    glClearColor(0.529, 0.808, 0.922, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
    glutDisplayFunc(display);
    glutTimerFunc(30, updateSunPosition, 0);
    glutMainLoop();
    return 0;
}
