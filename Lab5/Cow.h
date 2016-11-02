/*
* @file: 
* @author: Zack Mryyan
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
 
#include "FarmAnimal.h"
#ifndef Cow_h
#define Cow_h
#include <string>
#include <iostream>

class Cow: public FarmAnimal
{
    public:
           /**
	   *@pre None
	   *@post intializes cow
	   *@return initialized cow
	   */
            Cow();
           /**
	   *@pre protected milk
	   *@post None
	   *@return amount of milk
	   */
            double getMilkProduced() const;
           /**
	   *@pre protected mik
	   *@post sets milk
	   *@return none
	   */
            void setMilkProduced(double gallons);
		
    protected:
        double m_milkProduced;

};

#endif
