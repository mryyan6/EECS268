/**
*	@file : BinarySearchTree.h
*	@author :  
*	@date : 11/11/2015
*	Purpose: binarysearchtree header
*/
#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "BSTI.h"
#include "Node.h"
#include <vector>


template<typename T>
class BinarySearchTree: public BSTI<T>
{
public:
	/**
	*  @pre None
	*  @post Empty search tree
	*  @return None
	*/
	BinarySearchTree();
	/**
	*  @pre None
	*  @post Search tree that is a copy passed as a parameter
	*  @return None
	*/
	BinarySearchTree(const BinarySearchTree<T>& other);
	/**
	*  @pre Search Tree
	*  @post Deletes search tree
	*  @return None
	*/
	~BinarySearchTree();
	/**
	*  @pre A search tree
	*  @post None
	*  @return A copy of the search tree
	*/
	BinarySearchTree<T>* clone();
	/**
	*  @pre Search Tree
	*  @post None
	*  @return true if tree is empty
	*/
	bool isEmpty() const;
	/**
	*  @pre Search Tree
	*  @post none
	*  @return true if value was able to be added
	*/
	bool add(T value);
	/**
	*  @pre Search Tree
	*  @post None
	*  @return true if value was able to be found
	*/
	bool search(T value) const;
	/**
	*  @pre Search Tree
	*  @post None
	*  @return vector containing all of the values in the tree
	*/
	std::vector<T> treeToVector(Order order) const;
	/**
	*  @pre Search Tree
	*  @post prints all value in specified order
	*  @return None
	*/
	void printTree(Order order) const;

private: 
	Node<T>* m_root;
	/**
	*  @pre Search Tree nodes
	*  @post Search tree with new value
	*  @return Search tree with new value
	*/
	bool add(T value, Node<T>* subtree);
	/**
	*  @pre Search Tree nodes
	*  @post deletes entire subtree
	*  @return None
	*/
	void deleteTree(Node<T>* subtree);
	/**
	*  @pre Search Tree nodes
	*  @post None
	*  @return true if value was able to be found
	*/
	bool search(T value, Node<T>* subtree) const;
	/**
	*  @pre Search Tree nodes
	*  @post prints tree in specified order
	*  @return None
	*/
	void printTree(Node<T>* subtree, Order order) const;
	/**
	*  @pre Search Tree nodes
	*  @post None
	*  @return vector containing all nodes
	*/
	std::vector<T> treeToVector(Order order, Node<T>* node, std::vector<T>& vector) const;
	
	
	
};
#include "BinarySearchTree.hpp"
#endif

