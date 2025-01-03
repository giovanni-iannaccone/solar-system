#include <GL/glut.h>
#include "../include/planet.hpp"

Planet::Planet(GLfloat radius, GLfloat distance, 
                GLfloat speed, GLfloat selfSpeed, 
                Star* parent, GLfloat rgbColor[3]) :
    Star(radius, distance, speed, selfSpeed, parent) {
    rgbaColor[0] = rgbColor[0];
    rgbaColor[1] = rgbColor[1];
    rgbaColor[2] = rgbColor[2];
    rgbaColor[3] = 1.0f;
}

void Planet::drawPlanet() {
    GLfloat mat_ambient[]  = {0.0f, 0.0f, 0.5f, 1.0f};
    GLfloat mat_diffuse[]  = {0.0f, 0.0f, 0.5f, 1.0f};
    GLfloat mat_specular[] = {0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat mat_emission[] = {rgbaColor[0], rgbaColor[1], rgbaColor[2], rgbaColor[3]};
    GLfloat mat_shininess  = 90.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION,  mat_emission);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

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

LightPlanet::LightPlanet(GLfloat radius, GLfloat distance, 
                        GLfloat speed, GLfloat selfSpeed, 
                        Star* parent, GLfloat rgbColor[3]) :
    Planet(radius, distance, speed, selfSpeed, parent, rgbColor) { }

void LightPlanet::drawLight() {
    GLfloat light_position[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}
