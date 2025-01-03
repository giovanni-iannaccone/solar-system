#ifndef solarsystem_hpp
#define solarsystem_hpp

#include <GL/glut.h>

#include "data.hpp"
#include "star.hpp"

class SolarSystem {

public:

    SolarSystem();
    ~SolarSystem();

    void onDisplay();
    void onUpdate();
    void onKeyboard(unsigned char key, int x, int y);

private:
    Star *stars[STARS_NUM];

    GLdouble viewX, viewY, viewZ;
    GLdouble centerX, centerY, centerZ;
    GLdouble upX, upY, upZ;
    long lastUpdatedTime;

    void addStars();
};

#endif