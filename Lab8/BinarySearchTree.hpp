/**
*	@file : BinarySearchTree.hpp
*	@author :  Zack Mryyan
*	@date : 11/11/2015
*	Purpose: implementation of node header
*/
template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root=nullptr;
}
template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	Node<T>* second = other.m_root;
	if(second==nullptr)
	{
		m_root = nullptr;
		return;
	}
	m_root = new Node<T>(*second);
}
template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	BinarySearchTree<T>::deleteTree(m_root);
}
template<typename T>
BinarySearchTree<T>* BinarySearchTree<T>::clone()
{
	return(new BinarySearchTree(*this));
}
template<typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	return (m_root == nullptr);
}
template<typename T>
bool BinarySearchTree<T>::add(T value)
{
	if(m_root == nullptr)
	{
		m_root = new Node<T>();
		m_root->setValue( value );
		return(true);
	}
	else
	{
		return(BinarySearchTree<T>::add(value, m_root));
	}
}
template<typename T>
bool BinarySearchTree<T>::search(T value) const
{
	if(m_root == nullptr)
	{
		return(false);
	}
	return(BinarySearchTree<T>::search(value, m_root));
}
template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree)
{
	if(subtree == nullptr)
	{
		return;
	}
	BinarySearchTree<T>::deleteTree(subtree->getLeft());
	BinarySearchTree<T>::deleteTree(subtree->getRight());
	delete subtree;
	return;
}
template<typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const
{
	std::vector<T> vector;
	treeToVector(order,m_root,vector);
	return vector;
}
template<typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order, Node<T>* node, std::vector<T>& vector) const
{
	if(order == PRE_ORDER)
	{
		vector.push_back(node->getValue());
		if(node->getLeft() != nullptr)
		{
			treeToVector(order, node->getLeft(), vector);
		}	
		if(node->getRight() != nullptr)
		{
			treeToVector(order, node->getRight(), vector);
		}
		
	}
	else if(order == IN_ORDER)
	{
		if(node->getLeft() != nullptr)
		{
			treeToVector(order, node->getLeft(), vector);
		}
		vector.push_back(node->getValue());
		if(node->getRight() != nullptr) 
		{
			treeToVector(order, node->getRight(), vector);
		}
	}
	else if(order == POST_ORDER)
	{
		if(node->getLeft() != nullptr)
		{
			treeToVector(order, node->getLeft(), vector);
		}
		if(node->getRight() != nullptr) 
		{
			treeToVector( order, node->getRight(), vector);
		}
		vector.push_back(node->getValue());
	}
	return vector;
}
template<typename T>
void BinarySearchTree<T>::printTree(Node<T>* node, Order order) const
{
	if(order == PRE_ORDER)
	{
		node->printValue();
		if(node->getLeft() != nullptr)
		{
			printTree(node->getLeft(), order);
		}
		if(node->getRight() != nullptr)
		{
			printTree(node->getRight(), order);
		}
	}
	else if(order == IN_ORDER)
	{	
		if(node->getLeft() != nullptr) 
		{
			printTree(node->getLeft(), order);
		}
		node->printValue();
		if(node->getRight() != nullptr)
		{
			printTree(node->getRight(), order);
		}
	}
	else if(order == POST_ORDER)
	{
		if(node->getLeft() != nullptr)
		{
			printTree(node->getLeft(), order);
		}
		if(node->getRight() != nullptr) 
		{
			printTree(node->getRight(), order);
		}
		node->printValue();
	}
}
template<typename T>
void BinarySearchTree<T>::printTree(Order order) const
{	
	BinarySearchTree<T>::printTree(m_root,order);
}
template<typename T>
bool BinarySearchTree<T>::search(T value, Node<T>* subtree) const
{
	if(subtree->getValue() == value) 
	{
		return(true);
	}
	if(value < subtree->getValue())
	{
		if(subtree->getLeft() == nullptr)
		{
			return(false);
		}
		else
		{
			return(BinarySearchTree<T>::search(value, subtree->getLeft()));
		}
	}
	else
	{
		if(subtree->getRight() == nullptr)
		{
			return(false);
		}
		else
		{
			return(BinarySearchTree<T>::search( value, subtree->getRight()));	
		}
	}
}
template<typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	if(value == subtree->getValue())
	{
		return(false);
	}
	if(value < subtree->getValue())
	{
		if(subtree->getLeft() == nullptr)
		{
			subtree->setLeft(new Node<T>());
			subtree->getLeft()->setValue(value);
			return(true);
		}
		else
		{
			return(BinarySearchTree<T>::add(value, subtree->getLeft()));
		}
	}
	else
	{
		if( subtree->getRight() == nullptr )
		{
			subtree->setRight(new Node<T>() );
			subtree->getRight()->setValue(value);
			return(true);
		}
		else
		{
			return(BinarySearchTree<T>::add(value, subtree->getRight()));
		}
	}
}
