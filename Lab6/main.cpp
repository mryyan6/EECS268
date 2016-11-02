/*
* @file: main.cpp
* @author: Zack Mryyan
* @date: 10/28/2015
* @brief: interacts with the user and gets valid inputs to create arrays and sort them
*/
#include "Sorts.h"
#include "Test.h"
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>

void printMenu()
{
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "5) Run Tests\n"
			<< "Enter choice: ";
}
void printArray(int* arr, int size)
{
	std::cout << "[";
	for(int i = 0; i < size; i++)
	{
		std::cout << arr[i];
		if(i + 1 != size)
		{
			std::cout << ", ";
                }
        }
	std::cout << "]\n";    
}
int main()
{
	int choice;	
	int size;
	int upper;
	int lower;
	double time;
	std::string end = " ";
	std::string print = " ";
	int* arr = nullptr;
	Sorts<int> sort;
	do
	{
		printMenu();
		std::cin>>choice;
		if(choice==5)
            	{
            		Test myTester(std::cout);
            		std::cout << "Running tests.\n";
           		myTester.runTests();
           		break;
            	}
		std::cout<< "Input a size for the random array:\n";
		std::cin>>size;
		std::cout<< "Input a lower bound on the range of random numbers:\n";
		std::cin>>lower;
		std::cout<< "Input an upper bound on the range of numbers:\n";
		std::cin>>upper;
		if(choice==1)
		{
			arr = sort.createTestArray(size, lower, upper);
			std::cout<< "Do you want to print the unsorted array? (y/n):\n";
			std::cin>>print;
			if(print == "y")
			{
				std::cout << "Here is the unsorted array: \n";
				printArray(arr,size);
			}
			std::cout << "\nSorting with bubble sort...\n";
			time = sort.sortTimer(sort.bubbleSort, arr, size);
			std::cout << "Do you want to print the sorted array? (y/n): ";
            		std::cin >> print;
            		if(print == "y")
            		{
                		std::cout << "Here is the sorted array: \n";
                		printArray(arr, size);
            		}
            	std::cout << size << " numbers were sorted in " << time << " seconds\n";		}
            	else if(choice==2)
            	{
			arr = sort.createTestArray(size, lower, upper);
			std::cout<< "Do you want to print the unsorted array? (y/n):\n";
			std::cin>>print;
			if(print == "y")
			{
				std::cout << "Here is the unsorted array: \n";
				printArray(arr,size);
			}
			std::cout << "\nSorting with insertion sort...\n";
			time = sort.sortTimer(sort.insertionSort, arr, size);
			std::cout << "Do you want to print the sorted array? (y/n): ";
            		std::cin >> print;
            		if(print == "y")
            		{
                		std::cout << "Here is the sorted array: \n";
                		printArray(arr, size);
            		}
            	std::cout << size << " numbers were sorted in " << time << " seconds\n";		}
            	else if(choice==3)
            	{
			arr = sort.createTestArray(size, lower, upper);
			std::cout<< "Do you want to print the unsorted array? (y/n):\n";
			std::cin>>print;
			if(print == "y")
			{
				std::cout << "Here is the unsorted array: \n";
				printArray(arr,size);
			}
			std::cout << "\nSorting with selection sort...\n";
			time = sort.sortTimer(sort.selectionSort, arr, size);
			std::cout << "Do you want to print the sorted array? (y/n): ";
            		std::cin >> print;
            		if(print == "y")
            		{
                		std::cout << "Here is the sorted array: \n";
                		printArray(arr, size);
            		}
            	std::cout << size << " numbers were sorted in " << time << " seconds\n";		}
            	else if(choice==4)
            	{
			arr = sort.createTestArray(size, lower, upper);
			std::cout<< "Do you want to print the unsorted array? (y/n):\n";
			std::cin>>print;
			if(print == "y")
			{
				std::cout << "Here is the unsorted array: \n";
				printArray(arr,size);
			}
			std::cout << "\nSorting with bogo sort...\n";
			time = sort.sortTimer(sort.bogoSort, arr, size);
			std::cout << "Do you want to print the sorted array? (y/n): ";
            		std::cin >> print;
            		if(print == "y")
            		{
                		std::cout << "Here is the sorted array: \n";
                		printArray(arr, size);
            		}
            	std::cout << size << " numbers were sorted in " << time << " seconds\n";		}
		std::cout<< "Do you want to quit? (y/n):";
		std::cin>>end;
	}while(end !="y");
delete(arr);
return(0);
}
