/**
*	@file : main.cpp
*	@author :  Zack Mryyan
*	@date : 11/11/2015
*	Purpose: allows user to interact with the tree
*/
#include "Node.h"
#include "BSTI.h"
#include "Test.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <random>
#include <chrono>
#include <climits>
#include <string>
using namespace std;
void addRandomValues(BSTI<int>& bst, int amount)
{	
	int value;
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
	for(int i = 1; i<=amount; i++)
	{
		value = distribution(generator);
		bst.add(value);
	}
}
void printMenu()
{
	cout<< "\n\nInput a selection\n"
	<< "1) Add more values to original tree\n"
	<< "2) Copy the original tree\n"
	<< "3) Delete the original tree (one time only)\n"
	<< "4) Print original tree\n"
	<< "5) Print copy\n"
	<< "6) Search original tree\n"
	<< "7) Search copy\n"
	<< "8) Exit\n"
	<< "9) Run tests\n"
	<< "Your choice:\n"; 

}
void printSearchResult(int& value, bool found)
{
	if(found) cout<<value<<" was found in the tree.\n";
	else cout<<value<<" was not found in the tree.\n";

}
void printOrderMenu()
{
	cout<< "Input an order\n"
	<< "1) Post Order\n"
	<< "2) In Order\n"
	<< "3) Post Order\n";

}
void printError()
{
	cout<<"Invalid Command Line Argument.\n";
}
int main(int argc, char** argv)
{
	Test myTest;
	BSTI<int>* bst = nullptr;
	BSTI<int>* copy = nullptr;
	bool og = false;
	bool coppied = false;
	int choice;
	int amount;
	if( argc > 1)
	{
		std::string mode = argv[1];
		if( mode == "-nodes" )
		{
			if(argc == 3)
			{
				if( atoi(argv[2]) >= 0 )
				{
					bst = new BinarySearchTree<int>();
					og = true;
					addRandomValues((*bst),atoi(argv[2]));
				}
				else
				{
					printError();
					return 0;
				}
			}
			else if( argc != 3 )
			{
				printError();
				return 0;
			}
		}
		else if ( mode == "-test" )
		{
			myTest.runTests();
			return 0;
		}
		else
		{
			printError();
			return 0;
		}
	}
	if( argc == 1)
	{
		bst = new BinarySearchTree<int>();
		og = true;
	}
	while( choice != 8 )
	{
		printMenu();
		cin>>choice;
		if(choice==1)
		{
			cout<<"Input an amount of values to add: ";
			cin>>amount;
			addRandomValues((*bst),amount);
		}	
		if(choice==2)
		{
		 	if( bst == nullptr )
			{
				cout<<"No Original Exists to Copy"<<endl;
			}
			else
			{
				cout<<"Copying the original Tree.."<<endl;
				if(copy != nullptr) delete copy;
				copy = bst->clone();
				coppied = true;
				cout<<"Tree Copied."<<endl;
			}
		}				
		if(choice==3)
		{
			if(og)
			{
				cout<<"Deleting Original Tree.."<<endl;
				og=false;
				delete bst;
				bst=nullptr;
				cout<<"Tree Deleted."<<endl;
			}
			else
			{
				cout<<"Tree has already been deleted."<<endl;
			}
		}
		if(choice==4)
		{
			if( bst != nullptr)
			{
				printOrderMenu();
				cin>>amount;
				cout<<"Printing original Tree"<<endl;
				bst->printTree(static_cast<Order>(amount));
			}
			else
			{
				cout<<"The original does not exist to print"<<endl;
			}
		}
		if(choice==5)
		{
			if( copy != nullptr)
			{
				cout<<"Printing copied Tree"<<endl;
				printOrderMenu();
				cin>>amount;
				copy->printTree(static_cast<Order>(amount));
			}
			else
			{
				cout<<"No copy exists to print."<<endl;
			}
		}				
		if(choice==6)
		{
			if(og)
			{
				cout<<"Input a value to search for: "<<endl;
				cin>>amount;
				cout<<"Searching Original tree for "<<amount<<endl;
				printSearchResult( amount, bst->search(amount) );
			}
			else
			{
					cout<<"The original does not exist to search"<<endl;
			}
		}
		if(choice==7)
		{ 
			if(coppied)
			{
				cout<<"Input a value to search for: "<<endl;
				cin>>amount;
				cout<<"Searching Copied tree for "<<amount<<endl;
				printSearchResult( amount, copy->search(amount) );	
			}
			else
			{
				cout<<"The copy does not exist to search"<<endl;
			}
		}
		if(choice==8)		
		{
			cout<<"Exiting...."<<endl;
		}
		if (choice==9)
		{
			myTest.runTests();
		}				

	}
	if(bst != nullptr)
	{
	delete bst;
	}
	if(copy != nullptr)
	{
		delete copy;
	}
return 0;
}

