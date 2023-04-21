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

	// Setters.
	void setXPos(const int x);
	void setYPos(const int y);
	void setCanFall(const bool value);

protected:
	void setColor(sf::Color newColor);
	bool IsCellEmpty(const int x, const int y) const;

private:
	int xPos;
	int yPos;
	bool canFall = true; // If a cell can fall down anymore.
	sf::Color color;

	const class CellManager* cellManager;
};