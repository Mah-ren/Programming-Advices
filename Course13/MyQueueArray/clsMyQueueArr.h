#pragma once
#include "clsDynamicArray.h"

template <class T>
class clsMyQueueArr : public clsDynamicArray<T>
{
protected:
	clsDynamicArray<T> _MyArray;

public:

	bool Push(T item) {
		return _MyArray.InsertAtEnd(item);
	}
	
	bool Pop() {
		return _MyArray.DeleteFirstItem();
	}

	void Print() {
		return _MyArray.PrintList();
	}

	T front() {
		return _MyArray.GetItem(0);
	}

	T back() {
		return _MyArray.GetItem(_MyArray.Size() - 1);
	}

	void InsertAtFront(T value) {
		return _MyArray.InsertAtBeginning(value);
	}

	bool InsertAtBack(T value) {
		return _MyArray.InsertAtEnd(value);
	}


};




