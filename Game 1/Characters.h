#pragma once

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "GameMechanics.h"

//check ifndef


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
	//std::string attackNames[4];
	Attack attacks[4];
public:
	Characters();
		//remember you are missing a way to initialize mP
	Characters(std::string name,int hP,int aP, int dP);
	//accessors
	int getHitPoints() const;
	int getMagicPoints() const;
	int getAttackPoints() const;
	int getDefensePoints() const;
	std::string getCharacterName() const;
	int getLevel()const;
	Attack* getAttacks();

	
	//mutators
	void setHitPoints(int hP);
	void setMagicPoints(int m);
	void setAttackPoints(int aP);
	void setDefensePoints(int dP);
	void setCharacterName(std::string n);
	void setLevel(int x);
	void setAttack(int attackIndex, std::string name, int mP, int damageDone, double hitChance);

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

