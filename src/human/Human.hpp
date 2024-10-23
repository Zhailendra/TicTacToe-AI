/*
** PROJECT, 2024
** tic-tac-toe-AI
** File description:
** Human.hpp
*/

#pragma once

#include <iostream>

#include "Player.hpp"

class Human : public Player {
    public:
        explicit Human(char symbol, bool isAi);
        ~Human() override = default;

    protected:
    private:
};
