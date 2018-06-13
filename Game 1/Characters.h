#pragma once

#include "stdafx.h"
#include "Characters.h"
#include <string>
#include <iostream>

//check ifndef

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <ctime>

class Characters
{
private:
	std::string characterName;
	int hitPoints;
		//Points maybe changed later
	int attackPoints;
	int defensePoints;
	int attackNames[4];
public:
	Characters();
	Characters(std::string name,int hP, int aS, int dP);
	//accessors
	int getHitPoints() const;
	int getAttackPoints() const;
	int getDefensePoints() const;
	std::string getCharacterName() const;
	

	//mutators
	void setHitPoints(int hP);
	void setAttackPoints(int aS);
	void setDefensePoints(int dP);
	void setCharacterName(std::string n);
	void setAttacks();


	~Characters();
};

class Player : public Characters {
private:
	int lvl;
		//PROFESSIONS SHOULD BE THEIR OWN CLASSES!
public:
	Player();
	~Player();
	void setAttacks(int attack1, int attack2, int attack3, int attack4);
	
};

