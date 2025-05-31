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

int Game::getTaille() {
    return this->taille;
};



bool Game::updatePixel(int row, int col) {
    int cpt=0;

    if (is_alive(row+1,col)){
        //std::cout << "etape 1" << std::endl;
        cpt++;
    }
    if (is_alive(row-1,col)) {
        //std::cout << "etape 2" << std::endl;

        cpt++;
    }
    if (is_alive(row,col-1)) {
        //std::cout << "etape 3" << std::endl;

        cpt++;
    }
    if (is_alive(row,col+1)) {
       //std::cout << "etape 4" << std::endl;
        cpt++;
    }
    if (is_alive(row-1,col-1)) {
        //std::cout << "etape 5" << std::endl;

        cpt++;
    }
    if (is_alive(row+1,col+1)) {
        //std::cout << "etape 6" << std::endl;

        cpt++;
    }
    if (is_alive(row-1,col+1)) {
       //std::cout << "etape 7" << std::endl;

        cpt++;
    }
    if (is_alive(row+1,col-1)) {
        //std::cout << "etape 8" << std::endl;

        cpt++;
    }
    // std:: cout << cpt << std::endl;
    if (is_alive(row,col)) {
        if (!(cpt==2||cpt==3)) {
            return false;
        }
        return true;
    }else {
        if (cpt ==3) {
            return true;
        }
        return false;
    }
};


bool Game::is_alive(int row, int col) {
    if (row <0 || col <0 || row >= this->taille  || col >= this->taille) {
        return false;
    }
    return this->grid[row][col];
};

void Game::updateGrid() {

    std::cout << "Updating grid..." << std::endl;
    std::vector<std::vector<bool>> newGrid;

    for (int i = 0; i < this->taille; i++) {
        newGrid.push_back(std::vector<bool> (this->taille, false));
        for (int j = 0; j < this->taille; j++) {
            bool newValue = updatePixel(i,j);
            newGrid[i][j] = newValue;
        }
    }
    this->grid=newGrid;
    std::cout << "Close function" << std::endl;

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
