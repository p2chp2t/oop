#ifndef BOARD_H
#define BOARD_H

#include "Block.h"

class Board {
private:
    Block blocks[4][4];
public:
    Board();
    ~Board();
    void init();
    void placeBlock(Block& block, const Position& position);
    void move(const Direction& direction);
    void merge(const Direction& direction);
    bool game_over();
private:
    void moveBlock(Block& block, const Direction& direction);
};

#endif // BOARD_H
