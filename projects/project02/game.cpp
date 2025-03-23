#include "game.h"
Game::Game() {
    gameBoard.SetUpBoard();
}

int Game::Play(std::vector<int> moveSet, bool attack) {
    if (attack == true) {
        gameBoard.ChangePoisition(moveSet, blank);
    }
    else if (attack == false) {
        gameBoard.ChangePoisition(moveSet, currentPieceType);
    }
    int gameState = GameStatus();
    return gameState;
}

int Game::GameStatus() {
    std::vector<int> numOfPieceType{ CheckNumOfPieces() };
    if (numOfPieceType.at(0) == 0) {
        return P1Wins;
    }
    else if (numOfPieceType.at(1) == 0) {
        return P2Wins;
    }
    else {
        return ongoing;
    }
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

bool Game::ValidAttack() {
    std::vector<std::vector<int>> myBoard{ gameBoard.GiveBoard() };
    for (int i = 0; i < myBoard.size(); i++) {
        for (int z = 0; z < myBoard.size(); z++) {
            if (currentPieceType == myBoard.at(i).at(z)) {
                if (i - attackRange >= 0) {
                    if ((blank == myBoard.at(i - attackRange).at(z))) {
                        //not doing anything. 0 catch
                    }
                    else if (currentPieceType != myBoard.at(i - attackRange).at(z)) {
                        return 1;
                    }
                }
                if (i + attackRange < 10) {
                    if (blank == myBoard.at(i + attackRange).at(z)) {
                        //not doing anything. 0 catch
                    }
                    else if (currentPieceType != myBoard.at(i + attackRange).at(z)) {
                        return 1;
                    }
                }
                if (z - attackRange >= 0) {
                    if (blank == myBoard.at(i).at(z - attackRange)) {
                        //not doing anything. 0 catch
                    }
                    else if (currentPieceType != myBoard.at(i).at(z - attackRange)) {
                        return 1;
                    }
                }
                if (z + attackRange < 10) {
                    if (blank == myBoard.at(i).at(z + attackRange)) {
                        //not doing anything. 0 catch
                    }
                    else if (currentPieceType != myBoard.at(i).at(z + attackRange)) {
                        return 1;
                    }
                }
            }
        }
    }
    return false;
}