#pragma once
#include "Cell.h"
class Water : public Cell
{
public:
	explicit Water(const int x, const int y, const CellManager* cellManager);

	void CalculateNewPosition(int& x, int& y) override;

private:
	const std::vector<std::vector<int>> matrix =
    {
		{0, 1},		// Bottom
		{-1, 1},	// Bottom Left
		{1, 1},		// Bottom Right
		{-1, 0},	// Left
		{1, 0},		// Right
    };
};