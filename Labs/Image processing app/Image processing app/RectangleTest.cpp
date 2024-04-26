#include "RectangleTest.h"
#include<cassert>
#include<sstream>
void RectangleTest::testConstructor()
{
	Rectangle r = Rectangle(1, 1, 10, 10);
	assert(r.start.x == 1);
	assert(r.start.y == 1);
	assert(r.size.height == 10);
	assert(r.size.width == 10);
}

void RectangleTest::testConstructor1()
{
	Point p1 = Point(10, 10);
	Point p2 = Point(30, 30);
	Rectangle r = Rectangle(p1, p2);
	assert(r.start.x == 10);
	assert(r.start.y == 10);
	assert(r.size.width == 20);
	assert(r.size.height == 20);
}

void RectangleTest::testGetX()
{
	Rectangle r = Rectangle(1, 1, 10, 10);
	assert(r.start.x == 1);
}

void RectangleTest::testGetY()
{
	Rectangle r = Rectangle(1, 1, 10, 10);
	assert(r.start.y == 1);
}

void RectangleTest::testSetX()
{
	Rectangle r = Rectangle();
	r.start.setX(3);
	assert(r.start.x == 3);
}

void RectangleTest::testSetY()
{
	Rectangle r = Rectangle();
	r.start.setY(3);
	assert(r.start.y == 3);
}

void RectangleTest::testGetWidth()
{
	Rectangle r = Rectangle(1, 1, 10, 10);
	assert(r.size.width == 10);
}

void RectangleTest::testGetHeight()
{
	Rectangle r = Rectangle(1, 1, 10, 10);
	assert(r.size.height == 10);
}

void RectangleTest::testOstream()
{
	Rectangle r = Rectangle(1, 1, 10, 10);
	std::stringstream os;
	os << r;
	assert(os.str() == "(1, 1, 10, 10)");
}

void RectangleTest::testIstream()
{
	Rectangle r = Rectangle();
	std::stringstream is("1 1 10 10");
	is >> r;
	assert(r.start.x == 1);
	assert(r.start.y == 1);
	assert(r.size.width == 10);
	assert(r.size.height == 10);
}

void RectangleTest::runAllTests()
{
	testConstructor();
	testConstructor1();
	testGetX();
	testGetY();
	testSetX();
	testSetY();
	testGetWidth();
	testGetHeight();
	testOstream();
	testIstream();
}
