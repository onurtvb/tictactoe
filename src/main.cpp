#include <iostream>
#include "include/board.h"


int main() {

    char p = 'X', c = 'O';
    char* m = "XOXOOXOO";

    Board b = Board(p,c,m);

    return 0;
}