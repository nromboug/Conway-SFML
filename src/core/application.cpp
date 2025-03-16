#include "core/application.hpp"


Application::Application() : window(sf::VideoMode(1280, 720), "Conwayyyy") {}

void Application::run() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    std::vector vec{Cell(true), Cell(true), Cell(true)};
    
    for (auto it : vec)
        std::cout << it.isAlive() << std::endl;

    std::cout << std::endl;

    Cell& cell = vec[1];
    cell.setNextAlive(false);
    cell.update();

    for (auto it : vec)
        std::cout << it.isAlive() << std::endl;
}