/**
*	@file : node.pp
*	@author :  Zack Mryyan
*	@date : 11/11/2015
*	Purpose: node header
*/
#ifndef Node_h
#define Node_h

#include <iostream>

template <typename T>
class Node
{
	public:
		/**
		*  @pre None
		*  @post single Node
		*  @return None
		*/
		Node();
		/**
		*  @pre None
		*  @post Copy of node passed in
		*  @return None
		*/
		Node(const Node<T>& other);
		/**
		*  @pre a Node
		*  @post value placed in node
		*  @return None
		*/
		void setValue(T m_value);
		/**
		*  @pre a Node
		*  @post None
		*  @return value in the node
		*/
		T getValue() const;
		/**
		*  @pre a Node
		*  @post None
		*  @return Pointer to the left.
		*/
		Node<T>* getLeft() const;
		/**
		*  @pre a Node
		*  @post None
		*  @return Pointer to the right.
		*/
		Node<T>* getRight() const;
		/**
		*  @pre a Node
		*  @post a Node with a left pointer
		*  @return None
		*/
		void setLeft(Node<T>* m_Left);
		/**
		*  @pre a Node
		*  @post a Node with a right pointer
		*  @return None
		*/
		void setRight(Node<T>* m_Right);
		/**
		*  @pre a Node
		*  @post prints the value in the node
		*  @return None
		*/
		void printValue() const;

	private:
		T m_value;
		Node<T>* m_left;
		Node<T>* m_right;
};
#include "Node.hpp"
#endif 


