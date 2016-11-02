/*
* @file: 
* @author: Zack Mryyan
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
 
#ifndef AnimalPen_h
#define AnimalPen_h
#include "Stack.h"
#include "FarmAnimal.h"
#include "PreconditionViolationException.h"
#include <string>
#include <iostream>

class AnimalPen: public Stack<FarmAnimal*>
{
    public:
        /**
	*@pre None
	*@post Creates pen
	*@return An initialized pen
	*/
        AnimalPen();
        /**
	*@pre None
	*@post deletes animal pen
	*@return none
	*/
        ~AnimalPen();
         /**
	*@pre None
	*@post adds animal
	*@return initialized animal
	*/
        void addAnimal(FarmAnimal* animal);
         /**
	*@pre None
	*@post name of animal thats next
	*@return name of animal thats next
	*/
        FarmAnimal* peekAtNextAnimal();
         /**
	*@pre None
	*@post releases animal
	*@return none
	*/
        void releaseAnimal() throw(PreconditionViolationException);
         /**
	*@pre initialized pen
	*@post none
	*@return bool expression
	*/
        bool isPenEmpty();
        
};

#endif
