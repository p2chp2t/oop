#include "Board.h"

Board::Board() {
    init();
}

void Board::init() {
    for(int i=0;i<4;i++) { //모든 block의 value를 0으로 초기화
        for(int j=0;j<4;j++) {
            blocks[i][j].setVal(0);
        }
    }
}

void Board::placeBlock(Block& block, const Position& position) {
    int x = position.x;
    int y = position.y;
    if (x<0 || x>=4 || y<0 || y>=4 || blocks[x][y].getVal()!=0) {
        return;
    }
    blocks[x][y].setVal(block.getVal()); //board의 블럭판에 넣어주기
    block.setVal(0); //다시 초기화해주기
}

void Board::move(const Direction& direction) {
    //모든 block에 moveBlock 실행
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            moveBlock(blocks[i][j], direction);
        }
    }
}

void Board::merge(const Direction& direction) {
    //merge logic for all blocks
    int startX, startY; //병합 시작 위치
    int endX, endY; //병합 종료 위치
    int stepX, stepY; //이동 단계

    if (direction.x == 1) { //오른쪽 이동
        startX = 0;
        endX = 4;
        stepX = 1;
        startY = 0;
        endY = 4;
        stepY = 1;
    } else if (direction.x == -1) { //왼쪽 이동
        startX = 3;
        endX = -1;
        stepX = -1;
        startY = 0;
        endY = 4;
        stepY = 1;
    } else if (direction.y == 1) { //아래쪽 이동
        startX = 0;
        endX = 4;
        stepX = 1;
        startY = 0;
        endY = 4;
        stepY = 1;
    } else if (direction.y == -1) { //위쪽 이동
        startX = 0;
        endX = 4;
        stepX = 1;
        startY = 3;
        endY = -1;
        stepY = -1;
    } else { // 잘못된 방향
        return;
    }
    //블럭 병합
    for (int x = startX; x != endX; x += stepX) {
        for (int y = startY; y != endY; y += stepY) {
            int value = blocks[x][y].getVal();
            if (value == 0) { //빈 공간인 경우
                continue;
            }
            int nextX = x + direction.x;
            int nextY = y + direction.y;
            if (nextX < 0 || nextX >= 4 || nextY < 0 || nextY >= 4) { //범위를 벗어난 경우
                continue;
            }
            int nextValue = blocks[nextX][nextY].getVal(); //이동할 위치가 비어있으면 값 옮기기
            if (nextValue == 0) {
                blocks[nextX][nextY].setVal(value);
                blocks[x][y].setVal(0);
            } else if (nextValue == value) { //이동할 위치의 블록과 값이 같으면 병합
                int mergeVal = value * 2;
                blocks[nextX][nextY].setVal(mergeVal);
                blocks[x][y].setVal(0);
            } else {
                continue;
            }
        }
    }
}

bool Board::game_over() {
    //check game over logic
}

void Board::moveBlock(Block& block, const Direction& direction) {
    //block의 현재 위치 및 value 기록
    int x = block.getPosX();
    int y = block.getPosY();
    int value = block.getVal();
    //direction에 따라 이동했을 때의 좌표 기록
    int newX = x + direction.x;
    int newY = y + direction.y;
    //유효한 좌표 이동인지 확인
    if (newX < 0 || newX >= 4 || newY < 0 || newY >= 4 || blocks[newX][newY].getVal() != 0) {
        return;
    }
    //유효한 좌표일 때 이동시키고 값 세팅
    blocks[newX][newY].setVal(value);
    blocks[x][y].setVal(0);
    block.setPos(newX, newY);
}
