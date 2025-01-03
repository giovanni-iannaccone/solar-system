#include <cmath>
#include <GL/glut.h>

#include "../include/star.hpp"

#define PI 3.1415926535

Star::Star(GLfloat radius, GLfloat distance,
           GLfloat speed, GLfloat selfSpeed,
           Star* parent) {
    this->radius = radius;
    this->selfSpeed = selfSpeed;
    this->selfAlpha = this->alpha = 0;
    this->distance = distance;
    for (int i = 0; i < 4; i++) this->rgbaColor[i] = 1.0f;

    this->parentStar = parent;
    this->speed = (speed > 0) ? 360.0f / speed : 0.0f;
}

void Star::drawStar() {

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);

    int n = 1440;

    glPushMatrix();

    if (parentStar != nullptr) {
        glRotatef(parentStar->getAlpha(), 0, 0, 1);
        glTranslatef(parentStar->distance, 0.0, 0.0);
    }
    
    glRotatef(alpha, 0, 0, 1);
    glTranslatef(distance, 0.0, 0.0);

    glRotatef(selfAlpha, 0, 0, 1);

    glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
    glutSolidSphere(radius, 40, 32);
    
    glPopMatrix();
}


void Star::update(long timeSpan) {
    alpha += timeSpan * speed;
    selfAlpha += selfSpeed;
}
