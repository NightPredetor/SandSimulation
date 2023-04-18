#include "Cell.h"
#include "CellManager.h"

Cell::Cell(Vector2 position, CellStateEnum newCellState) : position(position), cellState(newCellState)
{
	updatedCellState = CellStateEnum::Dead;
	setColor(sf::Color::White);

	// Setup RNG.
	std::random_device rd;
	gen = std::mt19937(rd());
}

void Cell::CalculateNewState()
{
	if (!canFall || getCellState() == CellStateEnum::Dead) return;

	if (belowCell && belowCell->getCellState() == CellStateEnum::Dead)
	{
		setUpdatedCellState(CellStateEnum::Dead);
		belowCell->setUpdatedCellState(CellStateEnum::Alive);
		return;
	}

	// Generate random number between 0 and 1.
	bool checkLeft = distrib(gen);

	// Toggle based on RNG.
	// If either one of them is null then pick the other.
	for (int i = 0; i < 2; i++)
	{
		if (checkLeft && leftCell && leftCell->getCellState() == CellStateEnum::Dead)
		{
			setUpdatedCellState(CellStateEnum::Dead);
			leftCell->setUpdatedCellState(CellStateEnum::Alive);
			return;
		}
		else if (rightCell && rightCell->getCellState() == CellStateEnum::Dead)
		{
			setUpdatedCellState(CellStateEnum::Dead);
			rightCell->setUpdatedCellState(CellStateEnum::Alive);
			return;
		}

		// Update rng so both cells can be checked.
		checkLeft = !checkLeft;
	}

	// If all cells below cannot fall, then this cell cannot fall as well.
	// This saves us calculation for this cell.
	if ((belowCell && belowCell->canFall) ||
		(leftCell && leftCell->canFall) ||
		(rightCell && rightCell->canFall))
	{
		return;
	}

	canFall = false;
}

void Cell::UpdateToNewState()
{
	cellState = updatedCellState;
}

void Cell::SetupNeighbours(CellManager* cellManager)
{
	if (cellManager == nullptr) return;

	std::vector<Cell*> neighboursList = cellManager->GetNeigbourList(this);

	belowCell = neighboursList[0];
	leftCell = neighboursList[1];
	rightCell = neighboursList[2];
}

Vector2 Cell::getPosition() const { return position; }

sf::Color Cell::getColor() const { return color; }

void Cell::setCanFall(const bool value) { canFall = value; }

void Cell::setUpdatedCellState(const CellStateEnum newCellState) { updatedCellState = newCellState; }

void Cell::setCellState(const CellStateEnum newState)
{
	cellState = newState;
}

CellStateEnum Cell::getCellState() const { return cellState; }

void Cell::setColor(sf::Color newColor) { color = newColor; }