#include"CharacterTest.h"
#include<string>
#include<cassert>

void CharacterTest::testCharacter()
{
	Character c;
	assert(c.name == "");
	assert(c.health == 0);
	assert(c.level == 0);
}

void CharacterTest::testGetName()
{
	Character c("Ana", 100, 30);
	assert(c.name == c.getName());
}

void CharacterTest::testSetName()
{
	Character c;
	c.setName("Ana");
	assert(c.name == "Ana");
}

void CharacterTest::testGetHealth()
{
	Character c("Ana", 100, 30);
	assert(c.health == c.getHealth());
}

void CharacterTest::testSetHealth()
{
	Character c;
	c.setHealth(100);
	assert(c.health == 100);
}

void CharacterTest::testGetLevel()
{
	Character c("Ana", 100, 30);
	assert(c.level == c.getLevel());
}

void CharacterTest::testSetLevel()
{
	Character c;
	c.setLevel(100);
	assert(c.level == 100);
}

void CharacterTest::testDestructor()
{
	Character c("Ana", 100, 100);
	c.~Character();
	assert(c.name == "");
}

void CharacterTest::testCopyConstructor()
{
	Character c("Ana", 100, 10);
	Character c1(c);
	assert(c1.name == "Ana");
	assert(c1.health == 100);
	assert(c1.level == 10);
}

void CharacterTest::testAssignemntOperator()
{
	Character c("Ana", 100, 10);
	Character c1 = c;
	assert(c1.name == "Ana");
	assert(c1.health == 100);
	assert(c1.level == 10);
}

void CharacterTest::runAll()
{
	testCharacter();
	testGetName();
	testSetName();
	testGetHealth();
	testSetHealth();
	testGetLevel();
	testSetLevel();
	testDestructor();
	testCopyConstructor();
	testAssignemntOperator();
}


