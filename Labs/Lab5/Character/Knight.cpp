#include "Knight.h"
#include <exception>
#include <stdexcept>
#include<iostream>
#include<ostream>


Knight::Knight(): Character{ }
{
	armor = 0.0f;
	swordDamage = 0;
}

Knight::Knight(std::string name, int health, int level, float armor, int swordDamage): Character{ name, level, health }
{
	if(armor >= 0 && armor <= 1)
		this->armor = armor;
	else
		std::cout<<"Invalid armor value"<<std::endl;
	this->swordDamage = swordDamage;
}

float Knight::getArmor() const
{
	if (this->armor >= 0 && this->armor <= 1)
	{
		return this->armor;
	}
	else
		throw std::invalid_argument("Invalid armor value");
}

int Knight::getSwordDamage() const
{
	return this->swordDamage;
}

void Knight::setArmor(float armor)
{
	if (armor >= 0 && armor <= 1)
		this->armor = armor;
	else
		throw std::invalid_argument("Invalid armor value");
}

void Knight::setSwordDamage(int swordDamage)
{
	this->swordDamage = swordDamage;
}

Knight::Knight(const Knight& other)
{
	this->armor = other.armor;
	this->swordDamage = other.swordDamage;
}

Knight& Knight::operator=(const Knight& other)
{
	if (this != &other)
	{
		this->armor = other.armor;
		this->swordDamage = other.swordDamage;
	}
	return *this;
}

void Knight::takeDamage(int damage)
{
	this->armor -= damage;
	if (this->armor < 0)
		this->health = 0;
}




