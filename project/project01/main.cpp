#include <iostream>
#include <vector>
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

int Play(int newX, int newY, int prevX, int prevY, bool attacking){
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
    enum gameState{
        ongoing,
        P1Wins,
        P2Wins
    };
    if()
    return 
}

int main(){
    std::vector<std::vector<int>> myBoard = MakeBoard(10);
}