#include <iostream>
#include "../include/game.h"
#include "../include/GuiApp.h"

int main() {


    Game game1(10);
    game1.setPixel(4,5,true);
    game1.setPixel(4,4,true);
    game1.setPixel(4,6,true);

    //std::cout << game1.updatePixel(4,4) << std::endl;
    //std::cout << game1.updatePixel(3,4) << std::endl;

    GuiApp window(&game1);

    return 0;
}
