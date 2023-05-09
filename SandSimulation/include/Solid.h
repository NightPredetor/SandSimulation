#pragma once

#include "Cell.h"

class Solid : public Cell
{
public:
	explicit Solid(const int x, const int y, const CellManager* cellManager);
};

