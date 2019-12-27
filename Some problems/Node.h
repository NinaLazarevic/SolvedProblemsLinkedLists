#pragma once
#include <iostream>

template <class T>
class Node
{
public:
	T value;
	Node<T>* next;

	Node() {};
	Node(T el)
	{
		value = el;
		next = NULL;
	}
	~Node() {};
};
