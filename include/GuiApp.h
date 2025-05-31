#ifndef GUIAPP_H
#define GUIAPP_H

#include <SFML/Graphics.hpp>

#include "game.h"
#include "GameController.h"

class GuiApp {
public:
    GuiApp(Game *game,GameController *gameController);
    ~GuiApp();
    void run();

    void Left_click(int x, int y);

    void display_grid();
    void update_grid();

    void setGameController(GameController *gameController);

private:
    std::vector<std::vector<sf::RectangleShape>> cellules;
    Game *game;
    GameController *gameController;
    sf::Color btn_color{sf::Color(250, 150,100)};
    std::pair<int,int> window_size{1100,800};
    std::pair<int,int> leftPanel_size{300,800};
    std::pair<int,int> game_size{window_size.first-leftPanel_size.first,window_size.second-leftPanel_size.second};
    std::pair<int,int> game_coord{leftPanel_size.first,0};
    sf::RenderWindow window;
    float taille_cellule{static_cast<float>(game_size.first/game->getTaille())};
};



#endif //GUIAPP_H
