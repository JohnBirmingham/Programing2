#include "Board.h"
#include <iostream>
#include <cstdlib>
Board::Board(int size) {
    std::vector<int> row(size, 0);
    myBoard = std::vector<std::vector<int>>(size, row);
    SetUpBoard();
}

std::vector<std::vector<int>> Board::GiveBoard() {
    return myBoard;
}

void PrintRules() {
    std::cout << "Each Piece can move 2 spaces in this board." << std::endl;
    std::cout << "Each Piece can attack directly next to them" << std::endl;
    std::cout << "You either move or attack with a piece." << std::endl;
    std::cout << "Play starts with W and you go from there." << std::endl;
    std::cout << "You win when you are the last one standing." << std::endl;
}

void Board::SetUpBoard() {
    /*myBoard.at(8).at(6)=2;
    myBoard.at(8).at(8)=2;
    myBoard.at(9).at(8)=1;
    myBoard.at(5).at(8)=1;
    myBoard.at(4).at(8)=2;
    myBoard.at(6).at(2)=1;
    myBoard.at(6).at(3)=2;*/
    for (int i = 4; i < myBoard.size() - 4; i++) {
        myBoard.at(0).at(i) = 2;
    }
    for (int i = 4; i < myBoard.size() - 4; i++) {
        myBoard.at(1).at(i) = 2;
    }
    for (int i = 4; i < myBoard.size() - 4; i++) {
        myBoard.at(myBoard.size() - 2).at(i) = 1;
    }
    for (int i = 4; i < myBoard.size() - 4; i++) {
        myBoard.at(myBoard.size() - 1).at(i) = 1;
    }
}

void Board::PrintBoard() {
    int i = 0;
    PrintRules();
}

void Board::ChangePoisition(std::vector<int> moveSet, int pieceType) {
    myBoard.at(moveSet.at(1)).at(moveSet.at(0)) = pieceType;
}
void Board::Draw(Engine* e, int selectedRow, int selectedCol)
{
    int tokenRadius = 30;
    int sx = 50 + 100 * selectedCol;
    int sy = 50 + 100 * selectedRow;
    
    for (int row = 0; row < myBoard.size(); ++row) {
        for (int col = 0; col < myBoard.size(); ++col) {
            int cx = 50 + 100 * col;
            int cy = 50 + 100 * row;
            e->drawRectangle(cx, cy, 90, 90, { 100,60,200,255 });
            if (myBoard[row][col] != 0)
                e->drawCircle(cx + 5, cy + 5, tokenRadius, { 0,0,0,64 });
            if (myBoard[row][col] == 1)
                e->drawCircle(cx, cy, tokenRadius, { 255,255,255,255 });
            else if (myBoard[row][col] == 2)
                e->drawCircle(cx, cy, tokenRadius, { 0,0,0,255 });
            e->drawRectangle(sx, sy, 90, 90, { 0,255,0,25 });
        }
    }
}