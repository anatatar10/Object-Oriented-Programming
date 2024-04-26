#include "Empty.h"
#include"Gopher.h"
#include"Fox.h"
#include"Plant.h"
#include<iostream>
#include<ostream>

Empty::Empty() : Entity()
{}

Empty::Empty(int row, int col):Entity(row, col)
{}

Entity* Empty::next(const SimulationGrid & g)
{
	unsigned int histogram[4] = { 0 };
	/*int i;
	std::cout << "(" << this->row << " , " << this->column << ")\n";*/
	demographics(histogram, g);
	/*for (i = 0; i < 4; i++) {
		std::cout << histogram[i] << " ";
	}
	std::cout << "\n";
	std::cout << "E F G P" << std::endl;
	std::cout << "\n\n";*/
	if (histogram[2] > 1)
	{
		return new Gopher(this->row, this->column, 0);
	} else if (histogram[1] > 1)
	{
		return new Fox(this->row, this->column, 0);
	} else if (histogram[3] >= 1)
	{
		return new Plant(this->row, this->column);
	}
	else
	{
		return new Empty(this->row, this->column);
	}
}

EntityType Empty::what() const
{
	return EntityType::EMPTY;
}

std::string Empty::toString() const
{
	return "E ";
}

std::ostream& operator<<(std::ostream& os, const Empty& other)
{
	return os << other.toString() << " at (" << other.getRow() << "," << other.getCol() << ")";
}
