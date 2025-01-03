#include <GL/glut.h>
#include "../include/planet.hpp"
#include "../include/solar_system.hpp"
#include "../include/star.hpp"

#define ESC     27

#define REST    700
#define REST_Z  (REST)
#define REST_Y  (-REST)

#define MOVE_SPEED 5.0f
#define FAST_MOVE_SPEED 10.0f

#define TIMEPAST 1
#define SELFROTATE 3

SolarSystem::SolarSystem() {
    viewX = 0;
    viewY = REST_Y;
    viewZ = REST_Z;
    centerX = centerY = centerZ = 0;
    upX = upY = 0;
    upZ = 1;

    GLfloat rgbColor[3] = {1, 0, 0};
    stars[Sun]     = new LightPlanet(SUN_RADIUS, 0, 0, SELFROTATE, nullptr, rgbColor);
    
    SET_VALUE_3(rgbColor, .2, .2, .5);
    stars[Mercury] = new Planet(MER_RADIUS, MER_SUN_DIS, MER_SPEED, SELFROTATE, stars[Sun], rgbColor);
    
    SET_VALUE_3(rgbColor, 1, .7, 0);
    stars[Venus]   = new Planet(VEN_RADIUS, VEN_SUN_DIS, VEN_SPEED, SELFROTATE, stars[Sun], rgbColor);
    
    SET_VALUE_3(rgbColor, 0, 1, 0);
    stars[Earth]   = new Planet(EAR_RADIUS, EAR_SUN_DIS, EAR_SPEED, SELFROTATE, stars[Sun], rgbColor);
    
    SET_VALUE_3(rgbColor, 1, 1, 0);
    stars[Moon]    = new Planet(MOO_RADIUS, MOO_SUN_DIS, MOO_SPEED, SELFROTATE, stars[Earth], rgbColor);
    
    SET_VALUE_3(rgbColor, 1, .5, .5);
    stars[Mars]    = new Planet(MAR_RADIUS, MAR_SUN_DIS, MAR_SPEED, SELFROTATE, stars[Sun], rgbColor);
    
    SET_VALUE_3(rgbColor, 1, 1, .5);
    stars[Jupiter] = new Planet(JUP_RADIUS, JUP_SUN_DIS, JUP_SPEED, SELFROTATE, stars[Sun], rgbColor);
    
    SET_VALUE_3(rgbColor, .5, 1, .5);
    stars[Saturn]  = new Planet(SAT_RADIUS, SAT_SUN_DIS, SAT_SPEED, SELFROTATE, stars[Sun], rgbColor);

    SET_VALUE_3(rgbColor, .4, .4, .4);
    stars[Uranus]  = new Planet(URA_RADIUS, URA_SUN_DIS, URA_SPEED, SELFROTATE, stars[Sun], rgbColor);

    SET_VALUE_3(rgbColor, .5, .5, 1);
    stars[Neptune] = new Planet(NEP_RADIUS, NEP_SUN_DIS, NEP_SPEED, SELFROTATE, stars[Sun], rgbColor);
}

SolarSystem::~SolarSystem() {
    for (int i = 0; i < STARS_NUM; i++) {
        delete stars[i];
    }
}

void SolarSystem::onDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(.7f, .7f, .7f, .1f);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0f, 1.0f, 1.0f, 40000000);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewX, viewY, viewZ, centerX, centerY, centerZ, upX, upY, upZ);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    for (int i = 0; i < STARS_NUM; i++) {
        stars[i]->draw();
    }

    glutSwapBuffers();
}

void SolarSystem::onUpdate() {
    long currentTime = glutGet(GLUT_ELAPSED_TIME);
    long deltaTime = currentTime - lastUpdatedTime;

    for (int i = 0; i < STARS_NUM; i++)
        stars[i]->update(deltaTime / 10);

    lastUpdatedTime = currentTime;

    this->onDisplay();
}

void SolarSystem::onKeyboard(unsigned char key, int x, int y) {
    bool fastMove = (glutGetModifiers() & GLUT_ACTIVE_SHIFT) != 0;

    float speed = fastMove ? FAST_MOVE_SPEED : MOVE_SPEED;

    switch (key) {
        case 'w':
            viewY += speed; 
            break;

        case 's':
            viewY -= speed; 
            break;

        case 'a':
            viewX -= speed; 
            break;

        case 'd':
            viewX += speed; 
            break;

        case 'q':
            viewZ -= speed;
            break;

        case 'e':
            viewZ += speed;
            break;

        case 'r':
            viewX = 0; 
            viewY = REST_Y; 
            viewZ = REST_Z;
            centerX = centerY = centerZ = 0;
            upX = upY = 0; 
            upZ = 1;
            break;

        case ESC:
            exit(0); 
            break;

        default:
            break;
    }
}