#pragma once

#include "Liquid.h"

class Water : public Liquid
{
public:
	explicit Water(const int x, const int y, const CellManager* cellManager);

private:
	const std::vector<sf::Color> COLOR_LIST =
	{
		sf::Color(110, 195, 220),
		sf::Color(115, 200, 225),
		sf::Color(120, 205, 230),
		sf::Color(125, 210, 235),
		sf::Color(130, 215, 240),
	};
};