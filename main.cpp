#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Library!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    sf::Event event;
    Menu menu(&event);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered)
            {
               // std::cout << "Entered event\n" << std::endl;

                if (event.text.unicode < 128) {
                    std::cout << static_cast<char>(event.text.unicode) << std::endl;
                    std::cout << static_cast<int>(event.text.unicode) << std::endl;
                    menu.updateString(static_cast<char>(event.text.unicode));
                }
            }


        }

        window.clear();
        window.draw(menu);
        window.display();
    }
    return 0;

}