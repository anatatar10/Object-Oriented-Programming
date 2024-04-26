#pragma once
#include"Empty.h"
class EmptyTest
{
public:
	static void runAllTests();
private:
	static void testConstructor();
	static void testNext();
	static void testWhat();
	static void testToString();
	static void testOstreamOperator();
};

