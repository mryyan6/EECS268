/*
* @file: 
* @author: Zack Mryyan
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* message): std::runtime_error("Exception: ")
{
}
