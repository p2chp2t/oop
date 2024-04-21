#ifndef GAME_H
#define GAME_H

#define ACHIEVE_VAL 2048

#include "Board.h"

class Game {
private:
    Board* board;
    bool gameOver;
    int score;
public:
    Game();
    ~Game();
    void restart();
    void end();
    bool is_over();
    int getScore() const;
};

#endif // GAME_H
