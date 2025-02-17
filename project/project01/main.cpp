#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cmath>
enum gameState{
    ongoing,
    P1Wins,
    P2Wins
};
enum piece{
    blank,
    White,
    Black
};
int linesAfterBoard=0;
int BoardInput(std::string prompt);
std::vector<std::vector<int>> MakeBoard(int size);
void SetUpBoard(std::vector<std::vector<int>> &myBoard);
void PrintRules();
void PrintBoard(std::vector<std::vector<int>> &myBoard);
void ChangeBoard(std::vector<std::vector<int>> &myBoard);
std::vector<int> CheckNumOfPieces(std::vector<std::vector<int>> &myBoard);
int GameStatus(std::vector<std::vector<int>> &myBoard);
void Move(std::vector<std::vector<int>> &myBoard, int pieceType);
//bool ValidAttack(std::vector<std::vector<int>> &myBoard, int pieceType){}
void Attack(std::vector<std::vector<int>> &myBoard, int pieceType);

void Play(std::vector<std::vector<int>> &myBoard){
    int gameState=ongoing;
    bool attacking=false;
    int pieceType=White;
    while(gameState==ongoing){
        if(attacking==false){
            Move(myBoard,pieceType);
        }
        else{
            Attack(myBoard, pieceType);
        }
        ChangeBoard(myBoard);
        if(pieceType==White){
            pieceType=Black;
        } else if(pieceType==Black){
            pieceType=White;
        }
        gameState=GameStatus(myBoard);
    }
}

int main(){
    std::vector<std::vector<int>> myBoard = MakeBoard(10);
    SetUpBoard(myBoard);
    PrintBoard(myBoard);
    Play(myBoard);
}

int BoardInput(std::string prompt){
    int input;
	while (true) {
        linesAfterBoard++;
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.fail()) {
            linesAfterBoard++;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter an integer.\n";
		} else if(std::cin.peek() != '\n'){
            linesAfterBoard++;
            std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Too many inputs. Please only use one input" << std::endl;
        } else {
            if((-1<input)&&(input<10)){
                return input;
            } else {
                linesAfterBoard++;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "That move is not in the board" << std::endl;
            }
		}
	}
}

std::vector<std::vector<int>> MakeBoard(int size){
    std::vector<int> row;
    std::vector<std::vector<int>> Board;
    for(int i = 0; i < size; i++){
        row.push_back(0);
    }
    for(int i = 0; i < size; i++){
        Board.push_back(row);
    }
    return Board;
}

void PrintRules(){
    std::cout << "Each Piece can move 2 spaces in this board." << std::endl;
    std::cout << "Each Piece can attack directly next to them" << std::endl;
    std::cout << "You either move or attack with a piece." << std::endl;
    std::cout << "Play starts with W and you go from there." << std::endl;
    std::cout << "You win when you are the last one standing." << std::endl;
}

void SetUpBoard(std::vector<std::vector<int>> &myBoard){
    for(int i = 4; i < myBoard.size()-4; i++){
        myBoard.at(0).at(i)=Black;
    }
    for(int i = 4; i < myBoard.size()-4; i++){
        myBoard.at(1).at(i)=Black;
    }
    for(int i = 4; i < myBoard.size()-4; i++){
        myBoard.at(myBoard.size()-2).at(i)=White;
    }
    for(int i = 4; i < myBoard.size()-4; i++){
        myBoard.at(myBoard.size()-1).at(i)=White;
    }
}

void PrintBoard(std::vector<std::vector<int>> &myBoard){
    int i = 0;
    PrintRules();
    std::cout << ' ';
    for(int z = 0; z < myBoard.size(); z++){
        std::cout << ' ' << z;
    }
    std::cout << '\n';
    for(std::vector<int> row : myBoard){
        std::cout << i;
        for(int num : row){
            if(num==0){
                std::cout << "| ";
            } else if(num==1){
                std::cout << "|W";
            } else if(num==2){
                std::cout << "|B";
            }
        }
        std::cout << "|\n";
        i++;
    }
}

void ChangeBoard(std::vector<std::vector<int>> &myBoard){
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Linux and macOS
    #endif
    PrintBoard(myBoard);
}

std::vector<int> CheckNumOfPieces(std::vector<std::vector<int>> &myBoard){
    int P1PieceCount=0;
    int P2PieceCount=0;
    int temp=0;
    for(std::vector<int> row : myBoard){
        for(int i : row){
            if(i==1){
                P1PieceCount++;
            } else if(i == 2){
                P2PieceCount++;
            }
        }
        temp++;
    }
    std::vector<int> numOfPieceOutput{P1PieceCount, P2PieceCount};
    return numOfPieceOutput;
}

int GameStatus(std::vector<std::vector<int>> &myBoard){
    std::vector<int> numOfPieceType{CheckNumOfPieces(myBoard)};
    if(numOfPieceType.at(0) == 0){
        return P1Wins;
    } else if(numOfPieceType.at(1) == 0){
        return P2Wins;
    } else {
        return ongoing;
    }
}

void Move(std::vector<std::vector<int>> &myBoard, int pieceType){
    int newX;
    int newY;
    int prevX;
    int prevY;
    while(true){
        prevX = BoardInput("Enter the X cordinate you are coming from: ");
        prevY = BoardInput("Enter the Y cordinate you are coming from: ");
        newX = BoardInput("Enter the X cordinate you are going to: ");
        newY = BoardInput("Enter the Y cordinate you are going to: ");
        //checks to make sure move is valid
        if((pieceType!=myBoard.at(prevY).at(prevX))){
            linesAfterBoard++;
            std::cout << "Not moving the right piece." << std::endl;
        } else if((2>=(abs(prevX-newX)+abs(prevY-newY)))&&(myBoard.at(newY).at(newX)==0)){
            myBoard.at(newY).at(newX) = myBoard.at(prevY).at(prevX);
            myBoard.at(prevY).at(prevX) = 0;
            break;
        } else {
            linesAfterBoard++;
            std::cout << "Invalid move." << std::endl;
        }
    }
}

void Attack(std::vector<std::vector<int>> &myBoard, int pieceType){
    int Xopp;
    int Yopp;
    int Xpos;
    int Ypos;
    int attackRange=2;
    while(true){
        Xpos = BoardInput("Enter the X cordinate you are attacking from: ");
        Ypos = BoardInput("Enter the Y cordinate you are attacking from: ");
        Xopp = BoardInput("Enter the X cordinate you are going to attack: ");
        Yopp = BoardInput("Enter the Y cordinate you are going to attack: ");
        //checks to make sure move is valid
        if(pieceType==myBoard.at(Yopp).at(Xopp)){
            linesAfterBoard++;
            std::cout << "Not attacking the right piece." << std::endl;
        } else if(myBoard.at(Yopp).at(Xopp)==0){
            linesAfterBoard++;
            std::cout << "Not a valid enemy" << std::endl;
        } else if((attackRange>(abs(Xopp-Xpos)+abs(Yopp-Ypos)))){
            myBoard.at(Yopp).at(Xopp)=0;
            break;
        } else {
            linesAfterBoard++;
            std::cout << "Invalid attack." << std::endl;
        }
    }
}