/*
* @file: 
* @author: Zack Mryyan
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/

#include "CyberChicken.h"
#include <string>
#include <iostream>

CyberChicken::CyberChicken()
{
    m_name = "Cyber Chicken";
    m_sound = "Resistance is futile";
}

int CyberChicken::getCyberEggs() const
{
    return(m_eggs);
}

void CyberChicken::setCyberEggs(int eggs)
{
    m_eggs = eggs;
}
