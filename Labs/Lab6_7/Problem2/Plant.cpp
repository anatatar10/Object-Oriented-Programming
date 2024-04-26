#include "Plant.h"
#include"Empty.h"
#include"Fox.h"
#include"Gopher.h"
#include<iostream>
#include<ostream>
#include<string>

Plant::Plant() : Entity()
{}

Plant::Plant(int row, int col) :Entity( row, col )
{}

Entity* Plant::next(const SimulationGrid & g)
{
	unsigned int histogram[4] = { 0 };
	demographics(histogram, g);
	if (histogram[2] == 2 * histogram[3])
	{
		return new Empty(this->row, this->column);
	} 
	else if (histogram[2] >= 3)
	{
		return new Gopher(this->row, this->column, 0);
	}
	else
	{
		return new Plant(this->row, this->column);
	}
}

EntityType Plant::what() const
{
	return EntityType::PLANT;
}

std::string Plant::toString() const
{
	return "P ";
}

std::ostream& operator<<(std::ostream& os, const Plant& other)
{
	return os << other.toString() << " at (" << other.getRow() << "," << other.getCol() << ")";
}
