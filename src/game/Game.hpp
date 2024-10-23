/*
** PROJECT, 2024
** tic-tac-toe-ai
** File description:
** Game.hpp
*/

#pragma once

#include <iostream>
#include <map>
#include <array>
#include <memory>

#include "Human.hpp"
#include "AI.hpp"

#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_GREEN "\033[32m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_ORANGE "\033[38;5;208m"

#define RESET "\033[0m"

enum Mode {
    PLAYER_VS_PLAYER,
    PLAYER_VS_AI,
    AI_VS_AI,
    EXIT,
    NONE
};

static const std::map<Mode, std::string> modeToString = {
        {PLAYER_VS_PLAYER, "Player vs Player"},
        {PLAYER_VS_AI, "Player vs AI"},
        {AI_VS_AI, "AI vs AI"},
        {EXIT, "Exit"}
};

class Game {
    public:
        explicit Game();
        ~Game() = default;

        void drawMenu();
        void drawGame();

        void checkMode();
        void waitForTurn();
        void checkWin();
        void checkRestart();

        static std::string findPlayer(char symbol);

        void clearBoard();

        void setMode(Mode mode) { _mode = mode; }
        void setRunning(bool running) { _isRunning = running; }
        void setRestart(bool restart) { _restart = restart; }

        Mode getMode() const { return _mode; }
        std::string getModeString() const { return modeToString.at(_mode); }
        bool isRunning() const { return _isRunning; }

    protected:
        bool _isRunning;
    private:
        Mode _mode;
        std::shared_ptr<Player> _player_X;
        std::shared_ptr<Player> _player_O;
        std::shared_ptr<Player> _currentPlayer;
        std::array<std::array<char, 3>, 3> _board{};
        bool _restart;
};
