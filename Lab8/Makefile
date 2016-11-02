Lab08:main.o Test.o
	g++ -std=c++11 -g main.o Test.o -o Lab08

main.o: main.cpp BSTI.h Node.h BinarySearchTree.h  BinarySearchTree.hpp Node.hpp
	g++ -std=c++11 -g -c main.cpp
	
Test.o: Test.cpp
	g++ -std=c++11 -g -c Test.cpp
	
clean:
	rm *.o  Lab08
	echo clean rm done
	
