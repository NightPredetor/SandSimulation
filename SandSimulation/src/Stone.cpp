#include "Stone.h"

Stone::Stone(const int x, const int y, const CellManager* cellManager) : ImmovableSolid(x, y, cellManager)
{
	setColor(&COLOR_LIST);
}