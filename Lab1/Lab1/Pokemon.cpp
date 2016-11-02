/*
Pokemon.cpp
EECS 268 Lab 1
This file handles the stats of the pokemon.
9/9/2015
*/
#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon()//sets stats to 0
{
	m_hp = 0;
	m_attackLevel = 0;
	m_defenseLevel = 0;
	std::string m_name = "";
}
void Pokemon::reduceHp(int amount)
{
	m_hp = m_hp - amount;
}
int Pokemon::getHp() const
{
    return(m_hp);
}
int Pokemon::getAttackLevel() const
{
    return(m_attackLevel);
}
int Pokemon::getDefenseLevel() const
{
    return(m_defenseLevel);
}
std::string Pokemon::getName() const
{  
    return(m_name);
}

void Pokemon::setHp(int a)
{
	m_hp = a;
}
void Pokemon::setAttackLevel(int b)
{
	m_attackLevel= b;
}
void Pokemon::setDefenseLevel(int c)
{
	m_defenseLevel= c;
}
void Pokemon::setName(std::string d)
{
	m_name = d;
}


