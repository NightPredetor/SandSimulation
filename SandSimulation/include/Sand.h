#pragma once
#include "Cell.h"
class Sand : public Cell
{
public:
	explicit Sand(const int x, const int y, const CellManager* cellManager);

	void CalculateNewPosition(int& x, int& y) override;

private:
	const std::vector<int> xArray = {0, -1, 1};
};
