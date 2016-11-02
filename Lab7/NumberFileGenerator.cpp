#include "NumberFileGenerator.h"
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <random>
#include <cstdlib>
void NumberFileGenerator::ascending(std::string file, int amount)
{
	std::ofstream outFile(file);
	outFile<<amount<<"\n";
	for(int i = 0; i<amount; i++)
	{
		if(i!=amount-1)
		outFile<<i<<"\n";
		else
		outFile<<i;
	}
	outFile.close();
}
void NumberFileGenerator::descending(std::string file, int amount)
{
	std::ofstream outFile(file);
	outFile<<amount<<"\n";
	for(int i = amount; i>0; i--)
	{
		if(i!=1)
		outFile<<i<<"\n";
		else
		outFile<<i;
	}
	outFile.close();
}
void NumberFileGenerator::random(std::string file, int amount, int min, int max)
{
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distr(min, max-1);
	std::ofstream outFile(file);
	outFile<<amount<<"\n";
	for(int i = 0; i<amount; i++)
	{
		if(i!=amount-1)
		outFile<<distr(generator)<<"\n";
		else
		outFile<<i;
		outFile<<distr(generator);
	}
	outFile.close();
}
void NumberFileGenerator::singleValue(std::string file, int amount, int value)
{
	std::ofstream outFile(file);
	outFile<<amount<<"\n";
	for(int i = 0; i<amount; i++)
	{
		if(i!=amount-1)
		outFile<<value<<"\n";  //write to file
		else
		outFile<<value;
	}
	outFile.close();
}

