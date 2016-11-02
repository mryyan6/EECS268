/*
Colosseum.h
EECS 268 Lab 1
This file is handles the methods of Colosseum.cpp.
9/9/2015
*/
#ifndef COLOSSEUM_H
#define COLOSSEUM_H
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"
using namespace std;

class Colosseum
{
private:
	Dice d20;
	Dice d6;     
public:
	/**
	*  @pre None
	*  @post Creates and initializes a Dice instance
	*  @return Initialzed Dice with 6 sides and 20 sides
	*/	
	Colosseum();
	/**
	*  @pre None
	*  @post helps build the pokemon
	*  @return Stores the information about them
	*/
	void userBuild(Pokemon& p);
	/**
	*  @pre None
	*  @post sets up the attack
	*  @return if the pokemon is dead
	*/
	bool attack(const Pokemon& attacker, Pokemon& defender);
	/**
	*  @pre None
	*  @post handles the rounds
	*  @return if the game is over
	*/
	void play(Pokemon& p1, Pokemon& p2);
	/**
	*  @pre None
	*  @post None
	*  @return the value of dice d20
	*/
	int getd20();
	/**
	*  @pre None
	*  @post None
	*  @return the value of dice d6
	*/
	int getd6();
	
};
#endif
