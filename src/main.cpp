#include <iostream>
#include "include/board.h"
#include <stdlib.h>

//clear screen cross-platform
void clear_screen() { 
  printf("\033[2J" "\033[1;1H"); 
}


int main() {

    bool turn = true;
    char p,c,m[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

    std::cout << "--------------------\n" << "  Tic-Tac-Toe Game\n" << "--------------------\n";

    do {
        std::cout << "Choose what you want (X or O): ";
        std::cin >> p;
        std::cout << '\n';
    } while(p!='X' && p!='O');

    c = (p == 'X') ? 'O' : 'X';

    Board board = Board(p,c,m);

    board.draw();
    while(!board.won() && !board.tie()) {
        if(turn) {
            board.place(); 
            turn=false;
        } else {
            board.computer_place(); 
            turn=true;
        }
        clear_screen();
        board.draw();
    }

    if(board.tie()) std::cout << "\nTie!";

    return 0;
}