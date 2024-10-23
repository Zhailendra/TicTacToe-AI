/*
** PROJECT, 2024
** tic-tac-toe-AI
** File description:
** Player.hpp
*/

#pragma once

#include <iostream>

class Player {
    public:
        explicit Player(char symbol, bool isAi);
        virtual ~Player() = default;

        char getOpponentSymbol() const { return _symbol == 'X' ? 'O' : 'X'; }
        char getSymbol() const { return _symbol; }
        bool isAI() const { return _isAI; }

    protected:
        char _symbol;
    private:
        bool _isAI;
};
