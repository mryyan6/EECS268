/*
* @file: 
* @author: Zack Mryyan
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
#include <iostream>
#include <stdexcept>
#include "Cow.h"
#include "CyberChicken.h"
#include "AnimalPen.h"
#include "FarmAnimal.h"
#include "Chicken.h"
void printMenu()
{
	std::cout << "\n\nSelect from the following menu:\n"
			<< "1.) Cow (produces milk)\n"
			<< "2.) Chicken (cannot lay eggs)\n"
			<< "3.) Cyber Chicken (seems dangerous, but lays eggs)\n"
			<< "--------------------------------------------------\n"
			<< "choice: ";

}

void goodbyeMessage(const FarmAnimal& animal)

{
	std::cout  << "Upon release the " << animal.getName() << " said "  << animal.getSound() << "\n";
}

int main() 
{

	AnimalPen pen;
	FarmAnimal* fa;
	Cow* cow1;
	CyberChicken* cybchick1;
	int choice;
	double milk;
	double totalMilk = 0;
	int totalEggs = 0;
	std::string value;
	std::string result;
	std::string end = " ";

	while (end != "y") 
	{
		printMenu();
		std::cin >> choice;
		std::cout << "You chose: " << choice << "\n";

		if (choice == 1) 
		{
			Cow* cow2;
			cow2 = new Cow();
			std::cout << "how many gallons of milk did this cow produce?: \n";
			std::cin >> milk;
			cow2->setMilkProduced(milk);
			pen.addAnimal(cow2);
		}
		else if (choice == 2)
		{
			Chicken *chicken2 = new Chicken();
			std::cout << "Add an eggless chicken to the pen? OK. You're the boss. \n";
			pen.addAnimal(chicken2);
		}
		else if (choice == 3) 
		{
			CyberChicken *cybchick2 = new CyberChicken();
			std::cout << "How many eggs did this cyber chicken produce?: \n";
			std::cin >> choice;
			cybchick2->setCyberEggs(choice);
			pen.addAnimal(cybchick2);
		}
		std::cout << "Done adding animals? (y/n): ";
		std::cin >> end;
		std::cout << "\n";
	}

	std::cout << "\n\n";
	std::cout << "Releasing all animals!\n";
	std::cout << "-------------------------\n";

	while (pen.isEmpty() != true) 
	{
		fa = pen.peekAtNextAnimal();
		if (fa->getName() == "Cow")  
		{
			double milk = 0;
			cow1 = static_cast<Cow *>(fa);
			milk = cow1->getMilkProduced();
			std::cout << "This cow produced " << cow1->getMilkProduced() << " gallons of milk.\n";
			totalMilk = totalMilk + milk;
			goodbyeMessage(*fa);
		}
		if (fa->getName() == "Chicken")  
		{
			std::cout << "Chicken Destructor called\n";			
			std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help?\n";
			goodbyeMessage(*fa);
			std::cout << "Chicken Destructor called" << std::endl;	
		}
		if (fa->getName() == "Cyber Chicken")  
		{
			cybchick1 = static_cast<CyberChicken *>(fa);
			int eggs = cybchick1->getCyberEggs();
			std::cout << "This Cyber Chicken laid " << cybchick1->getCyberEggs() << " cyber eggs. Humanity is in trouble.\n";
			goodbyeMessage(*fa);
			totalEggs = totalEggs + eggs;
			std::cout << "CyberChicken Destructor is called\n";
		}
		pen.releaseAnimal();
	}
	std::cout << "Your farm produced " << totalMilk << " gallons of milk and " << totalEggs << " eggs.\n";
	return(0);
}
