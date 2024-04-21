#ifndef BLOCK_H
#define BLOCK_H

struct Direction {
    int x; // x축 방향: -1 왼 1 오
    int y; // y축 방향: -1 위 1 아래
};

struct Position {
    int x;
    int y;
};

class Block {
private:
    int value;
    Position pos;
public:
    Block();
    ~Block();
    int getVal() const;
    int getPosX() const;
    int getPosY() const;
    void setVal(int value);
    void setPos(int _x, int _y);
};

#endif // BLOCK_H
