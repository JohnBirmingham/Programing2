#include <iostream>
#include <vector>
#include <limits>
enum gameState{
    ongoing,
    P1Wins,
    P2Wins
};
int linesAfterBoard=1;
int moveInput(std::string prompt){
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
			std::cin.ignore();
            if(-1<input<10){
                return input;
            } else {
                linesAfterBoard++;
                std::cout << "That move is not in the board" << std::endl;
            }
		}
	}
    
}
std::vector<std::vector<int>> MakeBoard(int size);
void SetUpBoard(std::vector<std::vector<int>> &myBoard);
void PrintRules();
void PrintBoard(std::vector<std::vector<int>> &myBoard);
void ChangeBoard(std::vector<std::vector<int>> &myBoard);
std::vector<int> CheckNumOfPieces(std::vector<std::vector<int>> &myBoard);
int GameStatus(std::vector<std::vector<int>> &myBoard);
void move(std::vector<std::vector<int>> &myBoard){
    int newX;
    int newY;
    int prevX;
    int prevY;
    while(true){
        prevX = moveInput("Enter the X cordinate you are coming from: ");
        prevY = moveInput("Enter the Y cordinate you are coming from: ");
        newX = moveInput("Enter the X cordinate you are going to: ");
        newY = moveInput("Enter the Y cordinate you are going to: ");
        //checks to make sure move is valid
        if((4>(newX-prevX+(newY-prevY))>-4)&&(myBoard.at(newY).at(newX)==0)){
            break;
        } else {
            linesAfterBoard++;
            std::cout << "Invalid move." << std::endl;
        }
    }
}
/*
void Play(std::vector<std::vector<int>> &myBoard, int newX, int newY, int prevX, int prevY, bool attacking){
    int gameState=ongoing;
    while(gameState=ongoing){
        //checks for attack
        if(attacking==false){
            //checks to see if the player is in range of board
            if((-1<newX<10)&&(-1<newY<10)){
                //checks to make sure move is valid
                if(2>(newX-prevX+(newY-prevY))>-2){
            
                }
            }
            else{
            
            }
        }
        else{
            //checks to see if the player is in range of board
            if((-1<newX<10)&&(-1<newY<10)){
                //checks for valid attack spaces
                if(1>(newX-prevX+(newY-prevY))>-1){
            
                }
            }
            else{

            }
        }
    }
}
*/
int main(){
    std::vector<std::vector<int>> myBoard = MakeBoard(10);
    PrintRules();
    SetUpBoard(myBoard);
    PrintBoard(myBoard);
    GameStatus(myBoard);
    linesAfterBoard++;
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ChangeBoard(myBoard);
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
        myBoard.at(0).at(i)=2;
    }
    for(int i = 4; i < myBoard.size()-4; i++){
        myBoard.at(1).at(i)=2;
    }
    for(int i = 4; i < myBoard.size()-4; i++){
        myBoard.at(myBoard.size()-2).at(i)=1;
    }
    for(int i = 4; i < myBoard.size()-4; i++){
        myBoard.at(myBoard.size()-1).at(i)=1;
    }
}

void PrintBoard(std::vector<std::vector<int>> &myBoard){
    int i = 0;
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
    for(int i = 0; i < myBoard.size()+linesAfterBoard; i++){
        std::cout << "\033[F\033[K";
    }
    PrintBoard(myBoard);
    linesAfterBoard=1;
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