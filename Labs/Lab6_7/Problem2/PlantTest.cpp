#include "PlantTest.h"
#include<cassert>
#include<iostream>
#include<ostream>
#include<string>
#include<sstream>

void PlantTest::testConstructor()
{
	Plant p(2, 5);
	assert(p.getRow() == 2);
	assert(p.getCol() == 5);
}

void PlantTest::testWhat()
{
	Plant p(2, 5);
	assert(p.what() == EntityType::PLANT);
}

void PlantTest::testToString()
{
	Plant p(2, 5);
	assert(p.toString() == "P ");
}

void PlantTest::testOstreamOperator()
{
	Plant p = Plant(1, 1);
	std::stringstream os;
	os << p;
	assert(os.str() == "P");
}


void PlantTest::runAllTests()
{
	testConstructor();
	testWhat();
	testToString();
}


