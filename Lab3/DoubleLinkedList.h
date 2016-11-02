/**
*DoubleLinkedlist.h
*Zack Mryyan
*9/30/2015
*Purpose: Header file of DoubleLinkedlist class.
*/

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include "Node.h"
#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class DoubleLinkedList
{
	private:
	Node<T>* m_front;
	Node<T>* m_back;
	int m_size;
	public:
	/**
	*@pre None
	*@post creates a linked list
	*@return an initialized linked list
	*/
	DoubleLinkedList();
	/**
	*@pre None
	*@post no memory leaks
	*@return memory that can be used again
	*/
	~DoubleLinkedList();
	/**
	*@pre None
	*@post None
	*@return if empty true, if contains values false
	*/
	bool isEmpty() const;
	/**
	*@pre None
	*@post None
	*@return size of the list
	*/
	int size() const;
	/**
	*@pre value to add to the front of the list
	*@post added value to the front of the list
	*@return None
	*/
	void pushFront(T value);
	/**
	*@pre value to add to the end of the list
	*@post an added value in the end of the list
	*@return None
	*/
	void pushBack(T value);
	bool removeBack();
	bool removeFront();
	/**
	*@pre None
	*@post Linked list with the node at the back removed
	*@return true if removed, false otherwise
	*/
	bool remove(T value);
	/**
	*@pre new value to be added and the list value for where it should be added
	*@post added new value behind the list value
	*@return None
	*/
	void insertAhead(T listValue, T newValue) throw(std::runtime_error);
	/**
	*@pre new value to be added and the list value for where it should be added ahead
	*@post added new value ahead of the list value
	*@return None
	*/
	void insertBehind(T listValue, T newValue) throw(std::runtime_error);
	/**
	*@pre value to search for
	*@post None
	*@return true if value found, false if value wasnt found
	*/
	Node<T>* find(T value) const;
	/**
	*@pre None
	*@post Printed list of all values
	*@return None
	*/
	void printList() const; 
};
#include "DoubleLinkedList.hpp"
#endif

