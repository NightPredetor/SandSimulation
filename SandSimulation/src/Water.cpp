#include "Water.h"

Water::Water(const int x, const int y, const CellManager* cellManager) : Cell(x, y, cellManager)
{
	setColor(sf::Color::Blue);
	setCanFall(true);
}

void Water::CalculateNewPosition(int& x, int& y)
{
	// Calculate new position.
	for (int i = 0; i < matrix.size(); i++)
	{
		if (IsCellEmpty(getXPos() + matrix[i][0], getYPos() + matrix[i][1]))
		{
			SetPosition(getXPos() + matrix[i][0], getYPos() + matrix[i][1]);
			break;
		}
	}

	Cell::CalculateNewPosition(x, y);

	return;
}