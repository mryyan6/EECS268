/**
*Node.h
*9/24/2015
*Purpose: Header file of node class.
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

class Node
{
	public:
	/**
	*	@pre None
	*	@post Creates a node
	*	@return initialized node
	*/
   
	Node();
	/**
	*	@pre value to set the node to
	*	@post The value is in the node
	*	@return None
	*/
	void setValue(int val);
	/**
	*	@pre None
	*	@post None
	*	@return the value at a certain node
	*/
	int getValue() const;
	/**
	*	@pre Node that needs to be next
	*	@post node is set to be next
	*	@return None
	*/
	void setNext(Node* prev);
	/**
	*	@pre None
	*	@post None
	*	@return the value of next node
	*/
	Node* getNext() const;
	private:
	int m_value;
	Node* m_next;
};

#endif 
