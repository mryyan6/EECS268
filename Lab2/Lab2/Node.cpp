/**
*Node.cpp
*9/24/2015
*Purpose: Uses node.h to implement the functions.
*/
#include "Node.h"
using namespace std;

Node::Node()
{
	m_value= 0;
	m_next = nullptr;	
}

int Node::getValue() const
{
	return(m_value);
}
void Node::setValue(int value)
{
	m_value = value;
}
Node* Node::getNext() const
{
	return(m_next);
}
void Node::setNext(Node* prev)
{
	m_next = prev;
}
