#ifndef GAMEUI_H
#define GAMEUI_H

#include <QWidget>
#include "BlockUi.h"

class GameUi: public QWidget {
    Q_OBJECT

private:
    BlockUi blockUis[4][4];
public:
    GameUi(QWidget* parent = nullptr);
    void createBlockUis();
    void updateBlockUis();
    void handleInput(const Key& key);
signals:
    void keyPressed(const Key& key);
};

#endif // GAMEUI_H
