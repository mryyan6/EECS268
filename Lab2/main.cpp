/**
*main.cpp
*Zack Mryyan
*9/24/2015
*Purpose: Runs the program and interacts with the user.
*/
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Test.h"
using namespace std;

int main()
{
	LinkedList a;
	bool result;
	int choice;
	int value = 0;
	do 
	{
	cout<<"\n";
	cout<<"Select from the following menu:\n 1) Add to the front of the list\n 2) Add to the end of the list\n 3) Remove from front of the list\n 4) Remove from back of the list\n 5) Print the list\n 6) Search for value\n 7) Exit\n 8) Run tests\n Enter your choice: ";
	
	cin>>choice;
	cout<<"You chose: "<< choice << "\n";
	
		
	if(choice == 1)
	{
		cout << "Enter a value to add: ";
		cin >> value;
		a.addFront(value);
		cout << "Adding " << value << " to the list \n";
	}
	if (choice == 2)
	{
		cout << "Enter a value to add: ";
		cin >> value;
		a.addBack(value);
		cout << "Adding " << value << " to the list \n";
	}
	if (choice == 3) 
	{
		cout << "Attempting removal from front of list. \n";
		
		if(a.isEmpty() == false)
		{
			a.removeFront();
			cout<< "Removal successful. \n";
		}
		else
		{
			cout<< "There are no values to remove. \n";
		}
	}
	if (choice == 4) 
	{
		cout << "Attempting removal from back of list. \n";
		if(a.isEmpty()== false)
		{
			a.removeBack();
			cout<< "Removal successful. \n";
		}	
		else
		{
			cout<< "There are no more values to remove. \n";
		}
	}
	if (choice == 5) 
	{
		cout << "Printing list: ";
		a.printList();
		cout << "\n";
	}
	if (choice == 6) 
	{
		cout << "Enter a value to search for: ";
		cin >> value;
		cout << "Searching for " << value << "...\n";
		result = a.search(value);
		if (result) 
		{
			cout << value << " is in the list\n";
		}
		else 
		{
			cout << value << " is not in the list \n";
		}
	}
	if (choice == 7) 
	{
		cout << "Exiting... \n";
	}
	if (choice == 8) 
	{
		Test myTester(std::cout);
		myTester.runTests();
	}
	}while(choice!= 7);
return(0);

}
