#include <cstdlib>
#include <cstring>
#include "bot.h"


Bot::Bot() {
    
}

Bot::Bot(char* nickname_s) {
    nickname = new char[strlen(nickname_s)+1];
    if(nickname) strcpy(nickname,nickname_s);
}

Bot::~Bot() {
    delete[] nickname;
}

int Bot::next_move(char* moves, int player_last_move, char computer_symbol, char player_symbol) {

    if(moves[0] == computer_symbol && moves[1] == computer_symbol && moves[2]==' ') return 2;
    else if (moves[3] == computer_symbol && moves[4] == computer_symbol && moves[2]==' ') return 5;
    else if (moves[6] == computer_symbol && moves[7] == computer_symbol && moves[8]==' ') return 8;
    else if (moves[1] == computer_symbol && moves[2] == computer_symbol && moves[0]==' ') return 0;
    else if (moves[4] == computer_symbol && moves[5] == computer_symbol && moves[3]==' ') return 3;
    else if (moves[7] == computer_symbol && moves[8] == computer_symbol && moves[6]==' ') return 6;
    else if (moves[0] == computer_symbol && moves[3] == computer_symbol && moves[6]==' ') return 6;
    else if (moves[1] == computer_symbol && moves[4] == computer_symbol && moves[7]==' ') return 7;
    else if (moves[2] == computer_symbol && moves[5] == computer_symbol && moves[8]==' ') return 8;
    else if (moves[3] == computer_symbol && moves[6] == computer_symbol && moves[0]==' ') return 0;
    else if (moves[4] == computer_symbol && moves[7] == computer_symbol && moves[1]==' ') return 1;
    else if (moves[5] == computer_symbol && moves[8] == computer_symbol && moves[2]==' ') return 2;
    else if (moves[4] == computer_symbol && moves[6] == computer_symbol && moves[2]==' ') return 2;
    else if (moves[2] == computer_symbol && moves[4] == computer_symbol && moves[6]==' ') return 6;
    else if (moves[2] == computer_symbol && moves[6] == computer_symbol && moves[4]==' ') return 4;
    else if (moves[0] == computer_symbol && moves[2] == computer_symbol && moves[1]==' ') return 1;
    else if (moves[3] == computer_symbol && moves[5] == computer_symbol && moves[4]==' ') return 4;
    else if (moves[6] == computer_symbol && moves[8] == computer_symbol && moves[7]==' ') return 7;
    else if (moves[0] == computer_symbol && moves[6] == computer_symbol && moves[3]==' ') return 3;
    else if (moves[1] == computer_symbol && moves[7] == computer_symbol && moves[4]==' ') return 4;
    else if (moves[2] == computer_symbol && moves[8] == computer_symbol && moves[5]==' ') return 5;
    else if (moves[0] == computer_symbol && moves[4] == computer_symbol && moves[8]==' ') return 8;
    else if (moves[8] == computer_symbol && moves[4] == computer_symbol && moves[0]==' ') return 0;
    else if (moves[0] == computer_symbol && moves[8] == computer_symbol && moves[4]==' ') return 4;
    else {
        if(moves[0] == player_symbol && moves[1] == player_symbol && moves[2]==' ') return 2;
        else if (moves[3] == player_symbol && moves[4] == player_symbol && moves[5]==' ') return 5;
        else if (moves[6] == player_symbol && moves[7] == player_symbol && moves[8]==' ') return 8;
        else if (moves[1] == player_symbol && moves[2] == player_symbol && moves[0]==' ') return 0;
        else if (moves[4] == player_symbol && moves[5] == player_symbol && moves[3]==' ') return 3;
        else if (moves[7] == player_symbol && moves[8] == player_symbol && moves[6]==' ') return 6;
        else if (moves[0] == player_symbol && moves[3] == player_symbol && moves[6]==' ') return 6;
        else if (moves[1] == player_symbol && moves[4] == player_symbol && moves[7]==' ') return 7;
        else if (moves[2] == player_symbol && moves[5] == player_symbol && moves[8]==' ') return 8;
        else if (moves[3] == player_symbol && moves[6] == player_symbol && moves[0]==' ') return 0;
        else if (moves[4] == player_symbol && moves[7] == player_symbol && moves[1]==' ') return 1;
        else if (moves[5] == player_symbol && moves[8] == player_symbol && moves[2]==' ') return 2;
        else if (moves[4] == player_symbol && moves[6] == player_symbol && moves[2]==' ') return 2;
        else if (moves[2] == player_symbol && moves[4] == player_symbol && moves[6]==' ') return 6;
        else if (moves[2] == player_symbol && moves[6] == player_symbol && moves[4]==' ') return 4;
        else if (moves[0] == player_symbol && moves[2] == player_symbol && moves[1]==' ') return 1;
        else if (moves[3] == player_symbol && moves[5] == player_symbol && moves[4]==' ') return 4;
        else if (moves[6] == player_symbol && moves[8] == player_symbol && moves[7]==' ') return 7;
        else if (moves[0] == player_symbol && moves[6] == player_symbol && moves[3]==' ') return 3;
        else if (moves[1] == player_symbol && moves[7] == player_symbol && moves[4]==' ') return 4;
        else if (moves[2] == player_symbol && moves[8] == player_symbol && moves[5]==' ') return 5;
        else if (moves[0] == player_symbol && moves[4] == player_symbol && moves[8]==' ') return 8;
        else if (moves[8] == player_symbol && moves[4] == player_symbol && moves[0]==' ') return 0;
        else if (moves[0] == player_symbol && moves[8] == player_symbol && moves[4]==' ') return 4;
        else { // first available move - while top find first ' ' result
            int i=0;
            while(moves[i]!=' ') i++;
            return i;
        } 
    }
    
}

