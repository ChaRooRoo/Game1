// Game 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Characters.h"
#include "GameMechanics.h"
#include <ctime>

#define LINES_SKIPPED 15
//void readStory(int x);

void formatPlayArea(int x);
void gameSetup(Player& player, Enemy& enemy);



int main()
{
	srand(unsigned int(time(NULL)));

	std::cout << "____Welcome to the Game!____\n\n";
	Player player1;
	StarbucksEmployee janice;
	attackPhase aPhase;

			//placeholder text
	std::cout << "It's a sunny day on Monday and " << player1.getCharacterName() << " decides to go for a walk...\n\nYou grab what you have left from last week's paycheck to get on the bus.\nYou get off the bus and begin to walk. You spot a local Starbucks and order a grande latte with extra whipcream.\n\nThe barista tells you that whip cream is an extra 2.99\n\nCommence Battle!\n\n";
	
	formatPlayArea(LINES_SKIPPED);
	aPhase.display(player1, janice);



	

	

	

    return 0;
}

void formatPlayArea(int x) {
	for (int i = 0; i < x; i++) {
		std::cout << std::endl;
	}
	return;
}

void gameSetup(Player& player, Enemy& enemy) {
	Attack pAttack1("Punch", 1, 1, 1.0);
	Attack pAttack2("Punch", 1, 1, 1.0);
	Attack pAttack3("Punch", 1, 1, 1.0);
	Attack pAttack4("Punch", 1, 1, 1.0);
	player.setAttack(0,pAttack1);
	player.setAttack(1, pAttack2);
	player.setAttack(2, pAttack3);
	player.setAttack(4, pAttack4);

	Attack eAttack1("Punch", 1, 1, 1.0);
	Attack eAttack2("Punch", 1, 1, 1.0);
	Attack eAttack3("Punch", 1, 1, 1.0);
	Attack eAttack4("Punch", 1, 1, 1.0);
	player.setAttack(0, eAttack1);
	player.setAttack(1, eAttack2);
	player.setAttack(2, eAttack3);
	player.setAttack(4, eAttack4);

}
