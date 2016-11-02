Lab07: main.o Test.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o
	g++ -g -std=c++11 -Wall main.o Test.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o -o Lab07

main.o: main.cpp SortDriver.h NumberFileDriver.h Test.h
	g++ -g -std=c++11 -Wall -c main.cpp

Test.o: Test.cpp Test.h Sorts.h Sorts.hpp
	g++ -g -std=c++11 -c Test.cpp
	
SortDriver.o: SortDriver.cpp Test.h Sorts.h Sorts.hpp
	g++ -g -std=c++11 -c SortDriver.cpp
	
NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -g -std=c++11 -c NumberFileGenerator.cpp
	
NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp NumberFileGenerator.h
	g++ -g -std=c++11 -c NumberFileDriver.cpp

clean:
		rm *.o Lab07
		echo clean rm done
