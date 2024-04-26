#pragma once
#include"Character.h"
#include<string>

class Knight: public Character
{
public:
	Knight();
	Knight(std::string name, int health, int level, float armor, int swordDamage);

	float getArmor() const;
	int getSwordDamage() const;

	void setArmor(float armor);
	void setSwordDamage(int swordDamage);

	Knight(const Knight& other);
	Knight& operator=(const Knight& other);

	void takeDamage(int damage);

	friend class KnightTest;
	
private:
	float armor;
	int swordDamage;
};

