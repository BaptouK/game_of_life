#include "../include/game.h"
#include <iostream>
#include <vector>

Game::Game(int taille) : taille(taille) {
    for (int i = 0; i < taille; i++) {
        this->grid.push_back(std::vector<bool> (taille, false));
    }
};

Game::~Game(){};

void Game::setPixel(int row, int col, bool value) {
    this->grid[row][col] = value;
};

bool Game::getPixel(int row, int col) {
    return this->grid[row][col];
};

bool Game::updatePixel(int row, int col, bool value) {
    // A FAIRE
};

bool Game::is_alive(int row, int col) {
    // A FIX CAR GROS PROBLEM
    if (row <0 || col <0 || row >= this->taille  || col >= this->taille) {
        return false;
    }
    return this->grid[row][col];
};


void Game::updateGrid() {
    // A FIX CA FAIT TOUT BUGUER
    std::cout << "Updating grid..." << std::endl;
    std::vector<std::vector<bool>> newGrid;
    int cpt{0};

    for (int i = 0; i < this->taille; i++) {
        std::cout << "yo la  team ";
        for (int j = 0; j < this->taille; j++) {
            if (i+1==taille || i-1<0 || j+1==taille || j-1<taille ) {
                if (this->grid[i+1][j+1]) {
                    cpt++;
                }
                if (this->grid[i+1][j]) {
                    cpt++;
                }
                if (this->grid[i][j+1]) {
                    cpt++;
                }
                if (this->grid[i-1][j]) {
                    cpt++;
                }
                if (this->grid[i][j-1]) {
                    cpt++;
                }
                if (this->grid[i-1][j-1]) {
                    cpt++;
                }
                if (this->grid[i+1][j-1]) {
                    cpt++;
                }
                if (this->grid[i-1][j+1]) {
                    cpt++;
                }
                std::cout << cpt << std::endl;

                if (this->grid[i][j]) {
                    if (!(cpt==2||cpt==3) ) {
                        newGrid[i][j] = false;
                    }
                }else {
                    if (cpt==3) {
                        newGrid[i][j] = true;
                    }
                }

            }
        }
    }
    std::cout << "prout" << std::endl;
    this->grid=newGrid;
    this->showGrid();
    std::cout << "prout1" << std::endl;

};

void Game::showGrid() {
    std::cout << "Showing grid..." << std::endl;
    std::string grid;

    for (auto row : this->grid) {
        for (auto col : row) {
            grid += std::to_string(col) + " ";
        }
        grid += "\n";
    }
    std::cout << grid << std::endl;
};
