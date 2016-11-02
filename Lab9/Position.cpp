/*
* @file: Position.cpp
* @author: Zack Mryyan
* @date: 2015.11.13
* @brief: 
*/

#include "Position.h"

Position::Position()
{
	m_row = 0;
	m_col = 0;
}

Position::Position(int row, int col)
{
    m_row = row;
    m_col = col;    
}

int Position::getRow() const
{
    return(m_row);    
}

int Position::getCol() const
{
    return(m_col);    
}

void Position::setRow(int row) 
{
    m_row = row;
}

void Position::setCol(int col)
{
    m_col = col;
}
