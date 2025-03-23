#include <iostream>
#include <limits>
#include <cmath>
#include "game.h"
/*
    Make sure that the main includes;
    std::vector<int> for new space move;
    std::vector<games> listOfGames;
    while{
    while(game==ongoing){
    Valid Attack Check;
    Ask if player wants to attack;
    If player doesn't want to attack then{
    ask for Move Input;
    Set a tracker to move;
    }
    If player ask to attack{
    ask for Attack Input;
    Set a tracker to attack;
    }
    If player is want to quit because he is sad{
    break and shame the player who quit.
    }
    }
    ask if they want to play another game;
    if no{
    break;
    }
    if yes{
    listOfGames.push_back;
    }
    }
*/
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

int attackRange = 1;

int BoardInput(std::string prompt) {
    int input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
        }
        else if (std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Too many inputs. Please only use one input" << std::endl;
        }
        else {
            if ((-1 < input) && (input < 10)) {
                return input;
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "That move is not in the board" << std::endl;
            }
        }
    }
}
std::vector<int> MoveInput(Game& game) {
    int newX;
    int newY;
    int prevX;
    int prevY;
    int pieceType{ game.GetCurrentPiece() };
    std::vector<int> MovePosition;
    std::vector<std::vector<int>> myBoard{ game.GetBoard() };
    while (true) {
        prevX = BoardInput("Enter the X cordinate you are coming from: ");
        prevY = BoardInput("Enter the Y cordinate you are coming from: ");
        newX = BoardInput("Enter the X cordinate you are going to: ");
        newY = BoardInput("Enter the Y cordinate you are going to: ");
        //checks to make sure move is valid
        if ((pieceType != myBoard.at(prevY).at(prevX))) {
            std::cout << "Not moving the right piece." << std::endl;
        }
        else if ((2 >= (abs(prevX - newX) + abs(prevY - newY))) && (myBoard.at(newY).at(newX) == blank)) {
            myBoard.at(newY).at(newX) = myBoard.at(prevY).at(prevX);
            myBoard.at(prevY).at(prevX) = 0;
            break;
        }
        else {
            std::cout << "Invalid move." << std::endl;
        }
    }
    MovePosition.push_back(newX);
    MovePosition.push_back(newY);
    return MovePosition;
} //similar to old move Function but only is an considered input now.

bool YesNoInput(std::string prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter yes, y, no, or n.\n";
        }
        else if (std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Too many inputs. Please only use one input" << std::endl;
        }
        else {
            if (("yes" == input) || ("y" == input)) {
                return true;
            }
            else if (("no" == input) || ("n" == input)) {
                return false;
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid Input" << std::endl;
            }
        }
    }
}

void AttackInput(Game& game) {
    int Xopp;
    int Yopp;
    int Xpos;
    int Ypos;
    int pieceType{ game.GetCurrentPiece() };
    std::vector<int> MovePosition;
    std::vector<std::vector<int>>& myBoard{ game.GetBoard() };
    while (true) {
        Xpos = BoardInput("Enter the X cordinate you are attacking from: ");
        Ypos = BoardInput("Enter the Y cordinate you are attacking from: ");
        Xopp = BoardInput("Enter the X cordinate you are going to attack: ");
        Yopp = BoardInput("Enter the Y cordinate you are going to attack: ");
        //checks to make sure move is valid
        if (pieceType == myBoard.at(Yopp).at(Xopp)) {
            std::cout << "Not attacking the right piece." << std::endl;
        }
        else if (myBoard.at(Yopp).at(Xopp) == blank) {
            std::cout << "Not a valid enemy" << std::endl;
        }
        else if ((attackRange >= (abs(Xopp - Xpos) + abs(Yopp - Ypos)))) {
            myBoard.at(Yopp).at(Xopp) = blank;
            break;
        }
        else {
            std::cout << "Invalid attack." << std::endl;
        }
    }
}

int main() {
    bool noMore;
    while (true) {
        Play();
        noMore = YesNoInput("Do you want to continue? ");
        if (noMore == true) {
            std::cout << "Thank you for playing." << std::endl;
            break;
        }
    }
}