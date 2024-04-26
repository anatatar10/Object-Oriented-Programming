#include "Entity.h"
#include "EntityType.h"
#include <algorithm> // for std::fill
#include"Plant.h"
#include"Empty.h"
#include"Gopher.h"
#include"Fox.h"
#include<string>

Entity::Entity(): row{0}, column{0}
{}

Entity::Entity(int row, int column)
{
	this->row = row;
	this->column = column;
}

int Entity::getRow() const
{
	return this->row;
}

void Entity::setRow(int row)
{
	this->row = row;
}

int Entity::getCol() const
{
	return this->column;
}

void Entity::setCol(int column)
{
	this->column = column;
}

EntityType Entity::what() const
{
	switch (what())
	{
	case EntityType::EMPTY:
		return EntityType::EMPTY;
	case EntityType::FOX:
		return EntityType::FOX;
	case EntityType::GOPHER:
		return EntityType::GOPHER;
	case EntityType::PLANT:
		return EntityType::PLANT;
	}
}

std::string Entity::toString() const
{
	switch (what())
	{
	case EntityType::EMPTY:
		return "E";
	case EntityType::FOX:
		return "F";
	case EntityType::GOPHER:
		return "G";
	case EntityType::PLANT:
		return "P";

	default:
		return "";
	}
}

void Entity::demographics(unsigned int population[], const SimulationGrid& g)
{
	for (int i = 0; i < 4; i++)
	{
		population[i] = 0;
	}
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (dx == 0 && dy == 0)
			{
				continue;
			}
			if (dx + this->row < 0 || dx + this->row >= g.rows)
				continue;
			if (dy + this->column < 0 || dy + this->column >= g.cols)
				continue;
			
			switch (g.getCell(dx + this->row, dy + this->column)->what())
			
			{
			case EntityType::EMPTY:
				population[0]++;
				break;
			case EntityType::FOX:
				population[1]++;
				break;
			case EntityType::GOPHER:
				population[2]++;
				break;
			case EntityType::PLANT:
				population[3]++;
				break;
			}
		}
	}
}


std::ostream& operator<<(std::ostream& os, const Entity& other)
{
	os << other.toString();
	return os;
}
