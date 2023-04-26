#include "Water.h"

Water::Water(const int x, const int y, const CellManager* cellManager) : Cell(x, y, cellManager)
{
	setColor(sf::Color::Blue);
	setCanFall(true);
}

void Water::CalculateNewPosition(int& x, int& y)
{
	// TODO:
	// CellManager needs to keep track of each cell that has been calculated in the current frame.
	// This is done as a water cell can move to the left.

	// Generate RNG. To randomize next position.
	int multiplierRng = GetMultiplierRNG();

	// Cache current positions.
	int currentX = getXPos();
	int currentY = getYPos();

	// Calculate new position.
	for (std::vector<int> vector : matrix)
	{
		int newX = currentX + (vector[0] * multiplierRng);
		int newY = currentY + vector[1];

		if (IsCellEmpty(newX, newY))
		{
			SetPosition(newX, newY);
			break;
		}
	}

	Cell::CalculateNewPosition(x, y);

	return;
}