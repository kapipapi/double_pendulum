#include "Pendulum.hpp"

Pendulum::Pendulum(sf::RenderWindow *_w, float _x0, float _y0) {
    w = _w;
    x0 = _x0;
    y0 = _y0;
    
    r1 = 200;
    a1 = 2*M_PI*random()*10e-10-PI;
    m1 = 10;
    vel1 = 0;
    acc1 = 0;
    
    r2 = 200;
    a2 = 2*M_PI*random()*10e-10-PI;
    m2 = 10;
    vel2 = 0;
    acc2 = 0;
    
    std::cout << random() << std::endl;
}

void Pendulum::update() {
    
    float g = 9.81e-1;
    
    x1 = x0 + r1 * sin(a1);
    y1 = y0 + r1 * cos(a1);
    
    x2 = x1 + r2 * sin(a2);
    y2 = y1 + r2 * cos(a2);
    
    a1 += vel1;
    a2 += vel2;
    
    acc1 = (-g*(2*m1+m2)*sin(a1)-m2*g*sin(a1-2*a2)-2*sin(a1-a2)*m2*((vel2*vel2)*r2+(vel1*vel1)*r1*cos(a1-a2)))/(r1*(2*m1+m2-m2*cos(2*a1-2*a2)));
    
    acc2 = (2*sin(a1-a2)*((vel1*vel1)*r1*(m1+m2)+g*(m1+m2)*cos(a1)+(vel2*vel2)*r2*m2*cos(a1-a2)))/(r2*(2*m1+m2-m2*cos(2*a1-2*a2)));
    
    vel1 += acc1;
    vel2 += acc2;
    
}

void Pendulum::draw() {
    //first pendulum
    sf::Vertex line1[] = {
        sf::Vertex(sf::Vector2f(x0, y0)),
        sf::Vertex(sf::Vector2f(x1, y1))
    };
    w->draw(line1, 2, sf::Lines);

    sf::CircleShape ball1(m1);
    ball1.setPosition(x1-m1, y1-m1);
    ball1.setFillColor(sf::Color(255, 255, 255));
    w->draw(ball1);
    
    //second pendulum
    sf::Vertex line2[] = {
        sf::Vertex(sf::Vector2f(x1, y1)),
        sf::Vertex(sf::Vector2f(x2, y2))
    };
    w->draw(line2, 2, sf::Lines);

    sf::CircleShape ball2(m2);
    ball2.setPosition(x2-m2, y2-m2);
    ball2.setFillColor(sf::Color(255, 255, 255));
    w->draw(ball2);
}
