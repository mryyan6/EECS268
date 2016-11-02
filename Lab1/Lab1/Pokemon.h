/*
Pokemon.h
EECS 268 Lab 1
This file handles the methods of pokemon.cpp.
9/9/2015
*/
#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using namespace std;

class Pokemon
{
private:
	int m_hp;
	int m_attackLevel;
	int m_defenseLevel;
	std::string m_name;	
public:
	/*
	*  @pre none
	*  @post Creates and initializes a Pokemon instance
	*  @return Initialzed Pokemon with stats initialized to 0.
	*/
	Pokemon();
	/*
	*  @pre none
	*  @post Takes in data and subtracts it from the hp.
	*  @return New hp.
	*/
	void reduceHp(int amount);
	/*
	*  @pre hp between 1-50
	*  @post none
	*  @return Amount of hp left.
	*/
       	int getHp() const;       
       	/*
	*  @pre attack between 1-50
	*  @post none
	*  @return What the attack level is.
	*/	
	int getAttackLevel() const;
	/*
	*  @pre defense between 1-50
	*  @post none
	*  @return What the defense level is.
	*/
	int getDefenseLevel() const;
	/*
	*  @pre pokemon name
	*  @post none
	*  @return What the pokemon name is.
	*/
	std::string getName() const;
	/*
	*  @pre none
	*  @post Takes in data and subtracts it from the hp.
	*  @return New hp.
	*/
	void setHp(int a);	
	  	/*
	*  @pre attack between 1-50
	*  @post none
	*  @return What the attack level is.
	*/
	void setAttackLevel(int b);
	/*
	*  @pre defense between 1-50
	*  @post none
	*  @return What the defense level is.
	*/	
	void setDefenseLevel(int c);
	/*
	*  @pre pokemon name
	*  @post none
	*  @return What the pokemon name is.
	*/	
	void setName(std::string d);
	
};
#endif
