#pragma once

#include <map>
#include <vector>

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

	// Getters.
	std::vector<std::vector<Cell*>> getCellList() const;

private:
	std::vector<std::vector<Cell*>> cellList;

	void CreateCells(const int width, const int height);
	bool IsCellPosValid(const int x, const int y) const;
};


template <typename T>
void CellManager::DrawCell(const int x, const int y)
{
	if (IsCellPosValid(x, y) == false) return;

	// TODO: Generate a cell type based on input/UI.
	cellList[y][x] = new T(x, y, this);
}
