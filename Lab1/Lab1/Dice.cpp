/*
Dice.cpp
EECS 268 Lab 1
This file is handles the dice.
9/9/2015
*/
#include "Dice.h"
using namespace std;

Dice::Dice() 
{ 
	m_numSides = 6;
	/** initialize random seed: */
	srand (time(NULL));//Old C style NULL
}


Dice::Dice(int numSides)
{
	m_numSides = numSides;
	/** initialize random seed: */
	srand (time(NULL));//Old C style NULL
}


int Dice::getNumSides()
{
	return(m_numSides);
}

int Dice::roll()
{
	
	/** Get back a pseudo-random number */
	return(rand()%m_numSides + 1);
}
