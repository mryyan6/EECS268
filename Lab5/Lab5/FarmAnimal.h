/*
* @file: 
* @author:
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
#ifndef FarmAnimal_h
#define FarmAnimal_h
#include <string>
#include <iostream>

class FarmAnimal
{
    public:
        /**
	*@pre None
	*@post Creates farm animal
	*@return An initialized farm animal
	*/
        FarmAnimal();
        /**
	*@pre protected name
	*@post None
	*@return name
	*/
        std::string getName() const;
         /**
	*@pre protected name
	*@post sets name
	*@return none
	*/
        void setName(std::string name);
        /**
	*@pre protected sound
	*@post None
	*@return sound
	*/
        std::string getSound() const;
         /**
	*@pre protected sound
	*@post sets sound
	*@return none
	*/
        void setSound(std::string sound);        

    protected:
        std::string m_name;
        std::string m_sound;
    
};

#endif
