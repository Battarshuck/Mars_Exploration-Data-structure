#pragma once
#include "Node2.h"
template <typename T>
class Queue
{
private:

	Node2<T>* backPtr;
	Node2<T>* frontPtr;
public:
	Queue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	//bool peek(T& frntEntry)  const;
	//void print() const;
	~Queue();

	//copy constructor
	Queue(const Queue<T>& LQ);
};

template <typename T>
Queue<T>::Queue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}


template <typename T>
bool Queue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template <typename T>
bool Queue<T>::enqueue(const T& newEntry)
{
	Node2<T>* newNode2Ptr = new Node2<T>(newEntry);
	// Insert the new Node2
	if (isEmpty())	//special case if this is the first Node2 to insert
		frontPtr = newNode2Ptr; // The queue is empty
	else
		backPtr->setNext(newNode2Ptr); // The queue was not empty

	backPtr = newNode2Ptr; // New Node2 is the last Node2 now
	return true;
} // end enqueue

template <typename T>
bool Queue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node2<T>* Node2ToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (Node2ToDeletePtr == backPtr)	 // Special case: last Node2 in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued Node2
	delete Node2ToDeletePtr;

	return true;

}

template <typename T>
Queue<T>::~Queue()
{
	T temp;

	//Free (Dequeue) all Node2s in the queue
	while (dequeue(temp));
}

template <typename T>
Queue<T>::Queue(const Queue<T>& LQ)
{
	Node2<T>* Node2Ptr = LQ.frontPtr;
	if (!Node2Ptr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first Node2
	Node2<T>* ptr = new Node2<T>(Node2Ptr->getItem());
	frontPtr = backPtr = ptr;
	Node2Ptr = Node2Ptr->getNext();

	//insert remaining Node2s
	while (Node2Ptr)
	{
		Node2<T>* ptr = new Node2<T>(Node2Ptr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		Node2Ptr = Node2Ptr->getNext();
	}
}