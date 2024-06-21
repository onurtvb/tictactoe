#include <stdlib.h>
#include <string.h>
#include "include/board.h"
#include "include/color.hpp"


Board::Board(char player_p, char computer_p, char* moves_p) {
    player = player_p;
    computer = computer_p;
    moves = new char[strlen(moves_p)+1];
    if(moves) strcpy(moves,moves_p);
}

Board::~Board() {
    delete[] moves;
}

void Board::move() {

}

void Board::draw() {

}