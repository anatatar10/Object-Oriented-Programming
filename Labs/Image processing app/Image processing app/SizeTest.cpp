#include "SizeTest.h"
#include<cassert>
void SizeTest::testConstructor()
{
	Size s = Size(10, 10);
	assert(s.width == 10);
	assert(s.height == 10);
}

void SizeTest::testGetWidth()
{
	Size s = Size(10, 10);
	assert(s.getWidth() == 10);
}

void SizeTest::testGetHeight()
{
	Size s = Size(10, 10);
	assert(s.getHeight() == 10);
}

void SizeTest::runAllTests()
{
	testConstructor();
	testGetWidth();
	testGetHeight();
}
