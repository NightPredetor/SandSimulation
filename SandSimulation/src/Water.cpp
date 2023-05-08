#include "Water.h"

Water::Water(const int x, const int y, const CellManager* cellManager) : Liquid(x, y, cellManager)
{
	setColor(&COLOR_LIST);
}