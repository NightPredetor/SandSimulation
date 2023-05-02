#pragma once

#include "Cell.h"
#include <array>

class Sand : public Cell
{
public:
	explicit Sand(const int x, const int y, const CellManager* cellManager);

	void CalculateNewPosition(int& x, int& y) override;

private:
	const std::vector<int> xArray = {0, -1, 1};
	const std::vector<sf::Color> COLOR_LIST =
	{
		sf::Color(235, 200, 95),
		sf::Color(240, 205, 100),
		sf::Color(245, 210, 105),
		sf::Color(250, 215, 110),
		sf::Color(255, 220, 115),
	};
};