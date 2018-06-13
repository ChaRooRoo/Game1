#include "stdafx.h"
#include "Characters.h"
#include <iostream>


Characters::Characters() 
{
}

Characters::Characters(std::string c, int hP, int aP, int dP): characterName(c), hitPoints(hP), attackPoints(aP), defensePoints(dP) 
{
}

	//accessors
int Characters::getHitPoints() const {	return hitPoints; }
int Characters::getAttackPoints() const { return attackPoints; }
int Characters::getDefensePoints() const { return defensePoints; }
std::string Characters::getCharacterName() const { return characterName; }

int Characters::getLevel() const
{	
	return lvl;
}

const std::string* Characters::getAttackNames() const 
{
	return attackNames;
}

//mutators
void Characters::setHitPoints(int hP) { hitPoints = hP; }
void Characters::setAttackPoints(int aP) { attackPoints = aP; }
void Characters::setDefensePoints(int dP) { defensePoints = dP; }
void Characters::setCharacterName(std::string n) { characterName = n; }

void Characters::setLevel(int x)
{
	lvl = x;
}

void Characters::setMagicPoints(int m)
{
	this->setMagicPoints(m);
}


Characters::~Characters()
{
}

void Characters::setAttacks(std::string attack1, std::string attack2, std::string attack3, std::string attack4) {
	std::string temp[4] = { attack1, attack2, attack3, attack4 };
	for (int i = 0; i < 4; i++) {
		attackNames[i] = temp[i];
	}
	return;
}

void Characters::displayHP() const {
	int currentHP = this->getHitPoints() / 10;

	for (int i = 0; i < currentHP; i++) {
		std::cout << "|";
	}
	std::cout << "\n\nEach \'|\' = 10pts\n";
	return;
}

void Characters::displayMP() const{}


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
	this->setLevel(0);

}

Player::~Player() 
{
}


Enemy::Enemy(std::string name, int lvl) {
	setHitPoints(100 * lvl);
	setAttackPoints(1 * lvl);
	setDefensePoints(1 * lvl);
	setCharacterName(name);
	
}

Enemy::~Enemy() {}

StarbucksEmployee::StarbucksEmployee() : Enemy("Starbucks Employee", 1)
{
}

StarbucksEmployee::~StarbucksEmployee()
{

}
