#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include "GameMechanics.h"
//#include "Characters.h"
#include <ctime>

//Game Mechanics

GameMechanics::GameMechanics()
{
}

GameMechanics::GameMechanics(std::string name) : mechanicName(name) 
{
}

GameMechanics::~GameMechanics()
{
}


std::string GameMechanics::getMechanicName() const {
	return mechanicName;
}

// Dice

Dice::Dice(): GameMechanics("Dice"), sides(6)
{
}

Dice::Dice(int s) : sides(s) 
{
}

int Dice::getDieSides() const {
	return sides;
}

void Dice::setDieSides(int n) {
	sides = n;
}

int Dice::roll() {
	return rand() % sides + 1;
}


Phase::Phase() : GameMechanics("Phase")
{
}

Phase::Phase(std::string name) : phaseName(name) {

}

Phase::~Phase()
{
}

std::string Phase::getPhaseName() const
{
	return phaseName;
}

void Phase::display()
{
	std::cout << "Abstract Phase, no specific phase has been chosen.\n";
}

attackPhase::attackPhase() : Phase("Attack Phase")
{
}



void attackPhase::display(Characters& player, Characters& enemy) {
	//remember any changes made with this pointer will create issues with the original player
	Attack *tempPtr =  player.getAttacks();
	std::cout << "Health:  "; 
	player.displayHP();
	std::cout << std::endl << std::endl << "Magic: ";
	player.displayMP();
	std::cout << std::endl;
	std::cout << std::endl << "\nEach \'|\' = 10pts\n";
	std::cout << "\nSELECT AN ATTACK\n\n";
	//to have horizontal row you must create a separate type of algorithm

	//This actually displays the content
	for (int i = 0; i < 4; i++) {
		std::cout << "[" << i+1 << "]" << tempPtr[i] << std::endl;
	}
}

attackPhase::~attackPhase() 
{
}

int attackPhase::selectAttack() {
	int choice = 0;
	std::cout << "Please select which attack you would like to use: ";

};

Attack::Attack() : name(""), mPConsumed(0), damageDone(0), hitChance(0.0)
{
}

Attack::Attack(std::string aName, int mP, int damage, double hChance) :  name (aName), mPConsumed(mP), damageDone(damage), hitChance(hChance)
{

}


std::string Attack::getName() { return name; }
int Attack::getMPConsumption() { return mPConsumed; }
int Attack::getdamageDone() { return damageDone; }
double Attack::getHitChance() {return hitChance;}


void Attack::setName(std::string n) {

}
void Attack::setMPConsumption(int mP) {}
void Attack::setdamageDone(int damage) {}
void Attack::sethitChance(int h) {}
