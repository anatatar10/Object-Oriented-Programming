#pragma once
#include"Entity.h"
#include"Animal.h"
class Gopher:public Animal
{
public:
	Gopher();
	Gopher(int row, int column, int age);
	Entity* next(const SimulationGrid& g) override;
	EntityType what() const override;
	std::string toString() const override;
	friend std::ostream& operator<<(std::ostream& os, const Gopher& other);

	friend class GopherTest;
};

