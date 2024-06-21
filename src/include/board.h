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
        void move();
        void draw();

};



#endif