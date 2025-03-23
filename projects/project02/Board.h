#include <vector>
#include <string>
#pragma once
class Board {
private:
	std::vector<std::vector<int>> myBoard;
public:
	Board(int size);
	void ChangePoisition(std::vector<int> moveSet, int pieceType);
	void SetUpBoard();
	void PrintBoard(std::vector<std::vector<int>>& myBoard);
	void ChangeBoard(std::vector<std::vector<int>>& myBoard);
	std::vector<std::vector<int>> GiveBoard();
};
