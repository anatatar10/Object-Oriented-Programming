#pragma once
#include"SimulationGrid.h"

class Simulation
{
public:
	Simulation();
	~Simulation();
	void run();
	friend class SimulationTest;
private:
	SimulationGrid* sg;
};

