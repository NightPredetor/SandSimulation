#pragma once

#include <vector>
#include <random>
#include <SFML/Graphics/Shader.hpp>

class CellManager;

// A base empty cell class that occupies a position in a grid.
class Cell
{
public:
	explicit Cell(const int x, const int y, const CellManager* cellManager);
	virtual ~Cell() = default;

	virtual void CalculateNewPosition(int& x, int& y);

	// Getters.
	int getXPos() const;
	int getYPos() const;
	sf::Color getColor() const;

protected:
	void setColor(sf::Color newColor);
	void setColor(const std::vector<sf::Color>* colorList);

	void SetPosition(const int x, const int y);
	Cell* GetCell(const int x, const int y) const;
	bool IsCellEmpty(const int x, const int y) const;

	int GetMultiplierRNG();

private:
	int xPos;
	int yPos;
	sf::Color color = sf::Color::White;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution = std::uniform_int_distribution<int>(0, 1);
	std::uniform_int_distribution<int> distributionRandom = std::uniform_int_distribution<int>(0, 4);

	const class CellManager* cellManager;
};