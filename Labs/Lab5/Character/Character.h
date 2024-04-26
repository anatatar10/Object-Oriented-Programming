#pragma once
#include<string>


class Character
{
public:
	Character();
	Character(std::string name, int health, int level);
	
	std::string getName() const;
	int getHealth() const;
	int getLevel() const;

	void setName(std::string name);
	void setHealth(int health);
	void setLevel(int level);

	~Character();
	Character(const Character& other);
	Character& operator=(const Character& other);

	friend class CharacterTest;
protected:
	std::string name;
	int health;
	int level;
	
};

