#include <iostream>
#include <thread>

#include "../include/game.h"
#include "../include/GameController.h"
#include "../include/GuiApp.h"

int main() {


    Game game1(50);
    game1.setPixel(4,5,true);
    game1.setPixel(4,4,true);
    game1.setPixel(4,6,true);
    //std::cout << game1.updatePixel(4,4) << std::endl;
    //std::cout << game1.updatePixel(3,4) << std::endl;

    GameController gameController1(&game1);

    std::thread game_controller(&GameController::update_game_logic, &gameController1);

    game_controller.detach();

    GuiApp window(&game1,&gameController1);



    return 0;
}
