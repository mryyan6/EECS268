/*
Colosseum.cpp
EECS 268 Lab 1
This file is handles the game play of the program. It will interact with the user and play rounds.
9/9/2015
*/
#include "Colosseum.h"
using namespace std;

Colosseum::Colosseum()
{
	d20 = Dice(20);
	d6 = Dice(6);
}
void Colosseum::userBuild(Pokemon& p)//lets players build their pokemon
{
	cout << "=====================\n";
	cout << "Please name your pokemon:";
	string p_name;
	cin >> p_name;
	p.setName(p_name);
	cout << "How many hitpoint will it have? (1-50):\n";
	int hp;
	cin >> hp;
	while(hp < 1 || hp > 50) 
	{
		cout << "Sorry the hitpoints must be between 1-50:\n";
		cin >> hp;
	}
	p.setHp(hp);
	cout << "Split fifty points between attack level and defense level\n";
	cout << "Enter your attack level (1-49):\n";
	int attack;
	cin >> attack;
	while(attack < 1 || attack > 49)
	{
		cout << "Sorry. The attack level must be between 1-49:\n";
		cin >> attack;	
	}
	p.setAttackLevel(attack);
	int totalD=(50-attack);
	cout << "Enter your defense level (1-" << totalD << "):\n";
	int defense;
	cin >> defense;
	while(defense < 1 || defense > totalD)
	{
		cout << "Sorry. The defense level must be between 1 and " << totalD << ":\n";
		cin >> defense; 	
	}
	p.setDefenseLevel(defense);
}
bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)//handles the attacking
{
	int attack_bonus = d20.roll();
	int defense_bonus = d20.roll();
	cout << attacker.getName() << " is attacking " << defender.getName() << endl;
	cout << attacker.getName() << " rolls an attack bonus of " << attack_bonus << endl;
	cout << defender.getName() << " rolls a defense bonus of " << defense_bonus << endl;
	if((attacker.getAttackLevel() + attack_bonus) > (defender.getDefenseLevel() + defense_bonus))
	{
		cout << "The attack hits dealing 3-D6 damage!\n";
		int d1 = d6.roll();
		int d2 = d6.roll();
		int d3 = d6.roll();
		int total = d1 + d2 + d3;
		cout << "The rolls are " << d1 << ", " << d2 << ", and " << d3 << " totaling: " << total << " damage!\n";	
		defender.reduceHp(total);
	
	if(defender.getHp() > 0)
	{
		cout << defender.getName() << " has " << defender.getHp() << " hit points left\n\n";
		
	}
	else if(defender.getHp()<=0)
	{
		cout << defender.getName() << " has been defeated!\n";
		return(true);  
	}
	}	
	else
	{
		cout << "The attack missed!\n\n";
	}
	
	if(defender.getHp() > 0)//checks to see if pokemon is dead
		{
			return(false);
		}	
	else
		{
			return(true);
		}
}
void Colosseum::play(Pokemon& p1, Pokemon& p2)//determines who goes first and regulates the rounds
{
	cout << "Chosing which player to go first:\n";
	Dice d2 = Dice(2);
	int first = d2.roll();
	if(first==1)
	{
		cout << "Player 1 will go first.\n\n";
	}
	else
	{
		cout << "Player 2 will go first.\n\n";
	}
	for( int x = 1; x <11; x++)
	{
		if(first==1)
		{	
			cout << "Round " << x << "!\n\n";
			if(Colosseum::attack(p1,p2)==true)
			{
				return;
			}
			if(Colosseum::attack(p2,p1)==true)
			{
				return;
			}
		}
	 	else
		{
			cout << "Round " << x << "!\n\n";
			if(Colosseum::attack(p2,p1)==true)
			{
				return;
			}
			if(Colosseum::attack(p1,p2)==true)
			{
				return;
			}
		}
	
	}
	cout << "Both players are still standing! It is a draw!\n";
	
}
