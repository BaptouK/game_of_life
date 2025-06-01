
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "game.h"
#include <thread>

class GameController {
public:
    GameController(Game *game);
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

private:
    std::chrono::milliseconds speed {1000};
    GameState state {GameState::Stop};
    Game *game;
    std::mutex mutex;
};


#endif //GAMECONTROLLER_H
