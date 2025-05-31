#include "../include/GuiApp.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <float.h>


GuiApp::GuiApp(Game *game,GameController *gameController) : window(sf::VideoMode(1100, 800), "Game of Life"), game(game), gameController(gameController) {
    //window.setVerticalSyncEnabled(true); // Permet de gérer le framerate avec le gpu pour ce synchro avec l'écran
    window.setFramerateLimit(60);

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
    for (int i = 0; i < game->getTaille(); i++) {
        this->cellules.push_back(std::vector<sf::RectangleShape>());

        for (int j = 0; j < game->getTaille(); j++) {

            auto cellule_color = sf::Color::White;

            if (game->is_alive(i, j)) {
                cellule_color = sf::Color::Black;
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

    while (window.isOpen()) {

        sf::Event event;

        sf::RectangleShape menu(sf::Vector2f(300, 800));
        menu.setFillColor(sf::Color(150, 150, 150));
        menu.setPosition(sf::Vector2f(0,0));
        window.draw(menu);

        sf::Font font;
        if (!font.loadFromFile("../assets/OpenSans_Condensed-Light.ttf")) {
            std::cout << "Error loading font" << std::endl;
        }

        sf::RectangleShape btn_start(sf::Vector2f(90, 60));
        btn_start.setFillColor(this->btn_color);
        btn_start.setPosition(sf::Vector2f(40,40));
        window.draw(btn_start);
        sf::Text label_start;
        label_start.setPosition(sf::Vector2f(45, 40));
        label_start.setString("Start");
        label_start.setFont(font);
        label_start.setFillColor(sf::Color::Black);
        label_start.setCharacterSize(50);
        window.draw(label_start);

        sf::RectangleShape btn_stop(sf::Vector2f(110, 60));
        btn_stop.setFillColor(this->btn_color);
        btn_stop.setPosition(sf::Vector2f(160,40));
        window.draw(btn_stop);
        sf::Text label_stop;
        label_stop.setPosition(sf::Vector2f(165, 40));
        label_stop.setString("Pause");
        label_stop.setFont(font);
        label_stop.setFillColor(sf::Color::Black);
        label_stop.setCharacterSize(50);
        window.draw(label_stop);

        sf::RectangleShape btn_soup(sf::Vector2f(90, 60));
        btn_soup.setFillColor(this->btn_color);
        btn_soup.setPosition(sf::Vector2f(40,120));
        window.draw(btn_soup);
        sf::Text label_soup;
        label_soup.setPosition(sf::Vector2f(45, 115));
        label_soup.setString("Soup");
        label_soup.setFont(font);
        label_soup.setFillColor(sf::Color::Black);
        label_soup.setCharacterSize(50);
        window.draw(label_soup);

        sf::RectangleShape btn_clear(sf::Vector2f(110, 60));
        btn_clear.setFillColor(this->btn_color);
        btn_clear.setPosition(sf::Vector2f(160,120));
        window.draw(btn_clear);
        sf::Text label_clear;
        label_clear.setPosition(sf::Vector2f(165, 115));
        label_clear.setString("Clear");
        label_clear.setFont(font);
        label_clear.setFillColor(sf::Color::Black);
        label_clear.setCharacterSize(50);
        window.draw(label_clear);

        update_grid();
        display_grid();

        window.display();

        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    std::cout << "Right click" << std::endl;
                    std::cout << "mouse x " << event.mouseButton.x << " y " << event.mouseButton.y << std::endl;

                    Left_click(event.mouseButton.x, event.mouseButton.y);
                }
            }

            if (event.type == sf::Event::MouseMoved){
                //std::cout << "coords mouse x " << event.mouseMove.x << " y "  << event.mouseMove.y << std::endl;
            }

        }
        window.clear();
    }

};

GuiApp::~GuiApp() {

};

void GuiApp::display_grid() {
    // Diviser taille/nombre de cellules pour un truc responsive
    //std::cout << "GUI grid display" << std::endl;

    for (int i = 0; i < cellules.size(); i++) {
        for (int j = 0; j < cellules[i].size(); j++) {
            window.draw(cellules[i][j]);
        }
    }
};

void GuiApp::setGameController(GameController *gc) {
    this->gameController = gc;
};


void GuiApp::update_grid() {
    //std::cout << "GUI grid update" << std::endl;
    for (int i = 0; i < cellules.size(); i++) {
        for (int j = 0; j < cellules[i].size(); j++) {
            if (game->is_alive(i, j)) {
                cellules[i][j].setFillColor(sf::Color::Black);
            }
            else {
                cellules[i][j].setFillColor(sf::Color::White);
            }
        }
    }
};


void GuiApp::Left_click(int x, int y) {

    if (!(x<40 || x>130) && !(y<40 ||y>100)) { // Start Button
        std::cout << "Start button clicked " << std::endl;
        gameController->setState(GameController::GameState::Running);
        return;
    }

    if (!(x<130 || x>270) && !(y<40 ||y>100)) { // Stop Button
        std::cout << "Stop button clicked " << std::endl;
        gameController->setState(GameController::GameState::Stop);
        return;
    }

    if (!(x<40 || x>130) && !(y<120 ||y>180)) { // Soup Button
        std::cout << "Soup button clicked " << std::endl;
        game->CreateSoup();
        return;
    }

    if (!(x<130 || x>270) && !(y<120 ||y>180)) { // Clear Button
        std::cout << "Clear button clicked " << std::endl;
        game->clearGrid();
        return;
     }

    // Detecter si on clique sur une cellule

    int index_x = static_cast<int>(x/((window_size.first-leftPanel_size.first)/ game->getTaille())) ;
    int index_y = static_cast<int>(y/((window_size.second-leftPanel_size.second)/ game->getTaille()));

    std::cout << "Cellule clicked at index x: " << index_x << " y: " << index_y << std::endl;
    cellules[index_x][index_y].setFillColor(sf::Color::Black);
    game->setPixel(index_x,index_y, true);

}
