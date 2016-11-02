/**
*	@file : node.pp
*	@author :  
*	@date : 11/11/2015
*	Purpose: implementation of node header
*/
template <typename T>
Node<T>::Node()
{
	m_left=nullptr;
	m_right=nullptr;
	m_value = T();
}
template <typename T>
Node<T>::Node(const Node<T>& other)
{
	m_left = nullptr;
	m_right = nullptr;
	m_value = other.getValue();
	if(other.getLeft() != nullptr )
	{
		m_left = new Node(*other.getLeft());
	}
	if(other.getRight() != nullptr )
	{
		m_right = new Node(*other.getRight());
	}
}
template <typename T>
T Node<T>::getValue() const
{
	return m_value;
}
template <typename T>
Node<T>* Node<T>::getLeft() const
{
	return m_left;
}
template <typename T>
Node<T>* Node<T>::getRight() const
{
	return m_right;
}
template <typename T>
void Node<T>::setRight(Node<T>* m_right)
{
	this->m_right=m_right;
}
template <typename T>
void Node<T>::setLeft(Node<T>* m_left)
{
	this->m_left=m_left;
}
template <typename T>
void Node<T>::setValue(T m_value)
{
	this->m_value=m_value;
}
template <typename T>
void Node<T>::printValue() const
{
	std::cout<< m_value<<" ";
}






