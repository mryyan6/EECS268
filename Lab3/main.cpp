/**
*main.cpp
*Zack Mryyan
*9/30/2015
*Purpose: interacts with the user to manipulate lists.
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include "Test.h"

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove front value\n"
		<<	"6) remove back value\n"
		<<	"7) remove specific value\n"
		<<	"8) print list\n"
		<<	"9) Quit\n"
		<< 	"10) Run Tests\n"
		<< 	"Your choice: ";
}

int main()
{
	int choice;
	int value = 0;
	DoubleLinkedList<int> L;
	do
	{
	printMenu();
	std::cout<< "\n"<< "You chose: ";
	std::cin>> choice;
	if(choice == 1)
	{
            std::cout << "Give a value.\n";
            std::cin >> value;
            L.pushFront(value);
            std::cout << value << " added to the front of the list.";
        }
        if(choice == 2)
        {
            std::cout << "Give a value.\n";
            std::cin >> value;
            L.pushBack(value);
            std::cout << value << " added to the back of the list.";
        }
        if(choice == 3)
        {
            int listValue;
            int newValue;
            std::cout << "Give a value to insert.\n";
            std::cin >> newValue;
            std::cout << "Pick a value to insert behind.\n";
            std::cin >> listValue;
            std::cout << "Attempting to insert " << newValue << " behind \n" << listValue;
            if(L.isEmpty() == true)
            {
            	std::cout << "The value given isnt in the list. Insert failed.\n";
            }
            else
            {
            	L.insertAhead(listValue, newValue);
            	std::cout<<newValue << " inserted behind " << listValue;
            }
            
        }
        if(choice == 4)
        {
            int listValue;
            int newValue;
            std::cout << "Give a value to insert.\n";
            std::cin >> newValue;
            std::cout << "Pick a value to insert ahead of.\n";
            std::cin >> listValue;
            std::cout << "Attempting to insert " << newValue << " ahead of " << listValue;
            if(L.isEmpty() == true)
            {
            	std::cout << "The value given isnt in the list. Insert failed.";
            }
            else
            {
            	L.insertBehind(listValue, newValue);
            	std::cout<<newValue << " inserted ahead of " << listValue;
            }
        }
        if(choice == 5)
        {
            if(L.isEmpty() == true)
            {
                std::cout << "List empty.\n";
            }
            else
            {
                L.removeFront();
                std::cout << "Front of list removed.\n";
            }            
        }
        if(choice == 6)
        {
            if(L.isEmpty() == true)
            {
                std::cout << "List empty.\n";
            }
            else
            {
                L.removeBack();
                std::cout << "Back of list removed.\n";
            }
        }
        if(choice == 7)
        {
            std::cout << "Give a value to remove: ";
            std::cin >> value;
            std::cout << "You gave " << value << "\n";
            if(L.remove(value) == true)
            {
                std::cout << value << " removed from list.\n";
            }
            else
            {
                std::cout << value << " could not be removed from list.\n";
            }
        }
        if(choice == 8)
        {
            L.printList();
            std::cout << "\n";
        }
        if(choice == 9)
        {
            std::cout << "Program ending...\n";
        }
        if(choice == 10)
        {
            Test myTester(std::cout);
            myTester.runTests();
        }      
	}while(choice !=9);
L.~DoubleLinkedList();	
return(0);
}

