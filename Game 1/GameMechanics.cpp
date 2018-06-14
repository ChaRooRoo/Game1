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



void attackPhase::display(const Characters& player, const Characters& enemy) {
	const std::string *tempPtr =  player.getAttackNames();
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

Attack::Attack(std::string aName, int mP, int damage, double hChance) :  name (aName), mPConsumed(mP), damageDone(damage), hitChance(hChance)
{

}
