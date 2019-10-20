#ifndef Dotter_hpp
#define Dotter_hpp

#include "main.h"

class Dotter {
public:
    sf::RenderWindow* w;
    
    float x, y, r;
    
    float v_x = 0;
    float v_y = 0;
    
    float a_x = 0;
    float a_y = 0.6;
    
    float bounce;
    
    Dotter(sf::RenderWindow *_w, float _x, float _y, float _r=20.f, float _b=0.8);
    
    void border();
    void update();
    void draw();
};

#endif
