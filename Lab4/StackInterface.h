#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "PreconditionViolationException.h"
template <class T>
class StackInterface
{
	public:
	virtual ~StackInterface(){};
	virtual bool isEmpty() const = 0;
	virtual void push(const T newEntry) = 0;
	virtual void pop() throw(PreconditionViolationException) = 0;
	virtual T peek() const throw(PreconditionViolationException) = 0;
	virtual int size() const = 0;
	virtual void print() const = 0;
};
#endif
