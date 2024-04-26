#pragma once
#include "EntityType.h"
#include "SimulationGrid.h"
#include<string>
#include<iostream>
#include<ostream>

class Entity
{
public:
	Entity();
	Entity(int row, int column);
	int getRow() const;
	void setRow(int row);
	int getCol() const;
	void setCol(int column);

	// TODO make pure abstract method
	virtual EntityType what() const = 0;

	virtual std::string toString() const = 0;

	virtual Entity* next(const SimulationGrid& g) = 0;

	friend std::ostream& operator<<(std::ostream& os, const Entity& other);
	void demographics(unsigned int population[], const SimulationGrid& g);
	friend class EntityTest;

protected:
	 int row;
	 int column;

	
};

