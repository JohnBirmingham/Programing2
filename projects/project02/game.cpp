#include "game.h"

gameBoard.SetUpBoard(myBoard);
gameBoard.PrintBoard(myBoard);
int Game::Play(std::vector<int> moveSet, bool attack) {
    
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
    for (std::vector<int> row : gameBoard) {
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
    for (int i = 0; i < gameBoard.size(); i++) {
        for (int z = 0; z < gameBoard.size(); z++) {
            if (currentPieceType == gameBoard.at(i).at(z)) {
                if (i - attackRange >= 0) {
                    if ((blank == gameBoard.at(i - attackRange).at(z))) {
                        //not doing anything. 0 catch
                    }
                    else if (currentPieceType != gameBoard.at(i - attackRange).at(z)) {
                        return 1;
                    }
                }
                if (i + attackRange < 10) {
                    if (blank == gameBoard.at(i + attackRange).at(z)) {
                        //not doing anything. 0 catch
                    }
                    else if (currentPieceType != gameBoard.at(i + attackRange).at(z)) {
                        return 1;
                    }
                }
                if (z - attackRange >= 0) {
                    if (blank == gameBoard.at(i).at(z - attackRange)) {
                        //not doing anything. 0 catch
                    }
                    else if (currentPieceType != gameBoard.at(i).at(z - attackRange)) {
                        return 1;
                    }
                }
                if (z + attackRange < 10) {
                    if (blank == gameBoard.at(i).at(z + attackRange)) {
                        //not doing anything. 0 catch
                    }
                    else if (currentPieceType != gameBoard.at(i).at(z + attackRange)) {
                        return 1;
                    }
                }
            }
        }
    }
    return false;
}