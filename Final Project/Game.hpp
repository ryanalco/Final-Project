//
//  Game.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 11/19/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>



class Game {
public:
    Game(int level);
    virtual ~Game();
    void play();
private:
    Board* board;
    int enemies;
};


Game:: Game(int level) {
    //board = new Board(int level)
    
    int row_player = 1 + rand() % 10;
    int col_player = 1 + rand() % 10;
    
    if (level == 1) {
        enemies = 5;
        while (enemies > 0) {
            int row_enemy = 1 + rand() % 10;
            int col_enemy = 1 + rand() % 10;
            if (row_enemy == row_player && col_enemy == col_player) {
                continue;
            }
            Enemy* monster = new Enemy(row_enemy, col_enemy);
            board->add_enemy(monster);
            enemies--;
        }
    }
    else if (level == 2) {
        enemies = 7;
        while (enemies > 0) {
            int row_enemy = 1 + rand() % 10;
            int col_enemy = 1 + rand() % 10;
            if (row_enemy == row_player && col_enemy == col_player) {
                continue;
            }
            board->add_enemy(row_enemy, col_enemy);
            enemies--;
        }
    }
    else if (level == 3) {
        enemies = 10;
        while (enemies > 0) {
            int row_enemy = 1 + rand() % 10;
            int col_enemy = 1 + rand() % 10;
            if (row_enemy == row_player && col_enemy == col_player) {
                continue;
            }
            board->add_enemy(row_enemy, col_enemy);
            enemies--;
        }
    }
    else {
        std::cout << "error";
    }
    
    try {
        board = new Board();
    }
    catch(std::exception & e) {
        board = nullptr;
        throw;
    }
    
    board->add_player(row_player, col_player);
}

Game:: ~Game() {
    delete board;
}





#endif /* Game_hpp */
