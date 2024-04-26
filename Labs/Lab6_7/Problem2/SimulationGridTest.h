#pragma once
#include"SimulationGrid.h"
class SimulationGridTest
{
public:
	static void runAllTests();
	static void testDefault();
	static void testConstructor();
	static void testCopyConstructor();
	static void testAssignmentOperator();
	static void testGetCell();
	static void testSetEntity();
	static void testToString();
	static void testInsertionOperator();
};

