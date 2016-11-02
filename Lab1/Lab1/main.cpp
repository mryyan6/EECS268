/*
main.cpp
EECS 268 Lab 1
This file is handles the heart of the program which runs it.
9/9/2015
*/
#include <iostream>
#include "Dice.h"
#include "Pokemon.h"
#include "Colosseum.h"
using namespace std;

int main()
{
	string again;
	do
	{	
		cout << "Player 1, build your Pokemon!\n";
		Colosseum arena;//calls upon the arena
		Pokemon p1;
		Pokemon p2;
		arena.userBuild(p1);//builds first pokemon
		cout << "Player 2, build your Pokemon!\n";
		arena.userBuild(p2);//builds second pokemon
		arena.play(p1,p2);//lets the game play
		cout << "Do you want to play again? (y/n): ";
		cin >> again;
		cout << "\n";
	}while (again == "y" || again == "Y");	//keeps the game going if user desires
	cout << "Thanks for playing!\n";
return(0);
}
