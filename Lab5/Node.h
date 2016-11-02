/**
*Node.h
*Zack Mryyan
*9/30/2015
*Purpose: Header file of Node class.
*/
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Node
{
	private:
	T m_value;
	Node<T>* m_previous;
	Node<T>* m_next;
	public:
	/**
	*@pre None
	*@post Creates a node
	*@return An initialized node
	*/
	Node();
	/**
	*@pre None
	*@post None
	*@return the value at that specific node
	*/
	T getValue() const;
	/**
	*@pre None
	*post None
	*@return the value of m_prev
	*/	
	Node<T>* getPrevious() const;
	/**
	*@pre None
	*@post None
	*@return the value of m_next
	*/
	Node<T>* getNext() const;
	/**
	*@pre value that to set the node to
	*@post value is in the node
	*@return None
	*/
	void setValue(T value);
	/**
	*	@pre None
	*	@post node is set to the previous node
	*	@return None
	*/
	void setPrevious(Node<T>* next);
	/**
	*@pre node that needs to be next
	*@post node is set to be next
	*@return None
	*/
	void setNext(Node<T>* previous);
	
};
#include "Node.hpp"
#endif
