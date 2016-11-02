/**
*DoubleLinkedlist.hpp
*Zack Mryyan
*9/30/2015
*Purpose: Implementation of the doublelinkedlist header.
*/
#include "Node.h"
#include <iostream>
#include <stdexcept>

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Node<T>* current;
	current = m_front;
	while(current)
	{
		m_front = current->getNext();
		delete current;
		current = m_front;
	}
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
	if (m_size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

template<typename T>
int DoubleLinkedList<T>::size() const
{
		return m_size;
}

template<typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	
	if (m_size == 0)
	{
		Node<T>* start; 
		start= new Node<T>;
		start->setValue(value);
		m_back = start;
		m_front = start;
	}
	
	else
	{
		Node<T>* start;
		start = new Node<T>;
		start->setValue(value);
		start->setNext(m_front);
		m_front->setPrevious(start);
		m_front = start;
	}
	m_size++;
}

template<typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
	
	if (m_size == 0)
	{
		Node<T>* start;
		start = new Node<T>;
		start->setValue(value);
		m_front = start;
		m_back = start;
	}
	
	else
	{
		Node<T>* start;
		start = new Node<T>;
		start->setValue(value);
		start->setPrevious(m_back);
		m_back->setNext(start);
		m_back = start;
	}
	m_size++;
}

template<typename T>
bool DoubleLinkedList<T>::removeBack()
{
	if(m_size == 0)
	{
		return(false);
	}
	Node<T>* start = m_back;
	m_back = start->getPrevious();
	if(m_back == nullptr)
	{
		m_front = nullptr;
	}
	else	
	{
		m_back->setNext(nullptr);
	}
	delete start;
	m_size--;
	return(true);
}

template<typename T>
bool DoubleLinkedList<T>::removeFront()
{
	if(m_size == 0)
	{
		return false;
	}
	Node<T>* start;
	start = m_front;
	m_front = start->getNext();
	if(m_front == nullptr)
	{
		m_back = nullptr;
	}
	else
	{	
		m_front->setPrevious(nullptr);
	}
	delete start;
	m_size--;
	return(true);
}

template<typename T>
bool DoubleLinkedList<T>::remove(T value)
{
	if (isEmpty())
	{
		return(false);
	}
	if (m_front->getValue() == value)
	{
		removeFront();
		return(true);
	}
	Node<T>* start;
	start = find(value);
	if (start == nullptr)
	{
		return(false);
	}
	else if(start->getNext() == nullptr)
	{
		removeBack();
		return(true);
	}
	Node<T>* prev;
	prev = start->getPrevious();
	Node<T>* next;
	next = start->getNext();
	prev->setNext(next);
	next->setPrevious(prev);
	delete start;
	m_size--;
	return true;
}

template<typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error)
{
	Node<T>* x;
	x = find(listValue);
	if(x == nullptr)
	{
		throw std::runtime_error("\nSorry, the value is not in the list. Try another value.");
	}
	else if (m_size == 1)
	{
		pushFront(newValue);
	}
	else if (m_front == x)
	{
		pushFront(newValue);
	}
	else
	{
		Node<T>* y;
		y = new Node<T>;
		y->setValue(newValue);
		Node<T>* prev = x->getPrevious();
		x->setPrevious(y);
		prev->setNext(y);
		y->setNext(x);
		y->setPrevious(prev);
		m_size++;
	}

	
}

template<typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error)
{
	Node<T>* x;
	x = find(listValue);
	
	if(x == nullptr)
	{
		throw std::runtime_error("\nSorry, the value is not in the list. Try another value.");
	}
	else if (m_size == 1)
	{
		pushBack(newValue);
	}
	else if (m_back == x)
	{
		pushBack(newValue);
	}
	else
	{
		Node<T>* y;
		y = new Node<T>;
		y->setValue(newValue);
		Node<T>* prev = x->getNext();
		x->setNext(y);
		prev->setPrevious(y);
		y->setPrevious(x);
		y->setNext(prev);
		m_size++;
	}

	
}

template<typename T>
Node<T>* DoubleLinkedList<T>:: find(T value) const
{
	Node<T>* start;
	start = m_front;
	if(start == nullptr)
	{
		return(start);
	}
	else
	{
		while(start != nullptr)
		{
			if(start->getValue() == value)
			{
				return(start);
			}
			start = start->getNext();
		}
	}	
	return(start);
}

template<typename T>
void DoubleLinkedList<T>:: printList() const
{
	if(m_size == 0)
	{
		std::cout << "";
	}

	else if(m_size != 0)
	{
		Node<T>* start;
		start = m_front;

		while(start != nullptr)
		{
			std::cout << start->getValue() << " ";
			start = start->getNext();
		}
	}
}
