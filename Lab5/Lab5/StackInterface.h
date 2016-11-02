/*
* @file: 
* @author
* @date: 10/20/2015
* @brief: Header for the AnimalPen class
*/
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
	 /**
	*@pre none
	*@post deletes stack
	*@return none
	*/
	virtual ~StackInterface(){};
	 /**
	*@pre none
	*@post none
	*@return true if is empty
	*/
	virtual bool isEmpty() const = 0;
	/**
	*@pre none
	*@post pushes value to top of stack
	*@return none
	*/
	virtual void push(const T newEntry) = 0;
	/**
	*@pre none
	*@post pops top on stack
	*@return none
	*/
	virtual void pop() throw(PreconditionViolationException) = 0;
	 /**
	*@pre none
	*@post peeked value on top
	*@return none
	*/
	virtual T peek() const throw(PreconditionViolationException) = 0;
	/**
	*@pre none
	*@post none
	*@return size of stack
	*/
	virtual int size() const = 0;
	 /**
	*@pre none
	*@post none
	*@return prints stack
	*/
	virtual void print() const = 0;
};
#endif
