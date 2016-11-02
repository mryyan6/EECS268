/**
*DoubleLinkedList.hpp
*Zack Mryyan
*9/30/2015
*Purpose: Implementation of the node header.
*/
#include <iostream>
#include <string>
#include <stdexcept>


template <typename T>
Node<T>::Node()
{
	m_next= nullptr;
	m_previous= nullptr;
	m_value = T();
}
template <typename T>
T Node<T>::getValue() const
{
	return(m_value);
}
template <typename T>
Node<T>* Node<T>::getNext() const
{
    return(m_next);
}
template <typename T>
Node<T>* Node<T>::getPrevious() const
{
    return(m_previous);
}
template <typename T>
void Node<T>::setValue(T val)
{
    m_value = val;
}
template <typename T>
void Node<T>::setNext(Node<T>* next)
{
    m_next = next;
}
template <typename T>
void Node<T>::setPrevious(Node<T>* prev)
{
    m_previous = prev;
}
