#pragma once

#include <vector>
#include <unordered_map>

class Cell;

// Holds the data for all the cells.
class CellManager
{
public:
	CellManager(const int width, const int height);
	~CellManager() = default;

	void UpdateCells();
	bool IsCellEmpty(const int x, const int y) const;

	template<class T>
	void DrawCell(const int x, const int y);
	void DrawEmptyCell(const int x, const int y);
	Cell* GetCell(const int x, const int y) const;

	// Getters.
	std::vector<std::vector<Cell*>> getCellList() const;

private:
	std::vector<std::vector<Cell*>> cellList;
	std::unordered_map<Cell*, bool> calculatedCellMap; // Cells that have been calculated already.

	void CreateCells(const int width, const int height);
	bool IsCellPosValid(const int x, const int y) const;
};


template <typename T>
void CellManager::DrawCell(const int x, const int y)
{
	if (IsCellPosValid(x, y) == false) return;

	// Remove the old cell.
	if (cellList[y][x])
	{
		calculatedCellMap.erase(cellList[y][x]);
	}

	cellList[y][x] = new T(x, y, this);
	calculatedCellMap[cellList[y][x]] = false;
}
