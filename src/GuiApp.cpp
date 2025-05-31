#include "../include/GuiApp.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <float.h>


GuiApp::GuiApp(Game *game) : window(sf::VideoMode(1100, 800), "Game of Life"), game(game) {
    window.setVerticalSyncEnabled(true); // Permet de gérer le framerate avec le gpu pour ce synchro avec l'écran
    //window.setFramerateLimit(165);

    int i =1;
    while (window.isOpen()) {

        int x = game_coord.first;
        int y = game_coord.second;
        //Create grid
        for (int i = 0; i < game->getTaille(); i++) {
            this->cellules.push_back(std::vector<sf::RectangleShape>());
            for (int j = 0; j < game->getTaille(); j++) {
                auto cellule_color = sf::Color::Black;
                if (!game->is_alive(i, j)) {
                    cellule_color = sf::Color::White;
                }

                sf::RectangleShape cellule(sf::Vector2f( taille_cellule,taille_cellule));
                cellule.setFillColor(cellule_color);
                cellule.setPosition(sf::Vector2f(x, y));
                cellule.setOutlineColor(sf::Color(156, 156, 156));
                cellule.setOutlineThickness(1);
                this->cellules[i].push_back(cellule);

                x+=taille_cellule;
            }
            x = game_coord.first;
            y+=taille_cellule;
        }

        sf::Event event;

        sf::RectangleShape menu(sf::Vector2f(300, 800));
        menu.setFillColor(sf::Color(150, 150, 150));
        menu.setPosition(sf::Vector2f(0,0));
        window.draw(menu);

        sf::RectangleShape bouton_start(sf::Vector2f(90, 60));
        bouton_start.setFillColor(this->btn_color);
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


        display_grid();

        std::cout << i << std::endl;

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

};

GuiApp::~GuiApp() {

};

void GuiApp::display_grid() {
    // Diviser taille/nombre de cellules pour un truc responsive
    std::cout << "GUI grid display" << std::endl;

    for (int i = 0; i < cellules.size(); i++) {
        for (int j = 0; j < cellules[i].size(); j++) {
            window.draw(cellules[i][j]);
        }
    }
};

void GuiApp::update_grid() {
    std::cout << "GUI grid update" << std::endl;
    for (int i = 0; i < cellules.size(); i++) {
        for (int j = 0; j < cellules[i].size(); j++) {
            if (game->is_alive(i, j)) {
                cellules[i][j].setFillColor(sf::Color::Red);
            }
            else {
                cellules[i][j].setFillColor(sf::Color::Green);
            }
        }
    }
};


void GuiApp::Right_click(int x, int y) {
    if (!(x<40 || x>130) && !(y<40 ||y>100)) {
        std::cout << "yop la team le bouton a ete clicke "<< std::endl;
        this->btn_color = sf::Color::Red;

        game->updateGrid();
        game->showGrid();
        this->update_grid();

    }
}
