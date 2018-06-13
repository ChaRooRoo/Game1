#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include "GameMechanics.h"
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

/*
attackPhase() {};
~attackPhase();
int selectAttack();
*/

Phase::Phase() : GameMechanics("Phase")
{
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

}
