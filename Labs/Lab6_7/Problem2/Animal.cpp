#include "Animal.h"

Animal::Animal() : Entity(), age{ 0 }
{}

Animal::Animal(int row, int column, int age) : Entity(row, column)
{
    this->age = age;
}

int Animal::getAge() const
{
    return this->age;
}

void Animal::setAge(int age)
{
    this->age = age;
}
