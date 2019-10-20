#ifndef Pendulum_hpp
#define Pendulum_hpp

#include "main.h"

class Pendulum {
public:
    sf::RenderWindow *w;
    
    float x0, y0;
    float x1, y1, r1, a1, m1, vel1, acc1;
    float x2, y2, r2, a2, m2, vel2, acc2;
    
    Pendulum(sf::RenderWindow* _w, float _x0, float _y0);
    
    void update();
    void draw();
};

#endif
