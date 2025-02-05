#pragma once
#include <iostream>
#include "clsMyQueueArr.h"
using namespace std;

template <class T>
class clsMyStackArr : public clsMyQueueArr <T> {
public:

	void push(T Value) {
		clsMyQueueArr <T>::push(Value);
	}

	void pop() {
		clsMyQueueArr <T>::_MyDynamicArray.DeleteLastItem();
	}

	T Top() {
		return clsMyQueueArr <T>::back();
	}

	T Bottom() {
		return clsMyQueueArr <T>::front();
	}

	void InsertAtTop(T Value) {
		clsMyQueueArr <T>::InsertAtBack(Value);
	}

	void InsertAtBottom(T Value) {
		clsMyQueueArr <T>::InsertAtFront(Value);
	}

};

