/**
*main.cpp
*10/2/2015
*Purpose: interacts with the user to manipulate lists.
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include "Stack.h"
#include "Test.h"
#include "PreconditionViolationException.h"

void printMenu()
{
		std::cout
		 	<< "\n\nSelect an action:\n"
			<< "1) Add to stack 1\n"
			<< "2) See what is at the top of stack\n"
			<< "3) Print all stack\n"
			<< "4) Pop stack\n"
			<< "5) Quit\n"
 			<< "6) Run Tests\n"
			<< "Enter choice: ";
}

int main() 
{

int choice = 0;
int value;
int result;
StackInterface<int>* si = new Stack<int>();

do
{
	printMenu();
	std::cin >> choice;
	std::cout << "\nYou chose: " << choice << "\n";

	if (choice == 1) 
	{
		std::cout << "What is going in stack 1?: \n";
		std::cin >> value;
		si->push(value);
		std::cout << value << " successfully added to stack 1\n";
		
	}
	if (choice == 2)
	{
		try 
		{
			std::cout << "top of lane 1 is " << si->peek() << "\n";
		}
		catch  (PreconditionViolationException& e)
		{
			std::cout << "Exception: Peek attempted on empty stack\n"; 
		}
	}
	if (choice == 3) 
	{	 
		si->print();			
	}
	if (choice == 4) 
	{
		try
		{
			si->pop(); 
			
		}
		catch (PreconditionViolationException& e)
		{
			std::cout << " Exception: Pop attempted on empty stack\n";
		}
	}
	if (choice == 5) 
	{
		std::cout << "Program ending\n";
	}

	if (choice == 6) 
	{
		Test myTester(std::cout);
		myTester.runTests();
	}
	

}while (choice != 5);

si-> ~StackInterface<int>();
return(0); 
	
}
