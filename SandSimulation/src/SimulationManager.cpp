#include "SimulationManager.h"
#include "Water.h"
#include "Sand.h"
#include "Stone.h"

#include <iostream>
#include <math.h>

// ----- Public -----

SimulationManager::SimulationManager()
{
	totalWidth = WIDTH * CELL_SIZE;
	totalLength = LENGTH * CELL_SIZE;

	// Setup vertex buffer.
	SetupVertexBuffer();

	// Cell Background rect.
	cellBackground.setFillColor(BG_COLOR);
}

void SimulationManager::DrawCell(const int x, const int y)
{
	if (currentCellIndex == 0)
	{
		cellManager.DrawCell<Water>(x, y);
	}
	switch (currentCellIndex)
	{
		case 1:
			cellManager.DrawCell<Water>(x, y);
			break;

		case 2:
			cellManager.DrawCell<Stone>(x, y);
			break;

		default:
			cellManager.DrawCell<Sand>(x, y);
			break;
	}
}

void SimulationManager::TogglePause()
{
	pauseSimulation = !pauseSimulation;
}

void SimulationManager::ToggleClearBoard()
{
	clearBoard = !clearBoard;
}

void SimulationManager::PerformStep()
{
	step = true;
	pauseSimulation = false;
}

void SimulationManager::OnStepTrue()
{
	if (step == true)
	{
		step = false;
		pauseSimulation = true;
	}
}

void SimulationManager::OnRestart()
{
	step = clearBoard;
	pauseSimulation = clearBoard;

	cellManager = CellManager(WIDTH, LENGTH);
}

void SimulationManager::UpdateCells()
{
	cellManager.UpdateCells();
}

int SimulationManager::getWidth() const { return WIDTH; }

int SimulationManager::getTotalWidth() const { return totalWidth; }

int SimulationManager::getLength() const { return LENGTH; }

int SimulationManager::getTotalLength() const { return totalLength; }

int SimulationManager::getCellSize() const { return CELL_SIZE; }

int SimulationManager::getUiSpace() const { return UI_SPACE; }

sf::Color SimulationManager::getBgColor() const { return BG_COLOR; }

sf::RectangleShape SimulationManager::getCellBg() const { return cellBackground; }

bool SimulationManager::getPauseSimulation() const { return pauseSimulation; }

bool SimulationManager::getClearBoard() const { return clearBoard; }

void SimulationManager::setCurrentCellIndex(const int index) { currentCellIndex = index; }

// ----- Private -----

void SimulationManager::SetupVertexBuffer()
{
	// Calculate border size.
	const int BORDER_SIZE = roundf(CELL_SIZE * 0.1f);

	// Setup the vertex buffer for drawing all the cells.
	vertexArray = sf::VertexArray(sf::Quads, WIDTH * LENGTH * 4);

	int i = 0;
	sf::Vector2f point;
	for (int y = 0; y < LENGTH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			// ------------ Draw Cell ------------
			point = sf::Vector2f(x * CELL_SIZE + BORDER_SIZE, y * CELL_SIZE + BORDER_SIZE);
			vertexArray[i].position = point;

			// Top right point.
			point = sf::Vector2f(x * CELL_SIZE + CELL_SIZE - BORDER_SIZE, y * CELL_SIZE + BORDER_SIZE);
			vertexArray[i + 1].position = point;

			// Bottom right point.
			point = sf::Vector2f(x * CELL_SIZE + CELL_SIZE - BORDER_SIZE, y * CELL_SIZE + CELL_SIZE - BORDER_SIZE);
			vertexArray[i + 2].position = point;

			// Bottom left point.
			point = sf::Vector2f(x * CELL_SIZE + BORDER_SIZE, y * CELL_SIZE + CELL_SIZE - BORDER_SIZE);
			vertexArray[i + 3].position = point;

			i += 4;
		}
	}
}

sf::VertexArray SimulationManager::GetCellsForDraw()
{
	// Setup the vertex buffer for drawing all the alive cells.
	sf::VertexArray aliveVertexArray(sf::Quads);

	int vertexPoint = 0;
	for (const auto& xList : cellManager.getCellList())
	{
		for (const auto& cell : xList)
		{
			if (cell)
			{
				for (int i = 0; i < 4; i++)
				{
					vertexArray[vertexPoint + i].color = cell->getColor();
					aliveVertexArray.append(vertexArray[vertexPoint + i]);
				}
			}

			vertexPoint += 4;
		}
	}

	return aliveVertexArray;
}