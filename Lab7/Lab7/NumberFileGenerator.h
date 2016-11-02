#ifndef NUMBERFILEGENERATOR
#define NUMBERFILEGENERATOR
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <random>
#include <cstdlib>

class NumberFileGenerator{

	public:
		static void ascending(std::string file, int amount);
		static void descending(std::string file, int amount);
		static void random(std::string file, int amount, int min, int max);
		static void singleValue(std::string file, int amount, int value);
};

#endif
