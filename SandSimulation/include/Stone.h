#pragma once

#include "Cell.h"

class Stone : public Cell
{
public:
	Stone(Vector2 position, CellStateEnum newCellState);

	void CalculateNewState() override;
	void UpdateToNewState() override;
};

