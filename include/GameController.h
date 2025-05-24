//
// Created by Bapti on 5/24/2025.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H



class GameController {
public:
    GameController();
    ~GameController();
    enum class GameState {
        Running,
        Stop
    };

private:
    float speed {5.f};
    GameState state {GameState::Stop};
};



#endif //GAMECONTROLLER_H
