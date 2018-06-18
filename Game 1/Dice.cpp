#include "stdafx.h"
#include "Dice.h"
Dice::Dice(): sides(6)
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



