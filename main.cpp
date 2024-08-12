#ifdef __unix__
#elif defined(_WIN32) || defined(WIN32)
#define OS_Windows
#endif

#include <iostream>
#include <cstdlib>
#include "src/board.h"
#include "src/bot.h"


int main() {

    bool turn = true;
    char p,c,m[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}, bot_nickname[] = "Tristan";

    std::cout << "--------------------\n" << "  Tic-Tac-Toe Game\n" << "--------------------\n";

    do {
        std::cout << "Choose what you want (X or O): ";
        std::cin >> p;
        std::cout << '\n';
    } while(p!='X' && p!='O');

    c = (p == 'X') ? 'O' : 'X';

    Board board = Board(p,c,m);
    Bot bot = Bot(bot_nickname);

    board.draw();
    while(!board.won(bot_nickname) && !board.tie()) {
        if(turn) {
            board.place(); 
            turn=false;
        } else {
            int pos = bot.next_move(board.get_moves(), board.get_player_last_move(),c,p);
            board.bot_place(pos);
            turn=true;
        }

        #ifdef OS_Windows
            system("cls");
        #else
            system("clear");
        #endif

        board.draw();
    }

    if(board.tie()) std::cout << "\nTie!\n";

    #ifdef OS_Windows
        system("pause");
    #else
        system("read -n1 -r -p 'Press any key to continue...' key");
    #endif

    return 0;
}