/**
*linkedlist.h
*Zack Mryyan
*9/24/2015
*Purpose: Header file of linkedlist class.
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class LinkedList
{
	public:
	/**
	*	@pre None
	*	@post creates a linked list
	*	@return initialized linked list
	*/
	LinkedList();
	/**
	*	@pre None
	*	@post no memory leaks
	*	@return reusable memory
	*/
	~LinkedList();
	/**
	*	@pre None
	*	@post None
	*	@return if empty true, otherwise false
	*/
	bool isEmpty() const;
	/**
	*	@pre None
	*	@post None
	*	@return size of the list
	*/
	int size() const;
	/**
	*	@pre unempty list
	*	@post None
	*	@return true if value was found, false if value was not found
	*/
	bool search(int value) const;
	/**
	*	@pre None
	*	@post Prints list of all the values
	*	@return None
	*/
	void printList() const;
	/**
	*	@pre value to add to the end 
	*	@post an added value to the end
	*	@return None
	*/
	void addBack(int value);
	/**
	*	@pre value to add to the front
	*	@post added value to the front
	*	@return None
	*/
	void addFront(int value);
	/**
	*	@pre None
	*	@post node at the back removed
	*	@return true if removed, false otherwise
	*/
	bool removeBack();
	/**
	*	@pre None
	*	@post node at the front removed
	*	@return true if removed, false otherwise
	*/
	bool removeFront();
	private:
	int m_size;
	Node* m_front;
};

#endif

