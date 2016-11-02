/**
*	@file : bsti.h
*	@author :  Zack Mryyan
*	@date : 11/11/2015
*	Purpose: bsti header
*/
#ifndef BSTI_h
#define BSTI_h
#include <vector>

enum Order{ PRE_ORDER=1, IN_ORDER, POST_ORDER };
template<typename T>
class BSTI
{
	public:
		/**  
		*  @pre BSTI
		*  @post Deletes BSTI
		*  @return None
		*/
		virtual ~BSTI(){};
		/**  
		*  @pre BSTI
		*  @post None
		*  @return copy of tree
		*/
		virtual BSTI<T>* clone() = 0;
		/**
		*  @pre Search Tree
		*  @post None
		*  @return true if tree is empty
		*/
		virtual bool isEmpty() const = 0;
		/**
		*  @pre Search Tree
		*  @post none
		*  @return true if value was able to be added
		*/
		virtual bool add(T value) = 0;
		/**
		*  @pre Search Tree
		*  @post None
		*  @return true if value was found
		*/
		virtual bool search(T value) const = 0;
		/**
		*  @pre Search Tree
		*  @post prints all values
		*  @return None
		*/
		virtual void printTree(Order order) const = 0;
		/**
		*  @pre Search Tree
		*  @post None
		*  @return vector containing all of the values in the tree
		*/
		virtual std::vector<T> treeToVector(Order order) const = 0;
};
#endif

