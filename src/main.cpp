/*
** PROJECT, 2024
** tic-tac-toe-ai
** File description:
** main.cpp
*/

#include "Game.hpp"

int main() {

    Game game;

    while (game.isRunning()) {
        if (game.getMode() == NONE) {
            game.drawMenu();
            game.checkMode();
        } else {
            game.drawGame();
            game.waitForTurn();
            game.checkWin();
            game.checkRestart();
        }
    }

    return 0;
}
