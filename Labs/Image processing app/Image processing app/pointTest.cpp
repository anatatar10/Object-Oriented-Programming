#include "pointTest.h"
#include<cassert>
#include<ostream>
#include<istream>
#include<sstream>
void pointTest::testConstructor()
{
	Point p = Point(3, 3);
	assert(p.x == 3);
	assert(p.y == 3);
}

void pointTest::testCopyConstructor()
{
	Point p = Point(3, 3);
	Point p1 = Point(p);
	assert(p1.x == 3);
	assert(p1.y == 3);
}

void pointTest::testGetX()
{
	Point p = Point(3, 3);
	assert(p.getX() == 3);
}

void pointTest::testGetY()
{
	Point p = Point(3, 3);
	assert(p.getY() == 3);
}

void pointTest::testSetX()
{
	Point p = Point();
	p.setX(3);
	assert(p.x == 3);
}

void pointTest::testSetY()
{
	Point p = Point();
	p.setY(3);
	assert(p.y == 3);
}

void pointTest::testOstream()
{
	Point p(10, 20);

	std::stringstream os;
	os << p;
	assert(os.str() == "(10, 20)");
	
}

void pointTest::testIstream()
{
	Point p = Point();
	std::stringstream is("10 20");
	is >> p;
	assert(p.x == 10);
	assert(p.y == 20);

}

void pointTest::runAllTests()
{
	testConstructor();
	testCopyConstructor();
	testGetX();
	testGetY();
	testSetX();
	testSetY();
	testOstream();
	testIstream();
}
