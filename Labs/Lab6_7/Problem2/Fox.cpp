#include "Fox.h"
#include"Empty.h"
#include"Plant.h"
#include"Gopher.h"

Fox::Fox() : Animal()
{}

Fox::Fox(int row, int column, int age) : Animal(row, column, age)
{}


Entity* Fox::next(const SimulationGrid& g)
{
	unsigned int histogram[4] = { 0 };
	demographics(histogram, g);
	if (this->age >= 5)
	{
		return new Empty(this->row, this->column);
	}
	else if (histogram[2] == 0)
	{
		return new Empty(this->row, this->column);
	}
	else
		return new Fox(this->row, this->column, this->age + 1);

}

EntityType Fox::what() const
{
	return EntityType::FOX;
}

std::string Fox::toString() const
{
	return "F"+std::to_string(this->age);
}

std::ostream& operator<<(std::ostream& os, const Fox& other)
{
	return os << other.toString()/* << other.age*/;
}
