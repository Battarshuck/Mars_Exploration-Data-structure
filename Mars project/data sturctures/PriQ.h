#pragma once
#include "Node.h"
template <typename T>
class PriQ
{
private:
	Node<T>** heap;
	int size;
	int capacity;
	int parent(int i);
	int left(int i);
	int right(int i);
	void reheap_up(int idx);
	void reheap_down(int idx);
public:
	PriQ(int c = 50);
	bool insert(Node<T>* x);
	Node<T>* extract_max();
};

template <typename T>
PriQ<T>::PriQ(int c) {
	size = 0;
	capacity = c;
	heap = new Node<T> * [c];
}

template <typename T>
int PriQ<T>::parent(int i) {
	return (i - 1) / 2;
}

template <typename T>
int PriQ<T>::left(int i) {
	return (2 * i + 1);
}

template <typename T>
int PriQ<T>::right(int i) {
	return (2 * i + 2);
}

template <typename T>
void PriQ<T>::reheap_up(int idx) {
	while (idx > 0 && heap[parent(idx)]->getpriority() < heap[idx]->getpriority()) {
		Node<T>* temp = heap[parent(idx)];
		heap[parent(idx)] = heap[idx];
		heap[idx] = temp;
		idx = parent(idx);
	}
}

template <typename T>
void PriQ<T>::reheap_down(int idx) {
	int max = idx;
	int l = left(idx);
	int r = right(idx);
	if (l<size && heap[l]->getpriority() > heap[max]->getpriority()) {
		max = l;
	}
	if (r<size && heap[r]->getpriority() > heap[max]->getpriority()) {
		max = r;
	}
	if (idx != max) {
		Node<T>* temp = heap[idx];
		heap[idx] = heap[max];
		heap[max] = temp;
		reheap_down(max);
	}
}

template <typename T>
bool PriQ<T>::insert(Node<T>* x) {
	if (size == capacity) return 0;
	size++;
	heap[size - 1] = x;
	reheap_up(size - 1);
	return 1;
}

template <typename T>
Node<T>* PriQ<T>::extract_max() {
	if (size <= 0) return nullptr;
	if (size == 1) {
		size--;
		return heap[0];
	}
	Node<T>* x = heap[0];
	heap[0] = heap[size - 1];
	size--;
	reheap_down(0);
	return x;
}


