#ifndef GAME_H
#define GAME_H
#include <vector>

class Game {
public:
    Game()=delete;
    Game(int taille);
    ~Game();

    void setPixel(int row, int col, bool value);
    bool getPixel(int row, int col);

    int getTaille();
    int getGrid();

    int getGeneration();

    bool is_alive(int row, int col);

    bool updatePixel(int row, int col);

    void updateGrid();

    void showGrid();

    void CreateSoup();

    void clearGrid();
private:
    unsigned int generation{0};
    std::vector<std::vector<bool>> grid;
    int taille;
};
#endif
