#include "Stone.h"

Stone::Stone(const int x, const int y, const CellManager* cellManager) : Cell(x, y, cellManager)
{
	setColor(&COLOR_LIST);
}

void Stone::CalculateNewPosition(int& x, int& y)
{
	Cell::CalculateNewPosition(x, y);

	return;
}