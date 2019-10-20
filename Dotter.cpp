#include "Dotter.hpp"
    
Dotter::Dotter(sf::RenderWindow *_w, float _x, float _y, float _r, float _b) {
    w = _w;
    x = _x;
    y = _y;
    r = _r;
    bounce = _b;
}
    
void Dotter::border() {
    if(x-r < 0 || x+r > WIDTH) v_x *= -bounce;
    if(y-r < 0 || y+r > HEIGHT) v_y *= -bounce;
    
    if(x-r < 0) x = r;
    if(x+r > WIDTH) x = WIDTH-r;
    if(y-r < 0) y = r;
    if(y+r > HEIGHT) y = HEIGHT-r;
}

void Dotter::update() {
    v_x += a_x;
    v_y += a_y;
    
    x += v_x;
    y += v_y;
}

void Dotter::draw() {
    sf::CircleShape shape(r);
    shape.setPosition(x-r, y-r);
    shape.setFillColor(sf::Color(255, 255, 255));
    w->draw(shape);
}
