#include "Stone.h"

Stone::Stone(Vector2 position, CellStateEnum newCellState) : Cell(position, newCellState)
{
	setColor(sf::Color::Black);

	setCanFall(false);
	setCellState(CellStateEnum::Alive);
	setUpdatedCellState(CellStateEnum::Alive);
}

void Stone::CalculateNewState()
{
	return;
}

void Stone::UpdateToNewState()
{
	return;
}
