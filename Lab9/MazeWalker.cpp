/*
* @file: MazeWalker.h 
* @author: Zack Mryyan
* @date: 2015.11.13
* @brief: 
*/

#include "MazeWalker.h"

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice): m_curPos(startRow, startCol), m_startPos(startRow, startCol)
{
    m_rows = rows;
    m_cols = cols;
    m_maze = mazePtr;
    m_visited = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        m_visited[i] = new int[cols];
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            m_visited[i][j] = 0;
        }
    }    
    if(searchChoice == Search::DFS)
    {
        m_searchType = Search::DFS;
    }
    else
    {
        m_searchType = Search::BFS;
    }
}
MazeWalker::~MazeWalker()
{
    
}
const int* const* MazeWalker::getVisited() const
{
    return(m_visited);
}

int MazeWalker::getVisitedRows() const
{
    return(m_rows);
}

int MazeWalker::getVisitedCols() const
{
    return(m_cols);
}
const char* const* MazeWalker::getMaze() const
{
    return(m_maze);
}
void MazeWalker::storeValidMoves()
{
    Position pos;
    if(m_searchType == Search::DFS) 
    {
        if(m_curPos.getRow() > 0 && m_maze[m_curPos.getRow()-1][m_curPos.getCol()] != 'W' && m_visited[m_curPos.getRow()-1][m_curPos.getCol()] == 0) 
        {
            pos.setRow(m_curPos.getRow()-1);
            pos.setCol(m_curPos.getCol());
            m_moveStack.push(pos);
        }
        if(m_curPos.getCol() < m_cols-1 && m_maze[m_curPos.getRow()][m_curPos.getCol()+1] != 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()+1] == 0) 
        {
            pos.setRow(m_curPos.getRow());
            pos.setCol(m_curPos.getCol()+1);
            m_moveStack.push(pos);
        }
        if(m_curPos.getRow() < m_rows-1 && m_maze[m_curPos.getRow()+1][m_curPos.getCol()] != 'W' && m_visited[m_curPos.getRow()+1][m_curPos.getCol()] == 0) 
        {
            pos.setRow(m_curPos.getRow()+1);
            pos.setCol(m_curPos.getCol());
            m_moveStack.push(pos);
        }   
        if(m_curPos.getCol() > 0 && m_maze[m_curPos.getRow()][m_curPos.getCol()-1] != 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()-1] == 0) 
        {
            pos.setRow(m_curPos.getRow());
            pos.setCol(m_curPos.getCol()-1);
            m_moveStack.push(pos);
        }
    }
    else
    {
        if(m_curPos.getRow() > 0 && m_maze[m_curPos.getRow()-1][m_curPos.getCol()] != 'W' && m_visited[m_curPos.getRow()-1][m_curPos.getCol()] == 0) 
        {
            pos.setRow(m_curPos.getRow()-1);
            pos.setCol(m_curPos.getCol());
            m_moveQueue.push(pos);
        }
        if(m_curPos.getCol() < m_cols-1 && m_maze[m_curPos.getRow()][m_curPos.getCol()+1] != 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()+1] == 0) 
        {
            pos.setRow(m_curPos.getRow());
            pos.setCol(m_curPos.getCol()+1);
            m_moveQueue.push(pos);
        }
        if(m_curPos.getRow() < m_rows-1 && m_maze[m_curPos.getRow()+1][m_curPos.getCol()] != 'W' && m_visited[m_curPos.getRow()+1][m_curPos.getCol()] == 0) 
        {
            pos.setRow(m_curPos.getRow()+1);
            pos.setCol(m_curPos.getCol());
            m_moveQueue.push(pos);
        }   
        if(m_curPos.getCol() > 0 && m_maze[m_curPos.getRow()][m_curPos.getCol()-1] != 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()-1] == 0) 
        {
            pos.setRow(m_curPos.getRow());
            pos.setCol(m_curPos.getCol()-1);
            m_moveQueue.push(pos);
        }
    }   
}
void MazeWalker::printVisited() 
{
    for(int i = 0; i < m_rows; i++) 
    {
        for(int j = 0; j < m_cols; j++) 
        {
            std::cout << m_visited[i][j] << "   ";
        }
            std::cout << "\n";
    }
}
bool MazeWalker::walkMaze()
{
    m_curStep = 1;
    if(m_searchType == Search::DFS)
    {
        int end = 0;
        m_moveStack.push(m_curPos);
        m_visited[m_startPos.getRow()][m_startPos.getCol()] = m_curStep;
        while(!m_moveStack.empty() && end != 1) 
        {
            if(isGoalReached() == false && m_moveStack.empty() == false) 
            {
                storeValidMoves();
                move(m_moveStack.top());
                m_moveStack.pop();
            }
            else
            {
                std::cout << "We escaped!" << std::endl;
                end = 1;
                return(true);
            }
        }
        if(end == 0) 
        {
            std::cout << "No way out!" << std::endl;
            return(false);
        }
    }
    else
    {
        int end = 0;
        m_moveQueue.push(m_curPos);
        m_visited[m_curPos.getRow()][m_curPos.getCol()] = m_curStep;
        while(!m_moveQueue.empty() && end != 1) 
        {
            if(isGoalReached() == false && m_moveQueue.empty() == false) 
            {
                storeValidMoves();
                move(m_moveQueue.front());
                m_moveQueue.pop();
            }
            else
            {
                std::cout << "We escaped!" << std::endl;
                end = 1;
                return(true);
            }
        }
        if(end == 0) 
        {
            std::cout << "No way out!" << std::endl;
            return(false);
        }
    }
        
}
void MazeWalker::move(Position& p)
{
    m_curPos = p;
    if(m_visited[p.getRow()][p.getCol()] == 0)
    {
        m_curStep++;
        m_visited[p.getRow()][p.getCol()] = m_curStep;
    }        
}
bool MazeWalker::isGoalReached() const
{
    if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E')
    {
        return(true);
    }
    else
    {
        return(false);
    }
}



