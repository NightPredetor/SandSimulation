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
		{0, 1},
		{-1, 1},
		{1, 1},
		{1, 0},
		{-1, 0},
    };
};