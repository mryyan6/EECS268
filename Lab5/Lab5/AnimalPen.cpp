/*
* @file: 
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
 
#include "AnimalPen.h"
#include <string>
#include <iostream>


AnimalPen::AnimalPen()
{
    
}


AnimalPen::~AnimalPen()
{

}


void AnimalPen::addAnimal(FarmAnimal* animal)
{
    push(animal);
}


FarmAnimal* AnimalPen::peekAtNextAnimal()
{
    return(peek());
}


void AnimalPen::releaseAnimal() throw(PreconditionViolationException)
{
     pop();
}


bool AnimalPen::isPenEmpty()
{
    return(isEmpty());
}
