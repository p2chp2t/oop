#include "BlockUi.h"

BlockUi(QWidget* parent = nullptr): QLabel(parent) {
    setFixedSize(250,250); //크기
    setAlignment(QT::AlignCenter);
    setStyleSheet("QLabel { background: rgb(255, 255, 255); color: black; border-style: solid; font: bold 70pt; }");
}

void updateBlock(const Block& block) { //블록의 값에 따라 알맞게 스타일 지정
    int value = block.getVal();
    QString style;
    switch (value) {
    case 2:
        style = "background: rgb(187, 173, 160);";
        break;
    case 4:
        style = "background: rgb(237, 224, 200);";
        break;
    case 8:
        style = "background: rgb(242, 177, 121);";
        break;
    case 16:
        style = "background: rgb(245, 149, 99);";
        break;
    case 32:
        style = "background: rgb(246, 126, 95);";
        break;
    case 64:
        style = "background: rgb(246, 94, 59);";
        break;
    case 128:
        style = "background: rgb(237, 207, 114);";
        break;
    case 256:
        style = "background: rgb(237, 204, 97);";
        break;
    case 512:
        style = "background: rgb(237, 200, 80);";
        break;
    case 1024:
        style = "background: rgb(237, 197, 63);";
        break;
    case 2048:
        style = "background: rgb(237, 194, 46);";
        break;
    default:
        style = "background: rgb(255, 255, 255);";
        break;
    }

    setStyleSheet("QLabel { " + style + " color: black; border-style: solid; font: bold 70pt; }");
    setText(QString::number(value)); // 블록의 값을 텍스트로 설정
}
};

