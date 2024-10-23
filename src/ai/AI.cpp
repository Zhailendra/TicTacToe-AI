/*
** PROJECT, 2024
** tic-tac-toe-AI
** File description:
** AI.cpp
*/

#include "AI.hpp"

AI::AI(char symbol, bool isAi) : Player(symbol, isAi) {

}

void AI::findBestMove(std::array<std::array<char, 3>, 3> &board) {
    int bestVal = -1000;
    Move bestMove = {-1, -1};

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[x][y] == ' ') {
                board[x][y] = _symbol;
                int moveVal = miniMax(board, 0, false);
                board[x][y] = ' ';

                if (moveVal > bestVal) {
                    bestMove.row = x;
                    bestMove.col = y;
                    bestVal = moveVal;
                }
            }
        }
    }

    //std::cout << "BEST MOVE: " << bestMove.col << ' ' << bestMove.row << std::endl;
    board[bestMove.row][bestMove.col] = _symbol;
}

int AI::miniMax(std::array<std::array<char, 3>, 3> &board, int depth, bool isMax) {
    int score = evaluateBoard(board);

    if (score == 10) {
        return score;
    }
    if (score == -10) {
        return score;
    }

    if (isTie(board)) {
        return 0;
    }

    if (isMax) {
        int best = -1000;

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (board[x][y] == ' ') {
                    board[x][y] = _symbol;
                    best = std::max(best, miniMax(board, depth + 1, !isMax));
                    board[x][y] = ' ';
                }
            }
        }

        return best;
    } else {
        int best = 1000;

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (board[x][y] == ' ') {
                    board[x][y] = getOpponentSymbol();
                    best = std::min(best, miniMax(board, depth + 1, !isMax));
                    board[x][y] = ' ';
                }
            }
        }

        return best;
    }
}

int AI::evaluateBoard(const std::array<std::array<char, 3>, 3> &board) {
    for (int x = 0; x < 3; x++) {
        if (board[x][0] == board[x][1] && board[x][1] == board[x][2]) {
            if (board[x][0] == _symbol)
                return 10;
            else if (board[x][0] == getOpponentSymbol())
                return -10;
        }
    }

    for (int y = 0; y < 3; y++) {
        if (board[0][y] == board[1][y] && board[1][y] == board[2][y]) {
            if (board[0][y] == _symbol)
                return 10;
            else if (board[0][y] == getOpponentSymbol())
                return -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == _symbol)
            return 10;
        else if (board[0][0] == getOpponentSymbol())
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == _symbol)
            return 10;
        else if (board[0][2] == getOpponentSymbol())
            return -10;
    }

    return 0;
}

bool AI::isTie(const std::array<std::array<char, 3>, 3> &board) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[x][y] == ' ')
                return false;
        }
    }
    return true;
}
