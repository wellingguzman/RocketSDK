#ifndef ROCKET_NODE_H
#define ROCKET_NODE_H

namespace Rocket
{

template<class T>
class Node
{
public:
	Node<T> *next;
	Node<T> *previous;

	T data;

	Node();
	Node(T data);
	~Node();
};

template<class T>
Node<T>::Node()
{
	next = NULL;
	previous = NULL;
}

template<class T>
Node<T>::Node(T data)
{
	next = NULL;
	previous = NULL;
	this->data = data;
}

}// end namespace Rocket

#endif