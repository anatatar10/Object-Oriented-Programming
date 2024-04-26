#include "EmptyTest.h"
#include<cassert>
#include<iostream>
#include<ostream>
#include<string>
#include<sstream>

void EmptyTest::testConstructor()
{
	Empty e(1, 3);
	assert(e.getRow() == 1);
	assert(e.getCol() == 3);
}

void EmptyTest::testNext()
{
	SimulationGrid grid(3, 3);
	Empty e(1, 1);

	assert(e.next(grid) != nullptr);
}



void EmptyTest::testWhat()
{
	Empty e(1, 3);
	assert(e.what() == EntityType::EMPTY);
}

void EmptyTest::testToString()
{
	Empty e(1, 2);
	assert(e.toString() == "E ");
}

void EmptyTest::testOstreamOperator()
{
	Empty e = Empty(1, 2);
	std::stringstream os;
	os << e;
	assert(os.str() == "E");
}


void EmptyTest::runAllTests()
{
	testConstructor();
	testToString();
	testWhat();
	//testNext();
	
}

