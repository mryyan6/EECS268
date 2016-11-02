/*
* @file: MazeCreationException.h
* @author: Zack Mryyan
* @date: 2015.11.13
* @brief: 
*/
 
#ifndef MazeCreationException_h
#define MazeCreationException_h
#include <stdexcept>
#include <exception>

class MazeCreationException: public std::runtime_error
{
    public:
        MazeCreationException(const char* message);
};

#endif
