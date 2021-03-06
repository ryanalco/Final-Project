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
#include <iostream>
#include <string>
#include <cstdlib>
#include "Board.hpp"
#include "AddOns.hpp"

class Board;


class Game {
public:
    Game(int level);
    virtual ~Game();
    void play();
private:
    Board* board;
    int enemies;
    int traps;
    int first = 0;
};


Game:: Game(int level) {
    /*
    int row_player = 1 + rand() % 10;
    int col_player = 1 + rand() % 10;
    */
    if (level == 1) {
        enemies = 5;
        traps = 4;
        
        try {
            board = new Board(enemies);
        }
        catch(std::exception & e) {
            board = nullptr;
            throw;
        }
        while (enemies > 0) {
            int row_enemy = 1 + rand() % 10;
            int col_enemy = 1 + rand() % 10;
            if (row_enemy == 5 && col_enemy == 5) {
                continue;
            }
            board->add_enemy(row_enemy, col_enemy);
            enemies--;
        }
        
        board->create_money(2, 2);
        board->create_money(9, 9);
        board->create_money(2, 9);
        board->create_money(9, 2);
        
        while (traps > 0) {
            int row_trap = 1 + rand() % 10;
            int col_trap = 1 + rand() % 10;
            if ((row_trap == 5 && col_trap == 5) || (board->find_monies(row_trap, col_trap) == true)) {
                continue;
            }
            board->create_trap(row_trap, col_trap);
            traps--;
        }
        
        board->add_player();
    }
    else if (level == 2) {
        enemies = 7;
        traps = 6;
        
        try {
            board = new Board(enemies);
        }
        catch(std::exception & e) {
            board = nullptr;
            throw;
        }
        
        while (enemies > 0) {
            int row_enemy = 1 + rand() % 10;
            int col_enemy = 1 + rand() % 10;
            if (row_enemy == 5 && col_enemy == 5) {
                continue;
            }
            board->add_enemy(row_enemy, col_enemy);
            enemies--;
        }
        
        board->create_money(2, 2);
        board->create_money(9, 9);
        board->create_money(2, 9);
        board->create_money(9, 2);
        
        while (traps > 0) {
            int row_trap = 1 + rand() % 10;
            int col_trap = 1 + rand() % 10;
            if ((row_trap == 5 && col_trap == 5) || (board->find_monies(row_trap, col_trap))) {
                continue;
            }
            board->create_trap(row_trap, col_trap);
            traps--;
        }
        
        board->add_player();
    }
    else if (level == 3) {
        enemies = 10;
        traps = 10;
        
        try {
            board = new Board(enemies);
        }
        catch(std::exception & e) {
            board = nullptr;
            throw;
        }
        
        while (enemies > 0) {
            int row_enemy = 1 + rand() % 10;
            int col_enemy = 1 + rand() % 10;
            if (row_enemy == 5 && col_enemy == 5) {
                continue;
            }
            board->add_enemy(row_enemy, col_enemy);
            enemies--;
        }
        
        board->create_money(2, 2);
        board->create_money(9, 9);
        board->create_money(2, 9);
        board->create_money(9, 2);
        
        while (traps > 0) {
            int row_trap = 1 + rand() % 10;
            int col_trap = 1 + rand() % 10;
            if ((row_trap == 5 && col_trap == 5) || (board->find_monies(row_trap, col_trap))) {
                continue;
            }
            board->create_trap(row_trap, col_trap);
            traps--;
        }
        
        board->add_player();
    }
    else {
        std::cout << "error";
    }
    
    
}

Game:: ~Game() {
    delete board;
    board = nullptr;
}

void Game:: play() {
    Player* p = board->create_player();
    while ((p->is_alive()) && (board->num_monies() > 0)) {
        board->show_grid();
        if (!first) {
            std:: cout << "You(\"@\") must get all the money(\"$\") while avoiding the moving enemies(\"!\") and the traps(\"*\"). Be careful, the enemies could be hiding behind the money or the traps!\nUse the arrow keys to move.\nA number on the grid means there are that many enemies in that location.\n";
            first++;
        }
        if (board->make_money()) {
            std:: cout << "You got a money\n";
            board->lose_money();
        }
        std:: cout << "You have " << board->num_monies() << " monies remaining\n";
        char response;
        response = getCharacter(); //this is from the Additions.hpp
        if (isblank(response)) {
            return;
        }
        else {
            switch (response) {
                case 'u':
                case 'd':
                case 'l':
                case 'r':
                    p->move(decodeDirection(response));
                    break;
            }
        }
        board->move_enemies();
        board->check_monies();
        board->check_traps();
    }
    board->show_grid();
    if (!p->is_alive()) {
        std:: cout << "You died :( \n";
    }
    else {
        std:: cout << "You got all the money! You win :) \n";
    }
}





#endif /* Game_hpp */
