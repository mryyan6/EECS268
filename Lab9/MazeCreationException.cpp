/*
* @file: MazeCreationException.cpp 
* @author: Zack Mryyan
* @date: 2015.11.13
* @brief: 
*/

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message) : runtime_error(message)
{
    
}
