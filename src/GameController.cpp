#include "../include/GameController.h"

#include <chrono>
#include <thread>


GameController::GameController(int taille) : game(Game(taille)), save1(Game(taille)), save2(Game(taille)) {

};

GameController::~GameController() {

};

GameController::GameState GameController::getState() {
    std::lock_guard<std::mutex> lock(mutex);
    return state;
}

void GameController::setState(GameState state) {
    std::lock_guard<std::mutex> lock(mutex);
    this->state = state;
};

void GameController::update_game_logic() {
    while (true) {
        if (getState() == GameState::Running) {
            std::this_thread::sleep_for(getSpeed());
            game.updateGrid();
        }
    }
}

std::chrono::milliseconds GameController::getSpeed() {
    std::lock_guard<std::mutex> lock(mutex);
    return speed;
};

void GameController::setSpeed(std::chrono::milliseconds speed) {
    std::lock_guard<std::mutex> lock(mutex);
    this->speed = speed;
}

Game *GameController::getGame() {
    return &game;
};

void GameController::Save(int number) {
    std::lock_guard<std::mutex> lock(mutex);

    if (number == 1) {
        save1 = game;
    }
    if (number == 2) {
        save2 = game;
    }

};

void GameController::Load(int number) {
    std::lock_guard<std::mutex> lock(mutex);

    if (number == 1) {
        game = save1;
    }
    if (number == 2) {
        game = save2;
    }
};

void GameController::CreateNewGame(int taille) {
    game = Game(taille);
}
