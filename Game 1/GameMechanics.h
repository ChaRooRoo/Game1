#pragma once

#include "stdafx.h"
#include "GameMechanics.h"
#include <stdlib.h>
#include <string>
#include <ctime>

#define GameMechanics_H


class GameMechanics
{
private:
	std::string mechanicName;

public:
	GameMechanics();
	GameMechanics(std::string name);
	std::string getMechanicName() const;
	~GameMechanics();
};

class Dice : public GameMechanics 
{
private:
	int sides;

public:
	Dice();
	Dice(int s);
	//accessors
		//remember to be able to get the name of the game mechanic as well
	int getDieSides() const;
	//mutators
	void setDieSides(int s);

	int roll();
	
	~Dice() {}
};

class Phase : public GameMechanics
{
private:
	std::string phaseName;
	int count;
public:
	Phase();
	~Phase();
	std::string getPhaseName() const;
		//Remember -- make sure you check out VIRTUAL FUNCTIONS
	void display();
	void getCount();
	void addTurn();


};


/*
class attackPhase : public GameMechanics {
private:
	int attack1;
	int attack2;
	int attack3;
	int attack4;
public:
	attackPhase();
	~attackPhase();
	int selectAttack();
};

*/

