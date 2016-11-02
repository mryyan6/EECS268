/*
* @file: 
* @author: Zack Mryyan
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
 
#include "Chicken.h"
#include <string>

Chicken::Chicken()
{
    m_name = "Chicken";
    m_sound = "Cluck";
}

int Chicken::getEggs() const
{
    return(m_eggs);
}

void Chicken::setEggs(int eggs)
{
    m_eggs = eggs;
}
