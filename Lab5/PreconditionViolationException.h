/*
* @file: 
* @author: Zack Mryyan
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H

#include <string>
#include <stdexcept>

class PreconditionViolationException: public std::runtime_error
{
	public:
	 /**
	*@pre none
	*@post gives you error message
	*@return none
	*/
	PreconditionViolationException(const char* message);
};

#endif
