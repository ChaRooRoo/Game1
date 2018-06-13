#pragma once

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <iostream>

//check ifndef


class Characters
{
private:
	std::string characterName;
	int hitPoints;
		//Points maybe changed later
	int attackPoints;
	int defensePoints;
	int lvl;
	int magicPoints;
	std::string attackNames[4];
public:
	Characters();
		//remember you are missing a way to initialize mP
	Characters(std::string name,int hP,int aP, int dP);
	//accessors
	int getHitPoints() const;
	int getAttackPoints() const;
	int getDefensePoints() const;
	std::string getCharacterName() const;
	int getLevel()const;
	const std::string* getAttackNames() const;
	
	//mutators
	void setHitPoints(int hP);
	void setAttackPoints(int aP);
	void setDefensePoints(int dP);
	void setCharacterName(std::string n);
	void setLevel(int x);
	void setMagicPoints(int m);

	void setAttacks(std::string attack1, std::string attack2, std::string attack3, std::string attack4);
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

