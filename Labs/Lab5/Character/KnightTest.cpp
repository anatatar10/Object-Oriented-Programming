#include "KnightTest.h"
#include<cassert>
#include<iostream>
#include<ostream>

void KnightTest::testKnight()
{
	Knight k;
	assert(k.armor == 0.0f);
	assert(k.swordDamage == 0);
}

void KnightTest::testGetArmor()
{
	Knight k(std::string("name"), 10, 10, 3, 50);
	Knight k1(std::string("name"), 10, 10, 0.5, 50);
	assert(k1.armor == 0.5);
}

void KnightTest::testSetArmor()
{
	Knight k;
	k.setArmor(0.5);
	assert(k.armor == 0.5);
	Knight k1;
}

void KnightTest::testGetSwordDamage()
{
	Knight k(std::string("name"), 10, 10, 0.5, 50);
	assert(k.swordDamage == 50);
}

void KnightTest::testSetSwordDamage()
{
	Knight k;
	k.setSwordDamage(100);
	assert(k.swordDamage == 100);
}

void KnightTest::testCopyConstructor()
{
	Knight k(std::string("name"), 10, 10, 0.5, 50);
	Knight k1(k);
	assert(k.armor == 0.5);
	assert(k.swordDamage == 50);
}

void KnightTest::testAssignmentConstructor()
{
	Knight k(std::string("name"), 10, 10, 0.5, 50);
	Knight k1 = k;
	assert(k.armor == 0.5);
	assert(k.swordDamage == 50);
}

void KnightTest::testTakeDamage()
{
	Knight k(std::string("name"), 10, 10, 0.5, 50);
	k.takeDamage(3);
	assert(k.health == 0);
}

void KnightTest::runAll()
{
	testKnight();
	testGetArmor();
	testSetArmor();
	testGetSwordDamage();
	testSetSwordDamage();
	testCopyConstructor();
	testAssignmentConstructor();
	testTakeDamage();
}
