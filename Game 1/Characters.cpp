#include "stdafx.h"
#include "Characters.h"
#include <iostream>



Attack::Attack() : attackName(""), mPConsumed(0), damageDone(0), hitChance(0)
{
}

Attack::Attack(std::string aName, int mP, int damage, int hChance) : attackName(aName), mPConsumed(mP), damageDone(damage), hitChance(hChance), hasSpecial(false)
{

}


std::string Attack::getName() { return attackName; }
int Attack::getMPConsumption() { return mPConsumed; }
int Attack::getDamageDone() { return damageDone; }
int Attack::getHitChance() { return hitChance; }
bool Attack::getHasSpecial(){ return hasSpecial; }

void Attack::setName(std::string n) { attackName = n; }
void Attack::setMPConsumption(int mP) { mPConsumed = mP; }
void Attack::setDamageDone(int damage) { damageDone = damage; }
void Attack::sethitChance(int h) { hitChance = h; }
void Attack::setHasSpecial(bool special){ hasSpecial = special; }


void Attack::useSpecial()
{
	std::cout << "Nothing happened . . .\n";
}

Punch::Punch(std::string punchName, int magRequirement, int damageDealt, int h) : Attack(punchName, magRequirement, damageDealt, h) 
{
	setHasSpecial(false);
}

Punch::~Punch()
{

}



Characters::Characters() : characterName(""), hitPoints(0), magicPoints(0), attackPoints(0), defensePoints(0)
{
}

Characters::Characters(std::string cName) : characterName(cName) 
{
}

	//accessors
int Characters::getHitPoints() const {	return hitPoints; }
int Characters::getMagicPoints() const { return magicPoints;}
int Characters::getAttackPoints() const { return attackPoints; }
int Characters::getDefensePoints() const { return defensePoints; }
std::string Characters::getCharacterName() const { return characterName; }
int Characters::getLevel() const{ return lvl; }
Attack* Characters::getAttacks()  { return attackArray;}

//mutators
void Characters::setHitPoints(int hP) { hitPoints = hP; }	
void Characters::setMagicPoints(int m){ magicPoints = m; }
void Characters::setAttackPoints(int aP) { attackPoints = aP; } //Possibly rename this to Damage Points
void Characters::setDefensePoints(int dP) { defensePoints = dP; }
void Characters::setCharacterName(std::string n) { characterName = n; }
void Characters::setLevel(int x) { lvl = x; }
void Characters::setAttack(int attackIndex, Attack& currentAttack) { 
	Attack* p1 = this->getAttacks();	
	p1[attackIndex] = currentAttack;
	return;
}

void Characters::decreaseHP(Characters& goner, int d) { goner.setHitPoints(goner.getHitPoints() - d); }

void Characters::decreaseMP(int m) { setMagicPoints(getMagicPoints() - m); }

void Characters::attack(Attack* currentAttack, Characters& currentEnemy) { 
	int damageDealt = currentAttack->getDamageDone();
	currentEnemy.decreaseHP(currentEnemy, damageDealt);
	decreaseMP(currentAttack->getMPConsumption());
}


void Characters::displayHP() const {
	int currentHP = this->getHitPoints() / 10;
	for (int i = 0; i < currentHP; i++) { std::cout << "|"; }
	return;
}

void Characters::displayMP() const
{
	int currentMP = this->getMagicPoints() / 10;
	for (int i = 0; i < currentMP; i++) { std::cout << "|"; }
	return;
}

Characters::~Characters() { }

Player::Player() 
{
	std::string name;
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



Enemy::Enemy(std::string name, int lvl) :Characters(name){
	setHitPoints(100 * lvl);
	setAttackPoints(1 * lvl);
	setDefensePoints(1 * lvl);
	setMagicPoints(5 * lvl);
	
}

Enemy::~Enemy() {}

StarbucksEmployee::StarbucksEmployee() : Enemy("Starbucks Employee", 1)
{
}

StarbucksEmployee::~StarbucksEmployee()
{

}

