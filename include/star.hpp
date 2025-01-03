#ifndef stars_hpp
#define stars_hpp

class Star {

public:
    GLfloat radius;
    GLfloat speed, selfSpeed;
    GLfloat distance;

    GLfloat rgbaColor[4];

    Star* parentStar;

    Star(GLfloat radius, GLfloat distance, GLfloat speed,  GLfloat selfSpeed, Star* parentStar);

    void drawStar();

    virtual void draw() { 
        drawStar(); 
    }

    virtual void update(long timeSpan);

    GLfloat getAlpha() const { 
        return alpha; 
    } 

protected:
    GLfloat selfAlpha, alpha;
};

#endif