#include "main.h"

int main() {
    
    std::setprecision(4);
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pendulum");
    window.setFramerateLimit(60);
    
    Pendulum p = Pendulum(&window, 400, 200);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);
        
        //drawing area!
        p.update();
        p.draw();
        
        window.display();
    }

    return 0;
}
