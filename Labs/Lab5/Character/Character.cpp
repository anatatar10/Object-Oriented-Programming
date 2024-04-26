#include "Character.h"

Character::Character(): name{""}, health{0}, level{0}
{}

Character::Character(std::string name, int health, int level)
{
	this->name = name;
	this->health = health;
	this->level = level;
}

Character::~Character()
{
	if (!name.empty())
		name.erase();
}

Character::Character(const Character& other)
{
	this->name = other.name;
	this->health = other.health;
	this->level = other.level;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		if (!name.empty())
			name.erase();
		this->name = other.name;
		this->health = other.health;
		this->level = other.level;
	}
	return *this;
}

std::string Character::getName() const
{
	return this->name;
}

int Character::getHealth() const
{
	return this->health;
}

int Character::getLevel() const
{
	return this->level;
}

void Character::setName(std::string name)
{
	this->name = name;
}

void Character::setHealth(int health)
{
	this->health = health;
}

void Character::setLevel(int level)
{
	this->level = level;
}
