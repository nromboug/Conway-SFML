#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class Application {
    private:
    sf::RenderWindow window;

    public:
    Application();
    void run();

};

#endif