#ifndef BOT_H
#define BOT_H


class Bot {

    private:
        char* nickname;

    public:
        Bot();
        Bot(char*);
        ~Bot();
        int next_move(char*, int, char, char);

};


#endif