
#pragma once
#include "clsDblLinkedList.h"

template <class T>
class clsMyQueue {
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
}; 

