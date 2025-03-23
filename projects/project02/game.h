#pragma once
#include "Board.h"
class Game {
private:
    Board gameBoard;
    int currentPieceType = White;
    int attackRange = 1;
public:
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
    int Play(std::vector<int> moveSet);
    bool ValidAttack();
    int GameStatus();
    std::vector<int> CheckNumOfPieces();
    std::vector<std::vector<int>> GetBoard();
    int GetCurrentPiece();
};