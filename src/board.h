#ifndef BOARD_H
#define BOARD_H


class Board {

    private:
        char player;
        int player_last_move;
        char computer;
        char* moves;

    public:
        Board(char, char, char*);
        ~Board();
        void draw();
        void place();
        void bot_place(int);
        bool won(char*);
        bool tie();
        char* get_moves();
        int get_player_last_move();
};

#endif