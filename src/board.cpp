#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <random>
#include "board.h"


template <typename T, typename U>
bool allequal(const T &t, const U &u) {
    return (t == u);
}

template <typename T, typename U, typename... Others>
bool allequal(const T &t, const U &u, Others const &... args) {
    return ((t == u) && allequal(u, args...));
}


Board::Board(char player_p, char computer_p, char* moves_p) {
    player = player_p;
    computer = computer_p;
    moves = new char[strlen(moves_p)+1];
    if(moves) strcpy(moves,moves_p);
}

Board::~Board() {
    delete[] moves;
}


//draw the board with colors
void Board::draw() {
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << moves[0] << " | " << moves[1] << " | " << moves[2] << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << "-----------"<< std::endl;

    std::cout << "   |   |   " << std::endl;
    std::cout << " " << moves[3] << " | " << moves[4] << " | " << moves[5] << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << "-----------" << std::endl;

    std::cout << "   |   |   " << std::endl;
    std::cout << " " << moves[6] << " | " << moves[7] << " | " << moves[8] << std::endl;
    std::cout << "   |   |   \n" << std::endl;
}

//player's move
void Board::place() {
    int pos;
    do {
        std::cout << "Where to place (1-9): ";
        std::cin >> pos;
        std::cout << '\n';
    } while( (pos < 1 || pos > 9) || (moves[pos-1] == 'X' || moves[pos-1] == 'O') );
    player_last_move = pos-1;
    moves[pos-1] = player;
}


void Board::bot_place(int pos) {
    moves[pos] = computer;
}

bool Board::tie() {
    for(int i=0; i<9; i++) if(moves[i] == ' ') return false;
    return true;
}


bool Board::won(char* bot_nickname) {
    if(allequal(moves[0],moves[1],moves[2],player) ||
       allequal(moves[3],moves[4],moves[5],player) ||
       allequal(moves[6],moves[7],moves[8],player) ||
       allequal(moves[0],moves[3],moves[6],player) ||
       allequal(moves[1],moves[4],moves[7],player) ||
       allequal(moves[2],moves[5],moves[8],player) ||
       allequal(moves[0],moves[4],moves[8],player) ||
       allequal(moves[2],moves[4],moves[6],player)
       ) {std::cout << "\nYou won!\n"; return true;}

    if(allequal(moves[0],moves[1],moves[2],computer) ||
       allequal(moves[3],moves[4],moves[5],computer) ||
       allequal(moves[6],moves[7],moves[8],computer) ||
       allequal(moves[0],moves[3],moves[6],computer) ||
       allequal(moves[1],moves[4],moves[7],computer) ||
       allequal(moves[2],moves[5],moves[8],computer) ||
       allequal(moves[0],moves[4],moves[8],computer) ||
       allequal(moves[2],moves[4],moves[6],computer)
       ) {std::cout << "\nYou lost! " << bot_nickname << " won!\n"; return true;}

    return false;
}

char* Board::get_moves() {
    return moves;
}

int Board::get_player_last_move() {
    return player_last_move;
}