Lab05: main.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o PreconditionViolationException.o
	g++ -std=c++11 -g main.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o PreconditionViolationException.o -o Lab05

main.o: main.cpp Cow.h CyberChicken.h FarmAnimal.h AnimalPen.h
	g++ -std=c++11 -g -c main.cpp Cow.cpp CyberChicken.cpp FarmAnimal.cpp AnimalPen.cpp

AnimalPen.o: AnimalPen.cpp AnimalPen.h Stack.h Stack.hpp Node.h Node.hpp PreconditionViolationException.h FarmAnimal.h
	g++ -std=c++11 -g AnimalPen.cpp PreconditionViolationException.cpp FarmAnimal.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -std=c++11 -g FarmAnimal.cpp

PreconditionViolationException: PrecondtionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g PreconditionViolationException.cpp

clean:
	rm *.o Lab05
	clean done

