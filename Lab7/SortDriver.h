#ifndef SORTDRIVER_H
#define SORTDRIVER_H
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include "Sorts.h"
class SortDriver
{
	public:
		static void run(int argc, char** argv);
		static void printHelpMenu();
	private:
		static bool isFileAccessible(std::string fileName);
		static bool isSortValid(std::string sortParameter);
		static bool areParametersValid(std::string sortName, std::string inputFileName);
		static int getFileCount(std::ifstream& inputFile);
		static int* createArray(std::ifstream& inputFile, int size);
		static void copyArray(int original[], int copy[], int size);
};
#endif
