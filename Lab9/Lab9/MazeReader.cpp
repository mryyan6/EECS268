/*
* @file: MazeReader .cpp 
* @author: 
* @date: 2015.11.13
* @brief: 
*/

#include <fstream>
#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
    if(input.good() == true)
    {
        input.open(file);
        readMaze();
    }
    else
    {
        throw MazeCreationException("");
    }
}

MazeReader::~MazeReader()
{
    for(int i = 0; i < cols; i++)
    {
        delete(maze[i]);
    }
        delete(maze);
}

const char* const* MazeReader::getMaze() const
{
    const char* const* a = maze;
    return(a);
}

int MazeReader::getCols() const
{
    return(cols);
}

int MazeReader::getRows() const
{
    return(rows);
}

int MazeReader::getStartCol() const
{
    return(scol);
}

int MazeReader::getStartRow() const
{
    return(srow);
}
void MazeReader::readMaze() throw (MazeCreationException)
{
    
    input >> rows;
    input >> cols;
    input >> srow;
    input >> scol;
    if(rows < 1 || cols < 1)
    {
        throw(MazeCreationException(""));
    }
    if(srow >= rows || scol >= cols)
    {
        throw(MazeCreationException(""));
    }
    maze = new char*[rows];
    for(int i = 0; i < rows; i++)
    {
        maze[i] = new char[cols];
    }
    for(int i = 0; i < rows; i++)
    {
       for(int j = 0; j < cols; j++)
       {
          input >> maze[i][j];
       }
       
    }
}



