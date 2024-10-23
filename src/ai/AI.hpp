/*
** PROJECT, 2024
** tic-tac-toe-AI
** File description:
** AI.hpp
*/

#pragma once

#include <iostream>
#include <array>

#include "Player.hpp"

struct Move {
    int row;
    int col;
};

class AI : public Player {
    public:
        explicit AI(char symbol, bool isAi);
        ~AI() override = default;

        void findBestMove(std::array<std::array<char, 3>, 3>& board);
        int miniMax(std::array<std::array<char, 3>, 3>& board, int depth, bool isMax);
        int evaluateBoard(const std::array<std::array<char, 3>, 3>& board);

        static bool isTie(const std::array<std::array<char, 3>, 3>& board);

    protected:
    private:
};
