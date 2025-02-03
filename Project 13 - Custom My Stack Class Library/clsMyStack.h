#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyStack {
private:
	clsDblLinkedList <T> _MyList;

public:

	void push(T Value) {
		_MyList.InsertAtBeginning(Value);
	}

	void Print() {
		_MyList.PrintList();
	}

	short Size() {
		return _MyList.Size();
	}

	T Top() {
		return _MyList.GetItem(0);
	}

	T Bottom() {
		return _MyList.GetItem(Size() - 1);
	}

	void pop() {
		_MyList.DeleteFirstNode();
	}

	T GetItem(int Index) {
		return _MyList.GetItem(Index);
	}

	void Reverse() {
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T NewValue) {
		_MyList.UpdateItem(Index, NewValue);
	}

	void InsertAfter(int Index, T NewValue) {
		_MyList.InsertAfter(Index, NewValue);
	}

	void InsertAtFront(T Value) {
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value) {
		_MyList.InsertAtEnd(Value);
	}

	void Clear() {
		_MyList.Clear();
	}
};

