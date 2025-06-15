#include "../include/GuiApp.h"
#include <SFML/Graphics.hpp>
#include <iostream>

inline sf::Font font;


GuiApp::GuiApp(Game *game,GameController *gameController) : window(sf::VideoMode(1100, 800), "Game of Life"), game(game), gameController(gameController) {
    //window.setVerticalSyncEnabled(true); // Permet de gérer le framerate avec le gpu pour ce synchro avec l'écran
    window.setFramerateLimit(60);

    this->fillGrid();

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

        sf::RectangleShape btn_save_1(sf::Vector2f(110, 60));
        btn_save_1.setFillColor(this->btn_color);
        btn_save_1.setPosition(sf::Vector2f(30,410));
        window.draw(btn_save_1);
        sf::Text label_save_1;
        label_save_1.setPosition(sf::Vector2f(30, 410));
        label_save_1.setString("Save 1");
        label_save_1.setFont(font);
        label_save_1.setFillColor(sf::Color::Black);
        label_save_1.setCharacterSize(50);
        window.draw(label_save_1);

        sf::RectangleShape btn_load_1(sf::Vector2f(110, 60));
        btn_load_1.setFillColor(this->btn_color);
        btn_load_1.setPosition(sf::Vector2f(150,410));
        window.draw(btn_load_1);
        sf::Text label_load_1;
        label_load_1.setPosition(sf::Vector2f(150, 410));
        label_load_1.setString("Load 1");
        label_load_1.setFont(font);
        label_load_1.setFillColor(sf::Color::Black);
        label_load_1.setCharacterSize(50);
        window.draw(label_load_1);

        sf::RectangleShape btn_save_2(sf::Vector2f(110, 60));
        btn_save_2.setFillColor(this->btn_color);
        btn_save_2.setPosition(sf::Vector2f(30,480));
        window.draw(btn_save_2);
        sf::Text label_save_2;
        label_save_2.setPosition(sf::Vector2f(30, 480));
        label_save_2.setString("Save 2");
        label_save_2.setFont(font);
        label_save_2.setFillColor(sf::Color::Black);
        label_save_2.setCharacterSize(50);
        window.draw(label_save_2);

        sf::RectangleShape btn_load_2(sf::Vector2f(110, 60));
        btn_load_2.setFillColor(this->btn_color);
        btn_load_2.setPosition(sf::Vector2f(150,480));
        window.draw(btn_load_2);
        sf::Text label_load_2;
        label_load_2.setPosition(sf::Vector2f(150, 480));
        label_load_2.setString("Load 2");
        label_load_2.setFont(font);
        label_load_2.setFillColor(sf::Color::Black);
        label_load_2.setCharacterSize(50);
        window.draw(label_load_2);

        sf::RectangleShape btn_new_grid(sf::Vector2f(230, 60));
        btn_new_grid.setFillColor(this->btn_color);
        btn_new_grid.setPosition(sf::Vector2f(30,550));
        window.draw(btn_new_grid);
        sf::Text label_new_grid;
        label_new_grid.setPosition(sf::Vector2f(40, 550));
        label_new_grid.setString("Change size");
        label_new_grid.setFont(font);
        label_new_grid.setFillColor(sf::Color::Black);
        label_new_grid.setCharacterSize(50);
        window.draw(label_new_grid);

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
            }

        }
        window.clear();
    }

};

GuiApp::~GuiApp() {

};

void GuiApp::fillGrid() {
    int x = game_coord.first;
    int y = game_coord.second;
    //Create grid
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
};


void GuiApp::display_grid() {

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
        std::chrono::milliseconds speed{50};
        gameController->setSpeed(gameController->getSpeed()+speed );
        return;
    }

    if (!(x<10 || x>65) && !(y<140 ||y>180)) { // Double Speed Down Button
        std::chrono::milliseconds speed{100};
        gameController->setSpeed(gameController->getSpeed()+speed );
        return;
    }

    if (!(x<190 || x>220) && !(y<140 ||y>180)) { // Single Speed Up Button
        std::chrono::milliseconds speed{50};
        gameController->setSpeed(gameController->getSpeed()-speed );
        return;
    }

    if (!(x<240 || x>290) && !(y<140 ||y>180)) { // Double Speed Up Button
        std::chrono::milliseconds speed{100};
        gameController->setSpeed(gameController->getSpeed()-speed );
        return;
    }

    if (!(x<30 || x>140) && !(y<410 ||y>470)) { // Save 1
        gameController->Save(1);
        return;
    }

    if (!(x<150 || x>250) && !(y<410 ||y>460)) { // Load 1
        gameController->Load(1);
        updateTaille_cellule();
        cellules.clear();
        fillGrid();
        return;
    }

    if (!(x<30 || x>140) && !(y<480 ||y>540)) { // Save 2
        gameController->Save(2);
        return;
    }

    if (!(x<150 || x>260) && !(y<490 ||y>540)) { // Load 2
        gameController->Load(2);
        updateTaille_cellule();
        cellules.clear();
        fillGrid();
        return;
    }

    if (!(x<30 || x>260) && !(y<550 ||y>610)) { // Change size
        changeSize();
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

void handleTextInput(const sf::Event& event, std::string& input) {
    if (event.type == sf::Event::TextEntered) {
        // On accepte uniquement les caractères ASCII pour les chiffres
        if (event.text.unicode >= '0' && event.text.unicode <= '9') {
            input += static_cast<char>(event.text.unicode);
        }
        // Gérer retour arrière (backspace)
        else if (event.text.unicode == 8 && !input.empty()) {
            input.pop_back();
        }
    }
    std::cout << input << std::endl;

};

void GuiApp::updateTaille_cellule() {
    taille_cellule = static_cast<float>(game_size.first/game->getTaille());
}

void GuiApp::CreatenewGame(std::string& input) {
    if (input.empty()) {
        return;
    }else {
        int n = std::stoi(input);
        gameController->CreateNewGame(n);
        updateTaille_cellule();
        cellules.clear();
        fillGrid();
    }
}


void GuiApp::changeSize() {
    std::string input {""};

    sf::RenderWindow window2(sf::VideoMode(600, 600), "Change the size");

    sf::RectangleShape menu(sf::Vector2f(600, 600));
    menu.setFillColor(sf::Color(150, 150, 150));

    sf::RectangleShape btn_accept(sf::Vector2f(270, 50));
    btn_accept.setFillColor(btn_color);
    btn_accept.setPosition(sf::Vector2f(10, 300));

    sf::Text label_accept;
    label_accept.setPosition(sf::Vector2f(15, 290));
    label_accept.setFont(font);
    label_accept.setFillColor(sf::Color::Black);
    label_accept.setCharacterSize(50);

    sf::Text label_taille;
    label_taille.setPosition(sf::Vector2f(5, 0));
    label_taille.setFont(font);
    label_taille.setFillColor(sf::Color::Black);
    label_taille.setCharacterSize(50);

    while (window2.isOpen()) {
        sf::Event event;

        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();

            if (event.mouseButton.button == sf::Mouse::Left){
                if (!(event.mouseButton.x<10 || event.mouseButton.x>280) && !(event.mouseButton.y<300 ||event.mouseButton.y>350)) { // Change size
                    CreatenewGame(input);
                    window2.close();
                }
            }
            handleTextInput(event, input);
        }
        window2.clear();

        label_taille.setString("Write the new grid size \n min: 2\n max: 1000 \n New size : " + input);
        label_accept.setString("Create new grid ");

        window2.draw(menu);

        window2.draw(btn_accept);
        window2.draw(label_accept);

        window2.draw(label_taille);

        window2.display();
    }


}
