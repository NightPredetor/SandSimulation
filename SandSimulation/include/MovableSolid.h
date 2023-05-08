#pragma once

#include "Cell.h"

class MovableSolid : public Cell
{
public:
	explicit MovableSolid(const int x, const int y, const CellManager* cellManager);

	void CalculateNewPosition(int& x, int& y) override;

private:
	const std::vector<int> xArray = { 0, -1, 1 };
};

