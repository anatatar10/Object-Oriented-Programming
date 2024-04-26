#pragma once
#include"Entity.h"
#include"Animal.h"
class Fox : public Animal
{
public:
	Fox();
	Fox(int row, int column, int age);
	Entity* next(const SimulationGrid& g) override;
	EntityType what() const override;
	std::string toString() const override;
	friend std::ostream& operator<<(std::ostream& os, const Fox& other);

	friend class FoxTest;
};

