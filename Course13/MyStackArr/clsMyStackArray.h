#pragma once

#include <iostream>
#include "clsMyQueueArray.h"
using namespace std;

template <class T>
class clsMyStackArray :public clsMyQueueArray <T>
{
public:

	void Push(T Item)
	{
		clsMyQueueArray<T> ::_MyArray.InsertAtBeginning(Item);
	}

	void Pop()
	{
		clsMyQueueArray<T> ::_MyArray.DeleteFirstItem();
	}

	T Top()
	{
		return clsMyQueueArray<T> ::front();
	}

	T Bottom()
	{
		return clsMyQueueArray <T>::back();

	}

	int Size()
	{
		return clsMyQueueArray <T>::_MyArray.Size();
	}




};

