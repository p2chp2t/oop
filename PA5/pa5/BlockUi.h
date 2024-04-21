#ifndef BLOCKUI_H
#define BLOCKUI_H

#include <QLabel>
#include "Block.h"

class BlockUi: public QLabel {
    Q_OBJECT
public:
    BlockUi(QWidget* parent = nullptr) : Qlabel(parent) {}
    void updateBlock(Block& block);

#endif // BLOCKUI_H
