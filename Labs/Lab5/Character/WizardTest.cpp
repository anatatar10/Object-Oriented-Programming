#include "WizardTest.h"

#include<string>
#include<cassert>
#include<iostream>

using namespace std;
void WizardTest::runAll()
{
	testWizard();
	testGetMana();
	testSetMana();
	testGetSpells();
	testSetSpells();
	testGetSpellsPower();
	testSetSpellsPower();
	testDestructor();
	testCopyConstructor();
	testAssignmentOperator();
	testCastSpell();
}

void WizardTest::testWizard()
{
	Wizard w;
	assert(w.mana == 0);
	assert(w.spellPower == 0);
}

void WizardTest::testGetMana()
{
	std::vector<std::string> v;
	v.push_back("blackMagic");
	Wizard w(std::string("name"),10, 10, 10, v, 20);
	assert(w.mana == w.getMana());
}

void WizardTest::testSetMana()
{
	Wizard w;
	w.setMana(10);
	assert(w.mana == 10);
}

void WizardTest::testGetSpells()
{
	std::vector<std::string> v;
	v.push_back("blackMagic");
	Wizard w(std::string("name"), 10, 10, 10, v, 20);
	assert(w.spells == v);
}

void WizardTest::testSetSpells()
{
	Wizard w;
	std::vector<std::string> v;
	v.push_back("blackMagic");
	w.setSpells(v);
	assert(w.spells == v);
}

void WizardTest::testGetSpellsPower()
{
	std::vector<std::string> v;
	v.push_back("blackMagic");
	Wizard w(std::string("name"), 10, 10, 10, v, 20);
	assert(w.spellPower == 20);
}

void WizardTest::testSetSpellsPower()
{
	Wizard w;
	w.setSpellPower(10);
	assert(w.spellPower == 10);
}

void WizardTest::testDestructor()
{
	std::vector<std::string> v;
	v.push_back("blackMagic");
	Wizard w(std::string("name"), 10, 10, 10, v, 20);
	w.~Wizard();
	assert(w.spells.size() == 0);
	
}

void WizardTest::testCopyConstructor()
{
	std::vector<std::string> v;
	v.push_back("blackMagic");
	Wizard w(std::string("name"), 10, 10, 10, v, 20);
	Wizard w1(w);
	assert(w1.mana == 10);
	assert(w1.spells == v);
	assert(w1.spellPower == 20);
}

void WizardTest::testAssignmentOperator()
{
	std::vector<std::string> v;
	v.push_back("blackMagic");
	Wizard w(std::string("name"), 10, 10, 10, v, 20);
	Wizard w1 = w;
	assert(w1.mana == 10);
	assert(w1.spells == v);
	assert(w1.spellPower == 20);
}

void WizardTest::testCastSpell()
{
	std::vector<std::string> v;
	v.push_back("blackMagic");
	Wizard w(std::string("name"), 1, 5, 10, v, 20);
	assert(w.castSpell("blackMagic") == true);
	assert(w.castSpell("whiteMagic") == false);
	assert(w.mana == 0);
	w.setMana(5);
	assert(w.mana == 5);
}



