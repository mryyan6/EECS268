#include <iostream>
#include <string>
#include <stdexcept>
#include "Stack.h"

template <typename T>
Stack<T>::Stack() 
{
    top = nullptr;
    m_size = 0;
}
template <typename T>
Stack<T>::~Stack() 
{
	Node<T>* temp;
    	while(top != nullptr) 
    	{
		temp = top;
		top = top->getNext();
		delete(temp);
	}
}
template <typename T>
bool Stack<T>::isEmpty() const 
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
template <typename T>
void Stack<T>::push(const T newEntry) 
{
	Node<T>* n;
	n = new Node<T>;
	n->setValue(newEntry);
	n->setNext(top);
	top = n;
	m_size++;
}

template <typename T>
void Stack<T>::pop() throw (PreconditionViolationException) 
{
	if(isEmpty() == true)
    {
        throw(PreconditionViolationException("Attempted to pop an empty list"));
    }
        Node<T>* front;
        front = top;
        top = top -> getNext();
        delete(front);
        m_size--;	
}

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if (m_size== 0)
	{
		throw PreconditionViolationException("");
	}
	return top->getValue();

}
template <typename T>
int Stack<T>::size() const 
{
	return m_size;
}

template <typename T>
void Stack<T>::print() const 
{
	if(m_size == 0)
	{
		std::cout << "";
	}

	else if(m_size != 0)
	{
		Node<T>* start;
		start = top;

		while(start != nullptr)
		{
			std::cout << start->getValue() << " ";
			start = start->getNext();
		}
	}
}


