#include "Block.h"

Block::Block() {
    value = 0;
}

int Block::getVal() const {
    return value;
}

int Block::getPosX() const {
    return pos.x;
}

int Block::getPosY() const {
    return pos.y;
}

void Block::setVal(int _value) {
    this->value=_value;
}

void Block::setPos(int _x, int _y) {
    this->pos.x=_x;
    this->pos.y=_y;
}
