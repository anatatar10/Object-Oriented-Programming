#pragma once
#include"Entity.h"
class Animal : public Entity
{
public:
	Animal();
	Animal(int row, int column, int age);
	int getAge() const;
	void setAge(int age);

	// abstract methods of class Entity
	virtual EntityType what() const = 0;
	virtual std::string toString() const = 0;
	virtual Entity* next(const SimulationGrid& g) = 0;

protected:
	int age;
};

