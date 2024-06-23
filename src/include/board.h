#ifndef BOARD_H
#define BOARD_H


class Board {

    private:
        char player;
        char computer;
        char* moves;

    public:
        Board(char, char, char*);
        ~Board();
        void draw();
        void place();
        void computer_place();
        bool won();
        bool tie();
};

#endif