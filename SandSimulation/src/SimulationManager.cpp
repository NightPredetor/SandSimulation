#include "SimulationManager.h"
#include "Stone.h"
#include "Internal/Vector2.h"

#include <iostream>
#include <math.h>

// ----- Public -----

SimulationManager::SimulationManager()
{
	totalWidth = WIDTH * CELL_SIZE;
	totalLength = LENGTH * CELL_SIZE;

	// Get cell dictionary.
	cellMap = cellManager.getCellDict();
	if (cellMap.empty())
	{
		std::cout << "No cells found!";
	}

	// Setup vertex buffer.
	SetupVertexBuffer();

	// Cell Background rect.
	cellBackground.setFillColor(BG_COLOR);
}

void SimulationManager::ToggleCellState(const Vector2 cellPos)
{
	if (cellMap.count(cellPos))
	{
		if (cellMap[cellPos]->getCellState() == CellStateEnum::Dead)
		{
			cellMap[cellPos]->setCellState(CellStateEnum::Alive);
			cellMap[cellPos]->setUpdatedCellState(CellStateEnum::Alive);
		}
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

	cellManager = CellManager(WIDTH, LENGTH, clearBoard ? CellStateEnum::Dead : CellStateEnum::NONE);
	cellMap = cellManager.getCellDict();
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

// ----- Private -----

void SimulationManager::SetupVertexBuffer()
{
	// Calculate border size.
	const int BORDER_SIZE = roundf(CELL_SIZE * 0.1f);

	// Setup the vertex buffer for drawing all the cells.
	vertexArray = sf::VertexArray(sf::Quads, cellMap.size() * 4);

	int i = 0;
	sf::Vector2f point;
	std::vector<Vector2> gridList = Grid::CreateGrid(WIDTH, LENGTH);
	for (const auto& vector : gridList)
	{
		// ------------ Draw Cell ------------
		point = sf::Vector2f(vector.X * CELL_SIZE + BORDER_SIZE, vector.Y * CELL_SIZE + BORDER_SIZE);
		vertexArray[i].position = point;

		// Top right point.
		point = sf::Vector2f(vector.X * CELL_SIZE + CELL_SIZE - BORDER_SIZE, vector.Y * CELL_SIZE + BORDER_SIZE);
		vertexArray[i + 1].position = point;

		// Bottom right point.
		point = sf::Vector2f(vector.X * CELL_SIZE + CELL_SIZE - BORDER_SIZE, vector.Y * CELL_SIZE + CELL_SIZE - BORDER_SIZE);
		vertexArray[i + 2].position = point;

		// Bottom left point.
		point = sf::Vector2f(vector.X * CELL_SIZE + BORDER_SIZE, vector.Y * CELL_SIZE + CELL_SIZE - BORDER_SIZE);
		vertexArray[i + 3].position = point;

		i += 4;
	}
}

sf::VertexArray SimulationManager::GetCellsForDraw()
{
	// Setup the vertex buffer for drawing all the alive cells.
	sf::VertexArray aliveVertexArray(sf::Quads);

	int vertexPoint = 0;
	for (const auto& data : cellMap)
	{
		if (data.second->getCellState() == CellStateEnum::Alive)
		{
			for (int i = 0; i < 4; i++)
			{
				vertexArray[vertexPoint + i].color = data.second->getColor();
				aliveVertexArray.append(vertexArray[vertexPoint + i]);
			}
		}

		vertexPoint += 4;
	}

	return aliveVertexArray;
}