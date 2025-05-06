#include "Game.h"
#include <cmath>
Game::Game() {
    gameBoard.SetUpBoard();
    gameBoard.PrintBoard();
}

int Game::Play(std::vector<int> moveSet, std::vector<int> selectedMove, bool attack) {
    if (attack == true) {
        gameBoard.ChangePoisition(moveSet, blank);
    }
    else if (attack == false) {
        gameBoard.ChangePoisition(selectedMove, 0);
        gameBoard.ChangePoisition(moveSet, currentPieceType);
    }
    int gameState = GameStatus();
    if (currentPieceType == White) {
        currentPieceType = Black;
    }
    else if (currentPieceType == Black) {
        currentPieceType = White;
    }
    return gameState;
}

int Game::GameStatus() {
    std::vector<int> numOfPieceType{ CheckNumOfPieces() };
    if (numOfPieceType.at(1) == 0) {
        return P1Wins;
    }
    else if (numOfPieceType.at(0) == 0) {
        return P2Wins;
    }
    else {
        return ongoing;
    }
}

void Game::Draw(Engine* e, int selectedRow, int selectedCol) {
    gameBoard.Draw(e, selectedRow, selectedCol);
}

std::vector<int> Game::CheckNumOfPieces() {
    int P1PieceCount = 0;
    int P2PieceCount = 0;
    int temp = 0;
    std::vector<std::vector<int>> myBoard{ gameBoard.GiveBoard() };
    for (std::vector<int> row : myBoard) {
        for (int i : row) {
            if (i == 1) {
                P1PieceCount++;
            }
            else if (i == 2) {
                P2PieceCount++;
            }
        }
        temp++;
    }
    std::vector<int> numOfPieceOutput{ P1PieceCount, P2PieceCount };
    return numOfPieceOutput;
}

int Game::GetCurrentPiece() {
    return currentPieceType;
}

std::vector<std::vector<int>> Game::GetBoard() {
    std::vector<std::vector<int>> tempBoard = gameBoard.GiveBoard();
    return tempBoard;
}

bool Game::ValidAttack(std::vector<int> moveSet, std::vector<int> selectedMove) {
    if ((selectedMove.at(0) == moveSet.at(0)) && (selectedMove.at(1) == moveSet.at(1))) {
        return false;
    }
    int combinedX = std::abs(selectedMove.at(0) - moveSet.at(0));
    int combinedY = std::abs(selectedMove.at(1) - moveSet.at(1));
    if ((attackRange >= (combinedX + combinedY)) && ((GetPieceType(moveSet.at(0), moveSet.at(1)) != currentPieceType) && (GetPieceType(moveSet.at(0), moveSet.at(1)) !=0))) {
        return true;
    }
    return false;
}

bool Game::ValidMove(std::vector<int> moveSet, std::vector<int> selectedMove) {
    if ((selectedMove.at(0) == moveSet.at(0)) && (selectedMove.at(1) == moveSet.at(1))) {
        return false;
    }
    int combinedX = std::abs(selectedMove.at(0) - moveSet.at(0));
    int combinedY = std::abs(selectedMove.at(1) - moveSet.at(1));
    if ((moveRange >= (combinedX + combinedY)) && (GetPieceType(moveSet.at(0), moveSet.at(1))==0)) {
        return true;
    }
    return false;
}

int Game::GetPieceType(int selectedCol, int selectedRow) {
    std::vector<std::vector<int>> myBoard{ gameBoard.GiveBoard() };
    return myBoard.at(selectedRow).at(selectedCol);
}