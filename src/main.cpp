#include <iostream>
#include <thread>

#include "../include/game.h"
#include "../include/GameController.h"
#include "../include/GuiApp.h"

int main() {


    // Game game1(100);
    // game1.setPixel(4,5,true);
    // game1.setPixel(4,4,true);
    // game1.setPixel(4,6,true);

    GameController gameController1(50);
    std::thread game_controller(&GameController::update_game_logic, &gameController1);
    game_controller.detach();

    GuiApp window(gameController1.getGame(),&gameController1);

    return 0;
}