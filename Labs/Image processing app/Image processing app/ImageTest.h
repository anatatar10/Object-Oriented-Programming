#pragma once
#include"image.h"
class ImageTest
{
public:
	static void testConstructor();
	static void testGetWidth();
	static void testGetHeight();
	static void testCopyConstructor();
	static void testAssignmentOperator();
	static void testSize();
	static void testAt();
	static void testZeros();
	static void testOnes();
	static void testSetPixel();
	static void testGetPixel();
	static void testGetRow();
	static void runAllTests();
};

