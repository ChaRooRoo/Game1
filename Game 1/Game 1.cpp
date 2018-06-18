// Game 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Characters.h"
#include <ctime>

#define LINES_SKIPPED 2
//void readStory(int x);


void formatPlayArea(int x);
void setUpAttacks(Characters& player, Characters& enemy);
void display(Characters& p, Characters& e);
int selectAttack();
bool attackLanded(int chance);
//void testHitChance();



int main()
{
	srand(unsigned int(time(NULL)));

	std::cout << "____Welcome to the Game!____\n\n";
	Player player1;
	StarbucksEmployee janice;
	

			//placeholder text
	std::cout << "It's a sunny day on Monday and " << player1.getCharacterName() << " decides to go for a walk...\n\nYou grab what you have left from last week's paycheck to get on the bus.\nYou get off the bus and begin to walk. You spot a local Starbucks and order a grande latte with extra whipcream.\n\nThe barista tells you that whip cream is an extra 2.99\n\nCommence Battle!\n\n";
	
	formatPlayArea(LINES_SKIPPED);
	setUpAttacks(player1, janice);
	bool battle = true;

	while(battle){

	display(player1, janice);
	Attack * attackChoice = &player1.getAttacks()[selectAttack()];
	std::cout << player1.getCharacterName() << " used " << attackChoice->getName() << "!\n";

	if (attackLanded(attackChoice->getHitChance())){
		player1.attack(attackChoice, janice);

	}

	std::cout <<"Battle?\n";
		std::cin >> battle;
	}
	
	

    return 0;
}

void formatPlayArea(int x) {
	for (int i = 0; i < x; i++) {
		std::cout << std::endl;
	}
	return;
}

void setUpAttacks(Characters& player, Characters& enemy) {
	Attack pAttack1("Punch", 1, 1, 100);
	Attack pAttack2("Punch", 1, 1, 1);
	Attack pAttack3("Punch", 1, 1, 1);
	Attack pAttack4("Punch", 1, 1, 1);
	player.setAttack(0, pAttack1);
	player.setAttack(1, pAttack2);
	player.setAttack(2, pAttack3);
	player.setAttack(3, pAttack4);

	Attack eAttack1("Punch", 1, 1, 1);
	Attack eAttack2("Punch", 1, 1, 1);
	Attack eAttack3("Punch", 1, 1, 1);
	Attack eAttack4("Punch", 1, 1, 1);
	enemy.setAttack(0, eAttack1);
	enemy.setAttack(1, eAttack2);
	enemy.setAttack(2, eAttack3);
	enemy.setAttack(3, eAttack4);

}

void display(Characters& p, Characters& e) {
	//remember any changes made with this pointer will create issues with the original player
	Attack *tempPtr = p.getAttacks();
	int magicTextIndent1 = p.getCharacterName().length() + 3;
	int magicTextIndent2 = e.getCharacterName().length() + 3;
		
		//Player Health and Magic BEG
	std::cout << p.getCharacterName() << "'s Health: ";
	p.displayHP();
	std::cout << std::endl << std::endl;
	for (int i = 0; i < magicTextIndent1; i++) {
		std::cout << " ";
	}
	std::cout << "Magic:  ";
	p.displayMP();
		// Player Health and Magic END
	std::cout << std::endl << std::endl;
			//Enemy Health and Magic BEG
	std::cout << e.getCharacterName() << "'s Health: ";
	e.displayHP();
	std::cout << std::endl << std::endl;
	for (int i = 0; i < magicTextIndent2; i++) {
		std::cout << " ";
	}
	std::cout << "Magic:  ";
	p.displayMP();
			//Enemy Health and Magic END


	std::cout << std::endl << std::endl << "\nEach \'|\' = 10pts\n";
	std::cout << "\n\t\tSELECT AN ATTACK\n"
	//to have horizontal row you must create a separate type of algorithm
	<< "______________________________________________________________\n\n\n";
	//This actually displays the content
	for (int i = 0; i < 4; i++) {
		std::cout << "[" << i + 1 << "]\t"
			<< tempPtr[i].getName() << std::endl << std::endl
			<< "\tMP Cost:" << tempPtr[i].getMPConsumption() << " "
			<< "\tDamage:" << tempPtr[i].getDamageDone() << " "
			<< "\tHit Chance:" << tempPtr[i].getHitChance() << std::endl << std::endl;
	}
	std::cout << "______________________________________________________________\n\n";
}

int selectAttack()
{
	int choice = 0;
	std::cout << "Please select which attack you would like to use: ";
	std::cout << ">";
	std::cin >> choice;
	while (choice <= 0 || choice > 4) {
		std::cin >> choice;
	}
	std::cout << std::endl;

	return choice;
}

bool attackLanded(int chancePercentage) {
	const int MAX_POSSIBLE = 100;
	int numberOfOccurrences = MAX_POSSIBLE / chancePercentage;
	int randomNumber = (rand() % MAX_POSSIBLE) + 1;
	if (randomNumber % numberOfOccurrences == 0) {
		return true;
	}
	return false;
}

//Test function
void testHitChance(){
bool repeat = true;
int c = 0;
	while (repeat) {
		std::cout << "\nPlease enter a hitChance:";
		std::cin >> c;
		if (attackLanded(c))
			std::cout << "Attack Landed\n";
		else
			std::cout << "Attack did not land\n";
		std::cout << "Repeat?\n:";
		std::cin >> repeat;

	}
}





