#include <stdlib.h>
#include <string.h>
#include "include/board.h"
#include "include/color.hpp"


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

}

//place the player's decision
void Board::place() {

}

//place the computer's decision
void Board::computer_place() {

}

bool Board::won() {
    if(allequal(moves[0],moves[1],moves[2],player) ||
       allequal(moves[3],moves[4],moves[5],player) ||
       allequal(moves[6],moves[7],moves[8],player) ||
       allequal(moves[0],moves[3],moves[6],player) ||
       allequal(moves[1],moves[4],moves[7],player) ||
       allequal(moves[2],moves[5],moves[8],player) ||
       allequal(moves[0],moves[4],moves[8],player) ||
       allequal(moves[2],moves[4],moves[6],player)
       ) return true;

    return false;
}