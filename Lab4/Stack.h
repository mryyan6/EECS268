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
		~Stack();
		bool isEmpty() const;
		void push(const T newEntry);
		void pop() throw(PreconditionViolationException);
		T peek() const throw(PreconditionViolationException);
		int size() const;
		void print() const;
		Stack();
	private:
		Node<T>* top;
		int m_size;
};
#include "Stack.hpp"
#endif
