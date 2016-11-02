#ifndef NUMBERFILEDRIVER
#define NUMBERFILEDRIVER
#include <string>
#include <iostream>
#include <string>
#include "NumberFileGenerator.h"
#include <cstdlib>
#include <fstream>

class NumberFileDriver
{
	public:
		static void run(int argc, char** argv);
		static void printHelpMenu();

	private:
		static bool isValidOption(std::string option);
};

#endif

