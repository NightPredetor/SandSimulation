#include "Cell.h"
#include "CellManager.h"

// ##### Public #####
Cell::Cell(const int x, const int y, const CellManager* cellManager) : xPos(x), yPos(y), cellManager(cellManager)
{

}

void Cell::CalculateNewPosition(int& x, int& y)
{
	x = getXPos();
	y = getYPos();
}

// ----- Getters -----
int Cell::getXPos() const { return xPos; }

int Cell::getYPos() const { return yPos; }

sf::Color Cell::getColor() const { return color; }

void Cell::SetPosition(const int x, const int y)
{
	xPos = x;
	yPos = y;
}

void Cell::setColor(sf::Color newColor) { color = newColor; }

void Cell::setColor(const std::vector<sf::Color>* colorList) 
{
	if (colorList == nullptr || colorList->empty()) return;

	// Get RNG.
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, colorList->size()-1);

	// Set color.
	sf::Color newColor = (*colorList)[dis(gen)];
	setColor(newColor);
}

// ##### Protected #####
Cell* Cell::GetCell(const int x, const int y) const
{
	return cellManager->GetCell(x, y);
}

bool Cell::IsCellEmpty(const int x, const int y) const
{
	return cellManager->IsCellEmpty(x, y);
}

int Cell::GetMultiplierRNG()
{
	return distribution(generator) == 0 ? 1 : -1;
}