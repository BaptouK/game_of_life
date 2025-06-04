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

    sf::Font font;
    if (!font.loadFromFile("../assets/OpenSans_Condensed-Light.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }

    sf::Texture single_arrow;
    single_arrow.loadFromFile("../assets/arrow1.png");

    sf::Texture double_arrow;
    double_arrow.loadFromFile("../assets/arrow2.png");

    sf::Texture pause;
    pause.loadFromFile("../assets/pause.png");

    sf::Texture start;
    start.loadFromFile("../assets/start.png");

    while (window.isOpen()) {

        sf::Event event;

        sf::RectangleShape menu(sf::Vector2f(300, 800));
        menu.setFillColor(sf::Color(150, 150, 150));
        menu.setPosition(sf::Vector2f(0,0));
        window.draw(menu);

        sf::RectangleShape rec_gen_speed(sf::Vector2f(250, 60));
        rec_gen_speed.setFillColor(this->btn_color);
        rec_gen_speed.setPosition(sf::Vector2f(30,40));
        //window.draw(rec_gen_speed);
        sf::Text label_speed;
        label_speed.setPosition(sf::Vector2f(40, 35));
        label_speed.setString("Speed : "+ std::to_string(gameController->getSpeed().count()) + "ms");
        label_speed.setFont(font);
        label_speed.setFillColor(sf::Color::Black);
        label_speed.setCharacterSize(50);
        window.draw(label_speed);


        sf::Sprite double_speed_down;
        double_speed_down.setTexture(double_arrow);
        double_speed_down.setPosition(sf::Vector2f(10,125));
        double_speed_down.setScale(sf::Vector2f(0.15,0.15));
        window.draw(double_speed_down);

        sf::Sprite single_speed_down;
        single_speed_down.setTexture(single_arrow);
        single_speed_down.setPosition(sf::Vector2f(55,125));
        single_speed_down.setScale(sf::Vector2f(0.15,0.15));
        window.draw(single_speed_down);

        if (gameController->getState() == GameController::GameState::Stop) {
            sf::Sprite btn_start;
            btn_start.setTexture(start);
            btn_start.setPosition(sf::Vector2f(140,145));
            btn_start.setScale(sf::Vector2f(0.35,0.35));
            window.draw(btn_start);
        } else {
            sf::Sprite btn_pause;
            btn_pause.setTexture(pause);
            btn_pause.setPosition(sf::Vector2f(135,145));
            btn_pause.setScale(sf::Vector2f(0.18,0.18));
            window.draw(btn_pause);
        }



        sf::Sprite single_speed_up;
        single_speed_up.setTexture(single_arrow);
        single_speed_up.setPosition(sf::Vector2f(250,200));
        single_speed_up.setScale(sf::Vector2f(0.15,0.15));
        single_speed_up.setRotation(180);
        window.draw(single_speed_up);

        sf::Sprite double_speed_up;
        double_speed_up.setTexture(double_arrow);
        double_speed_up.setPosition(sf::Vector2f(300,200));
        double_speed_up.setScale(sf::Vector2f(0.15,0.15));
        double_speed_up.setRotation(180);
        window.draw(double_speed_up);

        sf::Text counter_generation;
        counter_generation.setPosition(sf::Vector2f(30, 200));
        counter_generation.setString("Generation : "+ std::to_string(game->getGeneration()));
        counter_generation.setFont(font);
        counter_generation.setFillColor(sf::Color::Black);
        counter_generation.setCharacterSize(50);
        window.draw(counter_generation);

        sf::RectangleShape btn_randomizer(sf::Vector2f(230, 60));
        btn_randomizer.setFillColor(this->btn_color);
        btn_randomizer.setPosition(sf::Vector2f(30,270));
        window.draw(btn_randomizer);
        sf::Text label_randomizer;
        label_randomizer.setPosition(sf::Vector2f(40, 266));
        label_randomizer.setString("Randomizer");
        label_randomizer.setFont(font);
        label_randomizer.setFillColor(sf::Color::Black);
        label_randomizer.setCharacterSize(50);
        window.draw(label_randomizer);

        sf::RectangleShape btn_clear(sf::Vector2f(110, 60));
        btn_clear.setFillColor(this->btn_color);
        btn_clear.setPosition(sf::Vector2f(30,340));
        window.draw(btn_clear);
        sf::Text label_clear;
        label_clear.setPosition(sf::Vector2f(40, 340));
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

    if (!(x<130 || x>170) && !(y<140 ||y>180)) { // Start Button
        if (gameController->getState() == GameController::GameState::Running) {
            gameController->setState(GameController::GameState::Stop);
        }else {
            gameController->setState(GameController::GameState::Running);
        }
        return;
    }

    if (!(x<30 || x>260) && !(y<270 ||y>330)) { // Randomizer Button
        game->CreateSoup();
        return;
    }

    if (!(x<30 || x>140) && !(y<340 ||y>400)) { // Clear Button
        std::cout << "Clear button clicked " << std::endl;
        game->clearGrid();
        return;
     }

    if (!(x<70 || x>110) && !(y<140 ||y>180)) { // Single Speed Down Button
        std::cout << "Prout " << std::endl;
        std::chrono::milliseconds speed{50};
        gameController->setSpeed(gameController->getSpeed()+speed );
        return;
    }

    if (!(x<10 || x>65) && !(y<140 ||y>180)) { // Double Speed Down Button
        std::cout << "Prout " << std::endl;
        std::chrono::milliseconds speed{100};
        gameController->setSpeed(gameController->getSpeed()+speed );
        return;
    }

    if (!(x<190 || x>220) && !(y<140 ||y>180)) { // Single Speed Up Button
        std::cout << "Prout " << std::endl;
        std::chrono::milliseconds speed{50};
        gameController->setSpeed(gameController->getSpeed()-speed );
        return;
    }

    if (!(x<240 || x>290) && !(y<140 ||y>180)) { // Double Speed Up Button
        std::cout << "Prout " << std::endl;
        std::chrono::milliseconds speed{100};
        gameController->setSpeed(gameController->getSpeed()-speed );
        return;
    }

    x -= game_coord.first;
    y -= game_coord.second;
    x/= taille_cellule;
    y/= taille_cellule;

    std::cout << "coords : " << x << "  -  " << y<< std::endl;
    if (game->is_alive(y,x)) {
        game->setPixel(y,x,false);
    } else {
        game->setPixel(y,x,true);
    }

}
