/*
* @file: 
* @author: Zack Mryyan
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
 
#include "Cow.h"
#include <string>

Cow::Cow()
{
    m_name = "Cow";
    m_sound = "Moo";
}

double Cow::getMilkProduced() const
{
    return(m_milkProduced);
}

void Cow::setMilkProduced(double gallons)
{
    if(gallons > 0)
    {
        m_milkProduced = gallons;
    }
    else
    {
        m_milkProduced = 0;
    }        
}
