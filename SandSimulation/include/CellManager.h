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
	void DrawCell(const int x, const int y);

	// Getters.
	std::vector<std::vector<Cell*>> getCellList() const;

private:
	std::vector<std::vector<Cell*>> cellList;
	std::vector<std::vector<Cell*>> cellBufferList;

	void CreateCells(const int width, const int height);
	bool IsCellPosValid(const size_t x, const size_t y) const;
};