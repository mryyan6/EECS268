/**
*linkedlist.cpp
*Zack Mryyan
*9/24/2015
*Purpose: Uses linkedlist.h to implement the functions.
*/
#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()//initializes
{
	m_front = nullptr;
	m_size = 0;
}
LinkedList::~LinkedList()//deletes
{
	while(!isEmpty())
	{
		Node* temp;
		temp = m_front;
		m_front = m_front -> getNext();
		delete(temp);
	}
}
bool LinkedList::isEmpty() const//determines if it is empty
{
	if(m_front == nullptr)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}
int LinkedList::size() const//tells you the size
{
	return(m_size);
}
bool LinkedList::search(int value) const//searches for a value
{
	Node* start = m_front;
	int finish = false;
	while(finish == false && start != nullptr)
	{
		if(start->getValue() == value)
		{
			finish = true;
		}
		else
		{
			start = start->getNext();
		}
	}
	if(finish==true)
	{
		return(true);
	}
	else
	{
		return(false);
	}		
}
void LinkedList::printList() const//prints the list
{
	Node* start = m_front;
	if(start != nullptr)
	{
		cout << "\n";
		while(start !=nullptr)
		{
			cout<<start->getValue() << " ";
			start = start->getNext();
		}
		cout<< "\n";
	}
	else
	{
		cout << "";
	}		
}
void LinkedList::addBack(int value)//adds number to the back
{
	if(isEmpty() == true)
	{
		Node* x;
		x = new Node;
		x->setValue(value);
		x->setNext(m_front);
		m_front = x;
		m_size++;
	}
	else
	{Node* start = m_front;
	while(start->getNext() !=nullptr)
	{
		start = start->getNext();
	}
	Node* x;
	x = new Node;
	x->setValue(value);
	x->setNext(nullptr);
	start->setNext(x);
	m_size++;
	}
}
void LinkedList::addFront(int value)//adds number to the front
{
	Node* n;
	n = new Node;
	n->setValue(value);
	n->setNext(m_front);
	m_front = n;
	m_size++;
	
}
bool LinkedList::removeBack()//removes from the back
{
	Node* start;
	if(m_size == 0)
	{
		return(false);
	}
	else if(m_size == 1)
	{
		delete(m_front);
		m_front = nullptr;
		m_size--;
		return(true);
	}
	else
	{
		start = m_front;
		while(start->getNext()->getNext() != nullptr)
		{
			start = start->getNext();
		}
		delete(start->getNext());
		start->setNext(nullptr);
		m_size--;
		return(true);
	}
}
bool LinkedList::removeFront()//removes from the front
{
	Node* temp;
	if(m_size == 0)
	{
		return(false);
	}
	else if(m_size == 1)
	{
		delete(m_front);
		m_front = nullptr;
		m_size--;
		return(true);
	}
	else
	{
		temp = m_front;
		m_front = m_front->getNext();
		delete(temp);
		m_size--;
		return(true);
	}
}

