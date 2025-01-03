#ifndef planet_h
#define planet_h

#include "../include/star.hpp"

class Planet : public Star {
public:
    Planet(GLfloat radius, GLfloat distance, 
            GLfloat speed,  GLfloat selfSpeed, 
            Star* parentStar, GLfloat rgbColor[3]);
    
    void drawPlanet();

    virtual void draw() override { 
        drawPlanet(); 
    }
};

class LightPlanet : public Planet {

public:
    LightPlanet(GLfloat Radius, GLfloat Distance,
                GLfloat Speed,  GLfloat SelfSpeed,
                Star* ParentStar, GLfloat rgbColor[]);

    void drawLight();
    
    virtual void draw() override { 
        drawLight(); 
        drawPlanet(); 
        drawStar();
    }
};

#endif