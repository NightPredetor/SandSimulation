#include "Sand.h"

Sand::Sand(const int x, const int y, const CellManager* cellManager) : Cell(x, y, cellManager)
{
	setColor(sf::Color::Yellow);
	setCanFall(true);
}

void Sand::CalculateNewPosition(int& x, int& y)
{
	// Generate RNG. To randomize next position.
	int multiplierRng = GetMultiplierRNG();

	// Cache current X position.
	int currentX = getXPos();

	// Calculate Y position.
	const int fixedYPos = getYPos() + 1;

	// Calculate new position.
	for (int pos : xArray)
	{
		int newX = currentX + (pos * multiplierRng);

		if (IsCellEmpty(newX, fixedYPos))
		{
			SetPosition(newX, fixedYPos);
			break;
		}
	}

	Cell::CalculateNewPosition(x, y);

	return;
}