#include <iostream>
#include <vector>
enum gameState{
    ongoing,
    P1Wins,
    P2Wins
};

std::vector<std::vector<int>> MakeBoard(int size);
void SetUpBoard(std::vector<std::vector<int>> &myBoard);
void PrintRules();
void PrintBoard(std::vector<std::vector<int>> &myBoard);
/*
void Play(std::vector<std::vector<int>> myBoard, int newX, int newY, int prevX, int prevY, bool attacking){
    //checks for attack
    if(attacking==false){
        //checks to see if the player is in range of board
        if((-1<newX<10)&&(-1<newY<10)){
            //checks to make sure move is valid
            if(2>(newX-prevX+(newY-prevY))>-2){
            
            }
        }
        else{
            return -1;
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
            return -1;
        }
    }
}

int GameStatus(int numbOfP1Pieces, int numbOfP2Pieces){
    if(numbOfP1Pieces == 0){
        return P1Wins;
    } else if(numbOfP2Pieces == 0){
        return P2Wins;
    } else {
        return ongoing;
    }
}
*/
int main(){
    std::vector<std::vector<int>> myBoard = MakeBoard(10);
    PrintRules();
    SetUpBoard(myBoard);
    PrintBoard(myBoard);
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
