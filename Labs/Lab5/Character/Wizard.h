#pragma once
#include"Character.h"
#include<vector>
#include<string>
class Wizard: public Character
{
public: 
	Wizard(std::string name, int health, int level, int mana, std::vector<std::string> spells, int spellPower);
	Wizard();
	int getMana() const;
	std::vector<std::string> getSpells() const;
	int getSpellPower() const;

	void setMana(int mana);
	void setSpells(std::vector<std::string> spells);
	void setSpellPower(int spellPower);

	~Wizard();
	Wizard(const Wizard& other);
	Wizard& operator=(const Wizard& other);

	bool castSpell(std::string spell);

	friend class WizardTest;

private:
	int mana;
	std::vector<std::string> spells;
	int spellPower;
	bool findSpell(std::string spell);
};

