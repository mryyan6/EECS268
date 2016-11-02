#include "SortDriver.h"
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <random>
#include <cstdlib>
void SortDriver::run(int argc, char** argv)
{
	std::string sortName(argv[2]);
	std::string inputFile(argv[3]);
	if(areParametersValid(sortName, inputFile))
	{
		std::string inputAsString(argv[2]);
		std::string inFile(argv[3]);
		std::string outFile(argv[4]);
		std::ifstream input(inFile);
		std::ofstream output(outFile);
		int size = getFileCount(input);
		int* arr = createArray(input, size);
		std::cout<<"Calculating sort timing information...\n";
		if(inputAsString.compare("-bubble")==0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
			output<<"bubble "<<size<<" "<< timeTaken << "\n";
		}
		else if(inputAsString.compare("-selection")==0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, size);
			output<<"selection "<<size<<" "<< timeTaken << "\n";
		}
		else if(inputAsString.compare("-insertion")==0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr, size);
			output<<"insertion "<<size<<" "<< timeTaken << "\n";
		}
		else if(inputAsString.compare("-quick")==0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::quickSort, arr, size);
			output<<"quick "<<size<<" "<< timeTaken << "\n";
		}
		else if(inputAsString.compare("-quick3")==0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, arr, size);
			output<<"quick3 "<<size<<" "<< timeTaken << "\n";
		}
		else if(inputAsString.compare("-merge")==0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::mergeSort, arr, size);
			output<<"merge "<<size<<" "<< timeTaken << "\n";
		}
		else if(inputAsString.compare("-all")==0)
		{
			int arr2[size];
			int arr3[size];
			int arr4[size];
			int arr5[size];
			int arr6[size];
			copyArray(arr, arr2, size);
			copyArray(arr, arr3, size);
			copyArray(arr, arr4, size);
			copyArray(arr, arr5, size);
			copyArray(arr, arr6, size);
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
			output<<"Bubble Sort sort "<<size<<" numbers in "<< timeTaken << " seconds.\n";
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr2, size);
			output<<"Selection Sort sort "<<size<<" numbers in "<< timeTaken << " seconds.\n";
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr3, size);
			output<<"Insertion Sort sort "<<size<<" numbers in "<< timeTaken << " seconds.\n";
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::quickSort, arr4, size);
			output<<"Quick Sort sort "<<size<<" numbers in "<< timeTaken << " seconds.\n";
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, arr5, size);
			output<<"Quick Sort (with median) sort "<<size<<" numbers in "<< timeTaken << " seconds.\n";
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::mergeSort, arr6, size);
			output<<"Merge Sort sort "<<size<<" numbers in "<< timeTaken << " seconds.\n";
		}
		delete [] arr;
		input.close();
		output.close();
		std::cout<<"Calculations finished.  Results stored in "<<argv[4]<<".\n"<<"Exiting...\n";

	}
	else
	{
		printHelpMenu();
	}
}
bool SortDriver::isFileAccessible(std::string fileName)
{
	std::ifstream myFile(fileName);
	if(myFile.good())
	{
		return true;
	}
	return false;
}


bool SortDriver::isSortValid(std::string sortParameter)
{

	if(sortParameter.compare("-bubble")==0)
	{
		return true;
	}
	if(sortParameter.compare("-selection")==0)
	{
		return true;
	}
	if(sortParameter.compare("-insertion")==0)
	{
		return true;
	}
	if(sortParameter.compare("-quick")==0)
	{
		return true;
	}
	if(sortParameter.compare("-quick3")==0)
	{
		return true;
	}
	if(sortParameter.compare("-merge")==0)
	{
		return true;
	}
	if(sortParameter.compare("-all")==0)
	{
		return true;
	}
	return false;
}
bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
	if(!isSortValid(sortName))
	{
		std::cout<<"Invalid sort option\n";
		return false;
	}
	else if(!isFileAccessible(inputFileName))
	{
		std::cout<<"Invalid file name\n";
		return false;
	}
	return true;
}
int SortDriver::getFileCount(std::ifstream& inputFile)
{
	int temp;
	inputFile>>temp;
	return temp;
}
int* SortDriver::createArray(std::ifstream& inputFile, int size)
{	
	int* arr = new int[size];
	for(int i = 0; i< size; i++)
	{
		inputFile>>arr[i];
	}
	return arr;
}
void SortDriver::copyArray(int original[], int copy[], int size)
{
	for(int i = 0; i<size; i++)
	{
		copy[i] = original[i];
	}
}
void SortDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";

}
