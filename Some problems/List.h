#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class List
{
public:
	Node<T>* head, * tail;

	List() { head = tail = NULL; };
	~List();

	void AddToHead(T el);
	void printAll();
	void deleteFromHead();
	bool isEmpty() { return head == NULL; };

	void SelectionSort();
	void SwapNode(Node<T>* a, Node<T>* b);

	void MovePartToEnd(T val1, T val2);

	void Transpose2(T key);
};

template<class T>
List<T>::~List()
{
	while (!isEmpty())
	{
		deleteFromHead();
	}
}

template<class T>
void List<T>::AddToHead(T el)
{
	if (!isEmpty())
	{
		Node<T>* newNode = new Node<T>(el);
		newNode->next = head;
		head = newNode;
	}
	else
	{
		head = tail = new Node<T>(el);
	}
}

template<class T>
void List<T>::SelectionSort()
{
	Node<T>* tmpMax, *tmp, *maxSwap, *tmpMaxSwap;

	tmpMax = head;
	while (tmpMax != tail)
	{
		tmp = tmpMax->next;
		maxSwap = tmpMax;
		while (tmp != NULL)
		{
			if (maxSwap->value < tmp->value)
				maxSwap = tmp;
			tmp = tmp->next;
		}

		tmpMaxSwap = tmpMax;
		tmpMax = tmpMax->next;
		SwapNode(tmpMaxSwap, maxSwap);

	}
}

template<class T>
void List<T>::SwapNode(Node<T>* a, Node<T>* b)
{
	int tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

template<class T>
void List<T>::MovePartToEnd(T val1, T val2)
{
	// dont use tail
	Node<T>* endOfList; //instead of tail

	endOfList = head;
	while (endOfList->next != NULL)
	{
		endOfList = endOfList->next;
	}

	Node<T>* nodeVal1Prev, *nodeVal2, *nodeVal1;
	nodeVal1Prev = nodeVal2 = head;

	while (nodeVal1Prev->next->value!= val1)
	{
		nodeVal1Prev = nodeVal1Prev->next;
	}

	nodeVal1 = nodeVal1Prev->next;

	while (nodeVal2->value != val2)
	{
		nodeVal2 = nodeVal2->next;
	}

	endOfList->next = nodeVal1;
	nodeVal1Prev->next = nodeVal2->next;
	nodeVal2->next = NULL;

}

template<class T>
void List<T>::Transpose2(T key)
{
	Node<T>* tmp, * tmpPrev;

	tmpPrev = tmp = head;

	while (tmpPrev->next->value != key)
	{
		tmpPrev = tmpPrev->next;
	}
	tmp = tmpPrev->next;

	if (tmp->next == NULL || tmp->next->next == NULL)
	{
		//not possible to move node 2 positions forward

		tmpPrev->next = tmp->next;
		tmp->next = head;
		head = tmp;
	}
	else
	{
		tmpPrev->next = tmp->next;
		tmp->next = tmpPrev->next->next->next;
		tmpPrev->next->next->next = tmp;
	}
}

template<class T>
void List<T>::printAll()
{
	Node<T>* tmp;
	for (tmp = head; tmp != NULL; tmp = tmp->next)
	{
		cout << tmp->value << " ";
	}
	cout << endl;
}

template<class T>
void List<T>::deleteFromHead()
{
	Node<T>* tmp;

	tmp = head;
	if (head == tail) head = tail = NULL;
	else head = head->next;
	delete tmp;
}
