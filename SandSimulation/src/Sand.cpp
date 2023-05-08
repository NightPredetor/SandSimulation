#include "Sand.h"

#include <iostream>

Sand::Sand(const int x, const int y, const CellManager* cellManager) : MovableSolid(x, y, cellManager)
{
	setColor(&COLOR_LIST);
}