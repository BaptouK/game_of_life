#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/game.h"

void Right_click(int x, int y) {
    if (!(x<40 || x>130) && !(y<40 ||y>100)) {
        std::cout << "yop la team le bouton a ete clicke "<< std::endl;
    }
}

int main() {


    Game game1(10);
    game1.setPixel(4,4,true);
    game1.setPixel(4,5,true);
    game1.setPixel(4,6,true);
    game1.showGrid();
    game1.updateGrid();
    game1.showGrid();



    // Crée une fenêtre de 800x600 pixels
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Game of Life");
    window.setVerticalSyncEnabled(true); // Permet de gérer le framerate avec le gpu pour ce synchro avec l'écran
    while (window.isOpen()) {
        sf::Event event;

        sf::RectangleShape menu(sf::Vector2f(300, 800));
        menu.setFillColor(sf::Color(150, 150, 150));
        menu.setPosition(sf::Vector2f(0,0));
        window.draw(menu);

        sf::RectangleShape separator(sf::Vector2f(10, 800));
        separator.setFillColor(sf::Color(100, 250, 100));
        separator.setPosition(sf::Vector2f(300,0));
        window.draw(separator);

        sf::RectangleShape bouton_start(sf::Vector2f(90, 60));
        bouton_start.setFillColor(sf::Color(250, 150,100));
        bouton_start.setPosition(sf::Vector2f(40,40));
        window.draw(bouton_start);


        sf::Font font;
        if (!font.loadFromFile("../assets/OpenSans_Condensed-Light.ttf")) {
            std::cout << "Error loading font" << std::endl;
        }
        sf::Text label_start;
        label_start.setPosition(sf::Vector2f(45, 40));
        label_start.setString("Start");
        label_start.setFont(font);
        label_start.setFillColor(sf::Color::Black);
        label_start.setCharacterSize(50);
        window.draw(label_start);

        window.display();

        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Right){
                    std::cout << "Right click" << std::endl;
                    std::cout << "mouse x " << event.mouseButton.x << " y " << event.mouseButton.y << std::endl;
                    Right_click(event.mouseButton.x, event.mouseButton.y);
                }
            }

            if (event.type == sf::Event::MouseMoved){
                //std::cout << "coords mouse x " << event.mouseMove.x << " y "  << event.mouseMove.y << std::endl;
            }

        }
    }
    return 0;
}
