#pragma once

#include "Cell.h"
#include "ImmovableSolid.h"

class Stone : public ImmovableSolid
{
public:
	explicit Stone(const int x, const int y, const CellManager* cellManager);

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

