#pragma once
#include"Entity.h"
class Empty : public Entity
{
public:
	Empty();
	Empty(int row, int col);
	Entity* next(const SimulationGrid& g) override;
	EntityType what() const override;
	std::string toString() const override;
	friend std::ostream& operator<<(std::ostream& os, const Empty& other);
};

