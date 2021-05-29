#pragma once
template < typename T>
class Node
{
private:
	T data;
	int priority;
public:
		
	Node(T val, int p);
	void setdata(T d);
	T getdata();
	void setpriority(int d);
	int getpriority();
};

template < typename T>
Node<T>::Node(T val, int p)
	{
		data = val;
		priority = p;
	}

template < typename T>
void Node<T>::setdata(T d)
	{
		data = d;
	}

template < typename T>
T Node<T>::getdata()
	{
		return data;
	}

template < typename T>
void Node<T>::setpriority(int d)
	{
		priority = d;
	}

template < typename T>
int Node<T>::getpriority()
	{
		return priority;
	}



