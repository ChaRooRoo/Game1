#include "stdafx.h"
#include "Characters.h"
#include <iostream>


Characters::Characters() 
{
}

Characters::Characters(std::string, int hP, int aS, int dP): hitPoints(hP), attackPoints(aS), defensePoints(dP) 
{
}

int Characters::getHitPoints() const {	return hitPoints; }
int Characters::getAttackPoints() const { return attackPoints; }
int Characters::getDefensePoints() const { return defensePoints; }
std::string Characters::getCharacterName() const { return characterName; }

void Characters::setHitPoints(int hP) { hitPoints = hP; }
void Characters::setAttackPoints(int aS) { attackPoints = aS; }
void Characters::setDefensePoints(int dP) { defensePoints = dP; }

void Characters::setCharacterName(std::string n) { characterName = n; }

void Characters::setAttacks()
{
	int tempName = '\0';
	for (int i = 0; i < 4; i++) 
	{
		std::cin >> tempName;
		attackNames[i] = tempName;
	}
}


Characters::~Characters()
{
}

Player::Player() 
{
	std::string name; int attackStrength = 0, defenseStrength = 0 ;
	std::cout << "Please enter a name:\n";
	std::cin >> name;
	std::cout << std::endl << std::endl;
	setHitPoints(100);
	setAttackPoints(1);
	setDefensePoints(5);
	setCharacterName(name);
	lvl = 0;

}
Player::~Player() {}

void setAttacks(std::string attack1, std::string attack2,  attack3, int attack4) {
	
}
