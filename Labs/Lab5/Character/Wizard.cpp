#include "Wizard.h"
#include<string>
#include<vector>

Wizard::Wizard() : Character{ }
{
	mana = 0;
	spellPower = 0;
}

Wizard::Wizard(std::string name, int health, int level, int mana, std::vector<std::string> spells, int spellPower): Character{name, level, health}
{
	this->mana = mana;
	this->spells = spells;
	this->spellPower = spellPower;
}

int Wizard::getMana() const
{
	return this->mana;
}

std::vector<std::string> Wizard::getSpells() const
{
	return this->spells;
}

int Wizard::getSpellPower() const
{
	return this->spellPower;
}

void Wizard::setMana(int mana)
{
	this->mana = mana;
}

void Wizard::setSpells(std::vector<std::string> spells)
{
	this->spells = spells;
}

void Wizard::setSpellPower(int spellPower)
{
	this->spellPower = spellPower;
}

Wizard::~Wizard()
{
	if (!spells.empty())
	{
		for (int i = 0; i < spells.size(); i++)
		{
			if (!spells[i].empty())
			{
				spells[i].erase();
				spells[i] = "";
			}
		}
		spells.clear();
	}

}

Wizard::Wizard(const Wizard& other)
{
	this->mana = other.mana;
	this->spells = other.spells;
	this->spellPower = other.spellPower;
}

Wizard& Wizard::operator=(const Wizard& other)
{
	if (this != &other)
	{
		if (!spells.empty())
		{
			for (int i = 0; i < spells.size(); i++)
			{
				if (!spells[i].empty())
				{
					spells[i].erase();
				}
			}
			spells.clear();
		}
		this->mana = other.mana;
		this->spells = other.spells;
		this->spellPower = other.spellPower;
	}
	return *this;
}

bool Wizard::findSpell(std::string spell)
{
	for (int i = 0; i < spells.size(); i++)
	{
		if (spells[i] == spell)
			return true;
	}
	return false;
}

bool Wizard::castSpell(std::string spell)
{
	if (this->findSpell(spell) == true && this->mana >= 10)
	{
		this->mana = this->mana - 10;
		return true;
	}
	else
		return false;

}



