#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr {
protected:

	clsDynamicArray <T> _MyDynamicArray;

public:

	void push(T Value) {
		_MyDynamicArray.InsertAtEnd(Value);
	}

	void pop() {
		_MyDynamicArray.DeleteFirstItem();
	}

	void Print() {
		_MyDynamicArray.PrintList();
	}

	short Size() {
		return _MyDynamicArray.Size();
	}

	bool IsEmpty() {
		return _MyDynamicArray.IsEmpty();
	}

	T front() {
		return _MyDynamicArray.GetItem(0);
	}

	T back() {
		return _MyDynamicArray.GetItem(Size() - 1);
	}

	T GetItem(int Index) {
		return _MyDynamicArray.GetItem(Index);
	}

	void Reverse() {
		_MyDynamicArray.Reverse();
	}

	void UpdateItem(int Index, T NewValue) {
		_MyDynamicArray.SetItem(Index, NewValue);
	}

	void InsertAfter(int Index, T NewValue) {
		_MyDynamicArray.InsertAfter(Index, NewValue);
	}

	void InsertAtFront(T Value) {
		_MyDynamicArray.InsertAtBegining(Value);
	}

	void InsertAtBack(T Value) {
		_MyDynamicArray.InsertAtEnd(Value);
	}

	void Clear() {
		_MyDynamicArray.Clear();
	}

};

