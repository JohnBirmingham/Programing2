#pragma once
#include "Board.h"
class Game {
private:
    Board gameBoard=Board(10);
    int currentPieceType = White;
    int attackRange = 1;
public:
    Game();
    enum gameState {
        ongoing,
        P1Wins,
        P2Wins
    };
    enum piece {
        blank,
        White,
        Black
    };
    int Play(std::vector<int> moveSet, bool attack);
    bool ValidAttack();
    int GameStatus();
    std::vector<int> CheckNumOfPieces();
    std::vector<std::vector<int>> GetBoard();
    int GetCurrentPiece();
};