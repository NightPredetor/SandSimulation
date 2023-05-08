#include "ImmovableSolid.h"

ImmovableSolid::ImmovableSolid(const int x, const int y, const CellManager* cellManager) : Cell(x, y, cellManager)
{

}

void ImmovableSolid::CalculateNewPosition(int& x, int& y)
{
	Cell::CalculateNewPosition(x, y);

	return;
}