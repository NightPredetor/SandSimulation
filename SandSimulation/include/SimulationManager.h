#pragma once

#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "CellManager.h"

class SimulationManager
{
public:
	SimulationManager();

	sf::VertexArray GetCellsForDraw();
	void DrawCell(const int x, const int y);
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
	int getBrushSize() const;

	// Setters.
	void setCurrentCellIndex(const int index);

private:
	// Set const variables.
	const int WIDTH = 400;
	const int LENGTH = 300;
	const int CELL_SIZE = 3;
	const int UI_SPACE = 200;
	const sf::Color BG_COLOR = sf::Color(150, 150, 150);

	int totalWidth;
	int totalLength;

	bool step = false;
	bool clearBoard = false;
	bool pauseSimulation = false;
	int currentCellIndex = 1;
	int brushSize = 5;

	CellManager cellManager = CellManager(WIDTH, LENGTH);

	sf::VertexArray vertexArray;
	sf::RectangleShape cellBackground = sf::RectangleShape(sf::Vector2f(WIDTH* CELL_SIZE, LENGTH* CELL_SIZE));

	void SetupVertexBuffer();
};