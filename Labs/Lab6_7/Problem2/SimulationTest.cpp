#include "SimulationTest.h"
#include<cassert>

void SimulationTest::testDefault()
{
	Simulation s = Simulation();
	assert(s.sg == nullptr);

}

void SimulationTest::runAllTests()
{
	testDefault();
}
