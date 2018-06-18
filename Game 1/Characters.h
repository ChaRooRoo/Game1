#pragma once

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Dice.h"

//check ifndef

class Attack {
private:
	std::string attackName;
	int mPConsumed;
	int damageDone;
	int hitChance;
	bool hasSpecial;
public:
	Attack();
	Attack(std::string aName, int mP, int damage, int hChance);
	//getters
	std::string getName();
	int getMPConsumption();
	int getDamageDone();
	int getHitChance();
	bool getHasSpecial();
	//setters
	void setName(std::string n);
	void setMPConsumption(int mP);
	void setDamageDone(int damage);
	void sethitChance(int h);
	void setHasSpecial(bool special);

	//helpers

	virtual void useSpecial();

};

class Punch : public Attack {
private:
	//have a special sound?
public:
	Punch(std::string punchName, int magRequirement, int damageDealt, int h);
	~Punch();
};


class Characters
{
private:
	std::string characterName;
	int hitPoints;
	int magicPoints;
		//Points maybe changed later
	int attackPoints;
	int defensePoints;
	int lvl;
	Attack attackArray[4];
public:
	Characters();
		//remember you are missing a way to initialize mP
	Characters(std::string cName);
	//accessors
	int getHitPoints() const;
	int getMagicPoints() const;
	int getAttackPoints() const;
	int getDefensePoints() const;
	std::string getCharacterName() const;
	int getLevel() const;
	Attack* getAttacks();
	
	//mutators
	void setHitPoints(int hP);
	void setMagicPoints(int m);
	void setAttackPoints(int aP);
	void setDefensePoints(int dP);
	void setCharacterName(std::string n);
	void setLevel(int x);
	void setAttack(int attackIndex, Attack& currentAttack);
	void decreaseHP(Characters& reciever, int d);
	void decreaseMP(int m);
	void attack(Attack* currentAttack, Characters& currentEnemy);

	void displayHP() const;
	void displayMP() const;

	~Characters();
};

class Player : public Characters {
private:
		//PROFESSIONS SHOULD BE THEIR OWN CLASSES!
public:
	Player();
	~Player();
	
};

class Enemy : public Characters {
private:
public:
	Enemy(std::string name ,int lvl);
	~Enemy();
};

class StarbucksEmployee : public Enemy {
private:


public:
	StarbucksEmployee();
	~StarbucksEmployee();
	
};

