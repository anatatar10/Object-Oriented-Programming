#include "FoxTest.h"
#include<cassert>
#include<iostream>
#include<ostream>
#include<string>
#include<sstream>

void FoxTest::runAllTests()
{
	testDefault();
	testConstructor();
	testGetAge();
	testSetAge();
	testWhat();
	testInsertOperator();
	testToString();
}

void FoxTest::testDefault()
{
	Fox f = Fox();
	assert(f.row == 0);
	assert(f.column == 0);
	assert(f.age == 0);
	
}

void FoxTest::testConstructor()
{
	Fox f(1, 3, 4);
	assert(f.row == 1);
	assert(f.column == 3);
	assert(f.age == 4);
}

void FoxTest::testGetAge()
{
	Fox f(1, 3, 12);
	assert(f.getAge() == 12);
}

void FoxTest::testSetAge()
{
	Fox f = Fox();
	f.setAge(3);
	assert(f.age == 3);
}

void FoxTest::testWhat()
{
	Fox f(1, 2, 3);
	assert(f.what() == EntityType::FOX);
}

void FoxTest::testToString()
{
	Fox f;
	assert(f.toString() == "F0");
}

void FoxTest::testInsertOperator()
{
	Fox f = Fox(1,2,3);
	std::stringstream os;
	os << f;
	assert(os.str() == "F3");
}
