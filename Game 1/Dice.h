#pragma once

#include "stdafx.h"

class Dice
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


