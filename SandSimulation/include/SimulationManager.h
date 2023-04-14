#pragma once

#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "CellManager.h"

class SimulationManager
{
public:
	SimulationManager();

	sf::VertexArray GetCellsForDraw();
	void ToggleCellState(const class Vector2 cellPos, const bool canFall);
	void TogglePause();
	void ToggleClearBoard();
	void PerformStep();
	void OnStepTrue();
	void OnRestart();
	void UpdateCells();

	// Const variables getter.
	int getWidth() const;
	int getTotalWidth() const;

	int getLength() const;
	int getTotalLength() const;

	int getCellSize() const;
	int getUiSpace() const;
	sf::Color getBgColor() const;
	sf::RectangleShape getCellBg() const;

	// Getters.
	bool getPauseSimulation() const;
	bool getClearBoard() const;

private:
	// Set const variables.
	const int WIDTH = 200;
	const int LENGTH = 120;
	const int CELL_SIZE = 8;
	const int UI_SPACE = 200;
	const sf::Color BG_COLOR = sf::Color(150, 150, 150);

	int totalWidth;
	int totalLength;

	bool step = false;
	bool clearBoard = false;
	bool pauseSimulation = false;

	CellManager cellManager = CellManager(WIDTH, LENGTH, CellStateEnum::NONE);
	std::map<Vector2, class Cell*> cellMap;

	sf::VertexArray vertexArray;
	sf::RectangleShape cellBackground = sf::RectangleShape(sf::Vector2f(WIDTH* CELL_SIZE, LENGTH* CELL_SIZE));

	void SetupVertexBuffer();
};