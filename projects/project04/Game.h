#pragma once
#include "Board.h"
    
class Game {
private:
    Board gameBoard = Board(10);
    int currentPieceType = White;
    int attackRange = 1;
    int moveRange = 2;
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
    void Draw(Engine* e, int selectedRow, int selectedCol);
    int Play(std::vector<int> moveSet, std::vector<int> selectedMove, bool attack);
    bool ValidAttack(std::vector<int> moveSet, std::vector<int> selectedMove);
    bool ValidMove(std::vector<int> moveSet, std::vector<int> selectedMove);
    int GameStatus();
    std::vector<int> CheckNumOfPieces();
    std::vector<std::vector<int>> GetBoard();
    int GetCurrentPiece();
    int GetPieceType(int selectedCol, int selectedRow);
};