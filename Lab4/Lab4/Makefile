Lab04: main.o PreconditionViolationException.o Test.o
	g++ -g -std=c++11 main.o PreconditionViolationException.o Test.o -o Lab04
main.o: main.cpp Node.h Node.hpp Stack.h Stack.hpp PreconditionViolationException.h StackInterface.h Test.h
	g++ -g -std=c++11 -c main.cpp
PrecondtionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -c PreconditionViolationException.cpp
Test.o: Test.h Test.cpp 
	g++ -g -std=c++11 -c Test.cpp
clean:
	rm *.o Lab04
	echo clean done	
