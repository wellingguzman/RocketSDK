#ifndef ROCKET_STACK_H
#define ROCKET_STACK_H

#include "Node.h"

namespace Rocket
{

template <class T>
class Stack
{
private:
	Node<T> *head;
	Node<T> *current;
	Node<T> *tail;
	void addToHead(const T data);

public:
	Stack();
	~Stack();

	bool isEmpty() const;

	T back();
	void pop();
	void push(const T data);

	void free();
};


/**
* Definitions
*/

template <class T>
Stack<T>::Stack()
{
	this->head = this->current = this->tail = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	free();
}

template <class T>
T Stack<T>::back()
{
	return this->tail->data;
}

template <class T>
bool Stack<T>::isEmpty() const
{
	if ( this->head == NULL )
	{
		return true;
	}

	return false;
}

template <class T>
void Stack<T>::addToHead(const T data)
{
	Node<T> *newNode = new Node<T>;

	newNode->data = data;
	newNode->next = this->head;

	this->head = newNode;

	this->current = this->head;

	if ( this->tail == NULL )
	{
		this->tail = newNode;
	}
}

template <class T>
void Stack<T>::push(const T data)
{
	addToHead(data);
}

template <class T>
void Stack<T>::pop()
{
	if ( isEmpty() )
	{
		return;
	}

    head = head->next;

	this->current = head;

    if ( head == NULL )
	{
		tail = NULL;
	}
}

template <class T>
void Stack<T>::free()
{
	while ( !isEmpty() )
	{
		pop();
	}
}

}//end namespace Rocket

#endif