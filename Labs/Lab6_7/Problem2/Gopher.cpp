#include "Gopher.h"
#include "Plant.h"
#include"Empty.h"
#include"Fox.h"
#include<string>

Gopher::Gopher() : Animal()
{}

Gopher::Gopher(int row, int column, int age) : Animal(row, column, age)
{}

Entity* Gopher::next(const SimulationGrid& g)
{
    unsigned int histogram[4] = { 0 };
    demographics(histogram, g);
    if (this->age == 4)
    {
        return new Empty(this->row, this->column);
    }
    else if (histogram[3] == 0)
    {
        return new Empty(this->row, this->column);
    }
    else if (histogram[1] >= histogram[2])
    {
        return new Fox(this->row, this->column, 0);
    }
    else
        return new Gopher(this->row, this->column, this->age + 1);
}

EntityType Gopher::what() const
{
    return EntityType::GOPHER;
}

std::string Gopher::toString() const
{
    return "G"+std::to_string(this->age);
}

std::ostream& operator<<(std::ostream& os, const Gopher& other)
{
    return os << other.toString()/* << other.age*/;
}
