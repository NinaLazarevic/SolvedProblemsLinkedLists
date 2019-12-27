#pragma once
#include "List.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main()
{
	List<int> list;

	list.AddToHead(0);
	list.AddToHead(3);
	list.AddToHead(10);
	list.AddToHead(1);
	list.AddToHead(7);
	list.AddToHead(2);
	list.AddToHead(12);
	list.AddToHead(8);

	list.printAll();

	/// problem 1.
	list.SelectionSort();
	list.printAll();

	//problem 2.
	list.MovePartToEnd(10, 7);
	list.printAll();

	//problem 3.
	list.Transpose2(3);
	list.printAll();

	return 0;
}