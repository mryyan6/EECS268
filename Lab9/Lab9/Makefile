Lab09: main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o Test.o
	g++ -std=c++11 -g main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o Test.o -o Lab09

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp 
	
MazeReader.o: MazeReader.cpp 
	g++ -std=c++11 -g -c MazeReader.cpp
	
MazeCreationException.o:  MazeCreationException.cpp
	g++ -std=c++11 -g -c MazeCreationException.cpp

MazeWalker.o: MazeWalker.cpp
	g++ -std=c++11 -g -c MazeWalker.cpp
	
Position.o: Position.cpp
	g++ -std=c++11 -g -c Position.cpp
	
Test.o: Test.cpp ArrayHelper.h ArrayHelper.hpp
	g++ -std=c++11 -g -c Test.cpp
	
clean:
	rm *.o Lab09
	echo clean done

