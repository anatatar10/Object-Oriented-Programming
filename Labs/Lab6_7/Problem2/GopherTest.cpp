#include "GopherTest.h"
#include<cassert>
#include<iostream>
#include<ostream>
#include<string>
#include<sstream>
void GopherTest::runAllTests()
{
	testDefault();
	testConstructor();
	testGetAge();
	testSetAge();
	testWhat();
	testToString();
	testIstreamOperator();
}

void GopherTest::testDefault()
{
	Gopher g;
	assert(g.row == 0);
	assert(g.column == 0);
	assert(g.age == 0);
}

void GopherTest::testConstructor()
{
	Gopher f(1, 3, 4);
	assert(f.row == 1);
	assert(f.column == 3);
	assert(f.age == 4);
}

void GopherTest::testGetAge()
{
	Gopher f(1, 3, 12);
	assert(f.getAge() == 12);
}

void GopherTest::testSetAge()
{
	Gopher f;
	f.setAge(3);
	assert(f.age == 3);
}

void GopherTest::testWhat()
{
	Gopher g(1, 2, 3);
	assert(g.what() == EntityType::GOPHER);
}

void GopherTest::testToString()
{
	Gopher g;
	assert(g.toString() == "G0");
}

void GopherTest::testIstreamOperator()
{
	Gopher g = Gopher(2, 1, 2);
	std::stringstream os;
	os << g;
	assert(os.str() == "G2");
}








