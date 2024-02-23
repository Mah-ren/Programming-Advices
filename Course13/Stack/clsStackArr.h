#pragma once

#include <iostream>
#include "clsStackArr.h"
using namespace std;
template <class T>
class clsMyStack : public clsMyQueue<T>
{
public:

	void Push(T Item)
	{
		clsMyQueue <T>::_MyList.InsertAtBeginning(Item);
	}

	T Top()
	{
		return clsMyQueue <T>::front();

	}

	T Bottom()
	{
		return clsMyQueue <T>::back();

	}

};

