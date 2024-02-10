
#pragma once
#include "clsDblLinkedList.h"

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList<T> _MyList;

public:

	void Push(T item) {
		return _MyList.InsertAtEnd(item);
	}

	void Pop() {
		return _MyList.DeleteFirstNode();
	}

	void Print() {
		return _MyList.PrintList();
	}

	int Size() {
		return _MyList.Size();
	}

	bool IsEmpty() {
		return _MyList.IsEmpty();
	}

	T front() {
		return _MyList.GetItem(0);
	}

	T back() {
		return _MyList.GetItem(Size() - 1);
	}

	T GetItem(int index) {
		return _MyList.GetItem(2);
	}

	void Reverse() {
		return _MyList.Reverse();
	}

	bool UpdateItem(int index, T new_value) {
		return _MyList.UpdateItem(index, new_value);
	}

	bool InsertAfter(int index, T new_value) {
		return _MyList.InsertAfter(index, new_value);
	}

	void InsertAtFront(T value) {
		return _MyList.InsertAtBeginning(value);
	}

	void InsertAtBack(T value) {
		return _MyList.InsertAtEnd(value);
	}

	void Clear() {
		return _MyList.Clear();
	}

};

