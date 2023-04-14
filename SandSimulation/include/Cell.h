#pragma once

#include <vector>
#include "Internal/Vector2.h"
#include "enums/CellStateEnum.h"

#include <random>

class CellManager;

// A base empty cell class that occupies a position in a grid.
class Cell
{
public:
	explicit Cell(Vector2 position, CellStateEnum newCellState);
	virtual ~Cell() = default;

	virtual void CalculateNewState();
	virtual void UpdateToNewState();

	virtual void SetupNeighbours(CellManager* cellManager);

	virtual Vector2 getPosition() const;

	virtual void setCellState(const CellStateEnum newState);
	virtual CellStateEnum getCellState() const;

protected:
	virtual void setUpdatedCellState(const CellStateEnum newCellState);

private:
	Vector2 position;
	CellStateEnum updatedCellState;
	CellStateEnum cellState;

	Cell* belowCell = nullptr;
	Cell* leftCell = nullptr;
	Cell* rightCell = nullptr;

	// RNG setup.
	std::mt19937 gen;
	std::uniform_int_distribution<> distrib = std::uniform_int_distribution<>(0, 1);
};