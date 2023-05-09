#pragma once

#include "Solid.h"

class MovableSolid : public Solid
{
public:
	explicit MovableSolid(const int x, const int y, const CellManager* cellManager);

	void CalculateNewPosition(int& x, int& y) override;

private:
	const std::vector<int> xArray = { 0, -1, 1 };
};

