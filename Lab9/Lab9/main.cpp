/*
* @file: main.cpp 
* @author:
* @date: 2015.11.13
* @brief: Driver for the mazerunner
*/

#include "MazeWalker.h"
#include "MazeReader.h"
#include "Test.h"
#include <string>
#include <iostream>
#include <random>
#include <cassert>
#include <functional>
#include <fstream>
#include <random>
#include <ctime>

int main(int argc, char** argv)
{
    if(argc == 3)
    {
        std::string search = argv[1];
        std::string file = argv[2];
        MazeReader mR(file);
        if(search == "-dfs") 
        {
            MazeWalker mW(mR.getMaze(),mR.getStartRow(),mR.getStartCol(),mR.getRows(),mR.getCols(),Search::DFS);
            mW.walkMaze();
            std::cout << "Starting position " << mR.getStartRow() << ", " << mR.getStartCol() << std::endl;
            std::cout << "Size: " << mR.getRows() << ", " << mR.getCols() << std::endl;
            mW.printVisited();
        }
        else
        {
            MazeWalker mW(mR.getMaze(),mR.getStartRow(),mR.getStartCol(),mR.getRows(),mR.getCols(),Search::BFS);
            mW.walkMaze();
            std::cout << "Starting position " << mR.getStartRow() << ", " << mR.getStartCol() << std::endl;
            std::cout << "Size: " << mR.getRows() << ", " << mR.getCols() << std::endl;
            mW.printVisited();
        }
    }
    else if(argc == 2)
    {
        Test myTest;
        myTest.runTests();
    }
    else
    {
        std::cout << "Valid command lines options are -dfs -bfs or -test";
    }
    
    return(0);
}











