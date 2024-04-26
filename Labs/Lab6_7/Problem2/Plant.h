#pragma once
#include"Entity.h"
class Plant:public Entity
{
public:
	Plant();
	Plant(int row, int col);
	Entity* next(const SimulationGrid& g) override;
	EntityType what() const override;
	std::string toString() const override;
	friend std::ostream& operator<<(std::ostream& os, const Plant& other);
};
