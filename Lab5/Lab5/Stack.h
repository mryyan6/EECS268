/*
* @file: 
* @author: 
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
#ifndef STACK_H
#define STACK_H
#include <string>
#include <iostream>
#include <stdexcept>
#include "Node.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"

template <class T>
class Stack: public StackInterface<T>
{
	public:
		 /**
		*@pre none
		*@post deletes stack
		*@return none
		*/
		~Stack();
		 /**
		*@pre none
		*@post none
		*@return true if is empty
		*/
		bool isEmpty() const;
		/**
		*@pre none
		*@post pushes value to top of stack
		*@return none
		*/
		void push(const T newEntry);
		 /**
		*@pre none
		*@post pops top on stack
		*@return none
		*/
		void pop() throw(PreconditionViolationException);
		 /**
		*@pre none
		*@post peeked value on top
		*@return none
		*/
		T peek() const throw(PreconditionViolationException);
		/**
		*@pre none
		*@post none
		*@return size of stack
		*/
		int size() const;
		 /**
		*@pre none
		*@post none
		*@return prints stack
		*/
		void print() const;
		 /**
		*@pre none
		*@post initializes stack
		*@return initialized stack
		*/
		Stack();
	private:
		Node<T>* top;
		int m_size;
};
#include "Stack.hpp"
#endif
