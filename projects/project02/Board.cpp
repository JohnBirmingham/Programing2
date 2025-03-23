#include "Board.h"
#include <iostream>
#include <cstdlib>
Board::Board(int size) {
    std::vector<int> row;
    std::vector<std::vector<int>> Board;
    for (int i = 0; i < size; i++) {
        row.push_back(0);
    }
    for (int i = 0; i < size; i++) {
        Board.push_back(row);
    }
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

void Board::PrintBoard(std::vector<std::vector<int>>& myBoard) {
    int i = 0;
    PrintRules();
    std::cout << ' ';
    for (int z = 0; z < myBoard.size(); z++) {
        std::cout << ' ' << z;
    }
    std::cout << '\n';
    for (std::vector<int> row : myBoard) {
        std::cout << i;
        for (int num : row) {
            if (num == 0) {
                std::cout << "| ";
            }
            else if (num == 1) {
                std::cout << "|W";
            }
            else if (num == 2) {
                std::cout << "|B";
            }
        }
        std::cout << "|\n";
        i++;
    }
}

void Board::ChangePoisition(std::vector<int> moveSet, int pieceType) {
    myBoard.at(moveSet.at(1)).at(moveSet.at(2))=pieceType;
}

void Board::ChangeBoard(std::vector<std::vector<int>>& myBoard) {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux and macOS
#endif
    PrintBoard(myBoard);
}