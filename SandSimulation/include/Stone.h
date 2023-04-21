#pragma once

#include "Cell.h"

class Stone : public Cell
{
public:
	explicit Stone(const int x, const int y, const CellManager* cellManager);

	void CalculateNewPosition(int& x, int& y) override;
};

