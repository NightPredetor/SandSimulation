#pragma once

#include <vector>
#include "Internal/Vector2.h"
#include "enums/CellStateEnum.h"

#include <random>
#include <SFML/Graphics/Shader.hpp>

class CellManager;

// A base empty cell class that occupies a position in a grid.
class Cell
{
public:
	explicit Cell(Vector2 position, CellStateEnum newCellState);
	virtual ~Cell() = default;

	virtual void CalculateNewState();
	virtual void UpdateToNewState();

	void SetupNeighbours(CellManager* cellManager);

	Vector2 getPosition() const;
	sf::Color getColor() const;
	void setCanFall(const bool value);
	void setCellState(const CellStateEnum newState);
	void setUpdatedCellState(const CellStateEnum newCellState);
	CellStateEnum getCellState() const;

protected:
	void setColor(sf::Color newColor);

private:
	bool canFall = true; // If a cell can fall down anymore.
	Vector2 position;
	CellStateEnum updatedCellState;
	CellStateEnum cellState;

	Cell* belowCell = nullptr;
	Cell* leftCell = nullptr;
	Cell* rightCell = nullptr;

	// RNG setup.
	std::mt19937 gen;
	std::uniform_int_distribution<> distrib = std::uniform_int_distribution<>(0, 1);

	sf::Color color;
};