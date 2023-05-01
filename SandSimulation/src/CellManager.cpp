#include "CellManager.h"
#include "Cell.h"

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

			if (cell && calculatedCellMap[cell] == false)
			{
				calculatedCellMap[cell] = true;
				cell->CalculateNewPosition(xPos, yPos);

				if (IsCellPosValid(xPos, yPos))
				{
					cellList[y][x] = nullptr;
					cellList[yPos][xPos] = cell;

					continue;
				}
			}
		}
	}

	// Reset calculated cell dict.
	for (auto& kvp : calculatedCellMap)
	{
		kvp.second = false;
	}
}

void CellManager::DrawEmptyCell(const int x, const int y)
{
	if (IsCellPosValid(x, y) == false) return;

	calculatedCellMap.erase(cellList[y][x]);
	cellList[y][x] = nullptr;
}

std::vector<std::vector<Cell*>> CellManager::getCellList() const
{
	return cellList;
}

bool CellManager::IsCellEmpty(const int x, const int y) const
{
	if (IsCellPosValid(x, y) == false) return false;

	return cellList[y][x] == nullptr;
}

// Private
void CellManager::CreateCells(const int width, const int height)
{
	// TODO: Only for testing by generating random cells. Remove later.
	srand(time(NULL));
	
	cellList = std::vector<std::vector<Cell*>>(height);

	for (int y = 0; y < height; y++)
	{
		cellList[y] = std::vector<Cell*>(width);

		for (int x = 0; x < width; x++)
		{
			// TODO: Only for testing by generating random cells. Remove later and generate null cells.
			int rng = rand() % 2;

			if (rng == 0)
			{
				//cellList[y][x] = new Stone(x, y, this);
			}
			else
			{
				cellList[y][x] = nullptr;
			}
		}
	}
}

bool CellManager::IsCellPosValid(const int x, const int y) const
{
	return (y < cellList.size()) && (x < cellList[y].size());
}
