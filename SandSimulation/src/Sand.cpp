#include "Sand.h"

Sand::Sand(const int x, const int y, const CellManager* cellManager) : Cell(x, y, cellManager)
{
	setColor(sf::Color::Yellow);
	setCanFall(true);
}

void Sand::CalculateNewPosition(int& x, int& y)
{
	// Calculate new position.
	for (int i = 0; i < xArray.size(); i++)
	{
		if (IsCellEmpty(getXPos() + i, getYPos() + 1))
		{
			SetPosition(getXPos() + i, getYPos() + 1);
			break;
		}
	}

	Cell::CalculateNewPosition(x, y);

	return;
}