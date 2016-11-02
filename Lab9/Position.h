/*
* @file: Position.h 
* @author: Zack Mryyan
* @date: 2015.11.13
* @brief: 
*/

#ifndef Position_h
#define Position_h


class Position
{
    public:
        /**
	*    @post Position created with row and col values set.
	*/
        Position();
        /**
	*    @post Position created with row and col values set.
	*/
        Position(int row, int col);
        /**
	*	@return row value
	*/
        int getRow() const;
        /**
	*	@return col value
	*/
        int getCol() const;
        void setRow(int row);
        void setCol(int col);
        
    private:
        int m_row;
        int m_col;    
        
};

#endif
