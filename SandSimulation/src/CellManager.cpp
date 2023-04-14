#include "CellManager.h"
#include "Cell.h"

#include <time.h>

// Public
CellManager::CellManager(const int width, const int height, const CellStateEnum defaultState)
{
	CreateCells(width, height, defaultState);
	SetupCellNeighbours();
}

void CellManager::UpdateCells() const
{
	for (const auto& data : cellDict)
	{
		data.second->CalculateNewState();
	}

	for (const auto& data : cellDict)
	{
		data.second->UpdateToNewState();
	}
}

std::vector<Cell*> CellManager::GetNeigbourList(const Cell* cell)
{
	// Create array for holding cells.
	std::vector<Cell*> neighbourList;

	// Loop 3 times in X.
	for (const int x : cellIndexList)
	{
		auto position = Vector2(cell->getPosition().X + x, cell->getPosition().Y + 1);
		if (cellDict.count(position))
		{
			neighbourList.push_back(cellDict[position]);
		}
		else
		{
			neighbourList.push_back(nullptr);
		}
	}

	return neighbourList;
}

std::map<Vector2, Cell*> CellManager::getCellDict() const
{
	return cellDict;
}

// Private
void CellManager::CreateCells(const int width, const int height, const CellStateEnum defaultState)
{
	srand(time(NULL));
	auto enumValue = (int)defaultState;

	std::vector<Vector2> gridList = Grid::CreateGrid(width, height);

	for (Vector2 position : gridList)
	{
		if (cellDict.count(position)) { continue; }

		if (defaultState == CellStateEnum::NONE)
		{
			enumValue = rand() % 3 + 1;
		}

		cellDict[position] = new Cell(position, (CellStateEnum)enumValue);
	}
}

void CellManager::SetupCellNeighbours()
{
	for (const auto& data : cellDict)
	{
		data.second->SetupNeighbours(this);
	}
}
