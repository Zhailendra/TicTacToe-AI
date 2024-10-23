/*
** PROJECT, 2024
** tic-tac-toe-ai
** File description:
** Game.cpp
*/

#include <limits>
#include "Game.hpp"

Game::Game() {
    _mode = NONE;
    _isRunning = true;
    _restart = false;
    clearBoard();
}

void Game::drawMenu() {
    std::cout << "Welcome to tic-tac-toe-ai" << std::endl;
    std::cout << "1. Player vs Player" << std::endl;
    std::cout << "2. Player vs AI" << std::endl;
    std::cout << "3. AI vs AI" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choose a mode: ";
}

void Game::checkMode() {
    int mode;

    while (true) {
        std::cin >> mode;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << COLOR_RED << "Please, enter a valid mode" << RESET << std::endl;
            drawMenu();
        } else {
            break;
        }
    }

    switch (mode) {
        case 1:
            setMode(PLAYER_VS_PLAYER);
            _player_X = std::make_shared<Human>('X', false);
            _player_O = std::make_shared<Human>('O', false);
            _currentPlayer = _player_X;
            break;
        case 2:
            setMode(PLAYER_VS_AI);
            _player_X = std::make_shared<Human>('X', false);
            _player_O = std::make_shared<AI>('O', true);
            _currentPlayer = _player_X;
            break;
        case 3:
            setMode(AI_VS_AI);
            _player_X = std::make_shared<AI>('X', true);
            _player_O = std::make_shared<AI>('O', true);
            break;
        case 4:
            setMode(EXIT);
            setRunning(false);
            return;
        default:
            std::cout << "Invalid mode" << std::endl;
            break;
    }

    _currentPlayer = _player_X;
    std::cout << COLOR_YELLOW << "You chose: " << getModeString() << RESET << std::endl;
}

void Game::drawGame() {
    std::cout << "-------------" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << _board[i][j] << " | ";
        }
        std::cout << "\n-------------" << std::endl;
    }
}

void Game::waitForTurn() {
    int x, y;

    if (_currentPlayer->isAI()) {
        std::cout << COLOR_MAGENTA << "AI is thinking..." << RESET << std::endl;
        std::dynamic_pointer_cast<AI>(_currentPlayer)->findBestMove(_board);
    } else {
        while (true) {
            std::cout << "Player " << _currentPlayer->getSymbol() << ", enter x and y coordinates (0-2): ";
            std::cin >> x >> y;

            if (std::cin.fail() || x < 0 || x > 2 || y < 0 || y > 2 || _board[y][x] != ' ') {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter valid coordinates for an empty spot (0-2)." << std::endl;
            } else {
                break;
            }
        }
        _board[y][x] = _currentPlayer->getSymbol();
    }

    if (_currentPlayer == _player_X) {
        _currentPlayer = _player_O;
    } else {
        _currentPlayer = _player_X;
    }
}

void Game::checkWin() {
    for (int i = 0; i < 3; i++) {
        if (_board[i][0] == _board[i][1] && _board[i][1] == _board[i][2] && _board[i][0] != ' ') {
            std::cout << "Player " << findPlayer(_board[i][0]) << _board[i][0] << RESET << " wins!" << std::endl;
            setRestart(true);
        }
        if (_board[0][i] == _board[1][i] && _board[1][i] == _board[2][i] && _board[0][i] != ' ') {
            std::cout << "Player " << findPlayer(_board[0][i]) << _board[0][i] << RESET << " wins!" << std::endl;
            setRestart(true);
        }
    }

    if (_board[0][0] == _board[1][1] && _board[1][1] == _board[2][2] && _board[0][0] != ' ') {
        std::cout << "Player " << findPlayer(_board[0][0]) << _board[0][0] << RESET << " wins!" << std::endl;
        setRestart(true);
    }

    if (_board[0][2] == _board[1][1] && _board[1][1] == _board[2][0] && _board[0][2] != ' ') {
        std::cout << "Player " << findPlayer(_board[0][2]) << _board[0][2] << RESET << " wins!" << std::endl;
        setRestart(true);
    }

    if (AI::isTie(_board)) {
        std::cout << COLOR_YELLOW << "It's a tie!" << RESET << std::endl;
        setRestart(true);
    }
}

void Game::checkRestart() {
    if (_restart) {
        std::cout << COLOR_BLUE;
        drawGame();
        char restart;

        std::cout << COLOR_GREEN << "Do you want to play again? (y/n): " << RESET;
        std::cin >> restart;

        if (restart == 'y') {
            _isRunning = true;
            _mode = NONE;
            _currentPlayer = _player_X;
            _restart = false;

            clearBoard();
        } else {
            _isRunning = false;
        }
    }
}

void Game::clearBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _board[i][j] = ' ';
        }
    }
}

std::string Game::findPlayer(char symbol) {
    std::string color = RESET;

    switch (symbol) {
        case 'X':
            color = COLOR_CYAN;
            break;
        case 'O':
            color = COLOR_ORANGE;
            break;
        default:
            break;
    }
    return color;
}

