/*
* @file: 
* @author: 
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
 
#include "FarmAnimal.h"
#include "Chicken.h"
#ifndef CyberChicken_h
#define CyberChicken_h
#include <string>
#include <iostream>

class CyberChicken: public Chicken
{
    public:
        /**
	*@pre None
	*@post intializes cyber chicken
	*@return initialized cow
	*/
        CyberChicken();
        /**
	*@pre protected eggs
	*@post None
	*@return amount of eggs
	*/
        int getCyberEggs() const;
        /**
	*@pre protected eggs
	*@post sets eggs
	*@return none
	*/
        void setCyberEggs(int eggs);
        
};

#endif
