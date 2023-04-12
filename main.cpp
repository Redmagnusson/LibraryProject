#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Lib.h"
#include <chrono>
#include "CD.h"
#include "Data.h"
#include <map>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Library!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    //Initialize everything
    sf::Event event;
    Library *lib = new Library();
    Data data("userTestFile.txt", "media.txt");
    data.loadMedia(lib->getVector());
    std::map<std::string, size_t> *map = new std::map<std::string, size_t>;
    data.loadUserData(map);
    for (auto it = map->begin(); it != map->end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
    //Create static test media
    //lib->getVector().push_back(CD("Sempiternal", 2013, "", "Bring Me The Horizon"));


    Menu menu(&event, lib);
    menu.setMap(map);
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";


    while (window.isOpen())
    {
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << elapsed_seconds.count() << std::endl;
        if (elapsed_seconds.count() > 20) {
            //Force logout if 20 seconds without input has passed
            menu.forceLogout();

        }
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered)
            {
                start = std::chrono::steady_clock::now();
               // std::cout << "Entered event\n" << std::endl;

                if (event.text.unicode < 128) {
                    std::cout << static_cast<char>(event.text.unicode) << std::endl;
                    std::cout << static_cast<int>(event.text.unicode) << std::endl;
                    int temp = menu.updateString(static_cast<char>(event.text.unicode));
                    if (temp == -1) {
                        window.close();
                        exit(0);
                    }
                }
            }


        }

        window.clear();
        window.draw(menu);
        window.display();
    }
    return 0;

}