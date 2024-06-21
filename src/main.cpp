#include <iostream>
#include "include/board.h"


int main() {

    char p,c;
    char* m = new char[9];

    std::cout << "--------------------\n" << "     Tic-Tac-Toe Game\n" << "--------------------\n";

    do {
        std::cout << "Choose what you want (X or O): ";
        std::cin >> p;
        std::cout << '\n';
    } while(p!='X' || p!='O');

    c = (p == 'X') ? 'O' : 'X';

    Board board = Board(p,c,m);


    while(!board.won()) {
        board.draw();
        // place player and computer
    }

    delete[] m;
    return 0;
}