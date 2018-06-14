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
int Characters::getMagicPoints() const { return magicPoints;}
int Characters::getAttackPoints() const { return attackPoints; }
int Characters::getDefensePoints() const { return defensePoints; }
std::string Characters::getCharacterName() const { return characterName; }

int Characters::getLevel() const{ return lvl; }

Attack* Characters::getAttacks()  {
	return attacks;
}

//mutators
void Characters::setHitPoints(int hP) { hitPoints = hP; }	
	//Damage
void Characters::setAttackPoints(int aP) { attackPoints = aP; }
void Characters::setDefensePoints(int dP) { defensePoints = dP; }
void Characters::setCharacterName(std::string n) { characterName = n; }

void Characters::setLevel(int x){ lvl = x; }

void Characters::setMagicPoints(int m){ magicPoints = m; }


Characters::~Characters() { }

void Characters::setAttack(int attackIndex, Attack currentAttack) {
	this->attacks[attackIndex] = currentAttack;
}

void Characters::displayHP() const {

	int currentHP = this->getHitPoints() / 10;
	for (int i = 0; i < currentHP; i++) {
		std::cout << "|";
	}
	return;
}

void Characters::displayMP() const
{
	int currentMP = this->getMagicPoints() / 10;
	for (int i = 0; i < currentMP; i++) {
		std::cout << "|";
	}
	
	return;
}


Player::Player() 
{
	std::string name; int attackStrength = 0, defenseStrength = 0 ;
	std::cout << "Please enter a name:\n";
	std::cin >> name;
	std::cout << std::endl << std::endl;
	setHitPoints(100);
	setMagicPoints(10);
	setAttackPoints(1);
	setDefensePoints(5);
	setCharacterName(name);
	setLevel(0);

}

Player::~Player() 
{
}


Enemy::Enemy(std::string name, int lvl) {
	setHitPoints(100 * lvl);
	setAttackPoints(1 * lvl);
	setDefensePoints(1 * lvl);
	setMagicPoints(5 * lvl);
	setCharacterName(name);
	
}

Enemy::~Enemy() {}

StarbucksEmployee::StarbucksEmployee() : Enemy("Starbucks Employee", 1)
{
}

StarbucksEmployee::~StarbucksEmployee()
{

}
