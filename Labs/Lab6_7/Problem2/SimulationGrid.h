
#pragma once
#define MAX_ROWS 100
#define MAX_COLS 100
#include<string>
// forward class declaration for Entity
class Entity;
class SimulationGrid
{
	friend class Entity;

public:
	SimulationGrid();
	SimulationGrid(int rows, int cols);
	SimulationGrid(const SimulationGrid& other);
	SimulationGrid(const std::string file);
	SimulationGrid& operator=(const SimulationGrid& other);
	~SimulationGrid();
	SimulationGrid* updateGrid();
	Entity* getCell(int row, int col) const;
	void setEntity(int row, int col, Entity* entity);
	virtual std::string toString() const;
	Entity* createEntity(std::string s);
	friend std::ostream& operator<<(std::ostream& os, const SimulationGrid& other);
	friend std::istream& operator>>(std::istream& is, SimulationGrid& other);
	friend class SimulationGridTest;

private:
	int rows;
	int cols;
	Entity* grid[MAX_ROWS][MAX_COLS];
};

