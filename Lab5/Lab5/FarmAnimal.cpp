/*
* @file: 
* @author: 
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/

#include "FarmAnimal.h"
#include <string>

FarmAnimal::FarmAnimal()
{
    m_name = "unset";
    m_sound = "unset";
}

std::string FarmAnimal::getName() const
{
    return(m_name);    
}

void FarmAnimal::setName(std::string name)
{
    m_name = name;
}

std::string FarmAnimal::getSound() const
{
    return(m_sound);
}

void FarmAnimal::setSound(std::string sound)
{
    m_sound = sound;
}
