#ifndef ROCKET_LIST_H
#define ROCKET_LIST_H

#include "Node.h"

namespace Rocket
{

template <class T>
class List
{
private:
	Node<T> *head;
	Node<T> *current;
	Node<T> *tail;

public:
	List();
	~List();

	Node<T>* getListHead();
	Node<T>* getListTail();
	Node<T>* getCurrent();

	bool isEmpty() const;
	void addToHead(const T data);
	void addToTail(const T data);

	void removeFromHead();

	int count();
	void print();

	void free();
};


/**
* Definitions
*/

template <class T>
List<T>::List()
{
	this->head = this->current = this->tail = NULL;
}

template <class T>
List<T>::~List()
{
	free();
}

template <class T>
Node<T>* List<T>::getListHead()
{
	return this->head;
}

template <class T>
Node<T>* List<T>::getListTail()
{
	return this->tail;
}

template <class T>
Node<T>* List<T>::getCurrent()
{
	return this->current;
}

template <class T>
bool List<T>::isEmpty() const
{
	if ( this->head == NULL )
	{
		return true;
	}

	return false;
}

template <class T>
void List<T>::addToHead(const T data)
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
void List<T>::addToTail(const T data)
{
	if ( isEmpty() )
	{
		addToHead(data);
		return;
	}

	Node<T> *newNode = new Node<T>;
	
	newNode->data = data;
	tail->next = newNode;

	tail = newNode;
}

template <class T>
void List<T>::removeFromHead()
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

template<class T>
int List<T>::count()
{
	int count = 0;

	this->current = head;

	while ( this->current != NULL )
	{
		count++;
		this->current = this->current->next;
	}

	return count;
}

template <class T>
void List<T>::print()
{
	current = head;
	while ( current != NULL )
	{
		std::cout << current->data << " <=== " << std::endl;
		current = current->next;
	}
}

template <class T>
void List<T>::free()
{
	while ( !isEmpty() )
	{
		removeFromHead();
	}
}

} //end namespace Rocket

#endif