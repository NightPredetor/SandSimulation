#include "Sand.h"

Sand::Sand(const int x, const int y, const CellManager* cellManager) : Cell(x, y, cellManager)
{
	setColor(sf::Color::Yellow);
	setCanFall(false);
}

void Sand::CalculateNewPosition(int& x, int& y)
{
	Cell::CalculateNewPosition(x, y);

	// Calculate new position.
	for (int i = 0; i < xArray.size(); i++)
	{
		if (IsCellEmpty(getXPos() + i, getYPos() + 1))
		{
			x = getXPos() + i;
			y = getYPos() + 1;

			setXPos(getXPos() + i);
			setYPos(getYPos() + 1);

			break;
		}
	}

	return;
}