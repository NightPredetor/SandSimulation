#pragma once
#include "Cell.h"
class Water : public Cell
{
public:
	explicit Water(const int x, const int y, const CellManager* cellManager);

	void CalculateNewPosition(int& x, int& y) override;

private:
	const std::vector<std::vector<int>> matrix =
    {
		{0, 1},		// Bottom
		{-1, 1},	// Bottom Left
		{1, 1},		// Bottom Right
		{-1, 0},	// Left
		{1, 0},		// Right
    };

	const std::vector<sf::Color> COLOR_LIST =
	{
		sf::Color(110, 195, 220),
		sf::Color(115, 200, 225),
		sf::Color(120, 205, 230),
		sf::Color(125, 210, 235),
		sf::Color(130, 215, 240),
	};
};