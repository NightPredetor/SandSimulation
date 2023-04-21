#include "Cell.h"
#include "CellManager.h"

// ##### Public #####
Cell::Cell(const int x, const int y, const CellManager* cellManager) : xPos(x), yPos(y), cellManager(cellManager)
{
	setColor(sf::Color::White);
}

void Cell::CalculateNewPosition(int& x, int& y)
{
	// Set current position.
	x = xPos;
	y = yPos;

	// Check if can fall further down.
	if (!canFall) return;
}

// ----- Getters -----
int Cell::getXPos() const { return xPos; }

int Cell::getYPos() const { return yPos; }

sf::Color Cell::getColor() const { return color; }

void Cell::setXPos(const int x) { xPos = x; }

void Cell::setYPos(const int y) { yPos = y; }

// ----- Setters -----
void Cell::setCanFall(const bool value) { canFall = value; }

void Cell::setColor(sf::Color newColor) { color = newColor; }

// ##### Protected #####
bool Cell::IsCellEmpty(const int x, const int y) const
{
	return cellManager->IsCellEmpty(x, y);
}
