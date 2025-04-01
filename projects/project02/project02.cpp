#include <iostream>
#include <limits>
#include <cmath>
#include "game.h"

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

int menuInput(std::string prompt, int maxValue) {
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
            if ((0 < input) && (input < maxValue+1)) {
                return input;
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Must be one of the options." << std::endl;
            }
        }
    }
}

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

std::vector<int> AttackInput(Game& game) {
    int Xopp;
    int Yopp;
    int Xpos;
    int Ypos;
    int pieceType{ game.GetCurrentPiece() };
    std::vector<int> MovePosition;
    std::vector<std::vector<int>> myBoard{ game.GetBoard() };
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
            break;
        }
        else {
            std::cout << "Invalid attack." << std::endl;
        }
    }
    MovePosition.push_back(Xpos);
    MovePosition.push_back(Ypos);
    return MovePosition;
}

int main() {
    bool attackPossible = false;
    int options;
    bool noMore;
    int gameStatus=ongoing;
    std::vector<int> group;
    Game Games;
    while (true) {
        while (gameStatus == ongoing) {
            attackPossible=Games.ValidAttack();
            if (attackPossible == true) {
                std::cout << "1. Attack" << std::endl;
                std::cout << "2. Move" << std::endl;
                std::cout << "3. End" << std::endl;
                options = menuInput("Chose which numbered option you want to do? ", 3);
                if (options == 1) {
                    group = AttackInput(Games);
                }
                else if (options == 2) {
                    group = MoveInput(Games);
                }
                else {
                    std::cout << "How dare you end this game early." << std::endl;
                    break;
                }
            }
            else {
                std::cout << "1. Move" << std::endl;
                std::cout << "2. End" << std::endl;
                options = menuInput("Chose which numbered option you want to do? ", 2);
                if (options == 1) {
                    group = MoveInput(Games);
                }
                else {
                    std::cout << "How dare you end this game early." << std::endl;
                    break;
                }
            }
            Games.Play(group, attackPossible);
        }
        noMore = YesNoInput("Do you want to play another? ");
        if (noMore == true) {
            std::cout << "Thank you for playing." << std::endl;
            break;
        }
    }
}