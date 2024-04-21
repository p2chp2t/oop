#include "GameUi.h"

GameUi::GameUi(QWidget* parent):Qwidget(parent) {
    //initialize GameUi
}

void GameUi::createBlockUis() {
    // Create BlockUi objects and set up layout
}

void GameUi::updateBlockUis() {
    // Update BlockUi objects based on block values
}

void GameUi::handleInput(const Key& key) {
    // Handle user input logic
    emit keyPressed(key);
}
