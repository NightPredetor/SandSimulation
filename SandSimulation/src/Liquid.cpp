#include "Liquid.h"

Liquid::Liquid(const int x, const int y, const CellManager* cellManager) : Cell(x, y, cellManager)
{

}

void Liquid::CalculateNewPosition(int& x, int& y)
{
	// Generate RNG. To randomize next position.
	int multiplierRng = GetMultiplierRNG();

	// Cache current positions.
	int currentX = getXPos();
	int currentY = getYPos();

	// Calculate new position.
	for (int i = 0; i < matrix.size(); i++)
	{
		int newX = currentX + (matrix[i][0] * multiplierRng);
		int newY = currentY + matrix[i][1];

		if (IsCellEmpty(newX, newY))
		{
			SetPosition(newX, newY);
			break;
		}
	}

	Cell::CalculateNewPosition(x, y);

	return;
}