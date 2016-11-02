/*
* @file: 
* @author: 
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
 
#include "FarmAnimal.h"
#ifndef Chicken_h
#define Chicken_h
#include <string>

class Chicken: public FarmAnimal
{
    public:
         /**
	*@pre None
	*@post intializes chicken
	*@return initialized chicken
	*/
        Chicken();
        
    protected:
         /**
	*@pre set of eggs
	*@post none
	*@return number of eggs
	*/
        int getEggs() const;
         /**
	*@pre None
	*@post unprotects egg
	*@return unprotected egg
	*/
        void setEggs(int eggs);
        int m_eggs;
};

#endif
