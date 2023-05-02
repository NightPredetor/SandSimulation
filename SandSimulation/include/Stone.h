#pragma once

#include "Cell.h"

class Stone : public Cell
{
public:
	explicit Stone(const int x, const int y, const CellManager* cellManager);

	void CalculateNewPosition(int& x, int& y) override;

private:
	const std::vector<sf::Color> COLOR_LIST =
	{
		sf::Color(60, 60, 60),
		sf::Color(65, 65, 65),
		sf::Color(70, 70, 70),
		sf::Color(85, 85, 85),
		sf::Color(90, 90, 90)
	};
};

