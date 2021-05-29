#pragma once
template < typename T>
class Node2
{
private:
	T item; // A data item
	Node2<T>* next; // Pointer to next Node2
public:
	Node2();
	Node2(const T& r_Item);
	Node2(const T& r_Item, Node2<T>* nextNode2Ptr);
	void setItem(const T& r_Item);
	void setNext(Node2<T>* nextNode2Ptr);
	T getItem() const;
	Node2<T>* getNext() const;
}; // end Node2

template < typename T>
Node2<T>::Node2()
{
	next = nullptr;
}

template < typename T>
Node2<T>::Node2(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template < typename T>
Node2<T>::Node2(const T& r_Item, Node2<T>* nextNode2Ptr)
{
	item = r_Item;
	next = nextNode2Ptr;
}
template < typename T>
void Node2<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void Node2<T>::setNext(Node2<T>* nextNode2Ptr)
{
	next = nextNode2Ptr;
}

template < typename T>
T Node2<T>::getItem() const
{
	return item;
}

template < typename T>
Node2<T>* Node2<T>::getNext() const
{
	return next;
}
