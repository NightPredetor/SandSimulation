#include "CellManager.h"
#include "Cell.h"
#include "Sand.h"

#include <time.h>
#include <iostream>

// Public
CellManager::CellManager(const int width, const int height)
{
	CreateCells(width, height);
}

void CellManager::UpdateCells()
{
	int xPos;
	int yPos;

	for (int y = cellList.size()-1; y >= 0; y--)
	{
		for (int x = cellList[y].size()-1; x >= 0; x--)
		{
			Cell* cell = cellList[y][x];
			if (cell == nullptr) continue;

			cell->CalculateNewPosition(xPos, yPos);
			
			if (IsCellPosValid(xPos, yPos) == false) continue;

			cellBufferList[yPos][xPos] = cell;
		}
	}

	cellList = std::vector<std::vector<Cell*>>(cellBufferList);

	for (int y = 0; y < cellList.size(); y++)
	{
		for (int x = 0; x < cellList[y].size(); x++)
		{
			cellBufferList[y][x] = nullptr;
		}
	}
}

std::vector<std::vector<Cell*>> CellManager::getCellList() const
{
	return cellList;
}

bool CellManager::IsCellEmpty(const int x, const int y) const
{
	if (IsCellPosValid(x, y) == false) return false;

	return cellBufferList[y][x] == nullptr;
}

void CellManager::DrawCell(const int x, const int y)
{
	if (IsCellPosValid(x, y) == false) return;

	// TODO: Generate a cell type based on input/UI.
	cellList[y][x] = new Sand(x, y, this);
}

// Private
void CellManager::CreateCells(const int width, const int height)
{
	// TODO: Only for testing by generating random cells. Remove later.
	srand(time(NULL));
	
	cellList = std::vector<std::vector<Cell*>>(height);
	cellBufferList = std::vector<std::vector<Cell*>>(height);

	for (size_t y = 0; y < height; y++)
	{
		cellList[y] = std::vector<Cell*>(width);
		cellBufferList[y] = std::vector<Cell*>(width);

		for (size_t x = 0; x < width; x++)
		{
			// TODO: Only for testing by generating random cells. Remove later and generate null cells.
			bool isAlive = rand() % 2;
			isAlive = false;

			if (isAlive)
			{
				cellList[y][x] = new Sand(x, y, this);
			}
			else
			{
				cellList[y][x] = nullptr;
			}

			cellBufferList[y][x] = nullptr;
		}
	}
}

bool CellManager::IsCellPosValid(const size_t x, const size_t y) const
{
	return (y < cellBufferList.size()) && (x < cellBufferList[y].size());
}
