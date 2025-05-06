#include <vector>
#include <string>
#include "Engine.h"
#pragma once
class Board {
private:
	std::vector<std::vector<int>> myBoard;
public:
	Board(int size);
	void ChangePoisition(std::vector<int> moveSet, int pieceType);
	void SetUpBoard();
	void PrintBoard();
	void Draw(Engine* e, int selectedRow, int selectedCol);
	std::vector<std::vector<int>> GiveBoard();
};
