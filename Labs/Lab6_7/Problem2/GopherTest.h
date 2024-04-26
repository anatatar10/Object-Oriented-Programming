#pragma once
#include"Gopher.h"
class GopherTest
{
public:
	static void runAllTests();
private:
	static void testDefault();
	static void testConstructor();
	static void testGetAge();
	static void testSetAge();
	static void testWhat();
	static void testToString();
	static void testIstreamOperator();
};

