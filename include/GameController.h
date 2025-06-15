
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "game.h"
#include <thread>

class GameController {
public:
    GameController(int taille);
    ~GameController();
    enum class GameState {
        Running,
        Stop
    };

    GameState getState();
    void setState(GameState state);

    std::chrono::milliseconds getSpeed();
    void setSpeed(std::chrono::milliseconds speed);

    void update_game_logic();

    Game *getGame();

    void Load(int number);
    void Save(int number);

private:
    std::chrono::milliseconds speed {1000};
    GameState state {GameState::Stop};
    Game game;
    Game save1;
    Game save2;
    std::mutex mutex;
};


#endif //GAMECONTROLLER_H
